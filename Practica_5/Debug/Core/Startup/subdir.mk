################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../Core/Startup/startup_stm32f429zitx.s 

OBJS += \
./Core/Startup/startup_stm32f429zitx.o 

S_DEPS += \
./Core/Startup/startup_stm32f429zitx.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Startup/%.o: ../Core/Startup/%.s Core/Startup/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m4 -g3 -DDEBUG -c -I"D:/Carlos/Documents/CESE_2023/PdM_Workspace_Carlos - copia/Practica_5/Drivers/API" -I"D:/Carlos/Documents/CESE_2023/PdM_Workspace_Carlos - copia/Practica_5/Drivers/API/Inc" -I"D:/Carlos/Documents/CESE_2023/PdM_Workspace_Carlos - copia/Practica_5/Drivers/API/Src" -I"D:/Carlos/Documents/CESE_2023/PdM_Workspace_Carlos - copia/Practica_5/Drivers/STM32F4xx_HAL_Driver" -I"D:/Carlos/Documents/CESE_2023/PdM_Workspace_Carlos - copia/Practica_5/Drivers/STM32F4xx_HAL_Driver/Inc" -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

clean: clean-Core-2f-Startup

clean-Core-2f-Startup:
	-$(RM) ./Core/Startup/startup_stm32f429zitx.d ./Core/Startup/startup_stm32f429zitx.o

.PHONY: clean-Core-2f-Startup

