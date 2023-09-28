################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../STM32F103C6_Drivers/STM32F103C6_EXTI_driver.c \
../STM32F103C6_Drivers/STM32F103C6_GPIO_driver.c \
../STM32F103C6_Drivers/STM32F103C6_I2C_driver.c \
../STM32F103C6_Drivers/STM32F103C6_RCC_driver.c \
../STM32F103C6_Drivers/STM32F103C6_SPI_driver.c \
../STM32F103C6_Drivers/STM32F103C6_USART_driver.c 

OBJS += \
./STM32F103C6_Drivers/STM32F103C6_EXTI_driver.o \
./STM32F103C6_Drivers/STM32F103C6_GPIO_driver.o \
./STM32F103C6_Drivers/STM32F103C6_I2C_driver.o \
./STM32F103C6_Drivers/STM32F103C6_RCC_driver.o \
./STM32F103C6_Drivers/STM32F103C6_SPI_driver.o \
./STM32F103C6_Drivers/STM32F103C6_USART_driver.o 

C_DEPS += \
./STM32F103C6_Drivers/STM32F103C6_EXTI_driver.d \
./STM32F103C6_Drivers/STM32F103C6_GPIO_driver.d \
./STM32F103C6_Drivers/STM32F103C6_I2C_driver.d \
./STM32F103C6_Drivers/STM32F103C6_RCC_driver.d \
./STM32F103C6_Drivers/STM32F103C6_SPI_driver.d \
./STM32F103C6_Drivers/STM32F103C6_USART_driver.d 


# Each subdirectory must supply rules for building sources it contributes
STM32F103C6_Drivers/STM32F103C6_EXTI_driver.o: ../STM32F103C6_Drivers/STM32F103C6_EXTI_driver.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"D:/MOHAMED/STM32 projects/unit8_lesson7_drivers_I2C/HAL/inc" -I"D:/MOHAMED/STM32 projects/unit8_lesson7_drivers_I2C/STM32F103C6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32F103C6_Drivers/STM32F103C6_EXTI_driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
STM32F103C6_Drivers/STM32F103C6_GPIO_driver.o: ../STM32F103C6_Drivers/STM32F103C6_GPIO_driver.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"D:/MOHAMED/STM32 projects/unit8_lesson7_drivers_I2C/HAL/inc" -I"D:/MOHAMED/STM32 projects/unit8_lesson7_drivers_I2C/STM32F103C6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32F103C6_Drivers/STM32F103C6_GPIO_driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
STM32F103C6_Drivers/STM32F103C6_I2C_driver.o: ../STM32F103C6_Drivers/STM32F103C6_I2C_driver.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"D:/MOHAMED/STM32 projects/unit8_lesson7_drivers_I2C/HAL/inc" -I"D:/MOHAMED/STM32 projects/unit8_lesson7_drivers_I2C/STM32F103C6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32F103C6_Drivers/STM32F103C6_I2C_driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
STM32F103C6_Drivers/STM32F103C6_RCC_driver.o: ../STM32F103C6_Drivers/STM32F103C6_RCC_driver.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"D:/MOHAMED/STM32 projects/unit8_lesson7_drivers_I2C/HAL/inc" -I"D:/MOHAMED/STM32 projects/unit8_lesson7_drivers_I2C/STM32F103C6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32F103C6_Drivers/STM32F103C6_RCC_driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
STM32F103C6_Drivers/STM32F103C6_SPI_driver.o: ../STM32F103C6_Drivers/STM32F103C6_SPI_driver.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"D:/MOHAMED/STM32 projects/unit8_lesson7_drivers_I2C/HAL/inc" -I"D:/MOHAMED/STM32 projects/unit8_lesson7_drivers_I2C/STM32F103C6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32F103C6_Drivers/STM32F103C6_SPI_driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
STM32F103C6_Drivers/STM32F103C6_USART_driver.o: ../STM32F103C6_Drivers/STM32F103C6_USART_driver.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"D:/MOHAMED/STM32 projects/unit8_lesson7_drivers_I2C/HAL/inc" -I"D:/MOHAMED/STM32 projects/unit8_lesson7_drivers_I2C/STM32F103C6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32F103C6_Drivers/STM32F103C6_USART_driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

