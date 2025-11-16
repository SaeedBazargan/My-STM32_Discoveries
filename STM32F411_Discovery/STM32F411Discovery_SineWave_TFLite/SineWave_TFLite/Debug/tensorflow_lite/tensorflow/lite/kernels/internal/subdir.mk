################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../tensorflow_lite/tensorflow/lite/kernels/internal/common.cc \
../tensorflow_lite/tensorflow/lite/kernels/internal/portable_tensor_utils.cc \
../tensorflow_lite/tensorflow/lite/kernels/internal/quantization_util.cc \
../tensorflow_lite/tensorflow/lite/kernels/internal/runtime_shape.cc \
../tensorflow_lite/tensorflow/lite/kernels/internal/tensor_ctypes.cc \
../tensorflow_lite/tensorflow/lite/kernels/internal/tensor_utils.cc 

CC_DEPS += \
./tensorflow_lite/tensorflow/lite/kernels/internal/common.d \
./tensorflow_lite/tensorflow/lite/kernels/internal/portable_tensor_utils.d \
./tensorflow_lite/tensorflow/lite/kernels/internal/quantization_util.d \
./tensorflow_lite/tensorflow/lite/kernels/internal/runtime_shape.d \
./tensorflow_lite/tensorflow/lite/kernels/internal/tensor_ctypes.d \
./tensorflow_lite/tensorflow/lite/kernels/internal/tensor_utils.d 

OBJS += \
./tensorflow_lite/tensorflow/lite/kernels/internal/common.o \
./tensorflow_lite/tensorflow/lite/kernels/internal/portable_tensor_utils.o \
./tensorflow_lite/tensorflow/lite/kernels/internal/quantization_util.o \
./tensorflow_lite/tensorflow/lite/kernels/internal/runtime_shape.o \
./tensorflow_lite/tensorflow/lite/kernels/internal/tensor_ctypes.o \
./tensorflow_lite/tensorflow/lite/kernels/internal/tensor_utils.o 


# Each subdirectory must supply rules for building sources it contributes
tensorflow_lite/tensorflow/lite/kernels/internal/%.o tensorflow_lite/tensorflow/lite/kernels/internal/%.su tensorflow_lite/tensorflow/lite/kernels/internal/%.cyclo: ../tensorflow_lite/tensorflow/lite/kernels/internal/%.cc tensorflow_lite/tensorflow/lite/kernels/internal/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tensorflow_lite" -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tensorflow_lite/third_party/flatbuffers/include" -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tensorflow_lite/third_party/gemmlowp" -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tensorflow_lite/third_party/ruy" -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tensorflow_lite/third_party/kissfft" -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tensorflow_lite/tensorflow/lite" -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tensorflow_lite/signal" -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/tensorflow_lite/signal/src" -I"C:/Users/Bazar/Desktop/My-STM32_Discoveries/STM32F411_Discovery/STM32F411Discovery_SineWave_TFLite/SineWave_TFLite/Lib" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-tensorflow_lite-2f-tensorflow-2f-lite-2f-kernels-2f-internal

clean-tensorflow_lite-2f-tensorflow-2f-lite-2f-kernels-2f-internal:
	-$(RM) ./tensorflow_lite/tensorflow/lite/kernels/internal/common.cyclo ./tensorflow_lite/tensorflow/lite/kernels/internal/common.d ./tensorflow_lite/tensorflow/lite/kernels/internal/common.o ./tensorflow_lite/tensorflow/lite/kernels/internal/common.su ./tensorflow_lite/tensorflow/lite/kernels/internal/portable_tensor_utils.cyclo ./tensorflow_lite/tensorflow/lite/kernels/internal/portable_tensor_utils.d ./tensorflow_lite/tensorflow/lite/kernels/internal/portable_tensor_utils.o ./tensorflow_lite/tensorflow/lite/kernels/internal/portable_tensor_utils.su ./tensorflow_lite/tensorflow/lite/kernels/internal/quantization_util.cyclo ./tensorflow_lite/tensorflow/lite/kernels/internal/quantization_util.d ./tensorflow_lite/tensorflow/lite/kernels/internal/quantization_util.o ./tensorflow_lite/tensorflow/lite/kernels/internal/quantization_util.su ./tensorflow_lite/tensorflow/lite/kernels/internal/runtime_shape.cyclo ./tensorflow_lite/tensorflow/lite/kernels/internal/runtime_shape.d ./tensorflow_lite/tensorflow/lite/kernels/internal/runtime_shape.o ./tensorflow_lite/tensorflow/lite/kernels/internal/runtime_shape.su ./tensorflow_lite/tensorflow/lite/kernels/internal/tensor_ctypes.cyclo ./tensorflow_lite/tensorflow/lite/kernels/internal/tensor_ctypes.d ./tensorflow_lite/tensorflow/lite/kernels/internal/tensor_ctypes.o ./tensorflow_lite/tensorflow/lite/kernels/internal/tensor_ctypes.su ./tensorflow_lite/tensorflow/lite/kernels/internal/tensor_utils.cyclo ./tensorflow_lite/tensorflow/lite/kernels/internal/tensor_utils.d ./tensorflow_lite/tensorflow/lite/kernels/internal/tensor_utils.o ./tensorflow_lite/tensorflow/lite/kernels/internal/tensor_utils.su

.PHONY: clean-tensorflow_lite-2f-tensorflow-2f-lite-2f-kernels-2f-internal

