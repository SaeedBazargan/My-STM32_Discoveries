################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../tflm/tensorflow/lite/micro/arena_allocator/non_persistent_arena_buffer_allocator.cc \
../tflm/tensorflow/lite/micro/arena_allocator/persistent_arena_buffer_allocator.cc \
../tflm/tensorflow/lite/micro/arena_allocator/recording_single_arena_buffer_allocator.cc \
../tflm/tensorflow/lite/micro/arena_allocator/single_arena_buffer_allocator.cc 

CC_DEPS += \
./tflm/tensorflow/lite/micro/arena_allocator/non_persistent_arena_buffer_allocator.d \
./tflm/tensorflow/lite/micro/arena_allocator/persistent_arena_buffer_allocator.d \
./tflm/tensorflow/lite/micro/arena_allocator/recording_single_arena_buffer_allocator.d \
./tflm/tensorflow/lite/micro/arena_allocator/single_arena_buffer_allocator.d 

OBJS += \
./tflm/tensorflow/lite/micro/arena_allocator/non_persistent_arena_buffer_allocator.o \
./tflm/tensorflow/lite/micro/arena_allocator/persistent_arena_buffer_allocator.o \
./tflm/tensorflow/lite/micro/arena_allocator/recording_single_arena_buffer_allocator.o \
./tflm/tensorflow/lite/micro/arena_allocator/single_arena_buffer_allocator.o 


# Each subdirectory must supply rules for building sources it contributes
tflm/tensorflow/lite/micro/arena_allocator/%.o tflm/tensorflow/lite/micro/arena_allocator/%.su tflm/tensorflow/lite/micro/arena_allocator/%.cyclo: ../tflm/tensorflow/lite/micro/arena_allocator/%.cc tflm/tensorflow/lite/micro/arena_allocator/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tensorflow_lite" -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tensorflow_lite/third_party/flatbuffers/include" -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tensorflow_lite/third_party/gemmlowp" -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tensorflow_lite/third_party/ruy" -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tensorflow_lite/third_party/kissfft" -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tensorflow_lite/tensorflow/lite" -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tflm" -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tflm/tensorflow/lite" -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tflm/third_party/flatbuffers/include" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-tflm-2f-tensorflow-2f-lite-2f-micro-2f-arena_allocator

clean-tflm-2f-tensorflow-2f-lite-2f-micro-2f-arena_allocator:
	-$(RM) ./tflm/tensorflow/lite/micro/arena_allocator/non_persistent_arena_buffer_allocator.cyclo ./tflm/tensorflow/lite/micro/arena_allocator/non_persistent_arena_buffer_allocator.d ./tflm/tensorflow/lite/micro/arena_allocator/non_persistent_arena_buffer_allocator.o ./tflm/tensorflow/lite/micro/arena_allocator/non_persistent_arena_buffer_allocator.su ./tflm/tensorflow/lite/micro/arena_allocator/persistent_arena_buffer_allocator.cyclo ./tflm/tensorflow/lite/micro/arena_allocator/persistent_arena_buffer_allocator.d ./tflm/tensorflow/lite/micro/arena_allocator/persistent_arena_buffer_allocator.o ./tflm/tensorflow/lite/micro/arena_allocator/persistent_arena_buffer_allocator.su ./tflm/tensorflow/lite/micro/arena_allocator/recording_single_arena_buffer_allocator.cyclo ./tflm/tensorflow/lite/micro/arena_allocator/recording_single_arena_buffer_allocator.d ./tflm/tensorflow/lite/micro/arena_allocator/recording_single_arena_buffer_allocator.o ./tflm/tensorflow/lite/micro/arena_allocator/recording_single_arena_buffer_allocator.su ./tflm/tensorflow/lite/micro/arena_allocator/single_arena_buffer_allocator.cyclo ./tflm/tensorflow/lite/micro/arena_allocator/single_arena_buffer_allocator.d ./tflm/tensorflow/lite/micro/arena_allocator/single_arena_buffer_allocator.o ./tflm/tensorflow/lite/micro/arena_allocator/single_arena_buffer_allocator.su

.PHONY: clean-tflm-2f-tensorflow-2f-lite-2f-micro-2f-arena_allocator

