################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../tflm/signal/micro/kernels/delay.cc \
../tflm/signal/micro/kernels/energy.cc \
../tflm/signal/micro/kernels/fft_auto_scale_common.cc \
../tflm/signal/micro/kernels/fft_auto_scale_kernel.cc \
../tflm/signal/micro/kernels/filter_bank.cc \
../tflm/signal/micro/kernels/filter_bank_log.cc \
../tflm/signal/micro/kernels/filter_bank_spectral_subtraction.cc \
../tflm/signal/micro/kernels/filter_bank_square_root.cc \
../tflm/signal/micro/kernels/filter_bank_square_root_common.cc \
../tflm/signal/micro/kernels/framer.cc \
../tflm/signal/micro/kernels/irfft.cc \
../tflm/signal/micro/kernels/overlap_add.cc \
../tflm/signal/micro/kernels/pcan.cc \
../tflm/signal/micro/kernels/rfft.cc \
../tflm/signal/micro/kernels/stacker.cc \
../tflm/signal/micro/kernels/window.cc 

CC_DEPS += \
./tflm/signal/micro/kernels/delay.d \
./tflm/signal/micro/kernels/energy.d \
./tflm/signal/micro/kernels/fft_auto_scale_common.d \
./tflm/signal/micro/kernels/fft_auto_scale_kernel.d \
./tflm/signal/micro/kernels/filter_bank.d \
./tflm/signal/micro/kernels/filter_bank_log.d \
./tflm/signal/micro/kernels/filter_bank_spectral_subtraction.d \
./tflm/signal/micro/kernels/filter_bank_square_root.d \
./tflm/signal/micro/kernels/filter_bank_square_root_common.d \
./tflm/signal/micro/kernels/framer.d \
./tflm/signal/micro/kernels/irfft.d \
./tflm/signal/micro/kernels/overlap_add.d \
./tflm/signal/micro/kernels/pcan.d \
./tflm/signal/micro/kernels/rfft.d \
./tflm/signal/micro/kernels/stacker.d \
./tflm/signal/micro/kernels/window.d 

OBJS += \
./tflm/signal/micro/kernels/delay.o \
./tflm/signal/micro/kernels/energy.o \
./tflm/signal/micro/kernels/fft_auto_scale_common.o \
./tflm/signal/micro/kernels/fft_auto_scale_kernel.o \
./tflm/signal/micro/kernels/filter_bank.o \
./tflm/signal/micro/kernels/filter_bank_log.o \
./tflm/signal/micro/kernels/filter_bank_spectral_subtraction.o \
./tflm/signal/micro/kernels/filter_bank_square_root.o \
./tflm/signal/micro/kernels/filter_bank_square_root_common.o \
./tflm/signal/micro/kernels/framer.o \
./tflm/signal/micro/kernels/irfft.o \
./tflm/signal/micro/kernels/overlap_add.o \
./tflm/signal/micro/kernels/pcan.o \
./tflm/signal/micro/kernels/rfft.o \
./tflm/signal/micro/kernels/stacker.o \
./tflm/signal/micro/kernels/window.o 


# Each subdirectory must supply rules for building sources it contributes
tflm/signal/micro/kernels/%.o tflm/signal/micro/kernels/%.su tflm/signal/micro/kernels/%.cyclo: ../tflm/signal/micro/kernels/%.cc tflm/signal/micro/kernels/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tensorflow_lite" -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tensorflow_lite/third_party/flatbuffers/include" -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tensorflow_lite/third_party/gemmlowp" -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tensorflow_lite/third_party/ruy" -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tensorflow_lite/third_party/kissfft" -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tensorflow_lite/tensorflow/lite" -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tflm" -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tflm/tensorflow/lite" -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tflm/third_party/flatbuffers/include" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-tflm-2f-signal-2f-micro-2f-kernels

