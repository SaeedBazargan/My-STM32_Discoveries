################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../tflm/third_party/cmsis_nn/Source/LSTMFunctions/arm_lstm_unidirectional_s16.c \
../tflm/third_party/cmsis_nn/Source/LSTMFunctions/arm_lstm_unidirectional_s8.c 

C_DEPS += \
./tflm/third_party/cmsis_nn/Source/LSTMFunctions/arm_lstm_unidirectional_s16.d \
./tflm/third_party/cmsis_nn/Source/LSTMFunctions/arm_lstm_unidirectional_s8.d 

OBJS += \
./tflm/third_party/cmsis_nn/Source/LSTMFunctions/arm_lstm_unidirectional_s16.o \
./tflm/third_party/cmsis_nn/Source/LSTMFunctions/arm_lstm_unidirectional_s8.o 


# Each subdirectory must supply rules for building sources it contributes
tflm/third_party/cmsis_nn/Source/LSTMFunctions/%.o tflm/third_party/cmsis_nn/Source/LSTMFunctions/%.su tflm/third_party/cmsis_nn/Source/LSTMFunctions/%.cyclo: ../tflm/third_party/cmsis_nn/Source/LSTMFunctions/%.c tflm/third_party/cmsis_nn/Source/LSTMFunctions/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tflm" -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tflm/tensorflow/lite" -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tflm/third_party/flatbuffers/include" -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tflm/third_party/gemmlowp" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-tflm-2f-third_party-2f-cmsis_nn-2f-Source-2f-LSTMFunctions

clean-tflm-2f-third_party-2f-cmsis_nn-2f-Source-2f-LSTMFunctions:
	-$(RM) ./tflm/third_party/cmsis_nn/Source/LSTMFunctions/arm_lstm_unidirectional_s16.cyclo ./tflm/third_party/cmsis_nn/Source/LSTMFunctions/arm_lstm_unidirectional_s16.d ./tflm/third_party/cmsis_nn/Source/LSTMFunctions/arm_lstm_unidirectional_s16.o ./tflm/third_party/cmsis_nn/Source/LSTMFunctions/arm_lstm_unidirectional_s16.su ./tflm/third_party/cmsis_nn/Source/LSTMFunctions/arm_lstm_unidirectional_s8.cyclo ./tflm/third_party/cmsis_nn/Source/LSTMFunctions/arm_lstm_unidirectional_s8.d ./tflm/third_party/cmsis_nn/Source/LSTMFunctions/arm_lstm_unidirectional_s8.o ./tflm/third_party/cmsis_nn/Source/LSTMFunctions/arm_lstm_unidirectional_s8.su

.PHONY: clean-tflm-2f-third_party-2f-cmsis_nn-2f-Source-2f-LSTMFunctions

