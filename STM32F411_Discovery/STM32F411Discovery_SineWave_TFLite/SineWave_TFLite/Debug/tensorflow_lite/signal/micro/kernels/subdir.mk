################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../tensorflow_lite/signal/micro/kernels/delay.cc \
../tensorflow_lite/signal/micro/kernels/energy.cc \
../tensorflow_lite/signal/micro/kernels/fft_auto_scale_common.cc \
../tensorflow_lite/signal/micro/kernels/fft_auto_scale_kernel.cc \
../tensorflow_lite/signal/micro/kernels/filter_bank.cc \
../tensorflow_lite/signal/micro/kernels/filter_bank_log.cc \
../tensorflow_lite/signal/micro/kernels/filter_bank_spectral_subtraction.cc \
../tensorflow_lite/signal/micro/kernels/filter_bank_square_root.cc \
../tensorflow_lite/signal/micro/kernels/filter_bank_square_root_common.cc \
../tensorflow_lite/signal/micro/kernels/framer.cc \
../tensorflow_lite/signal/micro/kernels/irfft.cc \
../tensorflow_lite/signal/micro/kernels/overlap_add.cc \
../tensorflow_lite/signal/micro/kernels/pcan.cc \
../tensorflow_lite/signal/micro/kernels/rfft.cc \
../tensorflow_lite/signal/micro/kernels/stacker.cc \
../tensorflow_lite/signal/micro/kernels/window.cc 

CC_DEPS += \
./tensorflow_lite/signal/micro/kernels/delay.d \
./tensorflow_lite/signal/micro/kernels/energy.d \
./tensorflow_lite/signal/micro/kernels/fft_auto_scale_common.d \
./tensorflow_lite/signal/micro/kernels/fft_auto_scale_kernel.d \
./tensorflow_lite/signal/micro/kernels/filter_bank.d \
./tensorflow_lite/signal/micro/kernels/filter_bank_log.d \
./tensorflow_lite/signal/micro/kernels/filter_bank_spectral_subtraction.d \
./tensorflow_lite/signal/micro/kernels/filter_bank_square_root.d \
./tensorflow_lite/signal/micro/kernels/filter_bank_square_root_common.d \
./tensorflow_lite/signal/micro/kernels/framer.d \
./tensorflow_lite/signal/micro/kernels/irfft.d \
./tensorflow_lite/signal/micro/kernels/overlap_add.d \
./tensorflow_lite/signal/micro/kernels/pcan.d \
./tensorflow_lite/signal/micro/kernels/rfft.d \
./tensorflow_lite/signal/micro/kernels/stacker.d \
./tensorflow_lite/signal/micro/kernels/window.d 

OBJS += \
./tensorflow_lite/signal/micro/kernels/delay.o \
./tensorflow_lite/signal/micro/kernels/energy.o \
./tensorflow_lite/signal/micro/kernels/fft_auto_scale_common.o \
./tensorflow_lite/signal/micro/kernels/fft_auto_scale_kernel.o \
./tensorflow_lite/signal/micro/kernels/filter_bank.o \
./tensorflow_lite/signal/micro/kernels/filter_bank_log.o \
./tensorflow_lite/signal/micro/kernels/filter_bank_spectral_subtraction.o \
./tensorflow_lite/signal/micro/kernels/filter_bank_square_root.o \
./tensorflow_lite/signal/micro/kernels/filter_bank_square_root_common.o \
./tensorflow_lite/signal/micro/kernels/framer.o \
./tensorflow_lite/signal/micro/kernels/irfft.o \
./tensorflow_lite/signal/micro/kernels/overlap_add.o \
./tensorflow_lite/signal/micro/kernels/pcan.o \
./tensorflow_lite/signal/micro/kernels/rfft.o \
./tensorflow_lite/signal/micro/kernels/stacker.o \
./tensorflow_lite/signal/micro/kernels/window.o 


# Each subdirectory must supply rules for building sources it contributes
tensorflow_lite/signal/micro/kernels/%.o tensorflow_lite/signal/micro/kernels/%.su tensorflow_lite/signal/micro/kernels/%.cyclo: ../tensorflow_lite/signal/micro/kernels/%.cc tensorflow_lite/signal/micro/kernels/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tensorflow_lite" -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tensorflow_lite/third_party/flatbuffers/include" -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tensorflow_lite/third_party/gemmlowp" -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tensorflow_lite/third_party/ruy" -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tensorflow_lite/third_party/kissfft" -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tensorflow_lite/tensorflow/lite" -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tensorflow_lite/signal" -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tensorflow_lite/signal/src" -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/Lib" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-tensorflow_lite-2f-signal-2f-micro-2f-kernels

