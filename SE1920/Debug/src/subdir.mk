################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/BMP280.c \
../src/button.c \
../src/iap.c \
../src/lcd.c \
../src/led.c \
../src/peripherals.c \
../src/rtc.c \
../src/spi.c \
../src/ui.c \
../src/wait.c 

OBJS += \
./src/BMP280.o \
./src/button.o \
./src/iap.o \
./src/lcd.o \
./src/led.o \
./src/peripherals.o \
./src/rtc.o \
./src/spi.o \
./src/ui.o \
./src/wait.o 

C_DEPS += \
./src/BMP280.d \
./src/button.d \
./src/iap.d \
./src/lcd.d \
./src/led.d \
./src/peripherals.d \
./src/rtc.d \
./src/spi.d \
./src/ui.d \
./src/wait.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -D__CODE_RED -D__REDLIB__ -DCORE_M3 -D__USE_CMSIS=CMSIS_CORE_LPC17xx -D__LPC17XX__ -I"D:\Isel\19-20\Inverno\SE1\SE1920\inc" -I"D:\Isel\19-20\Inverno\SE1\CMSIS_CORE_LPC17xx\inc" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


