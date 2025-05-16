################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/SIM/CHIP_B80/tc_ble_simple_sdk-3.4.2.2/tc_ble_simple_sdk-3.4.2.2/b80_ble_sdk/vendor/ble_sample/app.c \
C:/SIM/CHIP_B80/tc_ble_simple_sdk-3.4.2.2/tc_ble_simple_sdk-3.4.2.2/b80_ble_sdk/vendor/ble_sample/app_att.c \
C:/SIM/CHIP_B80/tc_ble_simple_sdk-3.4.2.2/tc_ble_simple_sdk-3.4.2.2/b80_ble_sdk/vendor/ble_sample/app_buffer.c \
C:/SIM/CHIP_B80/tc_ble_simple_sdk-3.4.2.2/tc_ble_simple_sdk-3.4.2.2/b80_ble_sdk/vendor/ble_sample/app_ui.c \
C:/SIM/CHIP_B80/tc_ble_simple_sdk-3.4.2.2/tc_ble_simple_sdk-3.4.2.2/b80_ble_sdk/vendor/ble_sample/main.c 

OBJS += \
./vendor/ble_sample/app.o \
./vendor/ble_sample/app_att.o \
./vendor/ble_sample/app_buffer.o \
./vendor/ble_sample/app_ui.o \
./vendor/ble_sample/main.o 


# Each subdirectory must supply rules for building sources it contributes
vendor/ble_sample/app.o: C:/SIM/CHIP_B80/tc_ble_simple_sdk-3.4.2.2/tc_ble_simple_sdk-3.4.2.2/b80_ble_sdk/vendor/ble_sample/app.c
	@echo 'Building file: $<'
	@echo 'Invoking: TC32 Compiler'
	tc32-elf-gcc -ffunction-sections -fdata-sections -I"C:\SIM\CHIP_B80\tc_ble_simple_sdk-3.4.2.2\tc_ble_simple_sdk-3.4.2.2\b80_ble_sdk\project\tlsr_tc32\B80" -I"C:\SIM\CHIP_B80\tc_ble_simple_sdk-3.4.2.2\tc_ble_simple_sdk-3.4.2.2\b80_ble_sdk\project\tlsr_tc32\B80/../../.." -I"C:\SIM\CHIP_B80\tc_ble_simple_sdk-3.4.2.2\tc_ble_simple_sdk-3.4.2.2\b80_ble_sdk\drivers" -I"C:\SIM\CHIP_B80\tc_ble_simple_sdk-3.4.2.2\tc_ble_simple_sdk-3.4.2.2\b80_ble_sdk\common" -I"C:\SIM\CHIP_B80\tc_ble_simple_sdk-3.4.2.2\tc_ble_simple_sdk-3.4.2.2\b80_ble_sdk\vendor\common" -DMCU_CORE_B80=1 -D__PROJECT_B80_BLE_SAMPLE__=1 -Wall -O2 -fpack-struct -fshort-enums -finline-small-functions -std=gnu99 -fshort-wchar -fms-extensions -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

vendor/ble_sample/app_att.o: C:/SIM/CHIP_B80/tc_ble_simple_sdk-3.4.2.2/tc_ble_simple_sdk-3.4.2.2/b80_ble_sdk/vendor/ble_sample/app_att.c
	@echo 'Building file: $<'
	@echo 'Invoking: TC32 Compiler'
	tc32-elf-gcc -ffunction-sections -fdata-sections -I"C:\SIM\CHIP_B80\tc_ble_simple_sdk-3.4.2.2\tc_ble_simple_sdk-3.4.2.2\b80_ble_sdk\project\tlsr_tc32\B80" -I"C:\SIM\CHIP_B80\tc_ble_simple_sdk-3.4.2.2\tc_ble_simple_sdk-3.4.2.2\b80_ble_sdk\project\tlsr_tc32\B80/../../.." -I"C:\SIM\CHIP_B80\tc_ble_simple_sdk-3.4.2.2\tc_ble_simple_sdk-3.4.2.2\b80_ble_sdk\drivers" -I"C:\SIM\CHIP_B80\tc_ble_simple_sdk-3.4.2.2\tc_ble_simple_sdk-3.4.2.2\b80_ble_sdk\common" -I"C:\SIM\CHIP_B80\tc_ble_simple_sdk-3.4.2.2\tc_ble_simple_sdk-3.4.2.2\b80_ble_sdk\vendor\common" -DMCU_CORE_B80=1 -D__PROJECT_B80_BLE_SAMPLE__=1 -Wall -O2 -fpack-struct -fshort-enums -finline-small-functions -std=gnu99 -fshort-wchar -fms-extensions -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

