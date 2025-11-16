################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../tflm/signal/src/kiss_fft_wrappers/kiss_fft_float.cc \
../tflm/signal/src/kiss_fft_wrappers/kiss_fft_int16.cc \
../tflm/signal/src/kiss_fft_wrappers/kiss_fft_int32.cc 

CC_DEPS += \
./tflm/signal/src/kiss_fft_wrappers/kiss_fft_float.d \
./tflm/signal/src/kiss_fft_wrappers/kiss_fft_int16.d \
./tflm/signal/src/kiss_fft_wrappers/kiss_fft_int32.d 

OBJS += \
./tflm/signal/src/kiss_fft_wrappers/kiss_fft_float.o \
./tflm/signal/src/kiss_fft_wrappers/kiss_fft_int16.o \
./tflm/signal/src/kiss_fft_wrappers/kiss_fft_int32.o 


# Each subdirectory must supply rules for building sources it contributes
tflm/signal/src/kiss_fft_wrappers/%.o tflm/signal/src/kiss_fft_wrappers/%.su tflm/signal/src/kiss_fft_wrappers/%.cyclo: ../tflm/signal/src/kiss_fft_wrappers/%.cc tflm/signal/src/kiss_fft_wrappers/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tensorflow_lite" -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tensorflow_lite/third_party/flatbuffers/include" -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tensorflow_lite/third_party/gemmlowp" -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tensorflow_lite/third_party/ruy" -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tensorflow_lite/third_party/kissfft" -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tensorflow_lite/tensorflow/lite" -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tflm" -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tflm/tensorflow/lite" -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tflm/third_party/flatbuffers/include" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-tflm-2f-signal-2f-src-2f-kiss_fft_wrappers

clean-tflm-2f-signal-2f-src-2f-kiss_fft_wrappers:
	-$(RM) ./tflm/signal/src/kiss_fft_wrappers/kiss_fft_float.cyclo ./tflm/signal/src/kiss_fft_wrappers/kiss_fft_float.d ./tflm/signal/src/kiss_fft_wrappers/kiss_fft_float.o ./tflm/signal/src/kiss_fft_wrappers/kiss_fft_float.su ./tflm/signal/src/kiss_fft_wrappers/kiss_fft_int16.cyclo ./tflm/signal/src/kiss_fft_wrappers/kiss_fft_int16.d ./tflm/signal/src/kiss_fft_wrappers/kiss_fft_int16.o ./tflm/signal/src/kiss_fft_wrappers/kiss_fft_int16.su ./tflm/signal/src/kiss_fft_wrappers/kiss_fft_int32.cyclo ./tflm/signal/src/kiss_fft_wrappers/kiss_fft_int32.d ./tflm/signal/src/kiss_fft_wrappers/kiss_fft_int32.o ./tflm/signal/src/kiss_fft_wrappers/kiss_fft_int32.su

.PHONY: clean-tflm-2f-signal-2f-src-2f-kiss_fft_wrappers

