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

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "stdio.h"

#include "tensorflow/lite/micro/kernels/micro_ops.h"
#include "tensorflow/lite/micro/tflite_bridge/micro_error_reporter.h"
#include "tensorflow/lite/micro/micro_interpreter.h"
#include "tensorflow/lite/micro/micro_mutable_op_resolver.h"
#include "tensorflow/lite/schema/schema_generated.h"
#include "sine_model.h"

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
TIM_HandleTypeDef htim11;

UART_HandleTypeDef huart2;

/* USER CODE BEGIN PV */
// <---- -------- TFLite variables -------- ---->
namespace
{
	tflite::MicroErrorReporter micro_error_reporter;
	tflite::ErrorReporter* error_reporter = &micro_error_reporter;
	const tflite::Model* model 		  	  = nullptr;
	tflite::MicroInterpreter* interpreter = nullptr;
	TfLiteTensor* model_input			  = nullptr;
	TfLiteTensor* model_output			  = nullptr;

	// <---- -------- Create an area of memory to use for input/output and other tensorflow arrays.
	// you will need to adjust this by compiling, running, and looking for errors  -------- ---->
	const int KTensorArenaSize = 2 * 1024;
	uint8_t tensor_arena[KTensorArenaSize];
}
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM11_Init(void);
static void MX_USART2_UART_Init(void);
/* USER CODE BEGIN PFP */

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

char buf[50];
int buf_len = 0;
TfLiteStatus tflite_status;
uint32_t num_elements;
uint32_t timestamp;
float y_val;
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
  MX_TIM11_Init();
  MX_USART2_UART_Init();
  /* USER CODE BEGIN 2 */
  HAL_TIM_Base_Start(&htim11);

  error_reporter->Report("STM32 TFLite Test.");

  buf_len = sprintf(buf, "STM32 TFLite Test.");
  HAL_UART_Transmit(&huart2, (uint8_t *)buf, buf_len, 100);

  model = tflite::GetModel(sine_model);
  if(model->version() != TFLITE_SCHEMA_VERSION)
  {
	  error_reporter->Report("Model version does not match schema.");

	  buf_len = sprintf(buf, "Model version does not match schema.");
	  HAL_UART_Transmit(&huart2, (uint8_t *)buf, buf_len, 100);

	  while(1);
  }

  // <---- -------- Pull in only needed operations (should match with your NN layers).
  // Template parameter (<n>) is number of ops to be added.
  // Available ops: tensorflow/lite/micro/kernels/micro_ops.h -------- ---->
  static tflite::MicroMutableOpResolver<1> micro_op_resolver;

  // <---- -------- Add dense NN layer operation -------- ---->
  tflite_status = micro_op_resolver.AddFullyConnected();
  if(tflite_status != kTfLiteOk)
  {
	  error_reporter->Report("Couldn't add fully connected op.");

	  buf_len = sprintf(buf, "Couldn't add fully connected op.");
	  HAL_UART_Transmit(&huart2, (uint8_t *)buf, buf_len, 100);

	  while(1);
  }

  // <---- -------- build an interpreter to run the model -------- ---->
  static tflite::MicroInterpreter static_interpreter(model, micro_op_resolver, tensor_arena, KTensorArenaSize);
  interpreter = &static_interpreter;

  // <---- -------- Allocate memory from the tensor_arena for the model's tensors. -------- ---->
  tflite_status = interpreter->AllocateTensors();
  if(tflite_status != kTfLiteOk)
  {
	  error_reporter->Report("AllocateTensors failed.");

	  buf_len = sprintf(buf, "AllocateTensors failed.");
	  HAL_UART_Transmit(&huart2, (uint8_t *)buf, buf_len, 100);

	  while(1);
  }

  // <---- -------- Allocate model input/output buffers(tensors) to pointers -------- ---->
  model_input  = interpreter->input(0);
  model_output = interpreter->output(0);

  // <---- -------- Get number of elements in input tensor -------- ---->
  num_elements = model_input->bytes / sizeof(float);
  buf_len = sprintf(buf, "Number of input elements: %lu\r\n", num_elements);
  HAL_UART_Transmit(&huart2, (uint8_t *)buf, buf_len, 100);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
	  // <---- -------- Fill input buffer (use test value) -------- ---->
	  for(uint32_t i = 0; i < num_elements; i++)
	  {
		  model_input->data.f[i] = 2.0f;
	  }

	  // <---- -------- Get current timestamp -------- ---->
	  timestamp = htim11.Instance->CNT;

	  // <---- -------- Run inference -------- ---->
	  tflite_status = interpreter->Invoke();
	  if(tflite_status != kTfLiteOk)
	  {
		  error_reporter->Report("Invoke failed.");

		  buf_len = sprintf(buf, "Invoke failed.");
		  HAL_UART_Transmit(&huart2, (uint8_t *)buf, buf_len, 100);
	  }

	  // <---- -------- Read output (predict y) of neural network -------- ---->
	  y_val = model_output->data.f[0];

	  buf_len = sprintf(buf, "Output: %f | Duration: %lu\r\n", y_val, (htim11.Instance->CNT - timestamp));
	  HAL_UART_Transmit(&huart2, (uint8_t *)buf, buf_len, 100);
	  HAL_Delay(500);

	  HAL_GPIO_TogglePin(LED_OK_GPIO_Port, LED_OK_Pin);
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
  * @brief TIM11 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM11_Init(void)
{

  /* USER CODE BEGIN TIM11_Init 0 */

  /* USER CODE END TIM11_Init 0 */

  /* USER CODE BEGIN TIM11_Init 1 */

  /* USER CODE END TIM11_Init 1 */
  htim11.Instance = TIM11;
  htim11.Init.Prescaler = 80 - 1;
  htim11.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim11.Init.Period = 65536 - 1;
  htim11.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim11.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim11) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM11_Init 2 */

  /* USER CODE END TIM11_Init 2 */

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

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOD, LED_OK_Pin|LED_Error_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : LED_OK_Pin LED_Error_Pin */
  GPIO_InitStruct.Pin = LED_OK_Pin|LED_Error_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

  /* USER CODE BEGIN MX_GPIO_Init_2 */

  /* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

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
