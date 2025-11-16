################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../tflm/tensorflow/lite/micro/fake_micro_context.cc \
../tflm/tensorflow/lite/micro/flatbuffer_utils.cc \
../tflm/tensorflow/lite/micro/hexdump.cc \
../tflm/tensorflow/lite/micro/hexdump_test.cc \
../tflm/tensorflow/lite/micro/memory_helpers.cc \
../tflm/tensorflow/lite/micro/micro_allocation_info.cc \
../tflm/tensorflow/lite/micro/micro_allocator.cc \
../tflm/tensorflow/lite/micro/micro_context.cc \
../tflm/tensorflow/lite/micro/micro_interpreter.cc \
../tflm/tensorflow/lite/micro/micro_interpreter_context.cc \
../tflm/tensorflow/lite/micro/micro_interpreter_graph.cc \
../tflm/tensorflow/lite/micro/micro_log.cc \
../tflm/tensorflow/lite/micro/micro_op_resolver.cc \
../tflm/tensorflow/lite/micro/micro_profiler.cc \
../tflm/tensorflow/lite/micro/micro_resource_variable.cc \
../tflm/tensorflow/lite/micro/micro_utils.cc \
../tflm/tensorflow/lite/micro/mock_micro_graph.cc \
../tflm/tensorflow/lite/micro/recording_micro_allocator.cc \
../tflm/tensorflow/lite/micro/system_setup.cc \
../tflm/tensorflow/lite/micro/test_helper_custom_ops.cc \
../tflm/tensorflow/lite/micro/test_helpers.cc 

CC_DEPS += \
./tflm/tensorflow/lite/micro/fake_micro_context.d \
./tflm/tensorflow/lite/micro/flatbuffer_utils.d \
./tflm/tensorflow/lite/micro/hexdump.d \
./tflm/tensorflow/lite/micro/hexdump_test.d \
./tflm/tensorflow/lite/micro/memory_helpers.d \
./tflm/tensorflow/lite/micro/micro_allocation_info.d \
./tflm/tensorflow/lite/micro/micro_allocator.d \
./tflm/tensorflow/lite/micro/micro_context.d \
./tflm/tensorflow/lite/micro/micro_interpreter.d \
./tflm/tensorflow/lite/micro/micro_interpreter_context.d \
./tflm/tensorflow/lite/micro/micro_interpreter_graph.d \
./tflm/tensorflow/lite/micro/micro_log.d \
./tflm/tensorflow/lite/micro/micro_op_resolver.d \
./tflm/tensorflow/lite/micro/micro_profiler.d \
./tflm/tensorflow/lite/micro/micro_resource_variable.d \
./tflm/tensorflow/lite/micro/micro_utils.d \
./tflm/tensorflow/lite/micro/mock_micro_graph.d \
./tflm/tensorflow/lite/micro/recording_micro_allocator.d \
./tflm/tensorflow/lite/micro/system_setup.d \
./tflm/tensorflow/lite/micro/test_helper_custom_ops.d \
./tflm/tensorflow/lite/micro/test_helpers.d 

OBJS += \
./tflm/tensorflow/lite/micro/fake_micro_context.o \
./tflm/tensorflow/lite/micro/flatbuffer_utils.o \
./tflm/tensorflow/lite/micro/hexdump.o \
./tflm/tensorflow/lite/micro/hexdump_test.o \
./tflm/tensorflow/lite/micro/memory_helpers.o \
./tflm/tensorflow/lite/micro/micro_allocation_info.o \
./tflm/tensorflow/lite/micro/micro_allocator.o \
./tflm/tensorflow/lite/micro/micro_context.o \
./tflm/tensorflow/lite/micro/micro_interpreter.o \
./tflm/tensorflow/lite/micro/micro_interpreter_context.o \
./tflm/tensorflow/lite/micro/micro_interpreter_graph.o \
./tflm/tensorflow/lite/micro/micro_log.o \
./tflm/tensorflow/lite/micro/micro_op_resolver.o \
./tflm/tensorflow/lite/micro/micro_profiler.o \
./tflm/tensorflow/lite/micro/micro_resource_variable.o \
./tflm/tensorflow/lite/micro/micro_utils.o \
./tflm/tensorflow/lite/micro/mock_micro_graph.o \
./tflm/tensorflow/lite/micro/recording_micro_allocator.o \
./tflm/tensorflow/lite/micro/system_setup.o \
./tflm/tensorflow/lite/micro/test_helper_custom_ops.o \
./tflm/tensorflow/lite/micro/test_helpers.o 


# Each subdirectory must supply rules for building sources it contributes
tflm/tensorflow/lite/micro/%.o tflm/tensorflow/lite/micro/%.su tflm/tensorflow/lite/micro/%.cyclo: ../tflm/tensorflow/lite/micro/%.cc tflm/tensorflow/lite/micro/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tensorflow_lite" -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tensorflow_lite/third_party/flatbuffers/include" -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tensorflow_lite/third_party/gemmlowp" -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tensorflow_lite/third_party/ruy" -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tensorflow_lite/third_party/kissfft" -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tensorflow_lite/tensorflow/lite" -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tflm" -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tflm/tensorflow/lite" -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tflm/third_party/flatbuffers/include" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-tflm-2f-tensorflow-2f-lite-2f-micro

