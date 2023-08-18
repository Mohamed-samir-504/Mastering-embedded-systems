################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../7-SEG/7-seg.c 

OBJS += \
./7-SEG/7-seg.o 

C_DEPS += \
./7-SEG/7-seg.d 


# Each subdirectory must supply rules for building sources it contributes
7-SEG/7-seg.o: ../7-SEG/7-seg.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"D:/MOHAMED/STM32 projects/Drivers_2_lcd_keypad/7-SEG" -I"D:/MOHAMED/STM32 projects/Drivers_2_lcd_keypad/STM32F103C6_Drivers/inc" -I"D:/MOHAMED/STM32 projects/Drivers_2_lcd_keypad/LCD" -I"D:/MOHAMED/STM32 projects/Drivers_2_lcd_keypad/KEYPAD" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"7-SEG/7-seg.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

