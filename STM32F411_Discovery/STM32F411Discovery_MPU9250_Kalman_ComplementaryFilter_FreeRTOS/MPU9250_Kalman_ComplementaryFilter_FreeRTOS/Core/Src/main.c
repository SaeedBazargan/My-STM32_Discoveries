/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "HAL_MPU9250.h"
#include "IMU_KalmanFilter.h"

#include "stdio.h"
#include "string.h"
#include "math.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
// <---- --- IMU Defines --- ---->
#define ZERO_MAX				20
#define ZERO_MIN				-20
#define N 						100
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
SPI_HandleTypeDef hspi1;

osThreadId defaultTaskHandle;
/* USER CODE BEGIN PV */
// <---- --- My Tasks Variables --- ---->
osThreadId readRawDataTaskHandle;
osThreadId kalmanFilterTaskHandle;
osThreadId complementaryFilterTaskHandle;

osMessageQId Queue_1Handle;

// <---- --- IMU Variables --- ---->
MPU9250TypeDef MPU9250;
KalmanFilter kf;

uint8_t IMU_rawData[14] = {0};
typedef struct
{
	int16_t Raw_Accel[3];
	int16_t Raw_Gyro[3];
}IMUdata_t;

float GX = 0, GY = 0, GZ = 0, AX = 0, AY = 0, AZ = 0;
float phi, theta;
float phi_acc_samples[N];
float theta_acc_samples[N];
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_SPI1_Init(void);
void StartDefaultTask(void const * argument);

/* USER CODE BEGIN PFP */
// <---- --- My Tasks Functions --- ---->
void StartReadRawDataTask(void const * argument);
void StartKalmanFilterTask(void const * argument);
void StartComplementaryFilterTask(void const * argument);

