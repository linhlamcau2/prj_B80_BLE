################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/SIM/CHIP_B80/tc_ble_simple_sdk-3.4.2.2/tc_ble_simple_sdk-3.4.2.2/b80_ble_sdk/drivers/driver_ext/ext_calibration.c \
C:/SIM/CHIP_B80/tc_ble_simple_sdk-3.4.2.2/tc_ble_simple_sdk-3.4.2.2/b80_ble_sdk/drivers/driver_ext/ext_misc.c \
C:/SIM/CHIP_B80/tc_ble_simple_sdk-3.4.2.2/tc_ble_simple_sdk-3.4.2.2/b80_ble_sdk/drivers/driver_ext/rf_pa.c \
C:/SIM/CHIP_B80/tc_ble_simple_sdk-3.4.2.2/tc_ble_simple_sdk-3.4.2.2/b80_ble_sdk/drivers/driver_ext/rf_private_pa.c 

OBJS += \
./drivers/driver_ext/ext_calibration.o \
./drivers/driver_ext/ext_misc.o \
./drivers/driver_ext/rf_pa.o \
./drivers/driver_ext/rf_private_pa.o 


# Each subdirectory must supply rules for building sources it contributes
drivers/driver_ext/ext_calibration.o: C:/SIM/CHIP_B80/tc_ble_simple_sdk-3.4.2.2/tc_ble_simple_sdk-3.4.2.2/b80_ble_sdk/drivers/driver_ext/ext_calibration.c
	@echo 'Building file: $<'
	@echo 'Invoking: TC32 Compiler'
	tc32-elf-gcc -ffunction-sections -fdata-sections -I"C:\SIM\CHIP_B80\tc_ble_simple_sdk-3.4.2.2\tc_ble_simple_sdk-3.4.2.2\b80_ble_sdk\project\tlsr_tc32\B80" -I"C:\SIM\CHIP_B80\tc_ble_simple_sdk-3.4.2.2\tc_ble_simple_sdk-3.4.2.2\b80_ble_sdk\project\tlsr_tc32\B80/../../.." -I"C:\SIM\CHIP_B80\tc_ble_simple_sdk-3.4.2.2\tc_ble_simple_sdk-3.4.2.2\b80_ble_sdk\drivers" -I"C:\SIM\CHIP_B80\tc_ble_simple_sdk-3.4.2.2\tc_ble_simple_sdk-3.4.2.2\b80_ble_sdk\common" -I"C:\SIM\CHIP_B80\tc_ble_simple_sdk-3.4.2.2\tc_ble_simple_sdk-3.4.2.2\b80_ble_sdk\vendor\common" -DMCU_CORE_B80=1 -D__PROJECT_B80_BLE_SAMPLE__=1 -Wall -O2 -fpack-struct -fshort-enums -finline-small-functions -std=gnu99 -fshort-wchar -fms-extensions -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

drivers/driver_ext/ext_misc.o: C:/SIM/CHIP_B80/tc_ble_simple_sdk-3.4.2.2/tc_ble_simple_sdk-3.4.2.2/b80_ble_sdk/drivers/driver_ext/ext_misc.c
	@echo 'Building file: $<'
	@echo 'Invoking: TC32 Compiler'
	tc32-elf-gcc -ffunction-sections -fdata-sections -I"C:\SIM\CHIP_B80\tc_ble_simple_sdk-3.4.2.2\tc_ble_simple_sdk-3.4.2.2\b80_ble_sdk\project\tlsr_tc32\B80" -I"C:\SIM\CHIP_B80\tc_ble_simple_sdk-3.4.2.2\tc_ble_simple_sdk-3.4.2.2\b80_ble_sdk\project\tlsr_tc32\B80/../../.." -I"C:\SIM\CHIP_B80\tc_ble_simple_sdk-3.4.2.2\tc_ble_simple_sdk-3.4.2.2\b80_ble_sdk\drivers" -I"C:\SIM\CHIP_B80\tc_ble_simple_sdk-3.4.2.2\tc_ble_simple_sdk-3.4.2.2\b80_ble_sdk\common" -I"C:\SIM\CHIP_B80\tc_ble_simple_sdk-3.4.2.2\tc_ble_simple_sdk-3.4.2.2\b80_ble_sdk\vendor\common" -DMCU_CORE_B80=1 -D__PROJECT_B80_BLE_SAMPLE__=1 -Wall -O2 -fpack-struct -fshort-enums -finline-small-functions -std=gnu99 -fshort-wchar -fms-extensions -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

