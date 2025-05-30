/********************************************************************************************************
 * @file    app_buffer.h
 *
 * @brief   This is the header file for BLE SDK
 *
 * @author  BLE GROUP
 * @date    12,2021
 *
 * @par     Copyright (c) 2021, Telink Semiconductor (Shanghai) Co., Ltd. ("TELINK")
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
#ifndef VENDOR_B80_BLE_SAMPLE_APP_BUFFER_H_
#define VENDOR_B80_BLE_SAMPLE_APP_BUFFER_H_



#if (FEATURE_TEST_MODE == TEST_FEATURE_BACKUP)



/**
 * @brief	connMaxRxOctets
 * refer to BLE SPEC "4.5.10 Data PDU length management" & "2.4.2.21 LL_LENGTH_REQ and LL_LENGTH_RSP"
 * usage limitation:
 * 1. should be in range of 27 ~ 251
 */
#define ACL_CONN_MAX_RX_OCTETS			27


/**
 * @brief	connMaxTxOctets
 * refer to BLE SPEC "4.5.10 Data PDU length management" & "2.4.2.21 LL_LENGTH_REQ and LL_LENGTH_RSP"
 * usage limitation:
 * 1. connMaxTxOctets should be in range of 27 ~ 251
 */
#define ACL_CONN_MAX_TX_OCTETS			27




/********************* ACL connection LinkLayer TX & RX data FIFO allocation, Begin ************************************************/
/**
 * @brief	ACL RX buffer size & number
 *  		ACL RX buffer is used to hold LinkLayer RF RX data.
 * usage limitation for ACL_RX_FIFO_SIZE:
 * 1. should be greater than or equal to (connMaxRxOctets + 22)
 * 2. should be be an integer multiple of 16 (16 Byte align)
 * 3. user can use formula:  size = CAL_LL_ACL_RX_FIFO_SIZE(connMaxRxOctets)
 * usage limitation for ACL_RX_FIFO_NUM:
 * 1. must be: 2^n, (power of 2)
 * 2. at least 4; recommended value: 8, 16
 */
#define ACL_RX_FIFO_SIZE				CAL_LL_ACL_RX_FIFO_SIZE(ACL_CONN_MAX_RX_OCTETS)
#define ACL_RX_FIFO_NUM					4	// must be: 2^n


/**
 * @brief	ACL TX buffer size & number
 *          ACL TX buffer is used to hold LinkLayer RF TX data.
 * usage limitation for ACL_TX_FIFO_SIZE:
 * 1. should be greater than or equal to (connMaxTxOctets + 10)
 * 2. should be be an integer multiple of 4 (4 Byte align)
 * 3. user can use formula:  size = CAL_LL_ACL_TX_FIFO_SIZE(connMaxTxOctets)
 * usage limitation for ACL_TX_FIFO_NUM:
 * 1. must be: 2^n  (power of 2)
 * 2. at least 8; recommended value: 8, 16, 32; other value not allowed.
 */
#define ACL_TX_FIFO_SIZE				CAL_LL_ACL_TX_FIFO_SIZE(ACL_CONN_MAX_TX_OCTETS)
#define ACL_TX_FIFO_NUM					8




extern	u8	app_acl_rxfifo[];
extern	u8	app_acl_txfifo[];
/******************** ACL connection LinkLayer TX & RX data FIFO allocation, End ***************************************************/







/***************** ACL connection L2CAP layer RX data FIFO allocation, Begin ********************************/

/* RX MTU size */
#define MTU_SIZE_SETTING						23


/**
 * @brief	L2CAP RX Buffer size
 * L2CAP RX buffer is used in stack, to hold split l2cap packet data sent by peer device, and will combine
 *                 them to one complete packet when last sub_packet come, then use for upper layer.
 * usage limitation for L2CAP_RX_BUFF_SIZE:
 *  1. should be greater than or equal to (MTU_SIZE_SETTING + 6)
 *  2. should be be an integer multiple of 4 (4 Byte align)
 */
#define	L2CAP_RX_BUFF_SIZE					CAL_L2CAP_BUFF_SIZE(MTU_SIZE_SETTING)


extern	u8 app_l2cap_rx_fifo[];
/***************** ACL connection L2CAP layer RX data FIFO allocation, End **********************************/




#endif //end of (FEATURE_TEST_MODE == xxx)
#endif /* VENDOR_B80_BLE_SAMPLE_APP_BUFFER_H_ */

