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
#include "fatfs.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "stdio.h"
#include "SDCard_Configuration.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define ImageBufferSize							30000
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

SD_HandleTypeDef hsd1;
DMA_HandleTypeDef hdma_sdmmc1_rx;
DMA_HandleTypeDef hdma_sdmmc1_tx;

UART_HandleTypeDef huart6;

osThreadId defaultTaskHandle;
osThreadId recDataTaskHandle;
osThreadId analysisDataTasHandle;
osThreadId saveSdCardTaskHandle;

osSemaphoreId recDataBinarySemaphoreHandle;
osSemaphoreId saveSdCardBinarySemaphoreHandle;
/* USER CODE BEGIN PV */
uint8_t RecData = 0;
uint8_t recBuffer[ImageBufferSize];
uint32_t recCount = 0;
uint32_t imageLen = 0;

uint8_t imageBuffer[ImageBufferSize];

char filename[32];
char sd_buffer[100];
#define ImageBuffer_Record		0x01
#define ReceiveBuffer_Record	0x01
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_DMA_Init(void);
static void MX_USART6_UART_Init(void);
static void MX_SDMMC1_SD_Init(void);
void StartDefaultTask(void const * argument);
void StartReceiveDataTask(void const * argument);
void StartAnalysisDataTask(void const * argument);
void StartSaveToSdCardTask(void const * argument);

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
  MX_DMA_Init();
  MX_USART6_UART_Init();
  MX_SDMMC1_SD_Init();
  MX_FATFS_Init();
  /* USER CODE BEGIN 2 */
  HAL_UART_Receive_IT(&huart6, &RecData, 1);
  /* USER CODE END 2 */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* Create the semaphores(s) */
  /* definition and creation of recDataBinarySemaphore */
  osSemaphoreDef(recDataBinarySemaphore);
  recDataBinarySemaphoreHandle = osSemaphoreCreate(osSemaphore(recDataBinarySemaphore), 1);

  /* definition and creation of saveSdCardBinarySemaphore */
  osSemaphoreDef(saveSdCardBinarySemaphore);
  saveSdCardBinarySemaphoreHandle = osSemaphoreCreate(osSemaphore(saveSdCardBinarySemaphore), 1);

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  if(saveSdCardBinarySemaphoreHandle != NULL)
  {
      // <---- ----- Non-blocking wait to take the token. This makes current count 0 ----- ---->
      osSemaphoreWait(saveSdCardBinarySemaphoreHandle, 0);
  }
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* definition and creation of defaultTask */
  osThreadDef(defaultTask, StartDefaultTask, osPriorityNormal, 0, 256);
  defaultTaskHandle = osThreadCreate(osThread(defaultTask), NULL);

  /* definition and creation of recDataTask */
  osThreadDef(recDataTask, StartReceiveDataTask, osPriorityAboveNormal, 0, 1024);
  recDataTaskHandle = osThreadCreate(osThread(recDataTask), NULL);

  /* definition and creation of analysisDataTas */
  osThreadDef(analysisDataTas, StartAnalysisDataTask, osPriorityNormal, 0, 1024);
  analysisDataTasHandle = osThreadCreate(osThread(analysisDataTas), NULL);

  /* definition and creation of saveSdCardTask */
  osThreadDef(saveSdCardTask, StartSaveToSdCardTask, osPriorityNormal, 0, 1024);
  saveSdCardTaskHandle = osThreadCreate(osThread(saveSdCardTask), NULL);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
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
  RCC_OscInitStruct.PLL.PLLM = 15;
  RCC_OscInitStruct.PLL.PLLN = 216;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 15;
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
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief SDMMC1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_SDMMC1_SD_Init(void)
{

  /* USER CODE BEGIN SDMMC1_Init 0 */

  /* USER CODE END SDMMC1_Init 0 */

  /* USER CODE BEGIN SDMMC1_Init 1 */

  /* USER CODE END SDMMC1_Init 1 */
  hsd1.Instance = SDMMC1;
  hsd1.Init.ClockEdge = SDMMC_CLOCK_EDGE_RISING;
  hsd1.Init.ClockBypass = SDMMC_CLOCK_BYPASS_DISABLE;
  hsd1.Init.ClockPowerSave = SDMMC_CLOCK_POWER_SAVE_DISABLE;
  hsd1.Init.BusWide = SDMMC_BUS_WIDE_1B;
  hsd1.Init.HardwareFlowControl = SDMMC_HARDWARE_FLOW_CONTROL_DISABLE;
  hsd1.Init.ClockDiv = 0;
  /* USER CODE BEGIN SDMMC1_Init 2 */

  /* USER CODE END SDMMC1_Init 2 */

}

