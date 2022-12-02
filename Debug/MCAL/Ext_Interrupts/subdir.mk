################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/Ext_Interrupts/Ext_Interrupts.c 

OBJS += \
./MCAL/Ext_Interrupts/Ext_Interrupts.o 

C_DEPS += \
./MCAL/Ext_Interrupts/Ext_Interrupts.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/Ext_Interrupts/%.o: ../MCAL/Ext_Interrupts/%.c MCAL/Ext_Interrupts/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O1 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


