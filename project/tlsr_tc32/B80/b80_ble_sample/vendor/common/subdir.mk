################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/SIM/CHIP_B80/tc_ble_simple_sdk-3.4.2.2/tc_ble_simple_sdk-3.4.2.2/b80_ble_sdk/vendor/common/app_common.c \
C:/SIM/CHIP_B80/tc_ble_simple_sdk-3.4.2.2/tc_ble_simple_sdk-3.4.2.2/b80_ble_sdk/vendor/common/battery_check.c \
C:/SIM/CHIP_B80/tc_ble_simple_sdk-3.4.2.2/tc_ble_simple_sdk-3.4.2.2/b80_ble_sdk/vendor/common/ble_flash.c \
C:/SIM/CHIP_B80/tc_ble_simple_sdk-3.4.2.2/tc_ble_simple_sdk-3.4.2.2/b80_ble_sdk/vendor/common/blt_fw_sign.c \
C:/SIM/CHIP_B80/tc_ble_simple_sdk-3.4.2.2/tc_ble_simple_sdk-3.4.2.2/b80_ble_sdk/vendor/common/blt_led.c \
C:/SIM/CHIP_B80/tc_ble_simple_sdk-3.4.2.2/tc_ble_simple_sdk-3.4.2.2/b80_ble_sdk/vendor/common/blt_soft_timer.c \
C:/SIM/CHIP_B80/tc_ble_simple_sdk-3.4.2.2/tc_ble_simple_sdk-3.4.2.2/b80_ble_sdk/vendor/common/custom_pair.c \
C:/SIM/CHIP_B80/tc_ble_simple_sdk-3.4.2.2/tc_ble_simple_sdk-3.4.2.2/b80_ble_sdk/vendor/common/flash_fw_check.c \
C:/SIM/CHIP_B80/tc_ble_simple_sdk-3.4.2.2/tc_ble_simple_sdk-3.4.2.2/b80_ble_sdk/vendor/common/flash_prot.c \
C:/SIM/CHIP_B80/tc_ble_simple_sdk-3.4.2.2/tc_ble_simple_sdk-3.4.2.2/b80_ble_sdk/vendor/common/simple_sdp.c \
C:/SIM/CHIP_B80/tc_ble_simple_sdk-3.4.2.2/tc_ble_simple_sdk-3.4.2.2/b80_ble_sdk/vendor/common/software_uart.c 

OBJS += \
./vendor/common/app_common.o \
./vendor/common/battery_check.o \
./vendor/common/ble_flash.o \
./vendor/common/blt_fw_sign.o \
./vendor/common/blt_led.o \
./vendor/common/blt_soft_timer.o \
./vendor/common/custom_pair.o \
./vendor/common/flash_fw_check.o \
./vendor/common/flash_prot.o \
./vendor/common/simple_sdp.o \
./vendor/common/software_uart.o 


# Each subdirectory must supply rules for building sources it contributes
vendor/common/app_common.o: C:/SIM/CHIP_B80/tc_ble_simple_sdk-3.4.2.2/tc_ble_simple_sdk-3.4.2.2/b80_ble_sdk/vendor/common/app_common.c
	@echo 'Building file: $<'
	@echo 'Invoking: TC32 Compiler'
	tc32-elf-gcc -ffunction-sections -fdata-sections -I"C:\SIM\CHIP_B80\tc_ble_simple_sdk-3.4.2.2\tc_ble_simple_sdk-3.4.2.2\b80_ble_sdk\project\tlsr_tc32\B80" -I"C:\SIM\CHIP_B80\tc_ble_simple_sdk-3.4.2.2\tc_ble_simple_sdk-3.4.2.2\b80_ble_sdk\project\tlsr_tc32\B80/../../.." -I"C:\SIM\CHIP_B80\tc_ble_simple_sdk-3.4.2.2\tc_ble_simple_sdk-3.4.2.2\b80_ble_sdk\drivers" -I"C:\SIM\CHIP_B80\tc_ble_simple_sdk-3.4.2.2\tc_ble_simple_sdk-3.4.2.2\b80_ble_sdk\common" -I"C:\SIM\CHIP_B80\tc_ble_simple_sdk-3.4.2.2\tc_ble_simple_sdk-3.4.2.2\b80_ble_sdk\vendor\common" -DMCU_CORE_B80=1 -D__PROJECT_B80_BLE_SAMPLE__=1 -Wall -O2 -fpack-struct -fshort-enums -finline-small-functions -std=gnu99 -fshort-wchar -fms-extensions -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

