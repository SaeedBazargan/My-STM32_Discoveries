################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_convolve_1_x_n_s4.c \
../tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_convolve_1_x_n_s8.c \
../tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_convolve_1x1_s4.c \
../tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_convolve_1x1_s4_fast.c \
../tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_convolve_1x1_s8.c \
../tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_convolve_1x1_s8_fast.c \
../tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_convolve_even_s4.c \
../tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_convolve_get_buffer_sizes_s16.c \
../tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_convolve_get_buffer_sizes_s4.c \
../tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_convolve_get_buffer_sizes_s8.c \
../tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_convolve_s16.c \
../tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_convolve_s4.c \
../tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_convolve_s8.c \
../tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_convolve_wrapper_s16.c \
../tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_convolve_wrapper_s4.c \
../tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_convolve_wrapper_s8.c \
../tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_depthwise_conv_3x3_s8.c \
../tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_depthwise_conv_fast_s16.c \
../tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_depthwise_conv_get_buffer_sizes_s16.c \
../tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_depthwise_conv_get_buffer_sizes_s4.c \
../tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_depthwise_conv_get_buffer_sizes_s8.c \
../tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_depthwise_conv_s16.c \
../tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_depthwise_conv_s4.c \
../tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_depthwise_conv_s4_opt.c \
../tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_depthwise_conv_s8.c \
../tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_depthwise_conv_s8_opt.c \
../tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_depthwise_conv_wrapper_s16.c \
../tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_depthwise_conv_wrapper_s4.c \
../tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_depthwise_conv_wrapper_s8.c \
../tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_nn_depthwise_conv_s8_core.c \
../tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_nn_mat_mult_kernel_row_offset_s8_s16.c \
../tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_nn_mat_mult_kernel_s16.c \
../tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_nn_mat_mult_kernel_s4_s16.c \
../tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_nn_mat_mult_kernel_s8_s16.c \
../tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_nn_mat_mult_s8.c \
../tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_transpose_conv_get_buffer_sizes_s8.c \
../tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_transpose_conv_s8.c \
../tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_transpose_conv_wrapper_s8.c 

C_DEPS += \
./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_convolve_1_x_n_s4.d \
./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_convolve_1_x_n_s8.d \
./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_convolve_1x1_s4.d \
./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_convolve_1x1_s4_fast.d \
./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_convolve_1x1_s8.d \
./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_convolve_1x1_s8_fast.d \
./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_convolve_even_s4.d \
./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_convolve_get_buffer_sizes_s16.d \
./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_convolve_get_buffer_sizes_s4.d \
./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_convolve_get_buffer_sizes_s8.d \
./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_convolve_s16.d \
./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_convolve_s4.d \
./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_convolve_s8.d \
./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_convolve_wrapper_s16.d \
./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_convolve_wrapper_s4.d \
./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_convolve_wrapper_s8.d \
./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_depthwise_conv_3x3_s8.d \
./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_depthwise_conv_fast_s16.d \
./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_depthwise_conv_get_buffer_sizes_s16.d \
./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_depthwise_conv_get_buffer_sizes_s4.d \
./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_depthwise_conv_get_buffer_sizes_s8.d \
./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_depthwise_conv_s16.d \
./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_depthwise_conv_s4.d \
./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_depthwise_conv_s4_opt.d \
./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_depthwise_conv_s8.d \
./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_depthwise_conv_s8_opt.d \
./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_depthwise_conv_wrapper_s16.d \
./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_depthwise_conv_wrapper_s4.d \
./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_depthwise_conv_wrapper_s8.d \
./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_nn_depthwise_conv_s8_core.d \
./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_nn_mat_mult_kernel_row_offset_s8_s16.d \
./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_nn_mat_mult_kernel_s16.d \
./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_nn_mat_mult_kernel_s4_s16.d \
./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_nn_mat_mult_kernel_s8_s16.d \
./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_nn_mat_mult_s8.d \
./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_transpose_conv_get_buffer_sizes_s8.d \
./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_transpose_conv_s8.d \
./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_transpose_conv_wrapper_s8.d 

