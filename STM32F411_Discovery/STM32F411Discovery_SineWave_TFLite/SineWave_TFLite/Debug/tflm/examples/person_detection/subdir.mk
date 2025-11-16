################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../tflm/examples/person_detection/detection_responder.cc \
../tflm/examples/person_detection/image_provider.cc \
../tflm/examples/person_detection/main.cc \
../tflm/examples/person_detection/main_functions.cc \
../tflm/examples/person_detection/model_settings.cc 

CC_DEPS += \
./tflm/examples/person_detection/detection_responder.d \
./tflm/examples/person_detection/image_provider.d \
./tflm/examples/person_detection/main.d \
./tflm/examples/person_detection/main_functions.d \
./tflm/examples/person_detection/model_settings.d 

OBJS += \
./tflm/examples/person_detection/detection_responder.o \
./tflm/examples/person_detection/image_provider.o \
./tflm/examples/person_detection/main.o \
./tflm/examples/person_detection/main_functions.o \
./tflm/examples/person_detection/model_settings.o 


# Each subdirectory must supply rules for building sources it contributes
tflm/examples/person_detection/%.o tflm/examples/person_detection/%.su tflm/examples/person_detection/%.cyclo: ../tflm/examples/person_detection/%.cc tflm/examples/person_detection/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tensorflow_lite" -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tensorflow_lite/third_party/flatbuffers/include" -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tensorflow_lite/third_party/gemmlowp" -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tensorflow_lite/third_party/ruy" -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tensorflow_lite/third_party/kissfft" -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tensorflow_lite/tensorflow/lite" -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tflm" -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tflm/tensorflow/lite" -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tflm/third_party/flatbuffers/include" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-tflm-2f-examples-2f-person_detection

clean-tflm-2f-examples-2f-person_detection:
	-$(RM) ./tflm/examples/person_detection/detection_responder.cyclo ./tflm/examples/person_detection/detection_responder.d ./tflm/examples/person_detection/detection_responder.o ./tflm/examples/person_detection/detection_responder.su ./tflm/examples/person_detection/image_provider.cyclo ./tflm/examples/person_detection/image_provider.d ./tflm/examples/person_detection/image_provider.o ./tflm/examples/person_detection/image_provider.su ./tflm/examples/person_detection/main.cyclo ./tflm/examples/person_detection/main.d ./tflm/examples/person_detection/main.o ./tflm/examples/person_detection/main.su ./tflm/examples/person_detection/main_functions.cyclo ./tflm/examples/person_detection/main_functions.d ./tflm/examples/person_detection/main_functions.o ./tflm/examples/person_detection/main_functions.su ./tflm/examples/person_detection/model_settings.cyclo ./tflm/examples/person_detection/model_settings.d ./tflm/examples/person_detection/model_settings.o ./tflm/examples/person_detection/model_settings.su

.PHONY: clean-tflm-2f-examples-2f-person_detection

