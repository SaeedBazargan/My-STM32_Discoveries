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
#include "stdio.h"
#include "string.h"
#include "math.h"

#include "HAL_MPU9250.h"

#include "ai_datatypes_defines.h"
#include "ai_platform.h"
#include "imu_model.h"
#include "imu_model_data.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/**
 * @brief If you want to read sensor data and send it to Python, Debug should be set to 1.
 * Otherwise, if you want to use the model to predict direction, Debug should be set to 0.
*/
#define Debug					1


#define ZERO_MAX				20
#define ZERO_MIN				-20
#define RAD2DEG 				57.2957795131
#define ALPHA 					0.98f          // Complementary filter coefficient
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
CRC_HandleTypeDef hcrc;

SPI_HandleTypeDef hspi1;

UART_HandleTypeDef huart2;

osThreadId defaultTaskHandle;
/* USER CODE BEGIN PV */
osThreadId runTaskHandle;
osThreadId readDataTaskHandle;
osThreadId sendDataTaskHandle;
osMessageQId Queue_1Handle;

MPU9250TypeDef MPU9250;

uint8_t IMU_rawData[14] = {0};
int16_t Raw_Accel[3] = {0}, Raw_Gyro[3] = {0};

float GX = 0, GY = 0, GZ = 0, AX = 0, AY = 0, AZ = 0;
float Roll, Pitch, Yaw;

typedef struct
{
	uint8_t Shifted_Roll;
	uint8_t Shifted_Pitch;
}IMUdata_t;

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_SPI1_Init(void);
static void MX_USART2_UART_Init(void);
static void MX_CRC_Init(void);
void StartDefaultTask(void const * argument);

/* USER CODE BEGIN PFP */
void StartRunTask(void const * argument);
void StartReadDataTask(void const * argument);

#if Debug
void StartSendDataTask(void const * argument);
#endif

void IMU_Init(void);
void IMU_readRawData(void);
void IMU_UpdateAngles(float dt);
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
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
  MX_USART2_UART_Init();
  MX_CRC_Init();
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
#if Debug
  osMessageQDef(Queue_1, 1, sizeof(IMUdata_t));
  Queue_1Handle = osMessageCreate(osMessageQ(Queue_1), NULL);
#endif
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* definition and creation of defaultTask */
  osThreadDef(defaultTask, StartDefaultTask, osPriorityIdle, 0, 128);
  defaultTaskHandle = osThreadCreate(osThread(defaultTask), NULL);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* definition and creation of runTask */
  osThreadDef(runTask, StartRunTask, osPriorityNormal, 0, 128);
  runTaskHandle = osThreadCreate(osThread(runTask), NULL);

  /* definition and creation of readDataTask */
  osThreadDef(readDataTask, StartReadDataTask, osPriorityIdle, 0, 512);
  readDataTaskHandle = osThreadCreate(osThread(readDataTask), NULL);
#if Debug
  /* definition and creation of sendDataTask */
  osThreadDef(sendDataTask, StartSendDataTask, osPriorityNormal, 0, 512);
  sendDataTaskHandle = osThreadCreate(osThread(sendDataTask), NULL);
#endif
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
  * @brief CRC Initialization Function
  * @param None
  * @retval None
  */