OBJS += \
./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_convolve_1_x_n_s4.o \
./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_convolve_1_x_n_s8.o \
./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_convolve_1x1_s4.o \
./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_convolve_1x1_s4_fast.o \
./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_convolve_1x1_s8.o \
./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_convolve_1x1_s8_fast.o \
./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_convolve_even_s4.o \
./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_convolve_get_buffer_sizes_s16.o \
./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_convolve_get_buffer_sizes_s4.o \
./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_convolve_get_buffer_sizes_s8.o \
./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_convolve_s16.o \
./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_convolve_s4.o \
./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_convolve_s8.o \
./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_convolve_wrapper_s16.o \
./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_convolve_wrapper_s4.o \
./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_convolve_wrapper_s8.o \
./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_depthwise_conv_3x3_s8.o \
./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_depthwise_conv_fast_s16.o \
./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_depthwise_conv_get_buffer_sizes_s16.o \
./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_depthwise_conv_get_buffer_sizes_s4.o \
./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_depthwise_conv_get_buffer_sizes_s8.o \
./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_depthwise_conv_s16.o \
./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_depthwise_conv_s4.o \
./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_depthwise_conv_s4_opt.o \
./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_depthwise_conv_s8.o \
./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_depthwise_conv_s8_opt.o \
./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_depthwise_conv_wrapper_s16.o \
./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_depthwise_conv_wrapper_s4.o \
./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_depthwise_conv_wrapper_s8.o \
./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_nn_depthwise_conv_s8_core.o \
./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_nn_mat_mult_kernel_row_offset_s8_s16.o \
./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_nn_mat_mult_kernel_s16.o \
./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_nn_mat_mult_kernel_s4_s16.o \
./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_nn_mat_mult_kernel_s8_s16.o \
./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_nn_mat_mult_s8.o \
./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_transpose_conv_get_buffer_sizes_s8.o \
./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_transpose_conv_s8.o \
./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_transpose_conv_wrapper_s8.o 


# Each subdirectory must supply rules for building sources it contributes
tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/%.o tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/%.su tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/%.cyclo: ../tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/%.c tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tflm" -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tflm/tensorflow/lite" -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tflm/third_party/flatbuffers/include" -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tflm/third_party/gemmlowp" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-tflm-2f-third_party-2f-cmsis_nn-2f-Source-2f-ConvolutionFunctions

