################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_depthwise_conv_nt_t_padded_s8.c \
../tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_depthwise_conv_nt_t_s16.c \
../tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_depthwise_conv_nt_t_s4.c \
../tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_depthwise_conv_nt_t_s8.c \
../tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_lstm_calculate_gate_s16.c \
../tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_lstm_calculate_gate_s8_s16.c \
../tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_lstm_step_s16.c \
../tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_lstm_step_s8.c \
../tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_mat_mul_core_1x_s4.c \
../tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_mat_mul_core_1x_s8.c \
../tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_mat_mul_core_4x_s8.c \
../tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_mat_mult_nt_interleaved_t_even_s4.c \
../tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_mat_mult_nt_t_s16.c \
../tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_mat_mult_nt_t_s4.c \
../tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_mat_mult_nt_t_s8.c \
../tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_mat_mult_nt_t_s8_s32.c \
../tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_transpose_conv_row_s8_s32.c \
../tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_vec_mat_mul_result_acc_s16.c \
../tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_vec_mat_mul_result_acc_s8_s16.c \
../tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_vec_mat_mult_t_per_ch_s8.c \
../tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_vec_mat_mult_t_s16.c \
../tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_vec_mat_mult_t_s16_s16.c \
../tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_vec_mat_mult_t_s4.c \
../tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_vec_mat_mult_t_s8.c \
../tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_vec_mat_mult_t_svdf_s8.c \
../tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nntables.c \
../tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_q7_to_q15_with_offset.c \
../tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_s8_to_s16_unordered_with_offset.c 

C_DEPS += \
./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_depthwise_conv_nt_t_padded_s8.d \
./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_depthwise_conv_nt_t_s16.d \
./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_depthwise_conv_nt_t_s4.d \
./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_depthwise_conv_nt_t_s8.d \
./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_lstm_calculate_gate_s16.d \
./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_lstm_calculate_gate_s8_s16.d \
./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_lstm_step_s16.d \
./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_lstm_step_s8.d \
./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_mat_mul_core_1x_s4.d \
./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_mat_mul_core_1x_s8.d \
./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_mat_mul_core_4x_s8.d \
./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_mat_mult_nt_interleaved_t_even_s4.d \
./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_mat_mult_nt_t_s16.d \
./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_mat_mult_nt_t_s4.d \
./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_mat_mult_nt_t_s8.d \
./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_mat_mult_nt_t_s8_s32.d \
./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_transpose_conv_row_s8_s32.d \
./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_vec_mat_mul_result_acc_s16.d \
./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_vec_mat_mul_result_acc_s8_s16.d \
./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_vec_mat_mult_t_per_ch_s8.d \
./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_vec_mat_mult_t_s16.d \
./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_vec_mat_mult_t_s16_s16.d \
./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_vec_mat_mult_t_s4.d \
./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_vec_mat_mult_t_s8.d \
./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_vec_mat_mult_t_svdf_s8.d \
./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nntables.d \
./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_q7_to_q15_with_offset.d \
./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_s8_to_s16_unordered_with_offset.d 

OBJS += \
./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_depthwise_conv_nt_t_padded_s8.o \
./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_depthwise_conv_nt_t_s16.o \
./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_depthwise_conv_nt_t_s4.o \
./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_depthwise_conv_nt_t_s8.o \
./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_lstm_calculate_gate_s16.o \
./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_lstm_calculate_gate_s8_s16.o \
./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_lstm_step_s16.o \
./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_lstm_step_s8.o \
./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_mat_mul_core_1x_s4.o \
./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_mat_mul_core_1x_s8.o \
./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_mat_mul_core_4x_s8.o \
./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_mat_mult_nt_interleaved_t_even_s4.o \
./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_mat_mult_nt_t_s16.o \
./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_mat_mult_nt_t_s4.o \
./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_mat_mult_nt_t_s8.o \
./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_mat_mult_nt_t_s8_s32.o \
./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_transpose_conv_row_s8_s32.o \
./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_vec_mat_mul_result_acc_s16.o \
./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_vec_mat_mul_result_acc_s8_s16.o \
./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_vec_mat_mult_t_per_ch_s8.o \
./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_vec_mat_mult_t_s16.o \
./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_vec_mat_mult_t_s16_s16.o \
./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_vec_mat_mult_t_s4.o \
./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_vec_mat_mult_t_s8.o \
./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_vec_mat_mult_t_svdf_s8.o \
./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nntables.o \
./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_q7_to_q15_with_offset.o \
./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_s8_to_s16_unordered_with_offset.o 


# Each subdirectory must supply rules for building sources it contributes
tflm/third_party/cmsis_nn/Source/NNSupportFunctions/%.o tflm/third_party/cmsis_nn/Source/NNSupportFunctions/%.su tflm/third_party/cmsis_nn/Source/NNSupportFunctions/%.cyclo: ../tflm/third_party/cmsis_nn/Source/NNSupportFunctions/%.c tflm/third_party/cmsis_nn/Source/NNSupportFunctions/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tflm" -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tflm/tensorflow/lite" -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tflm/third_party/flatbuffers/include" -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tflm/third_party/gemmlowp" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-tflm-2f-third_party-2f-cmsis_nn-2f-Source-2f-NNSupportFunctions

clean-tflm-2f-third_party-2f-cmsis_nn-2f-Source-2f-NNSupportFunctions:
	-$(RM) ./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_depthwise_conv_nt_t_padded_s8.cyclo ./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_depthwise_conv_nt_t_padded_s8.d ./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_depthwise_conv_nt_t_padded_s8.o ./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_depthwise_conv_nt_t_padded_s8.su ./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_depthwise_conv_nt_t_s16.cyclo ./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_depthwise_conv_nt_t_s16.d ./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_depthwise_conv_nt_t_s16.o ./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_depthwise_conv_nt_t_s16.su ./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_depthwise_conv_nt_t_s4.cyclo ./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_depthwise_conv_nt_t_s4.d ./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_depthwise_conv_nt_t_s4.o ./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_depthwise_conv_nt_t_s4.su ./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_depthwise_conv_nt_t_s8.cyclo ./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_depthwise_conv_nt_t_s8.d ./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_depthwise_conv_nt_t_s8.o ./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_depthwise_conv_nt_t_s8.su ./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_lstm_calculate_gate_s16.cyclo ./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_lstm_calculate_gate_s16.d ./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_lstm_calculate_gate_s16.o ./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_lstm_calculate_gate_s16.su ./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_lstm_calculate_gate_s8_s16.cyclo ./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_lstm_calculate_gate_s8_s16.d ./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_lstm_calculate_gate_s8_s16.o ./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_lstm_calculate_gate_s8_s16.su ./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_lstm_step_s16.cyclo ./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_lstm_step_s16.d ./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_lstm_step_s16.o ./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_lstm_step_s16.su ./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_lstm_step_s8.cyclo ./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_lstm_step_s8.d ./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_lstm_step_s8.o ./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_lstm_step_s8.su ./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_mat_mul_core_1x_s4.cyclo ./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_mat_mul_core_1x_s4.d ./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_mat_mul_core_1x_s4.o ./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_mat_mul_core_1x_s4.su ./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_mat_mul_core_1x_s8.cyclo ./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_mat_mul_core_1x_s8.d ./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_mat_mul_core_1x_s8.o ./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_mat_mul_core_1x_s8.su ./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_mat_mul_core_4x_s8.cyclo ./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_mat_mul_core_4x_s8.d ./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_mat_mul_core_4x_s8.o ./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_mat_mul_core_4x_s8.su ./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_mat_mult_nt_interleaved_t_even_s4.cyclo ./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_mat_mult_nt_interleaved_t_even_s4.d ./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_mat_mult_nt_interleaved_t_even_s4.o ./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_mat_mult_nt_interleaved_t_even_s4.su ./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_mat_mult_nt_t_s16.cyclo ./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_mat_mult_nt_t_s16.d ./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_mat_mult_nt_t_s16.o ./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_mat_mult_nt_t_s16.su ./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_mat_mult_nt_t_s4.cyclo ./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_mat_mult_nt_t_s4.d ./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_mat_mult_nt_t_s4.o ./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_mat_mult_nt_t_s4.su ./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_mat_mult_nt_t_s8.cyclo ./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_mat_mult_nt_t_s8.d ./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_mat_mult_nt_t_s8.o ./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_mat_mult_nt_t_s8.su ./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_mat_mult_nt_t_s8_s32.cyclo ./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_mat_mult_nt_t_s8_s32.d ./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_mat_mult_nt_t_s8_s32.o ./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_mat_mult_nt_t_s8_s32.su ./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_transpose_conv_row_s8_s32.cyclo ./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_transpose_conv_row_s8_s32.d ./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_transpose_conv_row_s8_s32.o ./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_transpose_conv_row_s8_s32.su ./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_vec_mat_mul_result_acc_s16.cyclo
	-$(RM) ./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_vec_mat_mul_result_acc_s16.d ./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_vec_mat_mul_result_acc_s16.o ./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_vec_mat_mul_result_acc_s16.su ./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_vec_mat_mul_result_acc_s8_s16.cyclo ./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_vec_mat_mul_result_acc_s8_s16.d ./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_vec_mat_mul_result_acc_s8_s16.o ./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_vec_mat_mul_result_acc_s8_s16.su ./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_vec_mat_mult_t_per_ch_s8.cyclo ./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_vec_mat_mult_t_per_ch_s8.d ./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_vec_mat_mult_t_per_ch_s8.o ./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_vec_mat_mult_t_per_ch_s8.su ./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_vec_mat_mult_t_s16.cyclo ./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_vec_mat_mult_t_s16.d ./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_vec_mat_mult_t_s16.o ./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_vec_mat_mult_t_s16.su ./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_vec_mat_mult_t_s16_s16.cyclo ./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_vec_mat_mult_t_s16_s16.d ./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_vec_mat_mult_t_s16_s16.o ./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_vec_mat_mult_t_s16_s16.su ./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_vec_mat_mult_t_s4.cyclo ./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_vec_mat_mult_t_s4.d ./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_vec_mat_mult_t_s4.o ./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_vec_mat_mult_t_s4.su ./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_vec_mat_mult_t_s8.cyclo ./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_vec_mat_mult_t_s8.d ./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_vec_mat_mult_t_s8.o ./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_vec_mat_mult_t_s8.su ./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_vec_mat_mult_t_svdf_s8.cyclo ./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_vec_mat_mult_t_svdf_s8.d ./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_vec_mat_mult_t_svdf_s8.o ./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_vec_mat_mult_t_svdf_s8.su ./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nntables.cyclo ./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nntables.d ./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nntables.o ./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nntables.su ./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_q7_to_q15_with_offset.cyclo ./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_q7_to_q15_with_offset.d ./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_q7_to_q15_with_offset.o ./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_q7_to_q15_with_offset.su ./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_s8_to_s16_unordered_with_offset.cyclo ./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_s8_to_s16_unordered_with_offset.d ./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_s8_to_s16_unordered_with_offset.o ./tflm/third_party/cmsis_nn/Source/NNSupportFunctions/arm_s8_to_s16_unordered_with_offset.su

.PHONY: clean-tflm-2f-third_party-2f-cmsis_nn-2f-Source-2f-NNSupportFunctions