// <---- --- IMU Functions --- ---->
void IMU_Init(void);
void IMU_readRawData(void);
void KalmanFilter_Init(void);
void IMU_UpdateAngles(float dt);
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
// <---- --- SWV Print --- ---->
int _write(int file, char *ptr, int len)
{
	int i = 0;
	for(i = 0; i < len; i++)
	{
		ITM_SendChar(*ptr++);
	}
	return len;
}
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_SPI1_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  osMessageQDef(Queue_1, 1, sizeof(IMUdata_t));
  Queue_1Handle = osMessageCreate(osMessageQ(Queue_1), NULL);
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* definition and creation of defaultTask */
  osThreadDef(defaultTask, StartDefaultTask, osPriorityNormal, 0, 128);
  defaultTaskHandle = osThreadCreate(osThread(defaultTask), NULL);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  osThreadDef(readRawDataTask, StartReadRawDataTask, osPriorityAboveNormal, 0, 1024);
  readRawDataTaskHandle = osThreadCreate(osThread(readRawDataTask), NULL);

  osThreadDef(kalmanFilterTask, StartKalmanFilterTask, osPriorityNormal, 0, 1024);
  kalmanFilterTaskHandle = osThreadCreate(osThread(kalmanFilterTask), NULL);

  osThreadDef(complementaryFilterTask, StartComplementaryFilterTask, osPriorityNormal, 0, 1024);
  complementaryFilterTaskHandle = osThreadCreate(osThread(complementaryFilterTask), NULL);
  /* USER CODE END RTOS_THREADS */

  /* Start scheduler */
  osKernelStart();

  /* We should never get here as control is now taken by the scheduler */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 4;
  RCC_OscInitStruct.PLL.PLLN = 100;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_3) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief SPI1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_SPI1_Init(void)
{

  /* USER CODE BEGIN SPI1_Init 0 */

  /* USER CODE END SPI1_Init 0 */

  /* USER CODE BEGIN SPI1_Init 1 */

  /* USER CODE END SPI1_Init 1 */
  /* SPI1 parameter configuration*/
  hspi1.Instance = SPI1;
  hspi1.Init.Mode = SPI_MODE_MASTER;
  hspi1.Init.Direction = SPI_DIRECTION_2LINES;
  hspi1.Init.DataSize = SPI_DATASIZE_8BIT;
  hspi1.Init.CLKPolarity = SPI_POLARITY_LOW;
  hspi1.Init.CLKPhase = SPI_PHASE_1EDGE;
  hspi1.Init.NSS = SPI_NSS_SOFT;
  hspi1.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_8;
  hspi1.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspi1.Init.TIMode = SPI_TIMODE_DISABLE;
  hspi1.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  hspi1.Init.CRCPolynomial = 10;
  if (HAL_SPI_Init(&hspi1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN SPI1_Init 2 */

  /* USER CODE END SPI1_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  /* USER CODE BEGIN MX_GPIO_Init_1 */

  /* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(SPI1_CS_GPIO_Port, SPI1_CS_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOD, LED_Error_Pin|LED_OK_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : SPI1_CS_Pin */
  GPIO_InitStruct.Pin = SPI1_CS_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(SPI1_CS_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : LED_Error_Pin LED_OK_Pin */
  GPIO_InitStruct.Pin = LED_Error_Pin|LED_OK_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

  /* USER CODE BEGIN MX_GPIO_Init_2 */

  /* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */
void IMU_Init(void)
{
	MPU9250.PWR_MGMT1	= CLKSEL_1;						// CLOCK_SEL_PLL
	MPU9250.PWR_MGMT2	= ENABLE_ALL;					// Enable All Sensors
	MPU9250.Gyro_DLPF   = BW250_D970;
	MPU9250.Accel_DLPF  = BW218_D1880;
	MPU9250.Gyro_Range  = MPU9250_Gyroscope_2000;
	MPU9250.Accel_Range = MPU9250_Accelerometer_16;

	if(MPU9250_Init(&hspi1, SPI1_CS_GPIO_Port, SPI1_CS_Pin, &MPU9250) != MPU9250_RESULT_OK)
	{
		Error_Handler();
	}
}

void IMU_readRawData(void)
{
	IMUdata_t data;
	// <---- ------------ Merging Data to get real IMU data ------------ ---->
	MPU9250_ReadData(&hspi1, IMU_rawData, MPU9250_ACCEL_XOUT_H, 6);
	data.Raw_Accel[0] = (int16_t)(IMU_rawData[0] << 8 | IMU_rawData[1]);
	data.Raw_Accel[1] = (int16_t)(IMU_rawData[2] << 8 | IMU_rawData[3]);
	data.Raw_Accel[2] = (int16_t)(IMU_rawData[4] << 8 | IMU_rawData[5]);

	MPU9250_ReadData(&hspi1, IMU_rawData, MPU9250_GYRO_XOUT_H, 6);
	data.Raw_Gyro[0] = (int16_t)(IMU_rawData[0] << 8 | IMU_rawData[1]);
	data.Raw_Gyro[1] = (int16_t)(IMU_rawData[2] << 8 | IMU_rawData[3]);
	data.Raw_Gyro[2] = (int16_t)(IMU_rawData[4] << 8 | IMU_rawData[5]);

	// <---- ------------ Removing Gyro's Noise around 0 state ------------ ---->
	data.Raw_Gyro[0] = (data.Raw_Gyro[0] <= ZERO_MAX && data.Raw_Gyro[0] >= ZERO_MIN)? 0: data.Raw_Gyro[0];
	data.Raw_Gyro[1] = (data.Raw_Gyro[1] <= ZERO_MAX && data.Raw_Gyro[1] >= ZERO_MIN)? 0: data.Raw_Gyro[1];
	data.Raw_Gyro[2] = (data.Raw_Gyro[2] <= ZERO_MAX && data.Raw_Gyro[2] >= ZERO_MIN)? 0: data.Raw_Gyro[2];

	GX = (float)(data.Raw_Gyro[0] * (2000 / 32768.0));
	GY = (float)(data.Raw_Gyro[1] * (2000 / 32768.0));
	GZ = (float)(data.Raw_Gyro[2] * (2000 / 32768.0));

	AX = (float)(data.Raw_Gyro[0] * (16.0 / 32768.0));
	AY = (float)(data.Raw_Gyro[1] * (16.0 / 32768.0));
	AZ = (float)(data.Raw_Gyro[2] * (16.0 / 32768.0));

	// <---- ------------ Converting Degree to Radian------------ ---->
//	GX = GX / (180.0 / M_PI);
//	GY = GY / (180.0 / M_PI);
//	GZ = GZ / (180.0 / M_PI);

//	printf("AX: %.2f \n", AX);
//	printf("AY: %.2f \n", AY);
//	printf("AZ: %.2f \n", AZ);
//
//	printf("GX: %.2f \n", GX);
//	printf("GY: %.2f \n", GY);
//	printf("GZ: %.2f \n", GZ);
}

void StartReadRawDataTask(void const * argument)
{

	float dt = 0.0f;


	IMU_Init();
	kalman_init(&kf);

	for(;;)
	{
		IMU_readRawData();
		Get_AccelAngles(AZ, AY, AZ, &phi, &theta);
		kalman_calibrate(&kf, phi, theta, N);

		kalman_update(&kf, GX, GY, GZ, AX, AY, AZ, dt);

		// Get filtered angles
		float roll  = kalman_get_roll(&kf);
		float pitch = kalman_get_pitch(&kf);

		printf("roll: %.2f \n", roll);
		printf("pitch: %.2f \n", pitch);

		osDelay(1);
	}
}

void StartKalmanFilterTask(void const * argument)
{
	for(;;)
	{
		osDelay(1);
	}
}

void StartComplementaryFilterTask(void const * argument)
{
	for(;;)
	{
		osDelay(1);
	}
}

/* USER CODE END 4 */

/* USER CODE BEGIN Header_StartDefaultTask */
/**
  * @brief  Function implementing the defaultTask thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_StartDefaultTask */
void StartDefaultTask(void const * argument)
{
  /* USER CODE BEGIN 5 */
  /* Infinite loop */
  for(;;)
  {
	  HAL_GPIO_TogglePin(LED_OK_GPIO_Port, LED_OK_Pin);
	  osDelay(500);
  }
  /* USER CODE END 5 */
}

/**
  * @brief  Period elapsed callback in non blocking mode
  * @note   This function is called  when TIM10 interrupt took place, inside
  * HAL_TIM_IRQHandler(). It makes a direct call to HAL_IncTick() to increment
  * a global variable "uwTick" used as application time base.
  * @param  htim : TIM handle
  * @retval None
  */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  /* USER CODE BEGIN Callback 0 */

  /* USER CODE END Callback 0 */
  if (htim->Instance == TIM10)
  {
    HAL_IncTick();
  }
  /* USER CODE BEGIN Callback 1 */

  /* USER CODE END Callback 1 */
}

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
	  HAL_GPIO_WritePin(LED_Error_GPIO_Port, LED_Error_Pin, GPIO_PIN_SET);
  }
  /* USER CODE END Error_Handler_Debug */
}
#ifdef USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
