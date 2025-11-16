################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../tflm/third_party/kissfft/tools/kiss_fftr.c 

C_DEPS += \
./tflm/third_party/kissfft/tools/kiss_fftr.d 

OBJS += \
./tflm/third_party/kissfft/tools/kiss_fftr.o 


# Each subdirectory must supply rules for building sources it contributes
tflm/third_party/kissfft/tools/%.o tflm/third_party/kissfft/tools/%.su tflm/third_party/kissfft/tools/%.cyclo: ../tflm/third_party/kissfft/tools/%.c tflm/third_party/kissfft/tools/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tflm" -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tflm/tensorflow/lite" -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tflm/third_party/flatbuffers/include" -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tflm/third_party/gemmlowp" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-tflm-2f-third_party-2f-kissfft-2f-tools

clean-tflm-2f-third_party-2f-kissfft-2f-tools:
	-$(RM) ./tflm/third_party/kissfft/tools/kiss_fftr.cyclo ./tflm/third_party/kissfft/tools/kiss_fftr.d ./tflm/third_party/kissfft/tools/kiss_fftr.o ./tflm/third_party/kissfft/tools/kiss_fftr.su

.PHONY: clean-tflm-2f-third_party-2f-kissfft-2f-tools

