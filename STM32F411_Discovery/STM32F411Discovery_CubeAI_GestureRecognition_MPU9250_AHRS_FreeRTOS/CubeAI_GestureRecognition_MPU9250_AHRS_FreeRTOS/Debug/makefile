################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include X-CUBE-AI/App/subdir.mk
-include Middlewares/Third_Party/FreeRTOS/Source/portable/MemMang/subdir.mk
-include Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F/subdir.mk
-include Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS/subdir.mk
-include Middlewares/Third_Party/FreeRTOS/Source/subdir.mk
-include Lib/subdir.mk
-include Drivers/STM32F4xx_HAL_Driver/Src/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := CubeAI_GestureRecognition_MPU9250_AHRS_FreeRTOS
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
CubeAI_GestureRecognition_MPU9250_AHRS_FreeRTOS.elf \

MAP_FILES += \
CubeAI_GestureRecognition_MPU9250_AHRS_FreeRTOS.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
CubeAI_GestureRecognition_MPU9250_AHRS_FreeRTOS.list \


# All Target
all: main-build

# Main-build Target
main-build: CubeAI_GestureRecognition_MPU9250_AHRS_FreeRTOS.elf secondary-outputs

# Tool invocations
CubeAI_GestureRecognition_MPU9250_AHRS_FreeRTOS.elf CubeAI_GestureRecognition_MPU9250_AHRS_FreeRTOS.map: $(OBJS) $(USER_OBJS) E:\sbzrgn\My-STM32_Discoveries\STM32F411_Discovery\STM32F411Discovery_CubeAI_GestureRecognition_MPU9250_AHRS_FreeRTOS\CubeAI_GestureRecognition_MPU9250_AHRS_FreeRTOS\STM32F411VETX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "CubeAI_GestureRecognition_MPU9250_AHRS_FreeRTOS.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"E:\sbzrgn\My-STM32_Discoveries\STM32F411_Discovery\STM32F411Discovery_CubeAI_GestureRecognition_MPU9250_AHRS_FreeRTOS\CubeAI_GestureRecognition_MPU9250_AHRS_FreeRTOS\STM32F411VETX_FLASH.ld" --specs=nosys.specs -Wl,-Map="CubeAI_GestureRecognition_MPU9250_AHRS_FreeRTOS.map" -Wl,--gc-sections -static -L../Middlewares/ST/AI/Lib -u _printf_float --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

CubeAI_GestureRecognition_MPU9250_AHRS_FreeRTOS.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "CubeAI_GestureRecognition_MPU9250_AHRS_FreeRTOS.list"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) CubeAI_GestureRecognition_MPU9250_AHRS_FreeRTOS.elf CubeAI_GestureRecognition_MPU9250_AHRS_FreeRTOS.list CubeAI_GestureRecognition_MPU9250_AHRS_FreeRTOS.map default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
