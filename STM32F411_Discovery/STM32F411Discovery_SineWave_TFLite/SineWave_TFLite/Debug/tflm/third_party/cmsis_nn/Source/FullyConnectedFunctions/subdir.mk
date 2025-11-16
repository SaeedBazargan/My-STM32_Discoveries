################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../tflm/third_party/cmsis_nn/Source/FullyConnectedFunctions/arm_batch_matmul_s16.c \
../tflm/third_party/cmsis_nn/Source/FullyConnectedFunctions/arm_batch_matmul_s8.c \
../tflm/third_party/cmsis_nn/Source/FullyConnectedFunctions/arm_fully_connected_get_buffer_sizes_s16.c \
../tflm/third_party/cmsis_nn/Source/FullyConnectedFunctions/arm_fully_connected_get_buffer_sizes_s8.c \
../tflm/third_party/cmsis_nn/Source/FullyConnectedFunctions/arm_fully_connected_per_channel_s8.c \
../tflm/third_party/cmsis_nn/Source/FullyConnectedFunctions/arm_fully_connected_s16.c \
../tflm/third_party/cmsis_nn/Source/FullyConnectedFunctions/arm_fully_connected_s4.c \
../tflm/third_party/cmsis_nn/Source/FullyConnectedFunctions/arm_fully_connected_s8.c \
../tflm/third_party/cmsis_nn/Source/FullyConnectedFunctions/arm_fully_connected_wrapper_s8.c \
../tflm/third_party/cmsis_nn/Source/FullyConnectedFunctions/arm_vector_sum_s8.c \
../tflm/third_party/cmsis_nn/Source/FullyConnectedFunctions/arm_vector_sum_s8_s64.c 

C_DEPS += \
./tflm/third_party/cmsis_nn/Source/FullyConnectedFunctions/arm_batch_matmul_s16.d \
./tflm/third_party/cmsis_nn/Source/FullyConnectedFunctions/arm_batch_matmul_s8.d \
./tflm/third_party/cmsis_nn/Source/FullyConnectedFunctions/arm_fully_connected_get_buffer_sizes_s16.d \
./tflm/third_party/cmsis_nn/Source/FullyConnectedFunctions/arm_fully_connected_get_buffer_sizes_s8.d \
./tflm/third_party/cmsis_nn/Source/FullyConnectedFunctions/arm_fully_connected_per_channel_s8.d \
./tflm/third_party/cmsis_nn/Source/FullyConnectedFunctions/arm_fully_connected_s16.d \
./tflm/third_party/cmsis_nn/Source/FullyConnectedFunctions/arm_fully_connected_s4.d \
./tflm/third_party/cmsis_nn/Source/FullyConnectedFunctions/arm_fully_connected_s8.d \
./tflm/third_party/cmsis_nn/Source/FullyConnectedFunctions/arm_fully_connected_wrapper_s8.d \
./tflm/third_party/cmsis_nn/Source/FullyConnectedFunctions/arm_vector_sum_s8.d \
./tflm/third_party/cmsis_nn/Source/FullyConnectedFunctions/arm_vector_sum_s8_s64.d 

OBJS += \
./tflm/third_party/cmsis_nn/Source/FullyConnectedFunctions/arm_batch_matmul_s16.o \
./tflm/third_party/cmsis_nn/Source/FullyConnectedFunctions/arm_batch_matmul_s8.o \
./tflm/third_party/cmsis_nn/Source/FullyConnectedFunctions/arm_fully_connected_get_buffer_sizes_s16.o \
./tflm/third_party/cmsis_nn/Source/FullyConnectedFunctions/arm_fully_connected_get_buffer_sizes_s8.o \
./tflm/third_party/cmsis_nn/Source/FullyConnectedFunctions/arm_fully_connected_per_channel_s8.o \
./tflm/third_party/cmsis_nn/Source/FullyConnectedFunctions/arm_fully_connected_s16.o \
./tflm/third_party/cmsis_nn/Source/FullyConnectedFunctions/arm_fully_connected_s4.o \
./tflm/third_party/cmsis_nn/Source/FullyConnectedFunctions/arm_fully_connected_s8.o \
./tflm/third_party/cmsis_nn/Source/FullyConnectedFunctions/arm_fully_connected_wrapper_s8.o \
./tflm/third_party/cmsis_nn/Source/FullyConnectedFunctions/arm_vector_sum_s8.o \
./tflm/third_party/cmsis_nn/Source/FullyConnectedFunctions/arm_vector_sum_s8_s64.o 


# Each subdirectory must supply rules for building sources it contributes
tflm/third_party/cmsis_nn/Source/FullyConnectedFunctions/%.o tflm/third_party/cmsis_nn/Source/FullyConnectedFunctions/%.su tflm/third_party/cmsis_nn/Source/FullyConnectedFunctions/%.cyclo: ../tflm/third_party/cmsis_nn/Source/FullyConnectedFunctions/%.c tflm/third_party/cmsis_nn/Source/FullyConnectedFunctions/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tflm" -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tflm/tensorflow/lite" -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tflm/third_party/flatbuffers/include" -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tflm/third_party/gemmlowp" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-tflm-2f-third_party-2f-cmsis_nn-2f-Source-2f-FullyConnectedFunctions

