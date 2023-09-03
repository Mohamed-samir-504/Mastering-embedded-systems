################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/keypad/keypad.c 

OBJS += \
./HAL/keypad/keypad.o 

C_DEPS += \
./HAL/keypad/keypad.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/keypad/keypad.o: ../HAL/keypad/keypad.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"D:/MOHAMED/STM32 projects/unit8_lesson3_drivers_UART/HAL/inc" -I"D:/MOHAMED/STM32 projects/unit8_lesson3_drivers_UART/STM32F103C6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"HAL/keypad/keypad.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