drivers/driver_ext/rf_pa.o: C:/SIM/CHIP_B80/tc_ble_simple_sdk-3.4.2.2/tc_ble_simple_sdk-3.4.2.2/b80_ble_sdk/drivers/driver_ext/rf_pa.c
	@echo 'Building file: $<'
	@echo 'Invoking: TC32 Compiler'
	tc32-elf-gcc -ffunction-sections -fdata-sections -I"C:\SIM\CHIP_B80\tc_ble_simple_sdk-3.4.2.2\tc_ble_simple_sdk-3.4.2.2\b80_ble_sdk\project\tlsr_tc32\B80" -I"C:\SIM\CHIP_B80\tc_ble_simple_sdk-3.4.2.2\tc_ble_simple_sdk-3.4.2.2\b80_ble_sdk\project\tlsr_tc32\B80/../../.." -I"C:\SIM\CHIP_B80\tc_ble_simple_sdk-3.4.2.2\tc_ble_simple_sdk-3.4.2.2\b80_ble_sdk\drivers" -I"C:\SIM\CHIP_B80\tc_ble_simple_sdk-3.4.2.2\tc_ble_simple_sdk-3.4.2.2\b80_ble_sdk\common" -I"C:\SIM\CHIP_B80\tc_ble_simple_sdk-3.4.2.2\tc_ble_simple_sdk-3.4.2.2\b80_ble_sdk\vendor\common" -DMCU_CORE_B80=1 -D__PROJECT_B80_BLE_SAMPLE__=1 -Wall -O2 -fpack-struct -fshort-enums -finline-small-functions -std=gnu99 -fshort-wchar -fms-extensions -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

drivers/driver_ext/rf_private_pa.o: C:/SIM/CHIP_B80/tc_ble_simple_sdk-3.4.2.2/tc_ble_simple_sdk-3.4.2.2/b80_ble_sdk/drivers/driver_ext/rf_private_pa.c
	@echo 'Building file: $<'
	@echo 'Invoking: TC32 Compiler'
	tc32-elf-gcc -ffunction-sections -fdata-sections -I"C:\SIM\CHIP_B80\tc_ble_simple_sdk-3.4.2.2\tc_ble_simple_sdk-3.4.2.2\b80_ble_sdk\project\tlsr_tc32\B80" -I"C:\SIM\CHIP_B80\tc_ble_simple_sdk-3.4.2.2\tc_ble_simple_sdk-3.4.2.2\b80_ble_sdk\project\tlsr_tc32\B80/../../.." -I"C:\SIM\CHIP_B80\tc_ble_simple_sdk-3.4.2.2\tc_ble_simple_sdk-3.4.2.2\b80_ble_sdk\drivers" -I"C:\SIM\CHIP_B80\tc_ble_simple_sdk-3.4.2.2\tc_ble_simple_sdk-3.4.2.2\b80_ble_sdk\common" -I"C:\SIM\CHIP_B80\tc_ble_simple_sdk-3.4.2.2\tc_ble_simple_sdk-3.4.2.2\b80_ble_sdk\vendor\common" -DMCU_CORE_B80=1 -D__PROJECT_B80_BLE_SAMPLE__=1 -Wall -O2 -fpack-struct -fshort-enums -finline-small-functions -std=gnu99 -fshort-wchar -fms-extensions -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