vendor/common/battery_check.o: C:/SIM/CHIP_B80/tc_ble_simple_sdk-3.4.2.2/tc_ble_simple_sdk-3.4.2.2/b80_ble_sdk/vendor/common/battery_check.c
	@echo 'Building file: $<'
	@echo 'Invoking: TC32 Compiler'
	tc32-elf-gcc -ffunction-sections -fdata-sections -I"C:\SIM\CHIP_B80\tc_ble_simple_sdk-3.4.2.2\tc_ble_simple_sdk-3.4.2.2\b80_ble_sdk\project\tlsr_tc32\B80" -I"C:\SIM\CHIP_B80\tc_ble_simple_sdk-3.4.2.2\tc_ble_simple_sdk-3.4.2.2\b80_ble_sdk\project\tlsr_tc32\B80/../../.." -I"C:\SIM\CHIP_B80\tc_ble_simple_sdk-3.4.2.2\tc_ble_simple_sdk-3.4.2.2\b80_ble_sdk\drivers" -I"C:\SIM\CHIP_B80\tc_ble_simple_sdk-3.4.2.2\tc_ble_simple_sdk-3.4.2.2\b80_ble_sdk\common" -I"C:\SIM\CHIP_B80\tc_ble_simple_sdk-3.4.2.2\tc_ble_simple_sdk-3.4.2.2\b80_ble_sdk\vendor\common" -DMCU_CORE_B80=1 -D__PROJECT_B80_BLE_SAMPLE__=1 -Wall -O2 -fpack-struct -fshort-enums -finline-small-functions -std=gnu99 -fshort-wchar -fms-extensions -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

vendor/common/ble_flash.o: C:/SIM/CHIP_B80/tc_ble_simple_sdk-3.4.2.2/tc_ble_simple_sdk-3.4.2.2/b80_ble_sdk/vendor/common/ble_flash.c
	@echo 'Building file: $<'
	@echo 'Invoking: TC32 Compiler'
	tc32-elf-gcc -ffunction-sections -fdata-sections -I"C:\SIM\CHIP_B80\tc_ble_simple_sdk-3.4.2.2\tc_ble_simple_sdk-3.4.2.2\b80_ble_sdk\project\tlsr_tc32\B80" -I"C:\SIM\CHIP_B80\tc_ble_simple_sdk-3.4.2.2\tc_ble_simple_sdk-3.4.2.2\b80_ble_sdk\project\tlsr_tc32\B80/../../.." -I"C:\SIM\CHIP_B80\tc_ble_simple_sdk-3.4.2.2\tc_ble_simple_sdk-3.4.2.2\b80_ble_sdk\drivers" -I"C:\SIM\CHIP_B80\tc_ble_simple_sdk-3.4.2.2\tc_ble_simple_sdk-3.4.2.2\b80_ble_sdk\common" -I"C:\SIM\CHIP_B80\tc_ble_simple_sdk-3.4.2.2\tc_ble_simple_sdk-3.4.2.2\b80_ble_sdk\vendor\common" -DMCU_CORE_B80=1 -D__PROJECT_B80_BLE_SAMPLE__=1 -Wall -O2 -fpack-struct -fshort-enums -finline-small-functions -std=gnu99 -fshort-wchar -fms-extensions -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

