################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../STM32_F103C6_Drivers/STM32_F103C6_Gpio.c 

OBJS += \
./STM32_F103C6_Drivers/STM32_F103C6_Gpio.o 

C_DEPS += \
./STM32_F103C6_Drivers/STM32_F103C6_Gpio.d 


# Each subdirectory must supply rules for building sources it contributes
STM32_F103C6_Drivers/STM32_F103C6_Gpio.o: ../STM32_F103C6_Drivers/STM32_F103C6_Gpio.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"D:/1st_step/Learn_in_depth/projects/Embedded_system_Online_Diploma/Unit7(MCUEssential)/Assignment/New folder/Drivers/STM32_F103C6_Drivers/includes" -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32_F103C6_Drivers/STM32_F103C6_Gpio.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

