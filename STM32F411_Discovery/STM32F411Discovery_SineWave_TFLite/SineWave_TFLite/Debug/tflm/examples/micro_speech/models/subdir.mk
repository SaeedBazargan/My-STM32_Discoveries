################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../tflm/examples/micro_speech/models/audio_preprocessor_int8_model_data.cc \
../tflm/examples/micro_speech/models/micro_speech_quantized_model_data.cc 

CC_DEPS += \
./tflm/examples/micro_speech/models/audio_preprocessor_int8_model_data.d \
./tflm/examples/micro_speech/models/micro_speech_quantized_model_data.d 

OBJS += \
./tflm/examples/micro_speech/models/audio_preprocessor_int8_model_data.o \
./tflm/examples/micro_speech/models/micro_speech_quantized_model_data.o 


# Each subdirectory must supply rules for building sources it contributes
tflm/examples/micro_speech/models/%.o tflm/examples/micro_speech/models/%.su tflm/examples/micro_speech/models/%.cyclo: ../tflm/examples/micro_speech/models/%.cc tflm/examples/micro_speech/models/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tensorflow_lite" -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tensorflow_lite/third_party/flatbuffers/include" -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tensorflow_lite/third_party/gemmlowp" -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tensorflow_lite/third_party/ruy" -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tensorflow_lite/third_party/kissfft" -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tensorflow_lite/tensorflow/lite" -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tflm" -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tflm/tensorflow/lite" -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tflm/third_party/flatbuffers/include" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-tflm-2f-examples-2f-micro_speech-2f-models

clean-tflm-2f-examples-2f-micro_speech-2f-models:
	-$(RM) ./tflm/examples/micro_speech/models/audio_preprocessor_int8_model_data.cyclo ./tflm/examples/micro_speech/models/audio_preprocessor_int8_model_data.d ./tflm/examples/micro_speech/models/audio_preprocessor_int8_model_data.o ./tflm/examples/micro_speech/models/audio_preprocessor_int8_model_data.su ./tflm/examples/micro_speech/models/micro_speech_quantized_model_data.cyclo ./tflm/examples/micro_speech/models/micro_speech_quantized_model_data.d ./tflm/examples/micro_speech/models/micro_speech_quantized_model_data.o ./tflm/examples/micro_speech/models/micro_speech_quantized_model_data.su

.PHONY: clean-tflm-2f-examples-2f-micro_speech-2f-models

