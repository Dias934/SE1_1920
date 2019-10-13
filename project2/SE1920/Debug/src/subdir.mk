################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Button.c \
../src/Lcd.c \
../src/Led.c \
../src/UI.c \
../src/Wait.c 

OBJS += \
./src/Button.o \
./src/Lcd.o \
./src/Led.o \
./src/UI.o \
./src/Wait.o 

C_DEPS += \
./src/Button.d \
./src/Lcd.d \
./src/Led.d \
./src/UI.d \
./src/Wait.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -D__CODE_RED -D__REDLIB__ -DCORE_M3 -D__USE_CMSIS=CMSIS_CORE_LPC17xx -D__LPC17XX__ -I"C:\Users\ASUS\Documents\faculdade\SE1\SE1920\inc" -I"C:\Users\ASUS\Documents\faculdade\SE1\CMSIS_CORE_LPC17xx\inc" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


