################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../STM32F103C6_Drivers/STM32F103C6_EXTI_driver.c \
../STM32F103C6_Drivers/STM32F103C6_GPIO_driver.c \
../STM32F103C6_Drivers/STM32F103C6_RCC_driver.c \
../STM32F103C6_Drivers/STM32F103C6_USART_driver.c 

OBJS += \
./STM32F103C6_Drivers/STM32F103C6_EXTI_driver.o \
./STM32F103C6_Drivers/STM32F103C6_GPIO_driver.o \
./STM32F103C6_Drivers/STM32F103C6_RCC_driver.o \
./STM32F103C6_Drivers/STM32F103C6_USART_driver.o 

C_DEPS += \
./STM32F103C6_Drivers/STM32F103C6_EXTI_driver.d \
./STM32F103C6_Drivers/STM32F103C6_GPIO_driver.d \
./STM32F103C6_Drivers/STM32F103C6_RCC_driver.d \
./STM32F103C6_Drivers/STM32F103C6_USART_driver.d 


# Each subdirectory must supply rules for building sources it contributes
STM32F103C6_Drivers/STM32F103C6_EXTI_driver.o: ../STM32F103C6_Drivers/STM32F103C6_EXTI_driver.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"D:/MOHAMED/STM32 projects/unit8_lesson3_drivers_UART/HAL/inc" -I"D:/MOHAMED/STM32 projects/unit8_lesson3_drivers_UART/STM32F103C6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32F103C6_Drivers/STM32F103C6_EXTI_driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
STM32F103C6_Drivers/STM32F103C6_GPIO_driver.o: ../STM32F103C6_Drivers/STM32F103C6_GPIO_driver.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"D:/MOHAMED/STM32 projects/unit8_lesson3_drivers_UART/HAL/inc" -I"D:/MOHAMED/STM32 projects/unit8_lesson3_drivers_UART/STM32F103C6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32F103C6_Drivers/STM32F103C6_GPIO_driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
STM32F103C6_Drivers/STM32F103C6_RCC_driver.o: ../STM32F103C6_Drivers/STM32F103C6_RCC_driver.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"D:/MOHAMED/STM32 projects/unit8_lesson3_drivers_UART/HAL/inc" -I"D:/MOHAMED/STM32 projects/unit8_lesson3_drivers_UART/STM32F103C6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32F103C6_Drivers/STM32F103C6_RCC_driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
STM32F103C6_Drivers/STM32F103C6_USART_driver.o: ../STM32F103C6_Drivers/STM32F103C6_USART_driver.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"D:/MOHAMED/STM32 projects/unit8_lesson3_drivers_UART/HAL/inc" -I"D:/MOHAMED/STM32 projects/unit8_lesson3_drivers_UART/STM32F103C6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32F103C6_Drivers/STM32F103C6_USART_driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

