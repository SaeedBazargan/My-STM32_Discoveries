################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../tflm/signal/src/circular_buffer.cc \
../tflm/signal/src/energy.cc \
../tflm/signal/src/fft_auto_scale.cc \
../tflm/signal/src/filter_bank.cc \
../tflm/signal/src/filter_bank_log.cc \
../tflm/signal/src/filter_bank_spectral_subtraction.cc \
../tflm/signal/src/filter_bank_square_root.cc \
../tflm/signal/src/irfft_float.cc \
../tflm/signal/src/irfft_int16.cc \
../tflm/signal/src/irfft_int32.cc \
../tflm/signal/src/log.cc \
../tflm/signal/src/max_abs.cc \
../tflm/signal/src/msb_32.cc \
../tflm/signal/src/msb_64.cc \
../tflm/signal/src/overlap_add.cc \
../tflm/signal/src/pcan_argc_fixed.cc \
../tflm/signal/src/rfft_float.cc \
../tflm/signal/src/rfft_int16.cc \
../tflm/signal/src/rfft_int32.cc \
../tflm/signal/src/square_root_32.cc \
../tflm/signal/src/square_root_64.cc \
../tflm/signal/src/window.cc 

CC_DEPS += \
./tflm/signal/src/circular_buffer.d \
./tflm/signal/src/energy.d \
./tflm/signal/src/fft_auto_scale.d \
./tflm/signal/src/filter_bank.d \
./tflm/signal/src/filter_bank_log.d \
./tflm/signal/src/filter_bank_spectral_subtraction.d \
./tflm/signal/src/filter_bank_square_root.d \
./tflm/signal/src/irfft_float.d \
./tflm/signal/src/irfft_int16.d \
./tflm/signal/src/irfft_int32.d \
./tflm/signal/src/log.d \
./tflm/signal/src/max_abs.d \
./tflm/signal/src/msb_32.d \
./tflm/signal/src/msb_64.d \
./tflm/signal/src/overlap_add.d \
./tflm/signal/src/pcan_argc_fixed.d \
./tflm/signal/src/rfft_float.d \
./tflm/signal/src/rfft_int16.d \
./tflm/signal/src/rfft_int32.d \
./tflm/signal/src/square_root_32.d \
./tflm/signal/src/square_root_64.d \
./tflm/signal/src/window.d 

OBJS += \
./tflm/signal/src/circular_buffer.o \
./tflm/signal/src/energy.o \
./tflm/signal/src/fft_auto_scale.o \
./tflm/signal/src/filter_bank.o \
./tflm/signal/src/filter_bank_log.o \
./tflm/signal/src/filter_bank_spectral_subtraction.o \
./tflm/signal/src/filter_bank_square_root.o \
./tflm/signal/src/irfft_float.o \
./tflm/signal/src/irfft_int16.o \
./tflm/signal/src/irfft_int32.o \
./tflm/signal/src/log.o \
./tflm/signal/src/max_abs.o \
./tflm/signal/src/msb_32.o \
./tflm/signal/src/msb_64.o \
./tflm/signal/src/overlap_add.o \
./tflm/signal/src/pcan_argc_fixed.o \
./tflm/signal/src/rfft_float.o \
./tflm/signal/src/rfft_int16.o \
./tflm/signal/src/rfft_int32.o \
./tflm/signal/src/square_root_32.o \
./tflm/signal/src/square_root_64.o \
./tflm/signal/src/window.o 


# Each subdirectory must supply rules for building sources it contributes
tflm/signal/src/%.o tflm/signal/src/%.su tflm/signal/src/%.cyclo: ../tflm/signal/src/%.cc tflm/signal/src/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tensorflow_lite" -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tensorflow_lite/third_party/flatbuffers/include" -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tensorflow_lite/third_party/gemmlowp" -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tensorflow_lite/third_party/ruy" -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tensorflow_lite/third_party/kissfft" -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tensorflow_lite/tensorflow/lite" -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tflm" -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tflm/tensorflow/lite" -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tflm/third_party/flatbuffers/include" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-tflm-2f-signal-2f-src

