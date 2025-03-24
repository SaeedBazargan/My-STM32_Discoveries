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
#include "ltdc.h"
#include "rng.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "string.h"
#include "stdlib.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define swap(a, b) {int16_t t = a; a = b; b = t;}
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
volatile uint32_t RGB565_480x272[65280] = {0x00000000};
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */
void TFT_FillScreen(uint32_t color);
void TFT_FillRectangle(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t color);
void TFT_DrawPixel(uint16_t Xpos, uint16_t Ypos, uint32_t color);
void TFT_DrawLine(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t color);
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

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
  MX_LTDC_Init();
  MX_RNG_Init();
  /* USER CODE BEGIN 2 */
  HAL_LTDC_SetAddress(&hltdc, (uint32_t) &RGB565_480x272, 0);
  TFT_FillScreen((uint32_t)0x0000);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
		for(uint16_t i = 0; i < 100; i++)
		{
			TFT_FillScreen((uint16_t)HAL_RNG_GetRandomNumber(&hrng));
			HAL_Delay(100);
		}

		TFT_FillScreen(0);
		HAL_Delay(1000);

		for(uint16_t i = 0; i < 1000; i++)
		{
			TFT_FillRectangle(HAL_RNG_GetRandomNumber(&hrng)%480,
				HAL_RNG_GetRandomNumber(&hrng)%272,
				HAL_RNG_GetRandomNumber(&hrng)%480,
				HAL_RNG_GetRandomNumber(&hrng)%272,
				(uint16_t)HAL_RNG_GetRandomNumber(&hrng));
			HAL_Delay(10);
		}

		TFT_FillScreen(0);
		HAL_Delay(1000);

		for(uint16_t i = 0; i < 10000; i++)
		{
			for(uint16_t j = 0; j < 100; j++)
			{
				TFT_DrawPixel(HAL_RNG_GetRandomNumber(&hrng)%480, HAL_RNG_GetRandomNumber(&hrng)%272, 0);
			}

			TFT_DrawPixel(HAL_RNG_GetRandomNumber(&hrng)%480, HAL_RNG_GetRandomNumber(&hrng)%272, (uint16_t)HAL_RNG_GetRandomNumber(&hrng));
			HAL_Delay(1);
		}

		TFT_FillScreen(0);
		HAL_Delay(1000);

		for(uint16_t i = 0; i < 1000; i++)
		{
			TFT_DrawLine(HAL_RNG_GetRandomNumber(&hrng)%480,
				HAL_RNG_GetRandomNumber(&hrng)%272,
				HAL_RNG_GetRandomNumber(&hrng)%480,
				HAL_RNG_GetRandomNumber(&hrng)%272,
				(uint16_t)HAL_RNG_GetRandomNumber(&hrng));
			HAL_Delay(10);
		}

		TFT_FillScreen(0);
		HAL_Delay(1000);
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
  RCC_OscInitStruct.PLL.PLLM = 25;
  RCC_OscInitStruct.PLL.PLLN = 432;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Activate the Over-Drive mode
  */
  if (HAL_PWREx_EnableOverDrive() != HAL_OK)
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

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_7) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */
void TFT_FillScreen(uint32_t color)
{
	uint32_t i;
	uint32_t n = hltdc.LayerCfg[0].ImageHeight * hltdc.LayerCfg[0].ImageWidth;

	for(i = 0; i < n; i++)
	{
		*(__IO uint16_t*)(hltdc.LayerCfg[0].FBStartAdress + (i*2)) = (uint16_t)color;
	}
}
// <---- ------------------------------------- ---->
void TFT_FillRectangle(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t color)
{
	uint32_t xpos,ypos;

	if(x1 > x2)
	{
		swap(x1, x2);
	}
	if(y1 > y2)
	{
		swap(y1, y2);
	}
	for(ypos = y1; ypos <= y2; ypos++)
	{
		for(xpos = x1; xpos <= x2; xpos++)
		{
			*(__IO uint16_t*)(hltdc.LayerCfg[0].FBStartAdress + (2 * (ypos * hltdc.LayerCfg[0].ImageWidth + xpos))) = (uint16_t)color;
		}
	}
}
// <---- ------------------------------------- ---->
void TFT_DrawPixel(uint16_t Xpos, uint16_t Ypos, uint32_t color)
{
	*(__IO uint16_t*)(hltdc.LayerCfg[0].FBStartAdress + (2 * (Ypos * hltdc.LayerCfg[0].ImageWidth + Xpos))) = (uint16_t)color;
}
// <---- ------------------------------------- ---->
void TFT_DrawLine(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t color)
{
	int steep = abs(y2 - y1) > abs(x2 - x1);

	if(steep)
	{
		swap(x1, y1);
		swap(x2, y2);
	}
	if(x1 > x2)
	{
		swap(x1, x2);
		swap(y1, y2);
	}
	int dx, dy;
	dx = x2 - x1;
	dy = abs(y2 - y1);

	int err = dx / 2;
	int ystep;

	if(y1 < y2)
	{
		ystep = 1;
	}
	else
	{
		ystep = -1;
	}
	for(; x1 <= x2; x1++)
	{
		if(steep)
		{
			TFT_DrawPixel(y1, x1, color);
		}
		else
		{
			TFT_DrawPixel(x1, y1, color);
		}
		err -= dy;

		if(err < 0)
		{
			y1 += ystep;
			err = dx;
		}
	}
}
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
