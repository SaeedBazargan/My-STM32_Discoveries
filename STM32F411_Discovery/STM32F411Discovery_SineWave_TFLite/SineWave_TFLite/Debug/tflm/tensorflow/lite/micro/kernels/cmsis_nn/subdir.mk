################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../tflm/tensorflow/lite/micro/kernels/cmsis_nn/add.cc \
../tflm/tensorflow/lite/micro/kernels/cmsis_nn/batch_matmul.cc \
../tflm/tensorflow/lite/micro/kernels/cmsis_nn/conv.cc \
../tflm/tensorflow/lite/micro/kernels/cmsis_nn/depthwise_conv.cc \
../tflm/tensorflow/lite/micro/kernels/cmsis_nn/fully_connected.cc \
../tflm/tensorflow/lite/micro/kernels/cmsis_nn/mul.cc \
../tflm/tensorflow/lite/micro/kernels/cmsis_nn/pooling.cc \
../tflm/tensorflow/lite/micro/kernels/cmsis_nn/softmax.cc \
../tflm/tensorflow/lite/micro/kernels/cmsis_nn/svdf.cc \
../tflm/tensorflow/lite/micro/kernels/cmsis_nn/transpose_conv.cc \
../tflm/tensorflow/lite/micro/kernels/cmsis_nn/unidirectional_sequence_lstm.cc 

CC_DEPS += \
./tflm/tensorflow/lite/micro/kernels/cmsis_nn/add.d \
./tflm/tensorflow/lite/micro/kernels/cmsis_nn/batch_matmul.d \
./tflm/tensorflow/lite/micro/kernels/cmsis_nn/conv.d \
./tflm/tensorflow/lite/micro/kernels/cmsis_nn/depthwise_conv.d \
./tflm/tensorflow/lite/micro/kernels/cmsis_nn/fully_connected.d \
./tflm/tensorflow/lite/micro/kernels/cmsis_nn/mul.d \
./tflm/tensorflow/lite/micro/kernels/cmsis_nn/pooling.d \
./tflm/tensorflow/lite/micro/kernels/cmsis_nn/softmax.d \
./tflm/tensorflow/lite/micro/kernels/cmsis_nn/svdf.d \
./tflm/tensorflow/lite/micro/kernels/cmsis_nn/transpose_conv.d \
./tflm/tensorflow/lite/micro/kernels/cmsis_nn/unidirectional_sequence_lstm.d 

OBJS += \
./tflm/tensorflow/lite/micro/kernels/cmsis_nn/add.o \
./tflm/tensorflow/lite/micro/kernels/cmsis_nn/batch_matmul.o \
./tflm/tensorflow/lite/micro/kernels/cmsis_nn/conv.o \
./tflm/tensorflow/lite/micro/kernels/cmsis_nn/depthwise_conv.o \
./tflm/tensorflow/lite/micro/kernels/cmsis_nn/fully_connected.o \
./tflm/tensorflow/lite/micro/kernels/cmsis_nn/mul.o \
./tflm/tensorflow/lite/micro/kernels/cmsis_nn/pooling.o \
./tflm/tensorflow/lite/micro/kernels/cmsis_nn/softmax.o \
./tflm/tensorflow/lite/micro/kernels/cmsis_nn/svdf.o \
./tflm/tensorflow/lite/micro/kernels/cmsis_nn/transpose_conv.o \
./tflm/tensorflow/lite/micro/kernels/cmsis_nn/unidirectional_sequence_lstm.o 


# Each subdirectory must supply rules for building sources it contributes
tflm/tensorflow/lite/micro/kernels/cmsis_nn/%.o tflm/tensorflow/lite/micro/kernels/cmsis_nn/%.su tflm/tensorflow/lite/micro/kernels/cmsis_nn/%.cyclo: ../tflm/tensorflow/lite/micro/kernels/cmsis_nn/%.cc tflm/tensorflow/lite/micro/kernels/cmsis_nn/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tensorflow_lite" -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tensorflow_lite/third_party/flatbuffers/include" -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tensorflow_lite/third_party/gemmlowp" -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tensorflow_lite/third_party/ruy" -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tensorflow_lite/third_party/kissfft" -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tensorflow_lite/tensorflow/lite" -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tflm" -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tflm/tensorflow/lite" -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tflm/third_party/flatbuffers/include" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-tflm-2f-tensorflow-2f-lite-2f-micro-2f-kernels-2f-cmsis_nn