vendor/common/blt_fw_sign.o: C:/SIM/CHIP_B80/tc_ble_simple_sdk-3.4.2.2/tc_ble_simple_sdk-3.4.2.2/b80_ble_sdk/vendor/common/blt_fw_sign.c
	@echo 'Building file: $<'
	@echo 'Invoking: TC32 Compiler'
	tc32-elf-gcc -ffunction-sections -fdata-sections -I"C:\SIM\CHIP_B80\tc_ble_simple_sdk-3.4.2.2\tc_ble_simple_sdk-3.4.2.2\b80_ble_sdk\project\tlsr_tc32\B80" -I"C:\SIM\CHIP_B80\tc_ble_simple_sdk-3.4.2.2\tc_ble_simple_sdk-3.4.2.2\b80_ble_sdk\project\tlsr_tc32\B80/../../.." -I"C:\SIM\CHIP_B80\tc_ble_simple_sdk-3.4.2.2\tc_ble_simple_sdk-3.4.2.2\b80_ble_sdk\drivers" -I"C:\SIM\CHIP_B80\tc_ble_simple_sdk-3.4.2.2\tc_ble_simple_sdk-3.4.2.2\b80_ble_sdk\common" -I"C:\SIM\CHIP_B80\tc_ble_simple_sdk-3.4.2.2\tc_ble_simple_sdk-3.4.2.2\b80_ble_sdk\vendor\common" -DMCU_CORE_B80=1 -D__PROJECT_B80_BLE_SAMPLE__=1 -Wall -O2 -fpack-struct -fshort-enums -finline-small-functions -std=gnu99 -fshort-wchar -fms-extensions -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

vendor/common/blt_led.o: C:/SIM/CHIP_B80/tc_ble_simple_sdk-3.4.2.2/tc_ble_simple_sdk-3.4.2.2/b80_ble_sdk/vendor/common/blt_led.c
	@echo 'Building file: $<'
	@echo 'Invoking: TC32 Compiler'
	tc32-elf-gcc -ffunction-sections -fdata-sections -I"C:\SIM\CHIP_B80\tc_ble_simple_sdk-3.4.2.2\tc_ble_simple_sdk-3.4.2.2\b80_ble_sdk\project\tlsr_tc32\B80" -I"C:\SIM\CHIP_B80\tc_ble_simple_sdk-3.4.2.2\tc_ble_simple_sdk-3.4.2.2\b80_ble_sdk\project\tlsr_tc32\B80/../../.." -I"C:\SIM\CHIP_B80\tc_ble_simple_sdk-3.4.2.2\tc_ble_simple_sdk-3.4.2.2\b80_ble_sdk\drivers" -I"C:\SIM\CHIP_B80\tc_ble_simple_sdk-3.4.2.2\tc_ble_simple_sdk-3.4.2.2\b80_ble_sdk\common" -I"C:\SIM\CHIP_B80\tc_ble_simple_sdk-3.4.2.2\tc_ble_simple_sdk-3.4.2.2\b80_ble_sdk\vendor\common" -DMCU_CORE_B80=1 -D__PROJECT_B80_BLE_SAMPLE__=1 -Wall -O2 -fpack-struct -fshort-enums -finline-small-functions -std=gnu99 -fshort-wchar -fms-extensions -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

vendor/common/blt_soft_timer.o: C:/SIM/CHIP_B80/tc_ble_simple_sdk-3.4.2.2/tc_ble_simple_sdk-3.4.2.2/b80_ble_sdk/vendor/common/blt_soft_timer.c
	@echo 'Building file: $<'
	@echo 'Invoking: TC32 Compiler'
	tc32-elf-gcc -ffunction-sections -fdata-sections -I"C:\SIM\CHIP_B80\tc_ble_simple_sdk-3.4.2.2\tc_ble_simple_sdk-3.4.2.2\b80_ble_sdk\project\tlsr_tc32\B80" -I"C:\SIM\CHIP_B80\tc_ble_simple_sdk-3.4.2.2\tc_ble_simple_sdk-3.4.2.2\b80_ble_sdk\project\tlsr_tc32\B80/../../.." -I"C:\SIM\CHIP_B80\tc_ble_simple_sdk-3.4.2.2\tc_ble_simple_sdk-3.4.2.2\b80_ble_sdk\drivers" -I"C:\SIM\CHIP_B80\tc_ble_simple_sdk-3.4.2.2\tc_ble_simple_sdk-3.4.2.2\b80_ble_sdk\common" -I"C:\SIM\CHIP_B80\tc_ble_simple_sdk-3.4.2.2\tc_ble_simple_sdk-3.4.2.2\b80_ble_sdk\vendor\common" -DMCU_CORE_B80=1 -D__PROJECT_B80_BLE_SAMPLE__=1 -Wall -O2 -fpack-struct -fshort-enums -finline-small-functions -std=gnu99 -fshort-wchar -fms-extensions -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

