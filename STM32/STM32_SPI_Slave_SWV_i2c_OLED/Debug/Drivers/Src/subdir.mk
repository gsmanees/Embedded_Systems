################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/Src/oled.c \
../Drivers/Src/ssd1306_basic.c \
../Drivers/Src/stm32f446xx_gpio_driver.c \
../Drivers/Src/stm32f446xx_i2c_driver.c \
../Drivers/Src/stm32f446xx_rcc_driver.c \
../Drivers/Src/stm32f446xx_spi_driver.c 

OBJS += \
./Drivers/Src/oled.o \
./Drivers/Src/ssd1306_basic.o \
./Drivers/Src/stm32f446xx_gpio_driver.o \
./Drivers/Src/stm32f446xx_i2c_driver.o \
./Drivers/Src/stm32f446xx_rcc_driver.o \
./Drivers/Src/stm32f446xx_spi_driver.o 

C_DEPS += \
./Drivers/Src/oled.d \
./Drivers/Src/ssd1306_basic.d \
./Drivers/Src/stm32f446xx_gpio_driver.d \
./Drivers/Src/stm32f446xx_i2c_driver.d \
./Drivers/Src/stm32f446xx_rcc_driver.d \
./Drivers/Src/stm32f446xx_spi_driver.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/Src/%.o Drivers/Src/%.su Drivers/Src/%.cyclo: ../Drivers/Src/%.c Drivers/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F446RETx -DNUCLEO_F446RE -c -I../Inc -I"C:/EmbeddedSystemsProjectsEntri/STM32/STM32_SPI_Slave_SWV_i2c_OLED/Drivers/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-Src

clean-Drivers-2f-Src:
	-$(RM) ./Drivers/Src/oled.cyclo ./Drivers/Src/oled.d ./Drivers/Src/oled.o ./Drivers/Src/oled.su ./Drivers/Src/ssd1306_basic.cyclo ./Drivers/Src/ssd1306_basic.d ./Drivers/Src/ssd1306_basic.o ./Drivers/Src/ssd1306_basic.su ./Drivers/Src/stm32f446xx_gpio_driver.cyclo ./Drivers/Src/stm32f446xx_gpio_driver.d ./Drivers/Src/stm32f446xx_gpio_driver.o ./Drivers/Src/stm32f446xx_gpio_driver.su ./Drivers/Src/stm32f446xx_i2c_driver.cyclo ./Drivers/Src/stm32f446xx_i2c_driver.d ./Drivers/Src/stm32f446xx_i2c_driver.o ./Drivers/Src/stm32f446xx_i2c_driver.su ./Drivers/Src/stm32f446xx_rcc_driver.cyclo ./Drivers/Src/stm32f446xx_rcc_driver.d ./Drivers/Src/stm32f446xx_rcc_driver.o ./Drivers/Src/stm32f446xx_rcc_driver.su ./Drivers/Src/stm32f446xx_spi_driver.cyclo ./Drivers/Src/stm32f446xx_spi_driver.d ./Drivers/Src/stm32f446xx_spi_driver.o ./Drivers/Src/stm32f446xx_spi_driver.su

.PHONY: clean-Drivers-2f-Src

