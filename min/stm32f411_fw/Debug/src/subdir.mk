################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/main.c 

OBJS += \
./src/main.o 

C_DEPS += \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o src/%.su src/%.cyclo: ../src/%.c src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -c -I"/home/psh/workspace_semicon/min/stm32f411_fw/src" -I"/home/psh/workspace_semicon/min/stm32f411_fw/src/common" -I"/home/psh/workspace_semicon/min/stm32f411_fw/src/hw" -I"/home/psh/workspace_semicon/min/stm32f411_fw/src/lib" -I"/home/psh/workspace_semicon/min/stm32f411_fw/src/bsp" -I"/home/psh/workspace_semicon/min/stm32f411_fw/src/ap" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-src

clean-src:
	-$(RM) ./src/main.cyclo ./src/main.d ./src/main.o ./src/main.su

.PHONY: clean-src

