################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/Src/fonts.c \
../Drivers/Src/lm35.c \
../Drivers/Src/oled.c \
../Drivers/Src/ssd1306.c \
../Drivers/Src/stm32f446xx_i2c_driver.c \
../Drivers/Src/stm32f446xx_rcc_driver.c \
../Drivers/Src/stm32f4xx_hal_msp.c \
../Drivers/Src/stm32f4xx_it.c \
../Drivers/Src/syscalls.c \
../Drivers/Src/sysmem.c \
../Drivers/Src/system_stm32f4xx.c 

OBJS += \
./Drivers/Src/fonts.o \
./Drivers/Src/lm35.o \
./Drivers/Src/oled.o \
./Drivers/Src/ssd1306.o \
./Drivers/Src/stm32f446xx_i2c_driver.o \
./Drivers/Src/stm32f446xx_rcc_driver.o \
./Drivers/Src/stm32f4xx_hal_msp.o \
./Drivers/Src/stm32f4xx_it.o \
./Drivers/Src/syscalls.o \
./Drivers/Src/sysmem.o \
./Drivers/Src/system_stm32f4xx.o 

C_DEPS += \
./Drivers/Src/fonts.d \
./Drivers/Src/lm35.d \
./Drivers/Src/oled.d \
./Drivers/Src/ssd1306.d \
./Drivers/Src/stm32f446xx_i2c_driver.d \
./Drivers/Src/stm32f446xx_rcc_driver.d \
./Drivers/Src/stm32f4xx_hal_msp.d \
./Drivers/Src/stm32f4xx_it.d \
./Drivers/Src/syscalls.d \
./Drivers/Src/sysmem.d \
./Drivers/Src/system_stm32f4xx.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/Src/%.o Drivers/Src/%.su Drivers/Src/%.cyclo: ../Drivers/Src/%.c Drivers/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F446RETx -DNUCLEO_F446RE -c -I../Inc -I"C:/EmbeddedSystemsProjectsEntri/STM32/oled_i2c_driver/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/EmbeddedSystemsProjectsEntri/STM32/oled_i2c_driver/Drivers/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-Src

clean-Drivers-2f-Src:
	-$(RM) ./Drivers/Src/fonts.cyclo ./Drivers/Src/fonts.d ./Drivers/Src/fonts.o ./Drivers/Src/fonts.su ./Drivers/Src/lm35.cyclo ./Drivers/Src/lm35.d ./Drivers/Src/lm35.o ./Drivers/Src/lm35.su ./Drivers/Src/oled.cyclo ./Drivers/Src/oled.d ./Drivers/Src/oled.o ./Drivers/Src/oled.su ./Drivers/Src/ssd1306.cyclo ./Drivers/Src/ssd1306.d ./Drivers/Src/ssd1306.o ./Drivers/Src/ssd1306.su ./Drivers/Src/stm32f446xx_i2c_driver.cyclo ./Drivers/Src/stm32f446xx_i2c_driver.d ./Drivers/Src/stm32f446xx_i2c_driver.o ./Drivers/Src/stm32f446xx_i2c_driver.su ./Drivers/Src/stm32f446xx_rcc_driver.cyclo ./Drivers/Src/stm32f446xx_rcc_driver.d ./Drivers/Src/stm32f446xx_rcc_driver.o ./Drivers/Src/stm32f446xx_rcc_driver.su ./Drivers/Src/stm32f4xx_hal_msp.cyclo ./Drivers/Src/stm32f4xx_hal_msp.d ./Drivers/Src/stm32f4xx_hal_msp.o ./Drivers/Src/stm32f4xx_hal_msp.su ./Drivers/Src/stm32f4xx_it.cyclo ./Drivers/Src/stm32f4xx_it.d ./Drivers/Src/stm32f4xx_it.o ./Drivers/Src/stm32f4xx_it.su ./Drivers/Src/syscalls.cyclo ./Drivers/Src/syscalls.d ./Drivers/Src/syscalls.o ./Drivers/Src/syscalls.su ./Drivers/Src/sysmem.cyclo ./Drivers/Src/sysmem.d ./Drivers/Src/sysmem.o ./Drivers/Src/sysmem.su ./Drivers/Src/system_stm32f4xx.cyclo ./Drivers/Src/system_stm32f4xx.d ./Drivers/Src/system_stm32f4xx.o ./Drivers/Src/system_stm32f4xx.su

.PHONY: clean-Drivers-2f-Src

