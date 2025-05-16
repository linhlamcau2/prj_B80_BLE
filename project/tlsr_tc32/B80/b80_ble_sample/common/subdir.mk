################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/SIM/CHIP_B80/tc_ble_simple_sdk-3.4.2.2/tc_ble_simple_sdk-3.4.2.2/b80_ble_sdk/common/sdk_version.c \
C:/SIM/CHIP_B80/tc_ble_simple_sdk-3.4.2.2/tc_ble_simple_sdk-3.4.2.2/b80_ble_sdk/common/string.c \
C:/SIM/CHIP_B80/tc_ble_simple_sdk-3.4.2.2/tc_ble_simple_sdk-3.4.2.2/b80_ble_sdk/common/timer_event.c \
C:/SIM/CHIP_B80/tc_ble_simple_sdk-3.4.2.2/tc_ble_simple_sdk-3.4.2.2/b80_ble_sdk/common/utility.c 

S_UPPER_SRCS += \
C:/SIM/CHIP_B80/tc_ble_simple_sdk-3.4.2.2/tc_ble_simple_sdk-3.4.2.2/b80_ble_sdk/common/div_mod.S 

OBJS += \
./common/div_mod.o \
./common/sdk_version.o \
./common/string.o \
./common/timer_event.o \
./common/utility.o 


# Each subdirectory must supply rules for building sources it contributes
common/div_mod.o: C:/SIM/CHIP_B80/tc_ble_simple_sdk-3.4.2.2/tc_ble_simple_sdk-3.4.2.2/b80_ble_sdk/common/div_mod.S
	@echo 'Building file: $<'
	@echo 'Invoking: TC32 CC/Assembler'
	tc32-elf-gcc -DMCU_STARTUP_FLASH -DMCU_STARTUP_B80=1 -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

common/sdk_version.o: C:/SIM/CHIP_B80/tc_ble_simple_sdk-3.4.2.2/tc_ble_simple_sdk-3.4.2.2/b80_ble_sdk/common/sdk_version.c
	@echo 'Building file: $<'
	@echo 'Invoking: TC32 Compiler'
	tc32-elf-gcc -ffunction-sections -fdata-sections -I"C:\SIM\CHIP_B80\tc_ble_simple_sdk-3.4.2.2\tc_ble_simple_sdk-3.4.2.2\b80_ble_sdk\project\tlsr_tc32\B80" -I"C:\SIM\CHIP_B80\tc_ble_simple_sdk-3.4.2.2\tc_ble_simple_sdk-3.4.2.2\b80_ble_sdk\project\tlsr_tc32\B80/../../.." -I"C:\SIM\CHIP_B80\tc_ble_simple_sdk-3.4.2.2\tc_ble_simple_sdk-3.4.2.2\b80_ble_sdk\drivers" -I"C:\SIM\CHIP_B80\tc_ble_simple_sdk-3.4.2.2\tc_ble_simple_sdk-3.4.2.2\b80_ble_sdk\common" -I"C:\SIM\CHIP_B80\tc_ble_simple_sdk-3.4.2.2\tc_ble_simple_sdk-3.4.2.2\b80_ble_sdk\vendor\common" -DMCU_CORE_B80=1 -D__PROJECT_B80_BLE_SAMPLE__=1 -Wall -O2 -fpack-struct -fshort-enums -finline-small-functions -std=gnu99 -fshort-wchar -fms-extensions -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

