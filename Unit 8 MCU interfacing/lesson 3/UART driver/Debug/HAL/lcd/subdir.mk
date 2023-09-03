################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/lcd/lcd.c 

OBJS += \
./HAL/lcd/lcd.o 

C_DEPS += \
./HAL/lcd/lcd.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/lcd/lcd.o: ../HAL/lcd/lcd.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"D:/MOHAMED/STM32 projects/unit8_lesson3_drivers_UART/HAL/inc" -I"D:/MOHAMED/STM32 projects/unit8_lesson3_drivers_UART/STM32F103C6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"HAL/lcd/lcd.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