clean-tflm-2f-signal-2f-src:
	-$(RM) ./tflm/signal/src/circular_buffer.cyclo ./tflm/signal/src/circular_buffer.d ./tflm/signal/src/circular_buffer.o ./tflm/signal/src/circular_buffer.su ./tflm/signal/src/energy.cyclo ./tflm/signal/src/energy.d ./tflm/signal/src/energy.o ./tflm/signal/src/energy.su ./tflm/signal/src/fft_auto_scale.cyclo ./tflm/signal/src/fft_auto_scale.d ./tflm/signal/src/fft_auto_scale.o ./tflm/signal/src/fft_auto_scale.su ./tflm/signal/src/filter_bank.cyclo ./tflm/signal/src/filter_bank.d ./tflm/signal/src/filter_bank.o ./tflm/signal/src/filter_bank.su ./tflm/signal/src/filter_bank_log.cyclo ./tflm/signal/src/filter_bank_log.d ./tflm/signal/src/filter_bank_log.o ./tflm/signal/src/filter_bank_log.su ./tflm/signal/src/filter_bank_spectral_subtraction.cyclo ./tflm/signal/src/filter_bank_spectral_subtraction.d ./tflm/signal/src/filter_bank_spectral_subtraction.o ./tflm/signal/src/filter_bank_spectral_subtraction.su ./tflm/signal/src/filter_bank_square_root.cyclo ./tflm/signal/src/filter_bank_square_root.d ./tflm/signal/src/filter_bank_square_root.o ./tflm/signal/src/filter_bank_square_root.su ./tflm/signal/src/irfft_float.cyclo ./tflm/signal/src/irfft_float.d ./tflm/signal/src/irfft_float.o ./tflm/signal/src/irfft_float.su ./tflm/signal/src/irfft_int16.cyclo ./tflm/signal/src/irfft_int16.d ./tflm/signal/src/irfft_int16.o ./tflm/signal/src/irfft_int16.su ./tflm/signal/src/irfft_int32.cyclo ./tflm/signal/src/irfft_int32.d ./tflm/signal/src/irfft_int32.o ./tflm/signal/src/irfft_int32.su ./tflm/signal/src/log.cyclo ./tflm/signal/src/log.d ./tflm/signal/src/log.o ./tflm/signal/src/log.su ./tflm/signal/src/max_abs.cyclo ./tflm/signal/src/max_abs.d ./tflm/signal/src/max_abs.o ./tflm/signal/src/max_abs.su ./tflm/signal/src/msb_32.cyclo ./tflm/signal/src/msb_32.d ./tflm/signal/src/msb_32.o ./tflm/signal/src/msb_32.su ./tflm/signal/src/msb_64.cyclo ./tflm/signal/src/msb_64.d ./tflm/signal/src/msb_64.o ./tflm/signal/src/msb_64.su ./tflm/signal/src/overlap_add.cyclo ./tflm/signal/src/overlap_add.d ./tflm/signal/src/overlap_add.o ./tflm/signal/src/overlap_add.su ./tflm/signal/src/pcan_argc_fixed.cyclo ./tflm/signal/src/pcan_argc_fixed.d ./tflm/signal/src/pcan_argc_fixed.o ./tflm/signal/src/pcan_argc_fixed.su ./tflm/signal/src/rfft_float.cyclo ./tflm/signal/src/rfft_float.d ./tflm/signal/src/rfft_float.o ./tflm/signal/src/rfft_float.su ./tflm/signal/src/rfft_int16.cyclo ./tflm/signal/src/rfft_int16.d ./tflm/signal/src/rfft_int16.o ./tflm/signal/src/rfft_int16.su ./tflm/signal/src/rfft_int32.cyclo ./tflm/signal/src/rfft_int32.d ./tflm/signal/src/rfft_int32.o ./tflm/signal/src/rfft_int32.su ./tflm/signal/src/square_root_32.cyclo ./tflm/signal/src/square_root_32.d ./tflm/signal/src/square_root_32.o ./tflm/signal/src/square_root_32.su ./tflm/signal/src/square_root_64.cyclo ./tflm/signal/src/square_root_64.d ./tflm/signal/src/square_root_64.o ./tflm/signal/src/square_root_64.su ./tflm/signal/src/window.cyclo ./tflm/signal/src/window.d ./tflm/signal/src/window.o ./tflm/signal/src/window.su

.PHONY: clean-tflm-2f-signal-2f-src

