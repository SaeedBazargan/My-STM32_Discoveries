################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../tensorflow_lite/signal/src/circular_buffer.cc \
../tensorflow_lite/signal/src/energy.cc \
../tensorflow_lite/signal/src/fft_auto_scale.cc \
../tensorflow_lite/signal/src/filter_bank.cc \
../tensorflow_lite/signal/src/filter_bank_log.cc \
../tensorflow_lite/signal/src/filter_bank_spectral_subtraction.cc \
../tensorflow_lite/signal/src/filter_bank_square_root.cc \
../tensorflow_lite/signal/src/irfft_float.cc \
../tensorflow_lite/signal/src/irfft_int16.cc \
../tensorflow_lite/signal/src/irfft_int32.cc \
../tensorflow_lite/signal/src/log.cc \
../tensorflow_lite/signal/src/max_abs.cc \
../tensorflow_lite/signal/src/msb_32.cc \
../tensorflow_lite/signal/src/msb_64.cc \
../tensorflow_lite/signal/src/overlap_add.cc \
../tensorflow_lite/signal/src/pcan_argc_fixed.cc \
../tensorflow_lite/signal/src/rfft_float.cc \
../tensorflow_lite/signal/src/rfft_int16.cc \
../tensorflow_lite/signal/src/rfft_int32.cc \
../tensorflow_lite/signal/src/square_root_32.cc \
../tensorflow_lite/signal/src/square_root_64.cc \
../tensorflow_lite/signal/src/window.cc 

CC_DEPS += \
./tensorflow_lite/signal/src/circular_buffer.d \
./tensorflow_lite/signal/src/energy.d \
./tensorflow_lite/signal/src/fft_auto_scale.d \
./tensorflow_lite/signal/src/filter_bank.d \
./tensorflow_lite/signal/src/filter_bank_log.d \
./tensorflow_lite/signal/src/filter_bank_spectral_subtraction.d \
./tensorflow_lite/signal/src/filter_bank_square_root.d \
./tensorflow_lite/signal/src/irfft_float.d \
./tensorflow_lite/signal/src/irfft_int16.d \
./tensorflow_lite/signal/src/irfft_int32.d \
./tensorflow_lite/signal/src/log.d \
./tensorflow_lite/signal/src/max_abs.d \
./tensorflow_lite/signal/src/msb_32.d \
./tensorflow_lite/signal/src/msb_64.d \
./tensorflow_lite/signal/src/overlap_add.d \
./tensorflow_lite/signal/src/pcan_argc_fixed.d \
./tensorflow_lite/signal/src/rfft_float.d \
./tensorflow_lite/signal/src/rfft_int16.d \
./tensorflow_lite/signal/src/rfft_int32.d \
./tensorflow_lite/signal/src/square_root_32.d \
./tensorflow_lite/signal/src/square_root_64.d \
./tensorflow_lite/signal/src/window.d 

OBJS += \
./tensorflow_lite/signal/src/circular_buffer.o \
./tensorflow_lite/signal/src/energy.o \
./tensorflow_lite/signal/src/fft_auto_scale.o \
./tensorflow_lite/signal/src/filter_bank.o \
./tensorflow_lite/signal/src/filter_bank_log.o \
./tensorflow_lite/signal/src/filter_bank_spectral_subtraction.o \
./tensorflow_lite/signal/src/filter_bank_square_root.o \
./tensorflow_lite/signal/src/irfft_float.o \
./tensorflow_lite/signal/src/irfft_int16.o \
./tensorflow_lite/signal/src/irfft_int32.o \
./tensorflow_lite/signal/src/log.o \
./tensorflow_lite/signal/src/max_abs.o \
./tensorflow_lite/signal/src/msb_32.o \
./tensorflow_lite/signal/src/msb_64.o \
./tensorflow_lite/signal/src/overlap_add.o \
./tensorflow_lite/signal/src/pcan_argc_fixed.o \
./tensorflow_lite/signal/src/rfft_float.o \
./tensorflow_lite/signal/src/rfft_int16.o \
./tensorflow_lite/signal/src/rfft_int32.o \
./tensorflow_lite/signal/src/square_root_32.o \
./tensorflow_lite/signal/src/square_root_64.o \
./tensorflow_lite/signal/src/window.o 


# Each subdirectory must supply rules for building sources it contributes
tensorflow_lite/signal/src/%.o tensorflow_lite/signal/src/%.su tensorflow_lite/signal/src/%.cyclo: ../tensorflow_lite/signal/src/%.cc tensorflow_lite/signal/src/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tensorflow_lite" -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tensorflow_lite/third_party/flatbuffers/include" -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tensorflow_lite/third_party/gemmlowp" -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tensorflow_lite/third_party/ruy" -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tensorflow_lite/third_party/kissfft" -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tensorflow_lite/tensorflow/lite" -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tensorflow_lite/signal" -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tensorflow_lite/signal/src" -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/Lib" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-tensorflow_lite-2f-signal-2f-src

clean-tensorflow_lite-2f-signal-2f-src:
	-$(RM) ./tensorflow_lite/signal/src/circular_buffer.cyclo ./tensorflow_lite/signal/src/circular_buffer.d ./tensorflow_lite/signal/src/circular_buffer.o ./tensorflow_lite/signal/src/circular_buffer.su ./tensorflow_lite/signal/src/energy.cyclo ./tensorflow_lite/signal/src/energy.d ./tensorflow_lite/signal/src/energy.o ./tensorflow_lite/signal/src/energy.su ./tensorflow_lite/signal/src/fft_auto_scale.cyclo ./tensorflow_lite/signal/src/fft_auto_scale.d ./tensorflow_lite/signal/src/fft_auto_scale.o ./tensorflow_lite/signal/src/fft_auto_scale.su ./tensorflow_lite/signal/src/filter_bank.cyclo ./tensorflow_lite/signal/src/filter_bank.d ./tensorflow_lite/signal/src/filter_bank.o ./tensorflow_lite/signal/src/filter_bank.su ./tensorflow_lite/signal/src/filter_bank_log.cyclo ./tensorflow_lite/signal/src/filter_bank_log.d ./tensorflow_lite/signal/src/filter_bank_log.o ./tensorflow_lite/signal/src/filter_bank_log.su ./tensorflow_lite/signal/src/filter_bank_spectral_subtraction.cyclo ./tensorflow_lite/signal/src/filter_bank_spectral_subtraction.d ./tensorflow_lite/signal/src/filter_bank_spectral_subtraction.o ./tensorflow_lite/signal/src/filter_bank_spectral_subtraction.su ./tensorflow_lite/signal/src/filter_bank_square_root.cyclo ./tensorflow_lite/signal/src/filter_bank_square_root.d ./tensorflow_lite/signal/src/filter_bank_square_root.o ./tensorflow_lite/signal/src/filter_bank_square_root.su ./tensorflow_lite/signal/src/irfft_float.cyclo ./tensorflow_lite/signal/src/irfft_float.d ./tensorflow_lite/signal/src/irfft_float.o ./tensorflow_lite/signal/src/irfft_float.su ./tensorflow_lite/signal/src/irfft_int16.cyclo ./tensorflow_lite/signal/src/irfft_int16.d ./tensorflow_lite/signal/src/irfft_int16.o ./tensorflow_lite/signal/src/irfft_int16.su ./tensorflow_lite/signal/src/irfft_int32.cyclo ./tensorflow_lite/signal/src/irfft_int32.d ./tensorflow_lite/signal/src/irfft_int32.o ./tensorflow_lite/signal/src/irfft_int32.su ./tensorflow_lite/signal/src/log.cyclo ./tensorflow_lite/signal/src/log.d ./tensorflow_lite/signal/src/log.o ./tensorflow_lite/signal/src/log.su ./tensorflow_lite/signal/src/max_abs.cyclo ./tensorflow_lite/signal/src/max_abs.d ./tensorflow_lite/signal/src/max_abs.o ./tensorflow_lite/signal/src/max_abs.su ./tensorflow_lite/signal/src/msb_32.cyclo ./tensorflow_lite/signal/src/msb_32.d ./tensorflow_lite/signal/src/msb_32.o ./tensorflow_lite/signal/src/msb_32.su ./tensorflow_lite/signal/src/msb_64.cyclo ./tensorflow_lite/signal/src/msb_64.d ./tensorflow_lite/signal/src/msb_64.o ./tensorflow_lite/signal/src/msb_64.su ./tensorflow_lite/signal/src/overlap_add.cyclo ./tensorflow_lite/signal/src/overlap_add.d ./tensorflow_lite/signal/src/overlap_add.o ./tensorflow_lite/signal/src/overlap_add.su ./tensorflow_lite/signal/src/pcan_argc_fixed.cyclo ./tensorflow_lite/signal/src/pcan_argc_fixed.d ./tensorflow_lite/signal/src/pcan_argc_fixed.o ./tensorflow_lite/signal/src/pcan_argc_fixed.su ./tensorflow_lite/signal/src/rfft_float.cyclo ./tensorflow_lite/signal/src/rfft_float.d ./tensorflow_lite/signal/src/rfft_float.o ./tensorflow_lite/signal/src/rfft_float.su ./tensorflow_lite/signal/src/rfft_int16.cyclo ./tensorflow_lite/signal/src/rfft_int16.d ./tensorflow_lite/signal/src/rfft_int16.o ./tensorflow_lite/signal/src/rfft_int16.su ./tensorflow_lite/signal/src/rfft_int32.cyclo ./tensorflow_lite/signal/src/rfft_int32.d ./tensorflow_lite/signal/src/rfft_int32.o ./tensorflow_lite/signal/src/rfft_int32.su ./tensorflow_lite/signal/src/square_root_32.cyclo ./tensorflow_lite/signal/src/square_root_32.d ./tensorflow_lite/signal/src/square_root_32.o ./tensorflow_lite/signal/src/square_root_32.su ./tensorflow_lite/signal/src/square_root_64.cyclo ./tensorflow_lite/signal/src/square_root_64.d ./tensorflow_lite/signal/src/square_root_64.o ./tensorflow_lite/signal/src/square_root_64.su ./tensorflow_lite/signal/src/window.cyclo ./tensorflow_lite/signal/src/window.d ./tensorflow_lite/signal/src/window.o ./tensorflow_lite/signal/src/window.su

.PHONY: clean-tensorflow_lite-2f-signal-2f-src