clean-tflm-2f-tensorflow-2f-lite-2f-micro:
	-$(RM) ./tflm/tensorflow/lite/micro/fake_micro_context.cyclo ./tflm/tensorflow/lite/micro/fake_micro_context.d ./tflm/tensorflow/lite/micro/fake_micro_context.o ./tflm/tensorflow/lite/micro/fake_micro_context.su ./tflm/tensorflow/lite/micro/flatbuffer_utils.cyclo ./tflm/tensorflow/lite/micro/flatbuffer_utils.d ./tflm/tensorflow/lite/micro/flatbuffer_utils.o ./tflm/tensorflow/lite/micro/flatbuffer_utils.su ./tflm/tensorflow/lite/micro/hexdump.cyclo ./tflm/tensorflow/lite/micro/hexdump.d ./tflm/tensorflow/lite/micro/hexdump.o ./tflm/tensorflow/lite/micro/hexdump.su ./tflm/tensorflow/lite/micro/hexdump_test.cyclo ./tflm/tensorflow/lite/micro/hexdump_test.d ./tflm/tensorflow/lite/micro/hexdump_test.o ./tflm/tensorflow/lite/micro/hexdump_test.su ./tflm/tensorflow/lite/micro/memory_helpers.cyclo ./tflm/tensorflow/lite/micro/memory_helpers.d ./tflm/tensorflow/lite/micro/memory_helpers.o ./tflm/tensorflow/lite/micro/memory_helpers.su ./tflm/tensorflow/lite/micro/micro_allocation_info.cyclo ./tflm/tensorflow/lite/micro/micro_allocation_info.d ./tflm/tensorflow/lite/micro/micro_allocation_info.o ./tflm/tensorflow/lite/micro/micro_allocation_info.su ./tflm/tensorflow/lite/micro/micro_allocator.cyclo ./tflm/tensorflow/lite/micro/micro_allocator.d ./tflm/tensorflow/lite/micro/micro_allocator.o ./tflm/tensorflow/lite/micro/micro_allocator.su ./tflm/tensorflow/lite/micro/micro_context.cyclo ./tflm/tensorflow/lite/micro/micro_context.d ./tflm/tensorflow/lite/micro/micro_context.o ./tflm/tensorflow/lite/micro/micro_context.su ./tflm/tensorflow/lite/micro/micro_interpreter.cyclo ./tflm/tensorflow/lite/micro/micro_interpreter.d ./tflm/tensorflow/lite/micro/micro_interpreter.o ./tflm/tensorflow/lite/micro/micro_interpreter.su ./tflm/tensorflow/lite/micro/micro_interpreter_context.cyclo ./tflm/tensorflow/lite/micro/micro_interpreter_context.d ./tflm/tensorflow/lite/micro/micro_interpreter_context.o ./tflm/tensorflow/lite/micro/micro_interpreter_context.su ./tflm/tensorflow/lite/micro/micro_interpreter_graph.cyclo ./tflm/tensorflow/lite/micro/micro_interpreter_graph.d ./tflm/tensorflow/lite/micro/micro_interpreter_graph.o ./tflm/tensorflow/lite/micro/micro_interpreter_graph.su ./tflm/tensorflow/lite/micro/micro_log.cyclo ./tflm/tensorflow/lite/micro/micro_log.d ./tflm/tensorflow/lite/micro/micro_log.o ./tflm/tensorflow/lite/micro/micro_log.su ./tflm/tensorflow/lite/micro/micro_op_resolver.cyclo ./tflm/tensorflow/lite/micro/micro_op_resolver.d ./tflm/tensorflow/lite/micro/micro_op_resolver.o ./tflm/tensorflow/lite/micro/micro_op_resolver.su ./tflm/tensorflow/lite/micro/micro_profiler.cyclo ./tflm/tensorflow/lite/micro/micro_profiler.d ./tflm/tensorflow/lite/micro/micro_profiler.o ./tflm/tensorflow/lite/micro/micro_profiler.su ./tflm/tensorflow/lite/micro/micro_resource_variable.cyclo ./tflm/tensorflow/lite/micro/micro_resource_variable.d ./tflm/tensorflow/lite/micro/micro_resource_variable.o ./tflm/tensorflow/lite/micro/micro_resource_variable.su ./tflm/tensorflow/lite/micro/micro_utils.cyclo ./tflm/tensorflow/lite/micro/micro_utils.d ./tflm/tensorflow/lite/micro/micro_utils.o ./tflm/tensorflow/lite/micro/micro_utils.su ./tflm/tensorflow/lite/micro/mock_micro_graph.cyclo ./tflm/tensorflow/lite/micro/mock_micro_graph.d ./tflm/tensorflow/lite/micro/mock_micro_graph.o ./tflm/tensorflow/lite/micro/mock_micro_graph.su ./tflm/tensorflow/lite/micro/recording_micro_allocator.cyclo ./tflm/tensorflow/lite/micro/recording_micro_allocator.d ./tflm/tensorflow/lite/micro/recording_micro_allocator.o ./tflm/tensorflow/lite/micro/recording_micro_allocator.su ./tflm/tensorflow/lite/micro/system_setup.cyclo ./tflm/tensorflow/lite/micro/system_setup.d ./tflm/tensorflow/lite/micro/system_setup.o ./tflm/tensorflow/lite/micro/system_setup.su ./tflm/tensorflow/lite/micro/test_helper_custom_ops.cyclo ./tflm/tensorflow/lite/micro/test_helper_custom_ops.d ./tflm/tensorflow/lite/micro/test_helper_custom_ops.o ./tflm/tensorflow/lite/micro/test_helper_custom_ops.su ./tflm/tensorflow/lite/micro/test_helpers.cyclo ./tflm/tensorflow/lite/micro/test_helpers.d ./tflm/tensorflow/lite/micro/test_helpers.o ./tflm/tensorflow/lite/micro/test_helpers.su

.PHONY: clean-tflm-2f-tensorflow-2f-lite-2f-micro

