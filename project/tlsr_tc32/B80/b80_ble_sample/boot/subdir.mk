################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_UPPER_SRCS += \
C:/SIM/CHIP_B80/tc_ble_simple_sdk-3.4.2.2/tc_ble_simple_sdk-3.4.2.2/b80_ble_sdk/boot/cstartup_flash.S 

OBJS += \
./boot/cstartup_flash.o 


# Each subdirectory must supply rules for building sources it contributes
boot/cstartup_flash.o: C:/SIM/CHIP_B80/tc_ble_simple_sdk-3.4.2.2/tc_ble_simple_sdk-3.4.2.2/b80_ble_sdk/boot/cstartup_flash.S
	@echo 'Building file: $<'
	@echo 'Invoking: TC32 CC/Assembler'
	tc32-elf-gcc -DMCU_STARTUP_FLASH -DMCU_STARTUP_B80=1 -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