vendor/common/custom_pair.o: C:/SIM/CHIP_B80/tc_ble_simple_sdk-3.4.2.2/tc_ble_simple_sdk-3.4.2.2/b80_ble_sdk/vendor/common/custom_pair.c
	@echo 'Building file: $<'
	@echo 'Invoking: TC32 Compiler'
	tc32-elf-gcc -ffunction-sections -fdata-sections -I"C:\SIM\CHIP_B80\tc_ble_simple_sdk-3.4.2.2\tc_ble_simple_sdk-3.4.2.2\b80_ble_sdk\project\tlsr_tc32\B80" -I"C:\SIM\CHIP_B80\tc_ble_simple_sdk-3.4.2.2\tc_ble_simple_sdk-3.4.2.2\b80_ble_sdk\project\tlsr_tc32\B80/../../.." -I"C:\SIM\CHIP_B80\tc_ble_simple_sdk-3.4.2.2\tc_ble_simple_sdk-3.4.2.2\b80_ble_sdk\drivers" -I"C:\SIM\CHIP_B80\tc_ble_simple_sdk-3.4.2.2\tc_ble_simple_sdk-3.4.2.2\b80_ble_sdk\common" -I"C:\SIM\CHIP_B80\tc_ble_simple_sdk-3.4.2.2\tc_ble_simple_sdk-3.4.2.2\b80_ble_sdk\vendor\common" -DMCU_CORE_B80=1 -D__PROJECT_B80_BLE_SAMPLE__=1 -Wall -O2 -fpack-struct -fshort-enums -finline-small-functions -std=gnu99 -fshort-wchar -fms-extensions -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

vendor/common/flash_fw_check.o: C:/SIM/CHIP_B80/tc_ble_simple_sdk-3.4.2.2/tc_ble_simple_sdk-3.4.2.2/b80_ble_sdk/vendor/common/flash_fw_check.c
	@echo 'Building file: $<'
	@echo 'Invoking: TC32 Compiler'
	tc32-elf-gcc -ffunction-sections -fdata-sections -I"C:\SIM\CHIP_B80\tc_ble_simple_sdk-3.4.2.2\tc_ble_simple_sdk-3.4.2.2\b80_ble_sdk\project\tlsr_tc32\B80" -I"C:\SIM\CHIP_B80\tc_ble_simple_sdk-3.4.2.2\tc_ble_simple_sdk-3.4.2.2\b80_ble_sdk\project\tlsr_tc32\B80/../../.." -I"C:\SIM\CHIP_B80\tc_ble_simple_sdk-3.4.2.2\tc_ble_simple_sdk-3.4.2.2\b80_ble_sdk\drivers" -I"C:\SIM\CHIP_B80\tc_ble_simple_sdk-3.4.2.2\tc_ble_simple_sdk-3.4.2.2\b80_ble_sdk\common" -I"C:\SIM\CHIP_B80\tc_ble_simple_sdk-3.4.2.2\tc_ble_simple_sdk-3.4.2.2\b80_ble_sdk\vendor\common" -DMCU_CORE_B80=1 -D__PROJECT_B80_BLE_SAMPLE__=1 -Wall -O2 -fpack-struct -fshort-enums -finline-small-functions -std=gnu99 -fshort-wchar -fms-extensions -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

