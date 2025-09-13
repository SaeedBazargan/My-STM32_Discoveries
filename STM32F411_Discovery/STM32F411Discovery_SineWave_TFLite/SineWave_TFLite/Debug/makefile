################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include tensorflow_lite/third_party/kissfft/tools/subdir.mk
-include tensorflow_lite/third_party/kissfft/subdir.mk
-include tensorflow_lite/tensorflow/lite/micro/tflite_bridge/subdir.mk
-include tensorflow_lite/tensorflow/lite/micro/memory_planner/subdir.mk
-include tensorflow_lite/tensorflow/lite/micro/kernels/subdir.mk
-include tensorflow_lite/tensorflow/lite/micro/arena_allocator/subdir.mk
-include tensorflow_lite/tensorflow/lite/micro/subdir.mk
-include tensorflow_lite/tensorflow/lite/kernels/internal/reference/subdir.mk
-include tensorflow_lite/tensorflow/lite/kernels/internal/subdir.mk
-include tensorflow_lite/tensorflow/lite/kernels/subdir.mk
-include tensorflow_lite/tensorflow/lite/core/c/subdir.mk
-include tensorflow_lite/tensorflow/lite/core/api/subdir.mk
-include tensorflow_lite/tensorflow/lite/subdir.mk
-include tensorflow_lite/tensorflow/compiler/mlir/lite/schema/subdir.mk
-include tensorflow_lite/tensorflow/compiler/mlir/lite/core/api/subdir.mk
-include tensorflow_lite/signal/src/kiss_fft_wrappers/subdir.mk
-include tensorflow_lite/signal/src/subdir.mk
-include tensorflow_lite/signal/micro/kernels/subdir.mk
-include Drivers/STM32F4xx_HAL_Driver/Src/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(CCM_DEPS)),)
-include $(CCM_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(CXXM_DEPS)),)
-include $(CXXM_DEPS)
endif
ifneq ($(strip $(C++M_DEPS)),)
-include $(C++M_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := SineWave_TFLite
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
SineWave_TFLite.elf \

MAP_FILES += \
SineWave_TFLite.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
SineWave_TFLite.list \


# All Target
all: main-build

# Main-build Target
main-build: SineWave_TFLite.elf secondary-outputs

# Tool invocations
SineWave_TFLite.elf SineWave_TFLite.map: $(OBJS) $(USER_OBJS) C:\Users\Bazar\Desktop\My-STM32_Discoveries\STM32F411_Discovery\STM32F411Discovery_SineWave_TFLite\SineWave_TFLite\STM32F411VETX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-g++ -o "SineWave_TFLite.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"C:\Users\Bazar\Desktop\My-STM32_Discoveries\STM32F411_Discovery\STM32F411Discovery_SineWave_TFLite\SineWave_TFLite\STM32F411VETX_FLASH.ld" --specs=nosys.specs -Wl,-Map="SineWave_TFLite.map" -Wl,--gc-sections -static -L"C:\Users\Bazar\Desktop\My-STM32_Discoveries\STM32F411_Discovery\STM32F411Discovery_SineWave_TFLite\SineWave_TFLite\Lib" -u _printf_float --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -lstdc++ -lsupc++ -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

SineWave_TFLite.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "SineWave_TFLite.list"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) SineWave_TFLite.elf SineWave_TFLite.list SineWave_TFLite.map default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
