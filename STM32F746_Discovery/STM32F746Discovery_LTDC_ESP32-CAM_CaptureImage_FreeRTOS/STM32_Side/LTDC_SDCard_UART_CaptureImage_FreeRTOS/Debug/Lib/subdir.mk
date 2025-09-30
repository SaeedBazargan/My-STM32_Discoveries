################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Lib/SDCard_Configuration.c 

OBJS += \
./Lib/SDCard_Configuration.o 

C_DEPS += \
./Lib/SDCard_Configuration.d 


# Each subdirectory must supply rules for building sources it contributes
Lib/%.o Lib/%.su Lib/%.cyclo: ../Lib/%.c Lib/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F746xx -c -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F746_Discovery/STM32F746Discovery_LTDC_ESP32-CAM_CaptureImage_FreeRTOS/STM32_Side/LTDC_SDCard_UART_CaptureImage_FreeRTOS/Lib" -O1 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Lib

clean-Lib:
	-$(RM) ./Lib/SDCard_Configuration.cyclo ./Lib/SDCard_Configuration.d ./Lib/SDCard_Configuration.o ./Lib/SDCard_Configuration.su

.PHONY: clean-Lib