/**
  * @brief USART6 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART6_UART_Init(void)
{

  /* USER CODE BEGIN USART6_Init 0 */

  /* USER CODE END USART6_Init 0 */

  /* USER CODE BEGIN USART6_Init 1 */

  /* USER CODE END USART6_Init 1 */
  huart6.Instance = USART6;
  huart6.Init.BaudRate = 115200;
  huart6.Init.WordLength = UART_WORDLENGTH_8B;
  huart6.Init.StopBits = UART_STOPBITS_1;
  huart6.Init.Parity = UART_PARITY_NONE;
  huart6.Init.Mode = UART_MODE_TX_RX;
  huart6.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart6.Init.OverSampling = UART_OVERSAMPLING_16;
  huart6.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart6.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  if (HAL_UART_Init(&huart6) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART6_Init 2 */

  /* USER CODE END USART6_Init 2 */

}

/**
  * Enable DMA controller clock
  */
static void MX_DMA_Init(void)
{

  /* DMA controller clock enable */
  __HAL_RCC_DMA2_CLK_ENABLE();

  /* DMA interrupt init */
  /* DMA2_Stream3_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA2_Stream3_IRQn, 5, 0);
  HAL_NVIC_EnableIRQ(DMA2_Stream3_IRQn);
  /* DMA2_Stream6_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA2_Stream6_IRQn, 5, 0);
  HAL_NVIC_EnableIRQ(DMA2_Stream6_IRQn);

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
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : SDMMC1_Detect_Pin */
  GPIO_InitStruct.Pin = SDMMC1_Detect_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(SDMMC1_Detect_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : LED_Pin */
  GPIO_InitStruct.Pin = LED_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(LED_GPIO_Port, &GPIO_InitStruct);

  /* USER CODE BEGIN MX_GPIO_Init_2 */

  /* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	if(huart->Instance == USART6)
	{
		HAL_UART_Receive_IT(&huart6, &RecData, 1);

        BaseType_t xHigherPriorityTaskWoken = pdFALSE;
        xSemaphoreGiveFromISR(recDataBinarySemaphoreHandle, &xHigherPriorityTaskWoken);
        portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
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
	  HAL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin);
	  osDelay(1000);
  }
  /* USER CODE END 5 */
}

/* USER CODE BEGIN Header_StartReceiveDataTask */
/**
* @brief Function implementing the recDataTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartReceiveDataTask */
void StartReceiveDataTask(void const * argument)
{
  /* USER CODE BEGIN StartReceiveDataTask */
  /* Infinite loop */
	for(;;)
	{
		if(xSemaphoreTake(recDataBinarySemaphoreHandle, portMAX_DELAY) == pdTRUE)
		{
			recBuffer[recCount++] = RecData;
			if(recCount == 9)
			{
				if(recBuffer[1] == 'I' && recBuffer[2] == 'M' && recBuffer[3] == 'G' && recBuffer[4] == '0')
				{
					printf("<---- ----- Marker was OK ----- ---->\r\n");
					imageLen = (uint32_t)recBuffer[5] | ((uint32_t)recBuffer[6] << 8) | ((uint32_t)recBuffer[7] << 16) | ((uint32_t)recBuffer[8] << 24);
					printf("<---- ----- Image Length is: %lu ----- ---->\r\n", (unsigned long)imageLen);
				}
			}
		}
	}
  /* USER CODE END StartReceiveDataTask */
}

/* USER CODE BEGIN Header_StartAnalysisDataTask */
/**
* @brief Function implementing the analysisDataTas thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartAnalysisDataTask */
void StartAnalysisDataTask(void const * argument)
{
  /* USER CODE BEGIN StartAnalysisDataTask */
  /* Infinite loop */
  for(;;)
  {
	  if(recCount == imageLen)
	  {
		  for(uint32_t i = 0; i < imageLen; i++)
		  {
			  imageBuffer[i] = recBuffer[i + 9];
		  }
		  printf("<---- ----- Image was copied to buffer ----- ---->\r\n");

		  recCount = 1;
		  xSemaphoreGive(saveSdCardBinarySemaphoreHandle);
	  }

	  osDelay(1);
  }
  /* USER CODE END StartAnalysisDataTask */
}

/* USER CODE BEGIN Header_StartSaveToSdCardTask */
/**
* @brief Function implementing the saveSdCardTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartSaveToSdCardTask */
void StartSaveToSdCardTask(void const * argument)
{
  /* USER CODE BEGIN StartSaveToSdCardTask */
	uint16_t SD_Chunk_Size = 512;
  /* Infinite loop */
  for(;;)
  {
	  if(xSemaphoreTake(saveSdCardBinarySemaphoreHandle, portMAX_DELAY) == pdTRUE)
	  {
#if ImageBuffer_Record
		  Mount_SD(SDPath);
		  Format_SD();
		  Check_SD_Space();
		  Create_File("MRL1.txt");

		  // Write a header
		  sprintf(sd_buffer, "Hello to MRL-HSL from Sbzrgn \n");
		  Update_File("MRL1.txt", sd_buffer);

		  // Write imageBuffer in HEX in chunks
		  for(uint32_t i = 0; i < imageLen; i += SD_Chunk_Size)
		  {
			  uint32_t chunkEnd = i + SD_Chunk_Size;
			  if(chunkEnd > imageLen)
			  {
				  chunkEnd = imageLen;
			  }

			  uint32_t bufIndex = 0;
			  for(uint32_t j = i; j < chunkEnd; j++)
			  {
				  // convert byte to HEX string
				  bufIndex += sprintf(&sd_buffer[bufIndex], "%02X", imageBuffer[j]);
			  }

			  // Append chunk to SD file
			  Update_File("MRL1.txt", sd_buffer);
		  }

		  Unmount_SD(SDPath);
		  printf("sssssssssssssssssssssssssss\r\n");

#endif
#if ReceiveBuffer_Record
		  Mount_SD(SDPath);
//		  Format_SD();
		  Check_SD_Space();
		  Create_File("MRL2.txt");

		  // Write a header
		  sprintf(sd_buffer, "Hello to MRL-HSL from Sbzrgn \n");
		  Update_File("MRL2.txt", sd_buffer);

		  // Write imageBuffer in HEX in chunks
		  for(uint32_t i = 0; i < imageLen; i += SD_Chunk_Size)
		  {
			  uint32_t chunkEnd = i + SD_Chunk_Size;
			  if(chunkEnd > imageLen)
			  {
				  chunkEnd = imageLen;
			  }

			  uint32_t bufIndex = 0;
			  for(uint32_t j = i; j < chunkEnd; j++)
			  {
				  // convert byte to HEX string
				  bufIndex += sprintf(&sd_buffer[bufIndex], "%02X", recBuffer[j]);
			  }

			  // Append chunk to SD file
			  Update_File("MRL2.txt", sd_buffer);
		  }

		  Unmount_SD(SDPath);
		  printf("sssssssssssssssssssssssssss\r\n");
#endif
	  }
  }
  /* USER CODE END StartSaveToSdCardTask */
}

/**
  * @brief  Period elapsed callback in non blocking mode
  * @note   This function is called  when TIM14 interrupt took place, inside
  * HAL_TIM_IRQHandler(). It makes a direct call to HAL_IncTick() to increment
  * a global variable "uwTick" used as application time base.
  * @param  htim : TIM handle
  * @retval None
  */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  /* USER CODE BEGIN Callback 0 */

  /* USER CODE END Callback 0 */
  if (htim->Instance == TIM14)
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
