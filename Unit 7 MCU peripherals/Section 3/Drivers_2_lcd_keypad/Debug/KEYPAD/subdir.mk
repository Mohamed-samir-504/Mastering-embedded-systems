################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../KEYPAD/keypad.c 

OBJS += \
./KEYPAD/keypad.o 

C_DEPS += \
./KEYPAD/keypad.d 


# Each subdirectory must supply rules for building sources it contributes
KEYPAD/keypad.o: ../KEYPAD/keypad.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"D:/MOHAMED/STM32 projects/Drivers_2_lcd_keypad/7-SEG" -I"D:/MOHAMED/STM32 projects/Drivers_2_lcd_keypad/STM32F103C6_Drivers/inc" -I"D:/MOHAMED/STM32 projects/Drivers_2_lcd_keypad/LCD" -I"D:/MOHAMED/STM32 projects/Drivers_2_lcd_keypad/KEYPAD" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"KEYPAD/keypad.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