clean-tensorflow_lite-2f-signal-2f-micro-2f-kernels:
	-$(RM) ./tensorflow_lite/signal/micro/kernels/delay.cyclo ./tensorflow_lite/signal/micro/kernels/delay.d ./tensorflow_lite/signal/micro/kernels/delay.o ./tensorflow_lite/signal/micro/kernels/delay.su ./tensorflow_lite/signal/micro/kernels/energy.cyclo ./tensorflow_lite/signal/micro/kernels/energy.d ./tensorflow_lite/signal/micro/kernels/energy.o ./tensorflow_lite/signal/micro/kernels/energy.su ./tensorflow_lite/signal/micro/kernels/fft_auto_scale_common.cyclo ./tensorflow_lite/signal/micro/kernels/fft_auto_scale_common.d ./tensorflow_lite/signal/micro/kernels/fft_auto_scale_common.o ./tensorflow_lite/signal/micro/kernels/fft_auto_scale_common.su ./tensorflow_lite/signal/micro/kernels/fft_auto_scale_kernel.cyclo ./tensorflow_lite/signal/micro/kernels/fft_auto_scale_kernel.d ./tensorflow_lite/signal/micro/kernels/fft_auto_scale_kernel.o ./tensorflow_lite/signal/micro/kernels/fft_auto_scale_kernel.su ./tensorflow_lite/signal/micro/kernels/filter_bank.cyclo ./tensorflow_lite/signal/micro/kernels/filter_bank.d ./tensorflow_lite/signal/micro/kernels/filter_bank.o ./tensorflow_lite/signal/micro/kernels/filter_bank.su ./tensorflow_lite/signal/micro/kernels/filter_bank_log.cyclo ./tensorflow_lite/signal/micro/kernels/filter_bank_log.d ./tensorflow_lite/signal/micro/kernels/filter_bank_log.o ./tensorflow_lite/signal/micro/kernels/filter_bank_log.su ./tensorflow_lite/signal/micro/kernels/filter_bank_spectral_subtraction.cyclo ./tensorflow_lite/signal/micro/kernels/filter_bank_spectral_subtraction.d ./tensorflow_lite/signal/micro/kernels/filter_bank_spectral_subtraction.o ./tensorflow_lite/signal/micro/kernels/filter_bank_spectral_subtraction.su ./tensorflow_lite/signal/micro/kernels/filter_bank_square_root.cyclo ./tensorflow_lite/signal/micro/kernels/filter_bank_square_root.d ./tensorflow_lite/signal/micro/kernels/filter_bank_square_root.o ./tensorflow_lite/signal/micro/kernels/filter_bank_square_root.su ./tensorflow_lite/signal/micro/kernels/filter_bank_square_root_common.cyclo ./tensorflow_lite/signal/micro/kernels/filter_bank_square_root_common.d ./tensorflow_lite/signal/micro/kernels/filter_bank_square_root_common.o ./tensorflow_lite/signal/micro/kernels/filter_bank_square_root_common.su ./tensorflow_lite/signal/micro/kernels/framer.cyclo ./tensorflow_lite/signal/micro/kernels/framer.d ./tensorflow_lite/signal/micro/kernels/framer.o ./tensorflow_lite/signal/micro/kernels/framer.su ./tensorflow_lite/signal/micro/kernels/irfft.cyclo ./tensorflow_lite/signal/micro/kernels/irfft.d ./tensorflow_lite/signal/micro/kernels/irfft.o ./tensorflow_lite/signal/micro/kernels/irfft.su ./tensorflow_lite/signal/micro/kernels/overlap_add.cyclo ./tensorflow_lite/signal/micro/kernels/overlap_add.d ./tensorflow_lite/signal/micro/kernels/overlap_add.o ./tensorflow_lite/signal/micro/kernels/overlap_add.su ./tensorflow_lite/signal/micro/kernels/pcan.cyclo ./tensorflow_lite/signal/micro/kernels/pcan.d ./tensorflow_lite/signal/micro/kernels/pcan.o ./tensorflow_lite/signal/micro/kernels/pcan.su ./tensorflow_lite/signal/micro/kernels/rfft.cyclo ./tensorflow_lite/signal/micro/kernels/rfft.d ./tensorflow_lite/signal/micro/kernels/rfft.o ./tensorflow_lite/signal/micro/kernels/rfft.su ./tensorflow_lite/signal/micro/kernels/stacker.cyclo ./tensorflow_lite/signal/micro/kernels/stacker.d ./tensorflow_lite/signal/micro/kernels/stacker.o ./tensorflow_lite/signal/micro/kernels/stacker.su ./tensorflow_lite/signal/micro/kernels/window.cyclo ./tensorflow_lite/signal/micro/kernels/window.d ./tensorflow_lite/signal/micro/kernels/window.o ./tensorflow_lite/signal/micro/kernels/window.su

.PHONY: clean-tensorflow_lite-2f-signal-2f-micro-2f-kernels