clean-tflm-2f-tensorflow-2f-lite-2f-micro-2f-kernels-2f-cmsis_nn:
	-$(RM) ./tflm/tensorflow/lite/micro/kernels/cmsis_nn/add.cyclo ./tflm/tensorflow/lite/micro/kernels/cmsis_nn/add.d ./tflm/tensorflow/lite/micro/kernels/cmsis_nn/add.o ./tflm/tensorflow/lite/micro/kernels/cmsis_nn/add.su ./tflm/tensorflow/lite/micro/kernels/cmsis_nn/batch_matmul.cyclo ./tflm/tensorflow/lite/micro/kernels/cmsis_nn/batch_matmul.d ./tflm/tensorflow/lite/micro/kernels/cmsis_nn/batch_matmul.o ./tflm/tensorflow/lite/micro/kernels/cmsis_nn/batch_matmul.su ./tflm/tensorflow/lite/micro/kernels/cmsis_nn/conv.cyclo ./tflm/tensorflow/lite/micro/kernels/cmsis_nn/conv.d ./tflm/tensorflow/lite/micro/kernels/cmsis_nn/conv.o ./tflm/tensorflow/lite/micro/kernels/cmsis_nn/conv.su ./tflm/tensorflow/lite/micro/kernels/cmsis_nn/depthwise_conv.cyclo ./tflm/tensorflow/lite/micro/kernels/cmsis_nn/depthwise_conv.d ./tflm/tensorflow/lite/micro/kernels/cmsis_nn/depthwise_conv.o ./tflm/tensorflow/lite/micro/kernels/cmsis_nn/depthwise_conv.su ./tflm/tensorflow/lite/micro/kernels/cmsis_nn/fully_connected.cyclo ./tflm/tensorflow/lite/micro/kernels/cmsis_nn/fully_connected.d ./tflm/tensorflow/lite/micro/kernels/cmsis_nn/fully_connected.o ./tflm/tensorflow/lite/micro/kernels/cmsis_nn/fully_connected.su ./tflm/tensorflow/lite/micro/kernels/cmsis_nn/mul.cyclo ./tflm/tensorflow/lite/micro/kernels/cmsis_nn/mul.d ./tflm/tensorflow/lite/micro/kernels/cmsis_nn/mul.o ./tflm/tensorflow/lite/micro/kernels/cmsis_nn/mul.su ./tflm/tensorflow/lite/micro/kernels/cmsis_nn/pooling.cyclo ./tflm/tensorflow/lite/micro/kernels/cmsis_nn/pooling.d ./tflm/tensorflow/lite/micro/kernels/cmsis_nn/pooling.o ./tflm/tensorflow/lite/micro/kernels/cmsis_nn/pooling.su ./tflm/tensorflow/lite/micro/kernels/cmsis_nn/softmax.cyclo ./tflm/tensorflow/lite/micro/kernels/cmsis_nn/softmax.d ./tflm/tensorflow/lite/micro/kernels/cmsis_nn/softmax.o ./tflm/tensorflow/lite/micro/kernels/cmsis_nn/softmax.su ./tflm/tensorflow/lite/micro/kernels/cmsis_nn/svdf.cyclo ./tflm/tensorflow/lite/micro/kernels/cmsis_nn/svdf.d ./tflm/tensorflow/lite/micro/kernels/cmsis_nn/svdf.o ./tflm/tensorflow/lite/micro/kernels/cmsis_nn/svdf.su ./tflm/tensorflow/lite/micro/kernels/cmsis_nn/transpose_conv.cyclo ./tflm/tensorflow/lite/micro/kernels/cmsis_nn/transpose_conv.d ./tflm/tensorflow/lite/micro/kernels/cmsis_nn/transpose_conv.o ./tflm/tensorflow/lite/micro/kernels/cmsis_nn/transpose_conv.su ./tflm/tensorflow/lite/micro/kernels/cmsis_nn/unidirectional_sequence_lstm.cyclo ./tflm/tensorflow/lite/micro/kernels/cmsis_nn/unidirectional_sequence_lstm.d ./tflm/tensorflow/lite/micro/kernels/cmsis_nn/unidirectional_sequence_lstm.o ./tflm/tensorflow/lite/micro/kernels/cmsis_nn/unidirectional_sequence_lstm.su

.PHONY: clean-tflm-2f-tensorflow-2f-lite-2f-micro-2f-kernels-2f-cmsis_nn

