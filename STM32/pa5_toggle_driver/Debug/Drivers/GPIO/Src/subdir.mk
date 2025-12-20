################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/GPIO/Src/stm32f446_gpio_driver.c 

OBJS += \
./Drivers/GPIO/Src/stm32f446_gpio_driver.o 

C_DEPS += \
./Drivers/GPIO/Src/stm32f446_gpio_driver.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/GPIO/Src/%.o Drivers/GPIO/Src/%.su Drivers/GPIO/Src/%.cyclo: ../Drivers/GPIO/Src/%.c Drivers/GPIO/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F446RETx -DNUCLEO_F446RE -c -I../Inc -I../Drivers/GPIO/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-GPIO-2f-Src

clean-Drivers-2f-GPIO-2f-Src:
	-$(RM) ./Drivers/GPIO/Src/stm32f446_gpio_driver.cyclo ./Drivers/GPIO/Src/stm32f446_gpio_driver.d ./Drivers/GPIO/Src/stm32f446_gpio_driver.o ./Drivers/GPIO/Src/stm32f446_gpio_driver.su

.PHONY: clean-Drivers-2f-GPIO-2f-Src

