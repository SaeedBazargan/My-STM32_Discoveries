#include "HAL_MPU9250.h"

#if FreeRTOS_En
#include "cmsis_os.h"
#endif

// <---- ------------ Variables ------------ ---->
uint16_t _CS_PinNumber = 0x0000;
GPIO_TypeDef *_CS_GPIO;

// <---- ------------ Main MPu9250 Functions ------------ ---->
// <---- ------------ MPU9250 Initialize ------------ ---->
MPU9250_Result MPU9250_Init(SPI_HandleTypeDef* SPIx, GPIO_TypeDef *CS_GPIOx, uint16_t CS_PinNumber, MPU9250TypeDef* datastruct)
{
	_CS_GPIO = CS_GPIOx;
	_CS_PinNumber = CS_PinNumber;

	uint8_t WHO_AM_I = MPU9250_WHO_AM_I;
	uint8_t temp;
	uint8_t transmit_buffer[2]={0};

	// <---- ------------ Initialize Registers ------------ ---->
	uint8_t CLOCK_SEL_PLL = 0x01;
	transmit_buffer[0] = MPU9250_PWR_MGMT_1;
	transmit_buffer[1] = CLOCK_SEL_PLL;
	MPU9250_WriteData(SPIx, transmit_buffer[0], transmit_buffer[1]);
#if FreeRTOS_En
	osDelay(25);
#else
	HAL_Delay(25);
#endif

	uint8_t I2C_MST_EN = 0x20;
	transmit_buffer[0] = MPU9250_USER_CTRL;
	transmit_buffer[1] = I2C_MST_EN;
	MPU9250_WriteData(SPIx, transmit_buffer[0], transmit_buffer[1]);
#if FreeRTOS_En
	osDelay(25);
#else
	HAL_Delay(25);
#endif

	uint8_t I2C_MST_CLK = 0x0D;
	transmit_buffer[0] = I2C_MST_CTRL;
	transmit_buffer[1] = I2C_MST_CLK;
	MPU9250_WriteData(SPIx, transmit_buffer[0], transmit_buffer[1]);
#if FreeRTOS_En
	osDelay(25);
#else
	HAL_Delay(25);
#endif

	uint8_t PWR_RESET = 0x80;
	transmit_buffer[0] = MPU9250_PWR_MGMT_1;
	transmit_buffer[1] = PWR_RESET;
	MPU9250_WriteData(SPIx, transmit_buffer[0], transmit_buffer[1]);
#if FreeRTOS_En
	osDelay(25);
#else
	HAL_Delay(25);
#endif

	// <---- ------------ Configure PowerManagement 1 ------------ ---->
	transmit_buffer[0] = MPU9250_PWR_MGMT_1;
	transmit_buffer[1] = datastruct->PWR_MGMT1;
	MPU9250_WriteData(SPIx, transmit_buffer[0], transmit_buffer[1]);
#if FreeRTOS_En
	osDelay(25);
#else
	HAL_Delay(25);
#endif
	MPU9250_ReadData(SPIx, &temp, MPU9250_PWR_MGMT_1, 1);
	if(temp != datastruct->PWR_MGMT1)
	{
#if Debug
		printf("Error: PWR_MGMT1");
#endif
		return MPU9250_RESULT_ERROR;
	}

	// <---- ------------ Check WHO_AM_I Register ------------ ---->
	MPU9250_ReadData(SPIx, &temp, WHO_AM_I, 1);
	if(temp != MPU9250_I_AM)
	{
#if Debug
		printf("Error: MPU9250_I_AM");
#endif
 		return MPU9250_RESULT_ERROR;
	}
#if FreeRTOS_En
	osDelay(25);
#else
	HAL_Delay(25);
#endif

	// <---- ------------ Configure PowerManagement 2 ------------ ---->
	transmit_buffer[0] = MPU9250_PWR_MGMT_2;
	transmit_buffer[1] = datastruct->PWR_MGMT2;
	MPU9250_WriteData(SPIx, transmit_buffer[0], transmit_buffer[1]);
#if FreeRTOS_En
	osDelay(25);
#else
	HAL_Delay(25);
#endif
	MPU9250_ReadData(SPIx, &temp, MPU9250_PWR_MGMT_2, 1);
	if(temp != datastruct->PWR_MGMT2)
	{
#if Debug
		printf("Error: PWR_MGMT2");
#endif
		return MPU9250_RESULT_ERROR;
	}

	// <---- ------------ Configure Config Register ------------ ---->
	transmit_buffer[0] = MPU9250_CONFIG;
	transmit_buffer[1] = datastruct->Gyro_DLPF;
	MPU9250_WriteData(SPIx, transmit_buffer[0], transmit_buffer[1]);
#if FreeRTOS_En
	osDelay(25);
#else
	HAL_Delay(25);
#endif
	MPU9250_ReadData(SPIx, &temp, MPU9250_CONFIG, 1);
	if(temp != datastruct->Gyro_DLPF)
	{
#if Debug
		printf("Error: Gyro_DLPF");
#endif
		return MPU9250_RESULT_ERROR;
	}

	// <---- ------------ Configure Gyro_Config Register ------------ ---->
	transmit_buffer[0] = MPU9250_GYRO_CONFIG;
	transmit_buffer[1] = (datastruct->Gyro_Range) << 3;
	MPU9250_WriteData(SPIx, transmit_buffer[0], transmit_buffer[1]);
#if FreeRTOS_En
	osDelay(25);
#else
	HAL_Delay(25);
#endif
	MPU9250_ReadData(SPIx, &temp, MPU9250_GYRO_CONFIG, 1);
	if(temp != ((datastruct->Gyro_Range) << 3))
	{
#if Debug
		printf("Error: Gyro_Range");
#endif
		return MPU9250_RESULT_ERROR;
	}

	// <---- ------------ Configure Accel Config Register 2 ------------ ---->
	transmit_buffer[0] = MPU9250_ACCEL_CONFIG_2;
	transmit_buffer[1] = datastruct->Accel_DLPF;
	MPU9250_WriteData(SPIx, transmit_buffer[0], transmit_buffer[1]);
#if FreeRTOS_En
	osDelay(25);
#else
	HAL_Delay(25);
#endif
	MPU9250_ReadData(SPIx, &temp, MPU9250_ACCEL_CONFIG_2, 1);
	if(temp != datastruct->Accel_DLPF)
	{
#if Debug
		printf("Error: Accel_DLPF");
#endif
		return MPU9250_RESULT_ERROR;
	}

	// <---- ------------ Configure Accel Config Register ------------ ---->
	transmit_buffer[0] = MPU9250_ACCEL_CONFIG;
	transmit_buffer[1] = (datastruct->Accel_Range) << 3;
	MPU9250_WriteData(SPIx, transmit_buffer[0], transmit_buffer[1]);
#if FreeRTOS_En
	osDelay(25);
#else
	HAL_Delay(25);
#endif
	MPU9250_ReadData(SPIx, &temp, MPU9250_ACCEL_CONFIG, 1);
	if(temp != ((datastruct->Accel_Range) << 3))
	{
#if Debug
		printf("Error: Accel_Range");
#endif
		return MPU9250_RESULT_ERROR;
	}

	/* Return OK */
	return MPU9250_RESULT_OK;
}

