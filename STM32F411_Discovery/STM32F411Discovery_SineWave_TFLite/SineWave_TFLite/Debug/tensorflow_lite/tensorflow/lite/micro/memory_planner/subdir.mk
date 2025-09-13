################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../tensorflow_lite/tensorflow/lite/micro/memory_planner/greedy_memory_planner.cc \
../tensorflow_lite/tensorflow/lite/micro/memory_planner/linear_memory_planner.cc \
../tensorflow_lite/tensorflow/lite/micro/memory_planner/non_persistent_buffer_planner_shim.cc 

CC_DEPS += \
./tensorflow_lite/tensorflow/lite/micro/memory_planner/greedy_memory_planner.d \
./tensorflow_lite/tensorflow/lite/micro/memory_planner/linear_memory_planner.d \
./tensorflow_lite/tensorflow/lite/micro/memory_planner/non_persistent_buffer_planner_shim.d 

OBJS += \
./tensorflow_lite/tensorflow/lite/micro/memory_planner/greedy_memory_planner.o \
./tensorflow_lite/tensorflow/lite/micro/memory_planner/linear_memory_planner.o \
./tensorflow_lite/tensorflow/lite/micro/memory_planner/non_persistent_buffer_planner_shim.o 


# Each subdirectory must supply rules for building sources it contributes
tensorflow_lite/tensorflow/lite/micro/memory_planner/%.o tensorflow_lite/tensorflow/lite/micro/memory_planner/%.su tensorflow_lite/tensorflow/lite/micro/memory_planner/%.cyclo: ../tensorflow_lite/tensorflow/lite/micro/memory_planner/%.cc tensorflow_lite/tensorflow/lite/micro/memory_planner/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tensorflow_lite" -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tensorflow_lite/third_party/flatbuffers/include" -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tensorflow_lite/third_party/gemmlowp" -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tensorflow_lite/third_party/ruy" -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tensorflow_lite/third_party/kissfft" -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tensorflow_lite/tensorflow/lite" -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tensorflow_lite/signal" -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tensorflow_lite/signal/src" -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/Lib" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-tensorflow_lite-2f-tensorflow-2f-lite-2f-micro-2f-memory_planner

clean-tensorflow_lite-2f-tensorflow-2f-lite-2f-micro-2f-memory_planner:
	-$(RM) ./tensorflow_lite/tensorflow/lite/micro/memory_planner/greedy_memory_planner.cyclo ./tensorflow_lite/tensorflow/lite/micro/memory_planner/greedy_memory_planner.d ./tensorflow_lite/tensorflow/lite/micro/memory_planner/greedy_memory_planner.o ./tensorflow_lite/tensorflow/lite/micro/memory_planner/greedy_memory_planner.su ./tensorflow_lite/tensorflow/lite/micro/memory_planner/linear_memory_planner.cyclo ./tensorflow_lite/tensorflow/lite/micro/memory_planner/linear_memory_planner.d ./tensorflow_lite/tensorflow/lite/micro/memory_planner/linear_memory_planner.o ./tensorflow_lite/tensorflow/lite/micro/memory_planner/linear_memory_planner.su ./tensorflow_lite/tensorflow/lite/micro/memory_planner/non_persistent_buffer_planner_shim.cyclo ./tensorflow_lite/tensorflow/lite/micro/memory_planner/non_persistent_buffer_planner_shim.d ./tensorflow_lite/tensorflow/lite/micro/memory_planner/non_persistent_buffer_planner_shim.o ./tensorflow_lite/tensorflow/lite/micro/memory_planner/non_persistent_buffer_planner_shim.su

.PHONY: clean-tensorflow_lite-2f-tensorflow-2f-lite-2f-micro-2f-memory_planner

