/********************************************************************************************************
 * @file    l2cap.h
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
#ifndef _L2CAP_H
#define _L2CAP_H




/**
 * @brief	Connection parameter update response
 */
typedef enum{
	CONN_PARAM_UPDATE_ACCEPT = 0x0000,
	CONN_PARAM_UPDATE_REJECT = 0x0001,
}conn_para_up_rsp;


typedef int (*l2cap_handler_t) (u16 conn, u8 * p);

/**
 * @brief	This function is used to set connect request parameter for updating connect parameter
 * @param	min_interval - connect interval minimum
 * @param	max_interval - connect interval maximum
 * @param	latency - connect latency
 * @param	timeout - connect timeout
 * @return	none.
 */
void		bls_l2cap_requestConnParamUpdate (u16 min_interval, u16 max_interval, u16 latency, u16 timeout);


/**
 * @brief	This function is used to set the minimal time for sending connect parameter update request after connect being created
 * @param	time_ms - the unit is millisecond
 * @return	none.
 */
void        bls_l2cap_setMinimalUpdateReqSendingTime_after_connCreate(int time_ms);


/**
 * @brief	This function is used to register the function for handler L2CAP data
 * @param	p - the pointer direct to blc_l2cap_handler
 * @return	none.
 */
void		blc_l2cap_register_handler (void *p);


/**
 * @brief	This function is used to handler L2CAP data
 * @param	connHandle - connection handle
 * @param	p - the pointer of l2cap data
 * @return	0
 */
int 		blc_l2cap_packet_receive (u16 connHandle, u8 * p);


/**
 * @brief	This function is used to register the function to process L2CAP SIG CHANNEL packet
 * @param	p - the pointer of l2cap data
 * @return	none.
 */
void 		blc_l2cap_reg_att_sig_handler(void *p);


/**
 * @brief		This function is used to initialize l2cap buffer to reassembly link lay PDU to SDU
 * @param[in]	pL2cap_rx_buff - the pointer of rx buffer
 * @param[in]	l2cap_rx_size   - the size of of rx buffer
 * @return		none.
 */
void 		blc_l2cap_initRxDataBuffer(u8 *pL2cap_rx_buff, u16 l2cap_rx_size);

/**
 * @brief	This function is used to send connect parameter update response
 * @param	connHandle - connection handle
 * @param	req_id - Request packet identifier
 * @param	result - connect parameter update result
 * @return	none.
 */
void  		blc_l2cap_SendConnParamUpdateResponse(u16 connHandle, u8 req_id, conn_para_up_rsp result);


#endif