clean-tflm-2f-signal-2f-micro-2f-kernels:
	-$(RM) ./tflm/signal/micro/kernels/delay.cyclo ./tflm/signal/micro/kernels/delay.d ./tflm/signal/micro/kernels/delay.o ./tflm/signal/micro/kernels/delay.su ./tflm/signal/micro/kernels/energy.cyclo ./tflm/signal/micro/kernels/energy.d ./tflm/signal/micro/kernels/energy.o ./tflm/signal/micro/kernels/energy.su ./tflm/signal/micro/kernels/fft_auto_scale_common.cyclo ./tflm/signal/micro/kernels/fft_auto_scale_common.d ./tflm/signal/micro/kernels/fft_auto_scale_common.o ./tflm/signal/micro/kernels/fft_auto_scale_common.su ./tflm/signal/micro/kernels/fft_auto_scale_kernel.cyclo ./tflm/signal/micro/kernels/fft_auto_scale_kernel.d ./tflm/signal/micro/kernels/fft_auto_scale_kernel.o ./tflm/signal/micro/kernels/fft_auto_scale_kernel.su ./tflm/signal/micro/kernels/filter_bank.cyclo ./tflm/signal/micro/kernels/filter_bank.d ./tflm/signal/micro/kernels/filter_bank.o ./tflm/signal/micro/kernels/filter_bank.su ./tflm/signal/micro/kernels/filter_bank_log.cyclo ./tflm/signal/micro/kernels/filter_bank_log.d ./tflm/signal/micro/kernels/filter_bank_log.o ./tflm/signal/micro/kernels/filter_bank_log.su ./tflm/signal/micro/kernels/filter_bank_spectral_subtraction.cyclo ./tflm/signal/micro/kernels/filter_bank_spectral_subtraction.d ./tflm/signal/micro/kernels/filter_bank_spectral_subtraction.o ./tflm/signal/micro/kernels/filter_bank_spectral_subtraction.su ./tflm/signal/micro/kernels/filter_bank_square_root.cyclo ./tflm/signal/micro/kernels/filter_bank_square_root.d ./tflm/signal/micro/kernels/filter_bank_square_root.o ./tflm/signal/micro/kernels/filter_bank_square_root.su ./tflm/signal/micro/kernels/filter_bank_square_root_common.cyclo ./tflm/signal/micro/kernels/filter_bank_square_root_common.d ./tflm/signal/micro/kernels/filter_bank_square_root_common.o ./tflm/signal/micro/kernels/filter_bank_square_root_common.su ./tflm/signal/micro/kernels/framer.cyclo ./tflm/signal/micro/kernels/framer.d ./tflm/signal/micro/kernels/framer.o ./tflm/signal/micro/kernels/framer.su ./tflm/signal/micro/kernels/irfft.cyclo ./tflm/signal/micro/kernels/irfft.d ./tflm/signal/micro/kernels/irfft.o ./tflm/signal/micro/kernels/irfft.su ./tflm/signal/micro/kernels/overlap_add.cyclo ./tflm/signal/micro/kernels/overlap_add.d ./tflm/signal/micro/kernels/overlap_add.o ./tflm/signal/micro/kernels/overlap_add.su ./tflm/signal/micro/kernels/pcan.cyclo ./tflm/signal/micro/kernels/pcan.d ./tflm/signal/micro/kernels/pcan.o ./tflm/signal/micro/kernels/pcan.su ./tflm/signal/micro/kernels/rfft.cyclo ./tflm/signal/micro/kernels/rfft.d ./tflm/signal/micro/kernels/rfft.o ./tflm/signal/micro/kernels/rfft.su ./tflm/signal/micro/kernels/stacker.cyclo ./tflm/signal/micro/kernels/stacker.d ./tflm/signal/micro/kernels/stacker.o ./tflm/signal/micro/kernels/stacker.su ./tflm/signal/micro/kernels/window.cyclo ./tflm/signal/micro/kernels/window.d ./tflm/signal/micro/kernels/window.o ./tflm/signal/micro/kernels/window.su

.PHONY: clean-tflm-2f-signal-2f-micro-2f-kernels