vendor/ble_sample/app_buffer.o: C:/SIM/CHIP_B80/tc_ble_simple_sdk-3.4.2.2/tc_ble_simple_sdk-3.4.2.2/b80_ble_sdk/vendor/ble_sample/app_buffer.c
	@echo 'Building file: $<'
	@echo 'Invoking: TC32 Compiler'
	tc32-elf-gcc -ffunction-sections -fdata-sections -I"C:\SIM\CHIP_B80\tc_ble_simple_sdk-3.4.2.2\tc_ble_simple_sdk-3.4.2.2\b80_ble_sdk\project\tlsr_tc32\B80" -I"C:\SIM\CHIP_B80\tc_ble_simple_sdk-3.4.2.2\tc_ble_simple_sdk-3.4.2.2\b80_ble_sdk\project\tlsr_tc32\B80/../../.." -I"C:\SIM\CHIP_B80\tc_ble_simple_sdk-3.4.2.2\tc_ble_simple_sdk-3.4.2.2\b80_ble_sdk\drivers" -I"C:\SIM\CHIP_B80\tc_ble_simple_sdk-3.4.2.2\tc_ble_simple_sdk-3.4.2.2\b80_ble_sdk\common" -I"C:\SIM\CHIP_B80\tc_ble_simple_sdk-3.4.2.2\tc_ble_simple_sdk-3.4.2.2\b80_ble_sdk\vendor\common" -DMCU_CORE_B80=1 -D__PROJECT_B80_BLE_SAMPLE__=1 -Wall -O2 -fpack-struct -fshort-enums -finline-small-functions -std=gnu99 -fshort-wchar -fms-extensions -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

vendor/ble_sample/app_ui.o: C:/SIM/CHIP_B80/tc_ble_simple_sdk-3.4.2.2/tc_ble_simple_sdk-3.4.2.2/b80_ble_sdk/vendor/ble_sample/app_ui.c
	@echo 'Building file: $<'
	@echo 'Invoking: TC32 Compiler'
	tc32-elf-gcc -ffunction-sections -fdata-sections -I"C:\SIM\CHIP_B80\tc_ble_simple_sdk-3.4.2.2\tc_ble_simple_sdk-3.4.2.2\b80_ble_sdk\project\tlsr_tc32\B80" -I"C:\SIM\CHIP_B80\tc_ble_simple_sdk-3.4.2.2\tc_ble_simple_sdk-3.4.2.2\b80_ble_sdk\project\tlsr_tc32\B80/../../.." -I"C:\SIM\CHIP_B80\tc_ble_simple_sdk-3.4.2.2\tc_ble_simple_sdk-3.4.2.2\b80_ble_sdk\drivers" -I"C:\SIM\CHIP_B80\tc_ble_simple_sdk-3.4.2.2\tc_ble_simple_sdk-3.4.2.2\b80_ble_sdk\common" -I"C:\SIM\CHIP_B80\tc_ble_simple_sdk-3.4.2.2\tc_ble_simple_sdk-3.4.2.2\b80_ble_sdk\vendor\common" -DMCU_CORE_B80=1 -D__PROJECT_B80_BLE_SAMPLE__=1 -Wall -O2 -fpack-struct -fshort-enums -finline-small-functions -std=gnu99 -fshort-wchar -fms-extensions -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

vendor/ble_sample/main.o: C:/SIM/CHIP_B80/tc_ble_simple_sdk-3.4.2.2/tc_ble_simple_sdk-3.4.2.2/b80_ble_sdk/vendor/ble_sample/main.c
	@echo 'Building file: $<'
	@echo 'Invoking: TC32 Compiler'
	tc32-elf-gcc -ffunction-sections -fdata-sections -I"C:\SIM\CHIP_B80\tc_ble_simple_sdk-3.4.2.2\tc_ble_simple_sdk-3.4.2.2\b80_ble_sdk\project\tlsr_tc32\B80" -I"C:\SIM\CHIP_B80\tc_ble_simple_sdk-3.4.2.2\tc_ble_simple_sdk-3.4.2.2\b80_ble_sdk\project\tlsr_tc32\B80/../../.." -I"C:\SIM\CHIP_B80\tc_ble_simple_sdk-3.4.2.2\tc_ble_simple_sdk-3.4.2.2\b80_ble_sdk\drivers" -I"C:\SIM\CHIP_B80\tc_ble_simple_sdk-3.4.2.2\tc_ble_simple_sdk-3.4.2.2\b80_ble_sdk\common" -I"C:\SIM\CHIP_B80\tc_ble_simple_sdk-3.4.2.2\tc_ble_simple_sdk-3.4.2.2\b80_ble_sdk\vendor\common" -DMCU_CORE_B80=1 -D__PROJECT_B80_BLE_SAMPLE__=1 -Wall -O2 -fpack-struct -fshort-enums -finline-small-functions -std=gnu99 -fshort-wchar -fms-extensions -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


