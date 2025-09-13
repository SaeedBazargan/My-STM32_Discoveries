################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../tflm/tensorflow/lite/kernels/internal/common.cc \
../tflm/tensorflow/lite/kernels/internal/portable_tensor_utils.cc \
../tflm/tensorflow/lite/kernels/internal/quantization_util.cc \
../tflm/tensorflow/lite/kernels/internal/runtime_shape.cc \
../tflm/tensorflow/lite/kernels/internal/tensor_ctypes.cc \
../tflm/tensorflow/lite/kernels/internal/tensor_utils.cc 

CC_DEPS += \
./tflm/tensorflow/lite/kernels/internal/common.d \
./tflm/tensorflow/lite/kernels/internal/portable_tensor_utils.d \
./tflm/tensorflow/lite/kernels/internal/quantization_util.d \
./tflm/tensorflow/lite/kernels/internal/runtime_shape.d \
./tflm/tensorflow/lite/kernels/internal/tensor_ctypes.d \
./tflm/tensorflow/lite/kernels/internal/tensor_utils.d 

OBJS += \
./tflm/tensorflow/lite/kernels/internal/common.o \
./tflm/tensorflow/lite/kernels/internal/portable_tensor_utils.o \
./tflm/tensorflow/lite/kernels/internal/quantization_util.o \
./tflm/tensorflow/lite/kernels/internal/runtime_shape.o \
./tflm/tensorflow/lite/kernels/internal/tensor_ctypes.o \
./tflm/tensorflow/lite/kernels/internal/tensor_utils.o 


# Each subdirectory must supply rules for building sources it contributes
tflm/tensorflow/lite/kernels/internal/%.o tflm/tensorflow/lite/kernels/internal/%.su tflm/tensorflow/lite/kernels/internal/%.cyclo: ../tflm/tensorflow/lite/kernels/internal/%.cc tflm/tensorflow/lite/kernels/internal/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tensorflow_lite" -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tensorflow_lite/third_party/flatbuffers/include" -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tensorflow_lite/third_party/gemmlowp" -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tensorflow_lite/third_party/ruy" -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tensorflow_lite/third_party/kissfft" -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tensorflow_lite/tensorflow/lite" -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tflm" -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tflm/tensorflow/lite" -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tflm/third_party/flatbuffers/include" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-tflm-2f-tensorflow-2f-lite-2f-kernels-2f-internal

clean-tflm-2f-tensorflow-2f-lite-2f-kernels-2f-internal:
	-$(RM) ./tflm/tensorflow/lite/kernels/internal/common.cyclo ./tflm/tensorflow/lite/kernels/internal/common.d ./tflm/tensorflow/lite/kernels/internal/common.o ./tflm/tensorflow/lite/kernels/internal/common.su ./tflm/tensorflow/lite/kernels/internal/portable_tensor_utils.cyclo ./tflm/tensorflow/lite/kernels/internal/portable_tensor_utils.d ./tflm/tensorflow/lite/kernels/internal/portable_tensor_utils.o ./tflm/tensorflow/lite/kernels/internal/portable_tensor_utils.su ./tflm/tensorflow/lite/kernels/internal/quantization_util.cyclo ./tflm/tensorflow/lite/kernels/internal/quantization_util.d ./tflm/tensorflow/lite/kernels/internal/quantization_util.o ./tflm/tensorflow/lite/kernels/internal/quantization_util.su ./tflm/tensorflow/lite/kernels/internal/runtime_shape.cyclo ./tflm/tensorflow/lite/kernels/internal/runtime_shape.d ./tflm/tensorflow/lite/kernels/internal/runtime_shape.o ./tflm/tensorflow/lite/kernels/internal/runtime_shape.su ./tflm/tensorflow/lite/kernels/internal/tensor_ctypes.cyclo ./tflm/tensorflow/lite/kernels/internal/tensor_ctypes.d ./tflm/tensorflow/lite/kernels/internal/tensor_ctypes.o ./tflm/tensorflow/lite/kernels/internal/tensor_ctypes.su ./tflm/tensorflow/lite/kernels/internal/tensor_utils.cyclo ./tflm/tensorflow/lite/kernels/internal/tensor_utils.d ./tflm/tensorflow/lite/kernels/internal/tensor_utils.o ./tflm/tensorflow/lite/kernels/internal/tensor_utils.su

.PHONY: clean-tflm-2f-tensorflow-2f-lite-2f-kernels-2f-internal

