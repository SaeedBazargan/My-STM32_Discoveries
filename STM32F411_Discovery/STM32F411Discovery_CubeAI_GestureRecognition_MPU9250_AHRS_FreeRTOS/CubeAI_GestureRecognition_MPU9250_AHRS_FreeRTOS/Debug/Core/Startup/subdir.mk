################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../Core/Startup/startup_stm32f411vetx.s 

OBJS += \
./Core/Startup/startup_stm32f411vetx.o 

S_DEPS += \
./Core/Startup/startup_stm32f411vetx.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Startup/%.o: ../Core/Startup/%.s Core/Startup/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m4 -g3 -DDEBUG -c -I"E:/sbzrgn/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_CubeAI_GestureRecognition_MPU9250_AHRS_FreeRTOS/CubeAI_GestureRecognition_MPU9250_AHRS_FreeRTOS/Lib" -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

clean: clean-Core-2f-Startup

clean-Core-2f-Startup:
	-$(RM) ./Core/Startup/startup_stm32f411vetx.d ./Core/Startup/startup_stm32f411vetx.o

.PHONY: clean-Core-2f-Startup