vendor/common/flash_prot.o: C:/SIM/CHIP_B80/tc_ble_simple_sdk-3.4.2.2/tc_ble_simple_sdk-3.4.2.2/b80_ble_sdk/vendor/common/flash_prot.c
	@echo 'Building file: $<'
	@echo 'Invoking: TC32 Compiler'
	tc32-elf-gcc -ffunction-sections -fdata-sections -I"C:\SIM\CHIP_B80\tc_ble_simple_sdk-3.4.2.2\tc_ble_simple_sdk-3.4.2.2\b80_ble_sdk\project\tlsr_tc32\B80" -I"C:\SIM\CHIP_B80\tc_ble_simple_sdk-3.4.2.2\tc_ble_simple_sdk-3.4.2.2\b80_ble_sdk\project\tlsr_tc32\B80/../../.." -I"C:\SIM\CHIP_B80\tc_ble_simple_sdk-3.4.2.2\tc_ble_simple_sdk-3.4.2.2\b80_ble_sdk\drivers" -I"C:\SIM\CHIP_B80\tc_ble_simple_sdk-3.4.2.2\tc_ble_simple_sdk-3.4.2.2\b80_ble_sdk\common" -I"C:\SIM\CHIP_B80\tc_ble_simple_sdk-3.4.2.2\tc_ble_simple_sdk-3.4.2.2\b80_ble_sdk\vendor\common" -DMCU_CORE_B80=1 -D__PROJECT_B80_BLE_SAMPLE__=1 -Wall -O2 -fpack-struct -fshort-enums -finline-small-functions -std=gnu99 -fshort-wchar -fms-extensions -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

vendor/common/simple_sdp.o: C:/SIM/CHIP_B80/tc_ble_simple_sdk-3.4.2.2/tc_ble_simple_sdk-3.4.2.2/b80_ble_sdk/vendor/common/simple_sdp.c
	@echo 'Building file: $<'
	@echo 'Invoking: TC32 Compiler'
	tc32-elf-gcc -ffunction-sections -fdata-sections -I"C:\SIM\CHIP_B80\tc_ble_simple_sdk-3.4.2.2\tc_ble_simple_sdk-3.4.2.2\b80_ble_sdk\project\tlsr_tc32\B80" -I"C:\SIM\CHIP_B80\tc_ble_simple_sdk-3.4.2.2\tc_ble_simple_sdk-3.4.2.2\b80_ble_sdk\project\tlsr_tc32\B80/../../.." -I"C:\SIM\CHIP_B80\tc_ble_simple_sdk-3.4.2.2\tc_ble_simple_sdk-3.4.2.2\b80_ble_sdk\drivers" -I"C:\SIM\CHIP_B80\tc_ble_simple_sdk-3.4.2.2\tc_ble_simple_sdk-3.4.2.2\b80_ble_sdk\common" -I"C:\SIM\CHIP_B80\tc_ble_simple_sdk-3.4.2.2\tc_ble_simple_sdk-3.4.2.2\b80_ble_sdk\vendor\common" -DMCU_CORE_B80=1 -D__PROJECT_B80_BLE_SAMPLE__=1 -Wall -O2 -fpack-struct -fshort-enums -finline-small-functions -std=gnu99 -fshort-wchar -fms-extensions -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

vendor/common/software_uart.o: C:/SIM/CHIP_B80/tc_ble_simple_sdk-3.4.2.2/tc_ble_simple_sdk-3.4.2.2/b80_ble_sdk/vendor/common/software_uart.c
	@echo 'Building file: $<'
	@echo 'Invoking: TC32 Compiler'
	tc32-elf-gcc -ffunction-sections -fdata-sections -I"C:\SIM\CHIP_B80\tc_ble_simple_sdk-3.4.2.2\tc_ble_simple_sdk-3.4.2.2\b80_ble_sdk\project\tlsr_tc32\B80" -I"C:\SIM\CHIP_B80\tc_ble_simple_sdk-3.4.2.2\tc_ble_simple_sdk-3.4.2.2\b80_ble_sdk\project\tlsr_tc32\B80/../../.." -I"C:\SIM\CHIP_B80\tc_ble_simple_sdk-3.4.2.2\tc_ble_simple_sdk-3.4.2.2\b80_ble_sdk\drivers" -I"C:\SIM\CHIP_B80\tc_ble_simple_sdk-3.4.2.2\tc_ble_simple_sdk-3.4.2.2\b80_ble_sdk\common" -I"C:\SIM\CHIP_B80\tc_ble_simple_sdk-3.4.2.2\tc_ble_simple_sdk-3.4.2.2\b80_ble_sdk\vendor\common" -DMCU_CORE_B80=1 -D__PROJECT_B80_BLE_SAMPLE__=1 -Wall -O2 -fpack-struct -fshort-enums -finline-small-functions -std=gnu99 -fshort-wchar -fms-extensions -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