clean-tflm-2f-third_party-2f-cmsis_nn-2f-Source-2f-ConvolutionFunctions:
	-$(RM) ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_convolve_1_x_n_s4.cyclo ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_convolve_1_x_n_s4.d ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_convolve_1_x_n_s4.o ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_convolve_1_x_n_s4.su ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_convolve_1_x_n_s8.cyclo ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_convolve_1_x_n_s8.d ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_convolve_1_x_n_s8.o ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_convolve_1_x_n_s8.su ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_convolve_1x1_s4.cyclo ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_convolve_1x1_s4.d ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_convolve_1x1_s4.o ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_convolve_1x1_s4.su ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_convolve_1x1_s4_fast.cyclo ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_convolve_1x1_s4_fast.d ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_convolve_1x1_s4_fast.o ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_convolve_1x1_s4_fast.su ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_convolve_1x1_s8.cyclo ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_convolve_1x1_s8.d ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_convolve_1x1_s8.o ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_convolve_1x1_s8.su ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_convolve_1x1_s8_fast.cyclo ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_convolve_1x1_s8_fast.d ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_convolve_1x1_s8_fast.o ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_convolve_1x1_s8_fast.su ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_convolve_even_s4.cyclo ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_convolve_even_s4.d ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_convolve_even_s4.o ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_convolve_even_s4.su ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_convolve_get_buffer_sizes_s16.cyclo ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_convolve_get_buffer_sizes_s16.d ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_convolve_get_buffer_sizes_s16.o ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_convolve_get_buffer_sizes_s16.su ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_convolve_get_buffer_sizes_s4.cyclo ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_convolve_get_buffer_sizes_s4.d ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_convolve_get_buffer_sizes_s4.o ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_convolve_get_buffer_sizes_s4.su ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_convolve_get_buffer_sizes_s8.cyclo ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_convolve_get_buffer_sizes_s8.d ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_convolve_get_buffer_sizes_s8.o ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_convolve_get_buffer_sizes_s8.su ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_convolve_s16.cyclo ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_convolve_s16.d ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_convolve_s16.o ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_convolve_s16.su ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_convolve_s4.cyclo ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_convolve_s4.d ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_convolve_s4.o ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_convolve_s4.su ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_convolve_s8.cyclo ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_convolve_s8.d ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_convolve_s8.o ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_convolve_s8.su ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_convolve_wrapper_s16.cyclo ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_convolve_wrapper_s16.d ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_convolve_wrapper_s16.o ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_convolve_wrapper_s16.su ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_convolve_wrapper_s4.cyclo ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_convolve_wrapper_s4.d ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_convolve_wrapper_s4.o ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_convolve_wrapper_s4.su ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_convolve_wrapper_s8.cyclo ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_convolve_wrapper_s8.d ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_convolve_wrapper_s8.o ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_convolve_wrapper_s8.su ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_depthwise_conv_3x3_s8.cyclo ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_depthwise_conv_3x3_s8.d ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_depthwise_conv_3x3_s8.o ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_depthwise_conv_3x3_s8.su ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_depthwise_conv_fast_s16.cyclo ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_depthwise_conv_fast_s16.d ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_depthwise_conv_fast_s16.o ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_depthwise_conv_fast_s16.su
	-$(RM) ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_depthwise_conv_get_buffer_sizes_s16.cyclo ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_depthwise_conv_get_buffer_sizes_s16.d ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_depthwise_conv_get_buffer_sizes_s16.o ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_depthwise_conv_get_buffer_sizes_s16.su ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_depthwise_conv_get_buffer_sizes_s4.cyclo ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_depthwise_conv_get_buffer_sizes_s4.d ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_depthwise_conv_get_buffer_sizes_s4.o ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_depthwise_conv_get_buffer_sizes_s4.su ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_depthwise_conv_get_buffer_sizes_s8.cyclo ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_depthwise_conv_get_buffer_sizes_s8.d ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_depthwise_conv_get_buffer_sizes_s8.o ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_depthwise_conv_get_buffer_sizes_s8.su ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_depthwise_conv_s16.cyclo ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_depthwise_conv_s16.d ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_depthwise_conv_s16.o ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_depthwise_conv_s16.su ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_depthwise_conv_s4.cyclo ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_depthwise_conv_s4.d ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_depthwise_conv_s4.o ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_depthwise_conv_s4.su ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_depthwise_conv_s4_opt.cyclo ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_depthwise_conv_s4_opt.d ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_depthwise_conv_s4_opt.o ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_depthwise_conv_s4_opt.su ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_depthwise_conv_s8.cyclo ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_depthwise_conv_s8.d ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_depthwise_conv_s8.o ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_depthwise_conv_s8.su ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_depthwise_conv_s8_opt.cyclo ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_depthwise_conv_s8_opt.d ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_depthwise_conv_s8_opt.o ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_depthwise_conv_s8_opt.su ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_depthwise_conv_wrapper_s16.cyclo ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_depthwise_conv_wrapper_s16.d ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_depthwise_conv_wrapper_s16.o ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_depthwise_conv_wrapper_s16.su ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_depthwise_conv_wrapper_s4.cyclo ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_depthwise_conv_wrapper_s4.d ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_depthwise_conv_wrapper_s4.o ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_depthwise_conv_wrapper_s4.su ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_depthwise_conv_wrapper_s8.cyclo ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_depthwise_conv_wrapper_s8.d ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_depthwise_conv_wrapper_s8.o ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_depthwise_conv_wrapper_s8.su ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_nn_depthwise_conv_s8_core.cyclo ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_nn_depthwise_conv_s8_core.d ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_nn_depthwise_conv_s8_core.o ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_nn_depthwise_conv_s8_core.su ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_nn_mat_mult_kernel_row_offset_s8_s16.cyclo ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_nn_mat_mult_kernel_row_offset_s8_s16.d ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_nn_mat_mult_kernel_row_offset_s8_s16.o ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_nn_mat_mult_kernel_row_offset_s8_s16.su ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_nn_mat_mult_kernel_s16.cyclo ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_nn_mat_mult_kernel_s16.d ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_nn_mat_mult_kernel_s16.o ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_nn_mat_mult_kernel_s16.su ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_nn_mat_mult_kernel_s4_s16.cyclo ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_nn_mat_mult_kernel_s4_s16.d ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_nn_mat_mult_kernel_s4_s16.o ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_nn_mat_mult_kernel_s4_s16.su ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_nn_mat_mult_kernel_s8_s16.cyclo ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_nn_mat_mult_kernel_s8_s16.d ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_nn_mat_mult_kernel_s8_s16.o ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_nn_mat_mult_kernel_s8_s16.su ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_nn_mat_mult_s8.cyclo ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_nn_mat_mult_s8.d ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_nn_mat_mult_s8.o
	-$(RM) ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_nn_mat_mult_s8.su ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_transpose_conv_get_buffer_sizes_s8.cyclo ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_transpose_conv_get_buffer_sizes_s8.d ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_transpose_conv_get_buffer_sizes_s8.o ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_transpose_conv_get_buffer_sizes_s8.su ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_transpose_conv_s8.cyclo ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_transpose_conv_s8.d ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_transpose_conv_s8.o ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_transpose_conv_s8.su ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_transpose_conv_wrapper_s8.cyclo ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_transpose_conv_wrapper_s8.d ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_transpose_conv_wrapper_s8.o ./tflm/third_party/cmsis_nn/Source/ConvolutionFunctions/arm_transpose_conv_wrapper_s8.su

.PHONY: clean-tflm-2f-third_party-2f-cmsis_nn-2f-Source-2f-ConvolutionFunctions