common/string.o: C:/SIM/CHIP_B80/tc_ble_simple_sdk-3.4.2.2/tc_ble_simple_sdk-3.4.2.2/b80_ble_sdk/common/string.c
	@echo 'Building file: $<'
	@echo 'Invoking: TC32 Compiler'
	tc32-elf-gcc -ffunction-sections -fdata-sections -I"C:\SIM\CHIP_B80\tc_ble_simple_sdk-3.4.2.2\tc_ble_simple_sdk-3.4.2.2\b80_ble_sdk\project\tlsr_tc32\B80" -I"C:\SIM\CHIP_B80\tc_ble_simple_sdk-3.4.2.2\tc_ble_simple_sdk-3.4.2.2\b80_ble_sdk\project\tlsr_tc32\B80/../../.." -I"C:\SIM\CHIP_B80\tc_ble_simple_sdk-3.4.2.2\tc_ble_simple_sdk-3.4.2.2\b80_ble_sdk\drivers" -I"C:\SIM\CHIP_B80\tc_ble_simple_sdk-3.4.2.2\tc_ble_simple_sdk-3.4.2.2\b80_ble_sdk\common" -I"C:\SIM\CHIP_B80\tc_ble_simple_sdk-3.4.2.2\tc_ble_simple_sdk-3.4.2.2\b80_ble_sdk\vendor\common" -DMCU_CORE_B80=1 -D__PROJECT_B80_BLE_SAMPLE__=1 -Wall -O2 -fpack-struct -fshort-enums -finline-small-functions -std=gnu99 -fshort-wchar -fms-extensions -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

common/timer_event.o: C:/SIM/CHIP_B80/tc_ble_simple_sdk-3.4.2.2/tc_ble_simple_sdk-3.4.2.2/b80_ble_sdk/common/timer_event.c
	@echo 'Building file: $<'
	@echo 'Invoking: TC32 Compiler'
	tc32-elf-gcc -ffunction-sections -fdata-sections -I"C:\SIM\CHIP_B80\tc_ble_simple_sdk-3.4.2.2\tc_ble_simple_sdk-3.4.2.2\b80_ble_sdk\project\tlsr_tc32\B80" -I"C:\SIM\CHIP_B80\tc_ble_simple_sdk-3.4.2.2\tc_ble_simple_sdk-3.4.2.2\b80_ble_sdk\project\tlsr_tc32\B80/../../.." -I"C:\SIM\CHIP_B80\tc_ble_simple_sdk-3.4.2.2\tc_ble_simple_sdk-3.4.2.2\b80_ble_sdk\drivers" -I"C:\SIM\CHIP_B80\tc_ble_simple_sdk-3.4.2.2\tc_ble_simple_sdk-3.4.2.2\b80_ble_sdk\common" -I"C:\SIM\CHIP_B80\tc_ble_simple_sdk-3.4.2.2\tc_ble_simple_sdk-3.4.2.2\b80_ble_sdk\vendor\common" -DMCU_CORE_B80=1 -D__PROJECT_B80_BLE_SAMPLE__=1 -Wall -O2 -fpack-struct -fshort-enums -finline-small-functions -std=gnu99 -fshort-wchar -fms-extensions -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

common/utility.o: C:/SIM/CHIP_B80/tc_ble_simple_sdk-3.4.2.2/tc_ble_simple_sdk-3.4.2.2/b80_ble_sdk/common/utility.c
	@echo 'Building file: $<'
	@echo 'Invoking: TC32 Compiler'
	tc32-elf-gcc -ffunction-sections -fdata-sections -I"C:\SIM\CHIP_B80\tc_ble_simple_sdk-3.4.2.2\tc_ble_simple_sdk-3.4.2.2\b80_ble_sdk\project\tlsr_tc32\B80" -I"C:\SIM\CHIP_B80\tc_ble_simple_sdk-3.4.2.2\tc_ble_simple_sdk-3.4.2.2\b80_ble_sdk\project\tlsr_tc32\B80/../../.." -I"C:\SIM\CHIP_B80\tc_ble_simple_sdk-3.4.2.2\tc_ble_simple_sdk-3.4.2.2\b80_ble_sdk\drivers" -I"C:\SIM\CHIP_B80\tc_ble_simple_sdk-3.4.2.2\tc_ble_simple_sdk-3.4.2.2\b80_ble_sdk\common" -I"C:\SIM\CHIP_B80\tc_ble_simple_sdk-3.4.2.2\tc_ble_simple_sdk-3.4.2.2\b80_ble_sdk\vendor\common" -DMCU_CORE_B80=1 -D__PROJECT_B80_BLE_SAMPLE__=1 -Wall -O2 -fpack-struct -fshort-enums -finline-small-functions -std=gnu99 -fshort-wchar -fms-extensions -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


