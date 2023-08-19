################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/API/Src/API_debounce.c \
../Drivers/API/Src/API_delay.c \
../Drivers/API/Src/API_dht11.c \
../Drivers/API/Src/API_i2c.c \
../Drivers/API/Src/API_lcd.c \
../Drivers/API/Src/API_timer1.c \
../Drivers/API/Src/API_uart.c \
../Drivers/API/Src/FSM.c \
../Drivers/API/Src/RTC_DS3231.c 

OBJS += \
./Drivers/API/Src/API_debounce.o \
./Drivers/API/Src/API_delay.o \
./Drivers/API/Src/API_dht11.o \
./Drivers/API/Src/API_i2c.o \
./Drivers/API/Src/API_lcd.o \
./Drivers/API/Src/API_timer1.o \
./Drivers/API/Src/API_uart.o \
./Drivers/API/Src/FSM.o \
./Drivers/API/Src/RTC_DS3231.o 

C_DEPS += \
./Drivers/API/Src/API_debounce.d \
./Drivers/API/Src/API_delay.d \
./Drivers/API/Src/API_dht11.d \
./Drivers/API/Src/API_i2c.d \
./Drivers/API/Src/API_lcd.d \
./Drivers/API/Src/API_timer1.d \
./Drivers/API/Src/API_uart.d \
./Drivers/API/Src/FSM.d \
./Drivers/API/Src/RTC_DS3231.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/API/Src/%.o Drivers/API/Src/%.su Drivers/API/Src/%.cyclo: ../Drivers/API/Src/%.c Drivers/API/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"D:/Carlos/Documents/CESE_2023/PdM_Workspace_Carlos/TP_CESE_2023_JOSE/Drivers/API" -I"D:/Carlos/Documents/CESE_2023/PdM_Workspace_Carlos/TP_CESE_2023_JOSE/Drivers/API/Inc" -I"D:/Carlos/Documents/CESE_2023/PdM_Workspace_Carlos/TP_CESE_2023_JOSE/Drivers/API/Src" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-API-2f-Src

clean-Drivers-2f-API-2f-Src:
	-$(RM) ./Drivers/API/Src/API_debounce.cyclo ./Drivers/API/Src/API_debounce.d ./Drivers/API/Src/API_debounce.o ./Drivers/API/Src/API_debounce.su ./Drivers/API/Src/API_delay.cyclo ./Drivers/API/Src/API_delay.d ./Drivers/API/Src/API_delay.o ./Drivers/API/Src/API_delay.su ./Drivers/API/Src/API_dht11.cyclo ./Drivers/API/Src/API_dht11.d ./Drivers/API/Src/API_dht11.o ./Drivers/API/Src/API_dht11.su ./Drivers/API/Src/API_i2c.cyclo ./Drivers/API/Src/API_i2c.d ./Drivers/API/Src/API_i2c.o ./Drivers/API/Src/API_i2c.su ./Drivers/API/Src/API_lcd.cyclo ./Drivers/API/Src/API_lcd.d ./Drivers/API/Src/API_lcd.o ./Drivers/API/Src/API_lcd.su ./Drivers/API/Src/API_timer1.cyclo ./Drivers/API/Src/API_timer1.d ./Drivers/API/Src/API_timer1.o ./Drivers/API/Src/API_timer1.su ./Drivers/API/Src/API_uart.cyclo ./Drivers/API/Src/API_uart.d ./Drivers/API/Src/API_uart.o ./Drivers/API/Src/API_uart.su ./Drivers/API/Src/FSM.cyclo ./Drivers/API/Src/FSM.d ./Drivers/API/Src/FSM.o ./Drivers/API/Src/FSM.su ./Drivers/API/Src/RTC_DS3231.cyclo ./Drivers/API/Src/RTC_DS3231.d ./Drivers/API/Src/RTC_DS3231.o ./Drivers/API/Src/RTC_DS3231.su

.PHONY: clean-Drivers-2f-API-2f-Src

