/********************************************************************************************************
 * @file    ll_scan.h
 *
 * @brief   This is the header file for BLE SDK
 *
 * @author  BLE GROUP
 * @date    06,2022
 *
 * @par     Copyright (c) 2022, Telink Semiconductor (Shanghai) Co., Ltd. ("TELINK")
 *
 *          Licensed under the Apache License, Version 2.0 (the "License");
 *          you may not use this file except in compliance with the License.
 *          You may obtain a copy of the License at
 *
 *              http://www.apache.org/licenses/LICENSE-2.0
 *
 *          Unless required by applicable law or agreed to in writing, software
 *          distributed under the License is distributed on an "AS IS" BASIS,
 *          WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *          See the License for the specific language governing permissions and
 *          limitations under the License.
 *
 *******************************************************************************************************/
#ifndef LL_SCAN_H_
#define LL_SCAN_H_


/**
 * @brief      This function is used to set the scan parameters
 * @param[in]  scan_type - passive Scanning or active scanning.Active scanning is unavailable.
 * @param[in]  scan_interval - time interval from when the Controller started its last LE scan until it begins the subsequent LE scan
 * @param[in]  scan_window - The duration of the LE scan.
 * @param[in]  ownAddrType - Own_Address_Type
 * @param[in]  scanFilterPolicy
 * @return     Status - 0x00: command succeeded; 0x01-0xFF: command failed
 */
ble_sts_t 	blc_ll_setScanParameter (scan_type_t scan_type, u16 scan_interval, u16 scan_window, own_addr_type_t  ownAddrType, scan_fp_type_t scanFilter_policy);

/**
 * @brief      This function is used to initialize scanning.
 * @param[in]  none.
 * @return     Status - 0x00: BLE success; 0x01-0xFF: fail
 */
ble_sts_t	blt_ll_initScanState(void);

/**
 * @brief      This function is used to add scan state in advertise state of slave role.
 * @param[in]  none.
 * @return     Status - 0x00: BLE success; 0x01-0xFF: fail
 */
ble_sts_t    blc_ll_addScanningInAdvState(void);


/**
 * @brief      This function is used to remove scan state in advertise state of slave role.
 * @param[in]  none.
 * @return      Status - 0x00: BLE success; 0x01-0xFF: fail
 */
ble_sts_t    blc_ll_removeScanningFromAdvState(void);


/**
 * @brief      This function is used to add scan state in connect state of slave role.
 * @param[in]  none.
 * @return     Status - 0x00: BLE success; 0x01-0xFF: fail
 */
ble_sts_t    blc_ll_addScanningInConnSlaveRole(void);


/**
 * @brief      This function is used to remove scan state in connect state of slave role.
 * @param[in]  none.
 * @return      Status - 0x00: BLE success; 0x01-0xFF: fail
 */
ble_sts_t    blc_ll_removeScanningFromConnSLaveRole(void);



#endif /* LL_SCAN_H_ */
