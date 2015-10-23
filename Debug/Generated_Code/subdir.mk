################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Generated_Code/AD1.c \
../Generated_Code/AS1.c \
../Generated_Code/AdcLdd1.c \
../Generated_Code/BigClock.c \
../Generated_Code/BitIoLdd1.c \
../Generated_Code/BitIoLdd2.c \
../Generated_Code/Cpu.c \
../Generated_Code/LitleClock.c \
../Generated_Code/PE_LDD.c \
../Generated_Code/PWM1.c \
../Generated_Code/PwmLdd1.c \
../Generated_Code/RxBuf.c \
../Generated_Code/SI.c \
../Generated_Code/TU1.c \
../Generated_Code/TU2.c \
../Generated_Code/TimerIntLdd1.c \
../Generated_Code/Vectors.c 

OBJS += \
./Generated_Code/AD1.o \
./Generated_Code/AS1.o \
./Generated_Code/AdcLdd1.o \
./Generated_Code/BigClock.o \
./Generated_Code/BitIoLdd1.o \
./Generated_Code/BitIoLdd2.o \
./Generated_Code/Cpu.o \
./Generated_Code/LitleClock.o \
./Generated_Code/PE_LDD.o \
./Generated_Code/PWM1.o \
./Generated_Code/PwmLdd1.o \
./Generated_Code/RxBuf.o \
./Generated_Code/SI.o \
./Generated_Code/TU1.o \
./Generated_Code/TU2.o \
./Generated_Code/TimerIntLdd1.o \
./Generated_Code/Vectors.o 

C_DEPS += \
./Generated_Code/AD1.d \
./Generated_Code/AS1.d \
./Generated_Code/AdcLdd1.d \
./Generated_Code/BigClock.d \
./Generated_Code/BitIoLdd1.d \
./Generated_Code/BitIoLdd2.d \
./Generated_Code/Cpu.d \
./Generated_Code/LitleClock.d \
./Generated_Code/PE_LDD.d \
./Generated_Code/PWM1.d \
./Generated_Code/PwmLdd1.d \
./Generated_Code/RxBuf.d \
./Generated_Code/SI.d \
./Generated_Code/TU1.d \
./Generated_Code/TU2.d \
./Generated_Code/TimerIntLdd1.d \
./Generated_Code/Vectors.d 


# Each subdirectory must supply rules for building sources it contributes
Generated_Code/%.o: ../Generated_Code/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"C:/Users/Marcelo/workspace.kds/Camera_com_Lag/Static_Code/PDD" -I"C:/Users/Marcelo/workspace.kds/Camera_com_Lag/Static_Code/IO_Map" -I"C:/Users/Marcelo/workspace.kds/Camera_com_Lag/Sources" -I"C:/Users/Marcelo/workspace.kds/Camera_com_Lag/Generated_Code" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


