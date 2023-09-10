################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include STM32F103C6_Drivers/subdir.mk
-include HAL/lcd/subdir.mk
-include HAL/keypad/subdir.mk
-include subdir.mk
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

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
unit8_lesson5_drivers_SPI.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
unit8_lesson5_drivers_SPI.list \

OBJCOPY_BIN += \
unit8_lesson5_drivers_SPI.bin \


# All Target
all:
	+@make --no-print-directory main-build && make --no-print-directory post-build

# Main-build Target
main-build: unit8_lesson5_drivers_SPI.elf secondary-outputs

# Tool invocations
unit8_lesson5_drivers_SPI.elf: $(OBJS) $(USER_OBJS) D:\MOHAMED\STM32\ projects\unit8_lesson5_drivers_SPI\STM32F103C6TX_FLASH.ld
	arm-none-eabi-gcc -gdwarf-2 -o "unit8_lesson5_drivers_SPI.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"D:\MOHAMED\STM32 projects\unit8_lesson5_drivers_SPI\STM32F103C6TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="unit8_lesson5_drivers_SPI.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

unit8_lesson5_drivers_SPI.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "unit8_lesson5_drivers_SPI.list"
	@echo 'Finished building: $@'
	@echo ' '

unit8_lesson5_drivers_SPI.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "unit8_lesson5_drivers_SPI.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

post-build:
	arm-none-eabi-objcopy -O ihex unit8_lesson5_drivers_SPI.elf unit8_lesson5_drivers_SPI.hex
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets
