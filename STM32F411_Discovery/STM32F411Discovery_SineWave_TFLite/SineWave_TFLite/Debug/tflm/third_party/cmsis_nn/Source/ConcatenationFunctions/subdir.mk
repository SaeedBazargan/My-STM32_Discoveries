################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../tflm/third_party/cmsis_nn/Source/ConcatenationFunctions/arm_concatenation_s8_w.c \
../tflm/third_party/cmsis_nn/Source/ConcatenationFunctions/arm_concatenation_s8_x.c \
../tflm/third_party/cmsis_nn/Source/ConcatenationFunctions/arm_concatenation_s8_y.c \
../tflm/third_party/cmsis_nn/Source/ConcatenationFunctions/arm_concatenation_s8_z.c 

C_DEPS += \
./tflm/third_party/cmsis_nn/Source/ConcatenationFunctions/arm_concatenation_s8_w.d \
./tflm/third_party/cmsis_nn/Source/ConcatenationFunctions/arm_concatenation_s8_x.d \
./tflm/third_party/cmsis_nn/Source/ConcatenationFunctions/arm_concatenation_s8_y.d \
./tflm/third_party/cmsis_nn/Source/ConcatenationFunctions/arm_concatenation_s8_z.d 

OBJS += \
./tflm/third_party/cmsis_nn/Source/ConcatenationFunctions/arm_concatenation_s8_w.o \
./tflm/third_party/cmsis_nn/Source/ConcatenationFunctions/arm_concatenation_s8_x.o \
./tflm/third_party/cmsis_nn/Source/ConcatenationFunctions/arm_concatenation_s8_y.o \
./tflm/third_party/cmsis_nn/Source/ConcatenationFunctions/arm_concatenation_s8_z.o 


# Each subdirectory must supply rules for building sources it contributes
tflm/third_party/cmsis_nn/Source/ConcatenationFunctions/%.o tflm/third_party/cmsis_nn/Source/ConcatenationFunctions/%.su tflm/third_party/cmsis_nn/Source/ConcatenationFunctions/%.cyclo: ../tflm/third_party/cmsis_nn/Source/ConcatenationFunctions/%.c tflm/third_party/cmsis_nn/Source/ConcatenationFunctions/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tflm" -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tflm/tensorflow/lite" -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tflm/third_party/flatbuffers/include" -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tflm/third_party/gemmlowp" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-tflm-2f-third_party-2f-cmsis_nn-2f-Source-2f-ConcatenationFunctions

clean-tflm-2f-third_party-2f-cmsis_nn-2f-Source-2f-ConcatenationFunctions:
	-$(RM) ./tflm/third_party/cmsis_nn/Source/ConcatenationFunctions/arm_concatenation_s8_w.cyclo ./tflm/third_party/cmsis_nn/Source/ConcatenationFunctions/arm_concatenation_s8_w.d ./tflm/third_party/cmsis_nn/Source/ConcatenationFunctions/arm_concatenation_s8_w.o ./tflm/third_party/cmsis_nn/Source/ConcatenationFunctions/arm_concatenation_s8_w.su ./tflm/third_party/cmsis_nn/Source/ConcatenationFunctions/arm_concatenation_s8_x.cyclo ./tflm/third_party/cmsis_nn/Source/ConcatenationFunctions/arm_concatenation_s8_x.d ./tflm/third_party/cmsis_nn/Source/ConcatenationFunctions/arm_concatenation_s8_x.o ./tflm/third_party/cmsis_nn/Source/ConcatenationFunctions/arm_concatenation_s8_x.su ./tflm/third_party/cmsis_nn/Source/ConcatenationFunctions/arm_concatenation_s8_y.cyclo ./tflm/third_party/cmsis_nn/Source/ConcatenationFunctions/arm_concatenation_s8_y.d ./tflm/third_party/cmsis_nn/Source/ConcatenationFunctions/arm_concatenation_s8_y.o ./tflm/third_party/cmsis_nn/Source/ConcatenationFunctions/arm_concatenation_s8_y.su ./tflm/third_party/cmsis_nn/Source/ConcatenationFunctions/arm_concatenation_s8_z.cyclo ./tflm/third_party/cmsis_nn/Source/ConcatenationFunctions/arm_concatenation_s8_z.d ./tflm/third_party/cmsis_nn/Source/ConcatenationFunctions/arm_concatenation_s8_z.o ./tflm/third_party/cmsis_nn/Source/ConcatenationFunctions/arm_concatenation_s8_z.su

.PHONY: clean-tflm-2f-third_party-2f-cmsis_nn-2f-Source-2f-ConcatenationFunctions