static void MX_CRC_Init(void)
{

  /* USER CODE BEGIN CRC_Init 0 */

  /* USER CODE END CRC_Init 0 */

  /* USER CODE BEGIN CRC_Init 1 */

  /* USER CODE END CRC_Init 1 */
  hcrc.Instance = CRC;
  if (HAL_CRC_Init(&hcrc) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN CRC_Init 2 */

  /* USER CODE END CRC_Init 2 */

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
  hspi1.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_4;
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
  * @brief USART2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART2_UART_Init(void)
{

  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 115200;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART2_Init 2 */

  /* USER CODE END USART2_Init 2 */

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
  HAL_GPIO_WritePin(GPIOD, LED_Run_Pin|LED_Error_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : SPI1_CS_Pin */
  GPIO_InitStruct.Pin = SPI1_CS_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(SPI1_CS_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : LED_Run_Pin LED_Error_Pin */
  GPIO_InitStruct.Pin = LED_Run_Pin|LED_Error_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */
// <---- ------------ IMU Initialized ------------ ---->
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
// <---- ------------ IMU Read Raw Data ------------ ---->
void IMU_readRawData(void)
{
	// <---- ------------ Merging Data to get real IMU data ------------ ---->
	MPU9250_ReadData(&hspi1, IMU_rawData, MPU9250_ACCEL_XOUT_H, 6);
	Raw_Accel[0] = (int16_t)(IMU_rawData[0] << 8 | IMU_rawData[1]);
	Raw_Accel[1] = (int16_t)(IMU_rawData[2] << 8 | IMU_rawData[3]);
	Raw_Accel[2] = (int16_t)(IMU_rawData[4] << 8 | IMU_rawData[5]);

	MPU9250_ReadData(&hspi1, IMU_rawData, MPU9250_GYRO_XOUT_H, 6);
	Raw_Gyro[0] = (int16_t)(IMU_rawData[0] << 8 | IMU_rawData[1]);
	Raw_Gyro[1] = (int16_t)(IMU_rawData[2] << 8 | IMU_rawData[3]);
	Raw_Gyro[2] = (int16_t)(IMU_rawData[4] << 8 | IMU_rawData[5]);

	// <---- ------------ Removing Gyro's Noise around 0 state ------------ ---->
	Raw_Gyro[0] = (Raw_Gyro[0] <= ZERO_MAX && Raw_Gyro[0] >= ZERO_MIN)? 0: Raw_Gyro[0];
	Raw_Gyro[1] = (Raw_Gyro[1] <= ZERO_MAX && Raw_Gyro[1] >= ZERO_MIN)? 0: Raw_Gyro[1];
	Raw_Gyro[2] = (Raw_Gyro[2] <= ZERO_MAX && Raw_Gyro[2] >= ZERO_MIN)? 0: Raw_Gyro[2];

	GX = (float)(Raw_Gyro[0] * (2000 / 32768.0));
	GY = (float)(Raw_Gyro[1] * (2000 / 32768.0));
	GZ = (float)(Raw_Gyro[2] * (2000 / 32768.0));

	AX = (float)(Raw_Accel[0] * (16.0 / 32768.0));
	AY = (float)(Raw_Accel[1] * (16.0 / 32768.0));
	AZ = (float)(Raw_Accel[2] * (16.0 / 32768.0));

//	// <---- ------------ Converting Degree to Radian------------ ---->
	GX = GX / (180.0 / M_PI);
	GY = GY / (180.0 / M_PI);
	GZ = GZ / (180.0 / M_PI);
}

// <---- ------------ Convert raw data to the Roll and Pitch ------------ ---->
void IMU_UpdateAngles(float dt)
{
    static int first_run = 1;
    static float last_roll, last_pitch;

    IMUdata_t data;

    if(first_run)
    {
        float roll_acc = atan2f(AY, sqrtf(AX*AX + AZ*AZ));
        float pitch_acc = atan2f(-AX, sqrtf(AY*AY + AZ*AZ));
        last_roll = roll_acc;
        last_pitch = pitch_acc;
        first_run = 0;
        return;
    }

    // Gyro integration
    float gyro_roll = last_roll + GX * dt;
    float gyro_pitch = last_pitch + GY * dt;

    // Accelerometer angles
    float roll_acc = atan2f(AY, sqrtf(AX * AX + AZ * AZ));
    float pitch_acc = atan2f(-AX, sqrtf(AY * AY + AZ * AZ));

    // Complementary filter
    Roll = ALPHA * gyro_roll + (1 - ALPHA) * roll_acc;
    Pitch = ALPHA * gyro_pitch + (1 - ALPHA) * pitch_acc;

    // Yaw integration (will drift without magnetometer)
    Yaw += GZ * dt;

    // Store for next iteration
    last_roll = Roll;
    last_pitch = Pitch;

    data.Shifted_Roll  = (Roll + 10) * 10;
    data.Shifted_Pitch = (Pitch + 10) * 10;
    osMessagePut(Queue_1Handle, &data, osWaitForever);
    osDelay(100);
}

// <---- ------------ Check RunTime Task ------------ ---->
void StartRunTask(void const * argument)
{
  for(;;)
  {
	HAL_GPIO_TogglePin(LED_Run_GPIO_Port, LED_Run_Pin);
    osDelay(500);
  }
}

// <---- ------------ Reading raw data and converting Task ------------ ---->
void StartReadDataTask(void const * argument)
{
  uint32_t last_time = HAL_GetTick();
  uint32_t now = HAL_GetTick();
  float dt = (now - last_time) * 0.001f;

  IMU_Init();

  for(;;)
  {
	IMU_readRawData();

	now = HAL_GetTick();
    dt = (now - last_time) * 0.001f;
    last_time = now;

    IMU_UpdateAngles(dt);
  }
}

// <---- ------------ Sending to the PC Task ------------ ---->
void StartSendDataTask(void const * argument)
{
	uint8_t buf[100];
  int buf_len;

  IMUdata_t *data;
  osEvent evt;

  for(;;)
  {
    evt = osMessageGet(Queue_1Handle, osWaitForever);
    if (evt.status == osEventMessage)
    {
    	data = evt.value.p;

    	printf("Roll ----> %d \r\n", data->Shifted_Roll);
    	buf_len = sprintf(buf, "Roll ----> %d \r\n", data->Shifted_Roll);
    	HAL_UART_Transmit(&huart2, buf, buf_len, 100);
    	memset(buf, 0, buf_len);

    	printf("Pitch ----> %d \r\n", data->Shifted_Pitch);
    	buf_len = sprintf(buf, "Pitch ----> %d \r\n", data->Shifted_Pitch);
    	HAL_UART_Transmit(&huart2, buf, buf_len, 100);
    	memset(buf, 0, buf_len);

    }
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
	HAL_GPIO_TogglePin(LED_Run_GPIO_Port, LED_Run_Pin);
    osDelay(500);
  }
  /* USER CODE END 5 */
}

/**
  * @brief  Period elapsed callback in non blocking mode
  * @note   This function is called  when TIM11 interrupt took place, inside
  * HAL_TIM_IRQHandler(). It makes a direct call to HAL_IncTick() to increment
  * a global variable "uwTick" used as application time base.
  * @param  htim : TIM handle
  * @retval None
  */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  /* USER CODE BEGIN Callback 0 */

  /* USER CODE END Callback 0 */
  if (htim->Instance == TIM11) {
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
	HAL_GPIO_WritePin(LED_Error_GPIO_Port, LED_Error_Pin, GPIO_PIN_SET);
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
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
