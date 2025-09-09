################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Lib/HAL_MPU9250.c \
../Lib/IMU_ComplementaryFilter.c \
../Lib/IMU_KalmanFilter.c 

OBJS += \
./Lib/HAL_MPU9250.o \
./Lib/IMU_ComplementaryFilter.o \
./Lib/IMU_KalmanFilter.o 

C_DEPS += \
./Lib/HAL_MPU9250.d \
./Lib/IMU_ComplementaryFilter.d \
./Lib/IMU_KalmanFilter.d 


# Each subdirectory must supply rules for building sources it contributes
Lib/%.o Lib/%.su Lib/%.cyclo: ../Lib/%.c Lib/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_MPU9250_Kalman_ComplementaryFilter_FreeRTOS/MPU9250_Kalman_ComplementaryFilter_FreeRTOS/Lib" -include"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_MPU9250_Kalman_ComplementaryFilter_FreeRTOS/MPU9250_Kalman_ComplementaryFilter_FreeRTOS/Lib/HAL_MPU9250.h" -include"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_MPU9250_Kalman_ComplementaryFilter_FreeRTOS/MPU9250_Kalman_ComplementaryFilter_FreeRTOS/Lib/IMU_KalmanFilter.h" -O2 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Lib

clean-Lib:
	-$(RM) ./Lib/HAL_MPU9250.cyclo ./Lib/HAL_MPU9250.d ./Lib/HAL_MPU9250.o ./Lib/HAL_MPU9250.su ./Lib/IMU_ComplementaryFilter.cyclo ./Lib/IMU_ComplementaryFilter.d ./Lib/IMU_ComplementaryFilter.o ./Lib/IMU_ComplementaryFilter.su ./Lib/IMU_KalmanFilter.cyclo ./Lib/IMU_KalmanFilter.d ./Lib/IMU_KalmanFilter.o ./Lib/IMU_KalmanFilter.su

.PHONY: clean-Lib

