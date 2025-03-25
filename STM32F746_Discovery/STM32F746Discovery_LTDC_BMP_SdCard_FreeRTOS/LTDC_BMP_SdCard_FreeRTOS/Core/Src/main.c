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
#include "dma.h"
#include "fatfs.h"
#include "ltdc.h"
#include "rng.h"
#include "sdmmc.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "MyTFT.h"
#include "SDCard_Configuration.h"
//#include "testImage.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
uint8_t  Debug = 0;
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
extern uint16_t imageBuffer[480 * 272];
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
void MX_FREERTOS_Init(void);
/* USER CODE BEGIN PFP */
void testLTDC(void);
void testSdCard(void);
void testImage_Show(void);
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
  MX_LTDC_Init();
  MX_SDMMC1_SD_Init();
  MX_FATFS_Init();
  MX_RNG_Init();
  /* USER CODE BEGIN 2 */
  HAL_LTDC_SetAddress(&hltdc, (uint32_t)&imageBuffer, 0);
  TFT_FillScreen((uint32_t)0x0000);
  /* USER CODE END 2 */

  /* Call init function for freertos objects (in cmsis_os2.c) */
  MX_FREERTOS_Init();

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
  RCC_OscInitStruct.PLL.PLLQ = 8;
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

/* USER CODE BEGIN 4 */
void testLTDC(void)
{
	for(uint16_t i = 0; i < 25; i++)
	{
		TFT_FillScreen((uint16_t)HAL_RNG_GetRandomNumber(&hrng));
		HAL_Delay(100);
	}

	TFT_FillScreen(0);
	HAL_Delay(1000);

	for(uint16_t i = 0; i < 250; i++)
	{
		TFT_FillRectangle(HAL_RNG_GetRandomNumber(&hrng) % 480,
			HAL_RNG_GetRandomNumber(&hrng) % 272,
			HAL_RNG_GetRandomNumber(&hrng) % 480,
			HAL_RNG_GetRandomNumber(&hrng) % 272,
			(uint16_t)HAL_RNG_GetRandomNumber(&hrng));
		HAL_Delay(10);
	}

	TFT_FillScreen(0);
	HAL_Delay(1000);

	for(uint16_t i = 0; i < 2500; i++)
	{
		for(uint16_t j = 0; j < 25; j++)
		{
			TFT_DrawPixel(HAL_RNG_GetRandomNumber(&hrng) % 480, HAL_RNG_GetRandomNumber(&hrng) % 272, 0);
		}

		TFT_DrawPixel(HAL_RNG_GetRandomNumber(&hrng) % 480, HAL_RNG_GetRandomNumber(&hrng) % 272, (uint16_t)HAL_RNG_GetRandomNumber(&hrng));
		HAL_Delay(1);
	}

	TFT_FillScreen(0);
	HAL_Delay(1000);

	for(uint16_t i = 0; i < 250; i++)
	{
		TFT_DrawLine(HAL_RNG_GetRandomNumber(&hrng) % 480,
			HAL_RNG_GetRandomNumber(&hrng) % 272,
			HAL_RNG_GetRandomNumber(&hrng) % 480,
			HAL_RNG_GetRandomNumber(&hrng) % 272,
			(uint16_t)HAL_RNG_GetRandomNumber(&hrng));
		HAL_Delay(10);
	}

	TFT_FillScreen(0);
	HAL_Delay(1000);
}
// <---- ----------------------------------------- ---->
void testSdCard(void)
{
	char sd_buffer[100];

	Mount_SD(SDPath);
//	Format_SD();
	Check_SD_Space();
	Create_File("MRL.txt");
	sprintf(sd_buffer, "Hello MRL-HSL \n");
	Update_File("MRL.txt", sd_buffer);
	Unmount_SD(SDPath);
}
// <---- ----------------------------------------- ---->
void testImage_Show(void)
{
//	TFT_DrawBitmap(0, 0, image_data_testImage);

	uint16_t* imgData = Read_Bitmap("testImage.bmp");
  if(imgData != NULL)
  {
      TFT_DrawBitmap(0, 0, imgData);
  }
}
/* USER CODE END 4 */

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
  if (htim->Instance == TIM14) {
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