// <---- ------------ MPU9250 Read Data ------------ ---->
MPU9250_Result MPU9250_ReadData(SPI_HandleTypeDef* SPIx, uint8_t* buffer, uint8_t addr, uint8_t num)
{
	uint8_t reg = addr | 0x80;
	
	HAL_GPIO_WritePin(_CS_GPIO, _CS_PinNumber, GPIO_PIN_RESET);
	HAL_Delay(20);
	HAL_SPI_Transmit(SPIx, &reg, 1, 1000);
	HAL_SPI_Receive(SPIx, buffer, num, 1000);
	HAL_GPIO_WritePin(_CS_GPIO, _CS_PinNumber, GPIO_PIN_SET);

	/* Return OK */
	return MPU9250_RESULT_OK;
}

// <---- ------------ MPU9250 Write Data ------------ ---->
MPU9250_Result MPU9250_WriteData(SPI_HandleTypeDef* SPIx, uint8_t addr, uint8_t data)
{
	uint8_t buffer[2] = {addr, data};
	
	HAL_GPIO_WritePin(_CS_GPIO, _CS_PinNumber, GPIO_PIN_RESET);
	HAL_Delay(20);
	HAL_SPI_Transmit(SPIx, buffer, 2, 1000);
	HAL_GPIO_WritePin(_CS_GPIO, _CS_PinNumber, GPIO_PIN_SET);

	/* Return OK */
	return MPU9250_RESULT_OK;
}