clean-tflm-2f-third_party-2f-cmsis_nn-2f-Source-2f-FullyConnectedFunctions:
	-$(RM) ./tflm/third_party/cmsis_nn/Source/FullyConnectedFunctions/arm_batch_matmul_s16.cyclo ./tflm/third_party/cmsis_nn/Source/FullyConnectedFunctions/arm_batch_matmul_s16.d ./tflm/third_party/cmsis_nn/Source/FullyConnectedFunctions/arm_batch_matmul_s16.o ./tflm/third_party/cmsis_nn/Source/FullyConnectedFunctions/arm_batch_matmul_s16.su ./tflm/third_party/cmsis_nn/Source/FullyConnectedFunctions/arm_batch_matmul_s8.cyclo ./tflm/third_party/cmsis_nn/Source/FullyConnectedFunctions/arm_batch_matmul_s8.d ./tflm/third_party/cmsis_nn/Source/FullyConnectedFunctions/arm_batch_matmul_s8.o ./tflm/third_party/cmsis_nn/Source/FullyConnectedFunctions/arm_batch_matmul_s8.su ./tflm/third_party/cmsis_nn/Source/FullyConnectedFunctions/arm_fully_connected_get_buffer_sizes_s16.cyclo ./tflm/third_party/cmsis_nn/Source/FullyConnectedFunctions/arm_fully_connected_get_buffer_sizes_s16.d ./tflm/third_party/cmsis_nn/Source/FullyConnectedFunctions/arm_fully_connected_get_buffer_sizes_s16.o ./tflm/third_party/cmsis_nn/Source/FullyConnectedFunctions/arm_fully_connected_get_buffer_sizes_s16.su ./tflm/third_party/cmsis_nn/Source/FullyConnectedFunctions/arm_fully_connected_get_buffer_sizes_s8.cyclo ./tflm/third_party/cmsis_nn/Source/FullyConnectedFunctions/arm_fully_connected_get_buffer_sizes_s8.d ./tflm/third_party/cmsis_nn/Source/FullyConnectedFunctions/arm_fully_connected_get_buffer_sizes_s8.o ./tflm/third_party/cmsis_nn/Source/FullyConnectedFunctions/arm_fully_connected_get_buffer_sizes_s8.su ./tflm/third_party/cmsis_nn/Source/FullyConnectedFunctions/arm_fully_connected_per_channel_s8.cyclo ./tflm/third_party/cmsis_nn/Source/FullyConnectedFunctions/arm_fully_connected_per_channel_s8.d ./tflm/third_party/cmsis_nn/Source/FullyConnectedFunctions/arm_fully_connected_per_channel_s8.o ./tflm/third_party/cmsis_nn/Source/FullyConnectedFunctions/arm_fully_connected_per_channel_s8.su ./tflm/third_party/cmsis_nn/Source/FullyConnectedFunctions/arm_fully_connected_s16.cyclo ./tflm/third_party/cmsis_nn/Source/FullyConnectedFunctions/arm_fully_connected_s16.d ./tflm/third_party/cmsis_nn/Source/FullyConnectedFunctions/arm_fully_connected_s16.o ./tflm/third_party/cmsis_nn/Source/FullyConnectedFunctions/arm_fully_connected_s16.su ./tflm/third_party/cmsis_nn/Source/FullyConnectedFunctions/arm_fully_connected_s4.cyclo ./tflm/third_party/cmsis_nn/Source/FullyConnectedFunctions/arm_fully_connected_s4.d ./tflm/third_party/cmsis_nn/Source/FullyConnectedFunctions/arm_fully_connected_s4.o ./tflm/third_party/cmsis_nn/Source/FullyConnectedFunctions/arm_fully_connected_s4.su ./tflm/third_party/cmsis_nn/Source/FullyConnectedFunctions/arm_fully_connected_s8.cyclo ./tflm/third_party/cmsis_nn/Source/FullyConnectedFunctions/arm_fully_connected_s8.d ./tflm/third_party/cmsis_nn/Source/FullyConnectedFunctions/arm_fully_connected_s8.o ./tflm/third_party/cmsis_nn/Source/FullyConnectedFunctions/arm_fully_connected_s8.su ./tflm/third_party/cmsis_nn/Source/FullyConnectedFunctions/arm_fully_connected_wrapper_s8.cyclo ./tflm/third_party/cmsis_nn/Source/FullyConnectedFunctions/arm_fully_connected_wrapper_s8.d ./tflm/third_party/cmsis_nn/Source/FullyConnectedFunctions/arm_fully_connected_wrapper_s8.o ./tflm/third_party/cmsis_nn/Source/FullyConnectedFunctions/arm_fully_connected_wrapper_s8.su ./tflm/third_party/cmsis_nn/Source/FullyConnectedFunctions/arm_vector_sum_s8.cyclo ./tflm/third_party/cmsis_nn/Source/FullyConnectedFunctions/arm_vector_sum_s8.d ./tflm/third_party/cmsis_nn/Source/FullyConnectedFunctions/arm_vector_sum_s8.o ./tflm/third_party/cmsis_nn/Source/FullyConnectedFunctions/arm_vector_sum_s8.su ./tflm/third_party/cmsis_nn/Source/FullyConnectedFunctions/arm_vector_sum_s8_s64.cyclo ./tflm/third_party/cmsis_nn/Source/FullyConnectedFunctions/arm_vector_sum_s8_s64.d ./tflm/third_party/cmsis_nn/Source/FullyConnectedFunctions/arm_vector_sum_s8_s64.o ./tflm/third_party/cmsis_nn/Source/FullyConnectedFunctions/arm_vector_sum_s8_s64.su

.PHONY: clean-tflm-2f-third_party-2f-cmsis_nn-2f-Source-2f-FullyConnectedFunctions

