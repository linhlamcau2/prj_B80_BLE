/********************************************************************************************************
 * @file    ble_common.h
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
#ifndef BLE_COMMON_H
#define BLE_COMMON_H

#include "tl_common.h"



typedef enum {
    BLE_SUCCESS = 0,

//// HCI Status, refer to BLE Core Specification: Vol 1, Part F, "1.3 LIST OF ERROR CODES" for more information.
    HCI_ERR_UNKNOWN_HCI_CMD                                        = 0x01,
    HCI_ERR_UNKNOWN_CONN_ID                                        = 0x02,
    HCI_ERR_HW_FAILURE                                             = 0x03,
    HCI_ERR_PAGE_TIMEOUT                                           = 0x04,
    HCI_ERR_AUTH_FAILURE                                           = 0x05,
    HCI_ERR_PIN_KEY_MISSING                                        = 0x06,
    HCI_ERR_MEM_CAP_EXCEEDED                                       = 0x07,
    HCI_ERR_CONN_TIMEOUT                                           = 0x08,
    HCI_ERR_CONN_LIMIT_EXCEEDED                                    = 0x09,
    HCI_ERR_SYNCH_CONN_LIMIT_EXCEEDED                              = 0x0A,
    HCI_ERR_ACL_CONN_ALREADY_EXISTS                                = 0x0B,
    HCI_ERR_CMD_DISALLOWED                                         = 0x0C,
    HCI_ERR_CONN_REJ_LIMITED_RESOURCES                             = 0x0D,
    HCI_ERR_CONN_REJECTED_SECURITY_REASONS                         = 0x0E,
    HCI_ERR_CONN_REJECTED_UNACCEPTABLE_BDADDR                      = 0x0F,
    HCI_ERR_CONN_ACCEPT_TIMEOUT_EXCEEDED                           = 0x10,
    HCI_ERR_UNSUPPORTED_FEATURE_PARAM_VALUE                        = 0x11,
    HCI_ERR_INVALID_HCI_CMD_PARAMS                                 = 0x12,
    HCI_ERR_REMOTE_USER_TERM_CONN                                  = 0x13,
    HCI_ERR_REMOTE_DEVICE_TERM_CONN_LOW_RESOURCES                  = 0x14,
    HCI_ERR_REMOTE_DEVICE_TERM_CONN_POWER_OFF                      = 0x15,
    HCI_ERR_CONN_TERM_BY_LOCAL_HOST                                = 0x16,
    HCI_ERR_REPEATED_ATTEMPTS                                      = 0x17,
    HCI_ERR_PAIRING_NOT_ALLOWED                                    = 0x18,
    HCI_ERR_UNKNOWN_LMP_PDU                                        = 0x19,
    HCI_ERR_UNSUPPORTED_REMOTE_FEATURE                             = 0x1A,
    HCI_ERR_SCO_OFFSET_REJ                                         = 0x1B,
    HCI_ERR_SCO_INTERVAL_REJ                                       = 0x1C,
    HCI_ERR_SCO_AIR_MODE_REJ                                       = 0x1D,
    HCI_ERR_INVALID_LMP_PARAMS                                     = 0x1E,
    HCI_ERR_UNSPECIFIED_ERROR                                      = 0x1F,
    HCI_ERR_UNSUPPORTED_LMP_PARAM_VAL                              = 0x20,
    HCI_ERR_ROLE_CHANGE_NOT_ALLOWED                                = 0x21,
    HCI_ERR_LMP_LL_RESP_TIMEOUT                                    = 0x22,
    HCI_ERR_LMP_ERR_TRANSACTION_COLLISION                          = 0x23,
    HCI_ERR_LMP_PDU_NOT_ALLOWED                                    = 0x24,
    HCI_ERR_ENCRYPT_MODE_NOT_ACCEPTABLE                            = 0x25,
    HCI_ERR_LINK_KEY_CAN_NOT_BE_CHANGED                            = 0x26,
    HCI_ERR_REQ_QOS_NOT_SUPPORTED                                  = 0x27,
    HCI_ERR_INSTANT_PASSED                                         = 0x28,
    HCI_ERR_PAIRING_WITH_UNIT_KEY_NOT_SUPPORTED                    = 0x29,
    HCI_ERR_DIFFERENT_TRANSACTION_COLLISION                        = 0x2A,
    HCI_ERR_RESERVED1                                              = 0x2B,
    HCI_ERR_QOS_UNACCEPTABLE_PARAM                                 = 0x2C,
    HCI_ERR_QOS_REJ                                                = 0x2D,
    HCI_ERR_CHAN_ASSESSMENT_NOT_SUPPORTED                          = 0x2E,
    HCI_ERR_INSUFFICIENT_SECURITY                                  = 0x2F,
    HCI_ERR_PARAM_OUT_OF_MANDATORY_RANGE                           = 0x30,
    HCI_ERR_RESERVED2                                              = 0x31,
    HCI_ERR_ROLE_SWITCH_PENDING                                    = 0x32,
    HCI_ERR_RESERVED3                                              = 0x33,
    HCI_ERR_RESERVED_SLOT_VIOLATION                                = 0x34,
    HCI_ERR_ROLE_SWITCH_FAILED                                     = 0x35,
    HCI_ERR_EXTENDED_INQUIRY_RESP_TOO_LARGE                        = 0x36,
    HCI_ERR_SIMPLE_PAIRING_NOT_SUPPORTED_BY_HOST                   = 0x37,
    HCI_ERR_HOST_BUSY_PAIRING                                      = 0x38,
    HCI_ERR_CONN_REJ_NO_SUITABLE_CHAN_FOUND                        = 0x39,
    HCI_ERR_CONTROLLER_BUSY                                        = 0x3A,
    HCI_ERR_UNACCEPTABLE_CONN_INTERVAL                             = 0x3B,
    HCI_ERR_ADVERTISING_TIMEOUT                                    = 0x3C,
    HCI_ERR_CONN_TERM_MIC_FAILURE                                  = 0x3D,
    HCI_ERR_CONN_FAILED_TO_ESTABLISH                               = 0x3E,
    HCI_ERR_MAC_CONN_FAILED                                        = 0x3F,
    HCI_ERR_COARSE_CLOCK_ADJUSTMENT_REJECT						   = 0x40,
    HCI_ERR_TYPE0_SUBMAP_NOT_DEFINED							   = 0x41,
	HCI_ERR_UNKNOWN_ADV_IDENTIFIER								   = 0x42,
    HCI_ERR_LIMIT_REACHED										   = 0x43,
    HCI_ERR_OP_CANCELLED_BY_HOST								   = 0x44,
    HCI_ERR_PACKET_TOO_LONG										   = 0x45,

    //telink define
    HCI_ERR_CONTROLLER_TX_FIFO_NOT_ENOUGH						   = HCI_ERR_CONTROLLER_BUSY,  //0x3A
    HCI_ERR_CONN_NOT_ESTABLISH									   = HCI_ERR_CONN_FAILED_TO_ESTABLISH,  //0x3E
	HCI_ERR_CURRENT_STATE_NOT_SUPPORTED_THIS_CMD 				   = HCI_ERR_CONTROLLER_BUSY,


///////////////////////// TELINK define status /////////////////////////////

    //LL status
	LL_ERR_CONNECTION_NOT_ESTABLISH 							   = 0x80,
	LL_ERR_TX_FIFO_NOT_ENOUGH,
	LL_ERR_ENCRYPTION_BUSY,
	LL_ERR_CURRENT_STATE_NOT_SUPPORTED_THIS_CMD,
	LL_ERR_INVALID_PARAMETER,
	LL_ERR_UNKNOWN_OPCODE,

	LL_ERR_CIS_SYNC_FAIL,
	LL_ERR_CIS_DISCONNECT,


	//L2CAP status
    L2CAP_ERR_INVALID_PARAMETER 								   = 0x90,
    L2CAP_ERR_INVALID_HANDLE,
    L2CAP_ERR_INSUFFICIENT_RESOURCES,
    L2CAP_ERR_PSM_NOT_REGISTER,
    L2CAP_ERR_CONTROL_NOT_READY,
    L2CAP_ERR_PSM_HAVE_ESTABLISH,

    //SMP status
	SMP_ERR_INVALID_PARAMETER 									   = 0xA0,
	SMP_ERR_PAIRING_BUSY,
    SMP_ERR_NO_SIGN_KEY,
    SMP_EER_PAIRING_IS_GOING_ON,

	//GATT status
	GATT_ERR_INVALID_PARAMETER 									   = 0xB0,
	GATT_ERR_PREVIOUS_INDICATE_DATA_HAS_NOT_CONFIRMED,
	GATT_ERR_SERVICE_DISCOVERY_TIMEOUT,
	GATT_ERR_NOTIFY_INDICATION_NOT_PERMITTED,
	GATT_ERR_DATA_PENDING_DUE_TO_SERVICE_DISCOVERY_BUSY,
	GATT_ERR_DATA_LENGTH_EXCEED_MTU_SIZE,

	//GAP status
	GAP_ERR_INVALID_PARAMETER 								   	   = 0xC0,


	//Service status
	SERVICE_ERR_INVALID_PARAMETER 								   = 0xD0,
    BLE_ERR_DUPLICATE_PACKET,

	//Application buffer check error code
	LL_ACL_RX_BUF_NO_INIT 							   	  		   = 0xE0,
	LL_ACL_RX_BUF_PARAM_INVALID,
	LL_ACL_RX_BUF_SIZE_NOT_MEET_MAX_RX_OCT,
	LL_ACL_TX_BUF_NO_INIT,
	LL_ACL_TX_BUF_PARAM_INVALID,
	LL_ACL_TX_BUF_SIZE_MUL_NUM_EXCEED_4K,
	LL_ACL_TX_BUF_SIZE_NOT_MEET_MAX_TX_OCT,

} ble_sts_t;

/**
 *  @brief  error code for user initialization error
 */
typedef enum {
    INIT_SUCCESS = 0,

	////////////////////////// Controller //////////////////////////////

    INIT_ERR_LL_ACL_RX_BUF_NO_INIT 						 = 0x1000,
    INIT_ERR_LL_ACL_RX_BUF_PARAM_INVALID,
    INIT_ERR_LL_ACL_RX_BUF_SIZE_NOT_MEET_MAX_RX_OCT,
    INIT_ERR_LL_ACL_TX_BUF_NO_INIT,
    INIT_ERR_LL_ACL_TX_BUF_PARAM_INVALID,
    INIT_ERR_LL_ACL_TX_BUF_SIZE_NOT_MEET_MAX_TX_OCT,




	///////////////////////////// Host ///////////////////////////////

	////////////// GAP /////////////
    INIT_ERR_GAP_PARAM_INVALID				= 0x2000,

	//
	////////////// L2CAP /////////////
    INIT_ERR_L2CAP_PARAM_INVALID			= 0x2100,


	////////////// ATT /////////////
    INIT_ERR_ATT_PARAM_INVALID				= 0x2200,
	INIT_ERR_ATT_MTU_SIZE_INVALID,
	/* MTU buffer is not enough for MTU size, user need register new buffer with API "blc l2cap_initMtuBuffer" */
	INIT_ERR_ATT_MTU_BUFF_NOT_MATCH_MTU_SIZE,






	////////////// GATT /////////////
    INIT_ERR_GATT_PARAM_INVALID				 = 0x2300,



	////////////// SMP /////////////
    INIT_ERR_SMP_PARAM_INVALID				 = 0x2400,
	/* user set bonding maximum number exceed stack design limitation. If default maximum number can not meet user's requirement,
	 * they should contact Telink for support */
	INIT_ERR_SMP_BONDING_MAX_NUMBER_EXCEED,
	INIT_ERR_SMP_MTU_SIZE_NOT_MATCH_SC,						 //MTU should equal to or greater than 65 for secure connection


	////////////////// Service/Profile /////////////////////


} init_err_t;



/**
 *  @brief  Definition for Error Response of ATTRIBUTE PROTOCOL PDUS
 *  See the Core_v5.0(Vol 3/Part F/3.4.1.1, "Error Response") for more information.
 */
typedef enum {

	ATT_SUCCESS = 0,  	ATT_ERR_START = 0,

    ATT_ERR_INVALID_HANDLE,                              //!< The attribute handle given was not valid on this server
    ATT_ERR_READ_NOT_PERMITTED,                          //!< The attribute cannot be read
    ATT_ERR_WRITE_NOT_PERMITTED,                         //!< The attribute cannot be written
    ATT_ERR_INVALID_PDU,                                 //!< The attribute PDU was invalid
    ATT_ERR_INSUFFICIENT_AUTH,                           //!< The attribute requires authentication before it can be read or written
    ATT_ERR_REQ_NOT_SUPPORTED,                           //!< Attribute server does not support the request received from the client
    ATT_ERR_INVALID_OFFSET,                              //!< Offset specified was past the end of the attribute
    ATT_ERR_INSUFFICIENT_AUTHOR,                         //!< The attribute requires authorization before it can be read or written
    ATT_ERR_PREPARE_QUEUE_FULL,                          //!< Too many prepare writes have been queued
    ATT_ERR_ATTR_NOT_FOUND,                              //!< No attribute found within the given attribute handle range
    ATT_ERR_ATTR_NOT_LONG,                               //!< The attribute cannot be read or written using the Read Blob Request
    ATT_ERR_INSUFFICIENT_KEY_SIZE,                       //!< The Encryption Key Size used for encrypting this link is insufficient
    ATT_ERR_INVALID_ATTR_VALUE_LEN,                      //!< The attribute value length is invalid for the operation
    ATT_ERR_UNLIKELY_ERR,                                //!< The attribute request that was requested has encountered an error that was unlikely, and therefore could not be completed as requested
    ATT_ERR_INSUFFICIENT_ENCRYPT,                        //!< The attribute requires encryption before it can be read or written
    ATT_ERR_UNSUPPORTED_GRP_TYPE,                        //!< The attribute type is not a supported grouping attribute as defined by a higher layer specification
    ATT_ERR_INSUFFICIENT_RESOURCES,                      //!< Insufficient Resources to complete the request

	/* List of Common Profile and Service Error Codes */
	ATT_ERR_WRITE_REQUEST_REJECT = 0xFC,                //!< Write Request Rejected
	ATT_ERR_CCC_DESCRIPTOR_IMPROPERLY_CONFIGURED,        //!< Client Characteristic Configuration Descriptor Improperly Configured
	ATT_ERR_PROCEDURE_ALREADY_IN_PROGRESS,               //!< Procedure Already in Progress
	ATT_ERR_OUT_OF_RANGE,                                //!< Out of Range

}att_err_t;


/////////////////////////////// BLE  MAC ADDRESS //////////////////////////////////////////////
#define BLE_ADDR_PUBLIC                  0
#define BLE_ADDR_RANDOM                  1
#define BLE_ADDR_INVALID                 0xff
#define BLE_ADDR_LEN                     6

//Definition for BLE Common Address Type
/*
 *
 *				  |--public  ..................................................... BLE_DEVICE_ADDRESS_PUBLIC
 *                |
 * Address Type --|		      |-- random static  ................................. BLE_DEVICE_ADDRESS_RANDOM_STATIC
 *           	  |           |
 *    			  |--random --|
 * 			   				  |				       |-- non_resolvable private  ... BLE_DEVICE_ADDRESS_NON_RESOLVABLE_PRIVATE
 * 			 				  |-- random private --|
 *           					                   |-- resolvable private  ....... BLE_DEVICE_ADDRESS_RESOLVABLE_PRIVATE
 *
 */

#define	BLE_DEVICE_ADDRESS_PUBLIC							1
#define BLE_DEVICE_ADDRESS_RANDOM_STATIC					2
#define BLE_DEVICE_ADDRESS_NON_RESOLVABLE_PRIVATE			3
#define BLE_DEVICE_ADDRESS_RESOLVABLE_PRIVATE				4



#define IS_PUBLIC_ADDR(Type, Addr)  					( (Type)==BLE_ADDR_PUBLIC) )
#define IS_RANDOM_STATIC_ADDR(Type, Addr)  				( (Type)==BLE_ADDR_RANDOM && (Addr[5] & 0xC0) == 0xC0 )
#define IS_NON_RESOLVABLE_PRIVATE_ADDR(Type, Addr)  	( (Type)==BLE_ADDR_RANDOM && (Addr[5] & 0xC0) == 0x00 )
#define IS_RESOLVABLE_PRIVATE_ADDR(Type, Addr)  		( (Type)==BLE_ADDR_RANDOM && (Addr[5] & 0xC0) == 0x40 )


#define		MAC_MATCH8(md,ms)	(md[0]==ms[0] && md[1]==ms[1] && md[2]==ms[2] && md[3]==ms[3] && md[4]==ms[4] && md[5]==ms[5])
#define		MAC_MATCH16(md,ms)	(md[0]==ms[0] && md[1]==ms[1] && md[2]==ms[2])
#define		MAC_MATCH32(md,ms)	(md[0]==ms[0] && md[1]==ms[1])

/******************************************** L2CAP ***************************************************************/
/**
 *  @brief  Definition for L2CAP CID name space for the LE-U
 */
typedef enum{
	L2CAP_CID_NULL				= 0x0000,
	L2CAP_CID_ATTR_PROTOCOL		= 0x0004,
	L2CAP_CID_SIG_CHANNEL		= 0x0005,
	L2CAP_CID_SMP				= 0x0006,
}l2cap_cid_type;

/**
 *  @brief  Definition for L2CAP signal packet formats
 */
typedef enum{
	L2CAP_COMMAND_REJECT_RSP           		= 0x01,
	L2CAP_CONNECTION_REQ                 	= 0x02,
	L2CAP_CONNECTION_RSP                 	= 0x03,
	L2CAP_CONFIGURATION_REQ                	= 0x04,
	L2CAP_CONFIGURATION_RSP           		= 0x05,
	L2CAP_DISCONNECTION_REQ           		= 0x06,
	L2CAP_DISCONNECTION_RSP           		= 0x07,
	L2CAP_ECHO_REQ          		 		= 0x08,
	L2CAP_ECHO_RSP           				= 0x09,
	L2CAP_INFORMATION_REQ           		= 0x0A,
	L2CAP_INFORMATION_RSP           		= 0x0B,
	L2CAP_CREATE_CHANNEL_REQ          		= 0x0C,
	L2CAP_CREATE_CHANNEL_RSP           		= 0x0D,
	L2CAP_MOVE_CHANNEL_REQ           		= 0x0E,
	L2CAP_MOVE_CHANNEL_RSP           		= 0x0F,
	L2CAP_MOVE_CHANNEL_CONFIRMATION_REQ		= 0x10,
	L2CAP_MOVE_CHANNEL_CONFIRMATION_RSP     = 0x11,
	L2CAP_CONNECTION_PARAMETER_UPDATE_REQ	= 0x12,		L2CAP_CMD_CONN_UPD_PARA_REQ		= 0x12,
	L2CAP_CONNECTION_PARAMETER_UPDATE_RSP	= 0x13,		L2CAP_CMD_CONN_UPD_PARA_RESP 	= 0x13,
	L2CAP_LE_CREDIT_BASED_CONNECTION_REQ 	= 0x14,
	L2CAP_LE_CREDIT_BASED_CONNECTION_RSP 	= 0x15,
	L2CAP_FLOW_CONTROL_CREDIT_IND 			= 0x16,
	L2CAP_CREDIT_BASED_CONNECTION_REQ 		= 0x17,	//core_5.2
	L2CAP_CREDIT_BASED_CONNECTION_RSP 		= 0x18,	//core_5.2
	L2CAP_CREDIT_BASED_RECONFIGURE_REQ 		= 0x19,	//core_5.2
	L2CAP_CREDIT_BASED_RECONFIGURE_RSP 		= 0x1A,	//core_5.2
}l2cap_sig_pkt_format;

/******************************************** ATT ***************************************************************/
/**
 *  @brief  Definition for Attribute protocol PDUs
 */
typedef enum{
	ATT_OP_ERROR_RSP					= 0x01,
	ATT_OP_EXCHANGE_MTU_REQ				= 0x02,
	ATT_OP_EXCHANGE_MTU_RSP				= 0x03,
	ATT_OP_FIND_INFORMATION_REQ			= 0x04,		ATT_OP_FIND_INFO_REQ = 0x04,
	ATT_OP_FIND_INFORMATION_RSP			= 0x05,		ATT_OP_FIND_INFO_RSP = 0x05,
	ATT_OP_FIND_BY_TYPE_VALUE_REQ		= 0x06,
	ATT_OP_FIND_BY_TYPE_VALUE_RSP		= 0x07,
	ATT_OP_READ_BY_TYPE_REQ				= 0x08,
	ATT_OP_READ_BY_TYPE_RSP				= 0x09,
	ATT_OP_READ_REQ						= 0x0A,
	ATT_OP_READ_RSP						= 0x0B,
	ATT_OP_READ_BLOB_REQ				= 0x0C,
	ATT_OP_READ_BLOB_RSP				= 0x0D,
	ATT_OP_READ_MULTIPLE_REQ			= 0x0E,		ATT_OP_READ_MULTI_REQ = 0x0E,
	ATT_OP_READ_MULTIPLE_RSP			= 0x0F,
	ATT_OP_READ_BY_GROUP_TYPE_REQ		= 0x10,
	ATT_OP_READ_BY_GROUP_TYPE_RSP		= 0x11,
	ATT_OP_WRITE_REQ					= 0x12,
	ATT_OP_WRITE_RSP					= 0x13,
	ATT_OP_PREPARE_WRITE_REQ			= 0x16,
	ATT_OP_PREPARE_WRITE_RSP			= 0x17,
	ATT_OP_EXECUTE_WRITE_REQ			= 0x18,
	ATT_OP_EXECUTE_WRITE_RSP			= 0x19,

	ATT_OP_HANDLE_VALUE_NTF				= 0x1B,		ATT_OP_HANDLE_VALUE_NOTI = 0x1B,
	ATT_OP_HANDLE_VALUE_IND				= 0x1D,
	ATT_OP_HANDLE_VALUE_CFM				= 0x1E,

	ATT_OP_READ_MULTIPLE_VARIABLE_REQ	= 0x20,	//core_5.2
	ATT_OP_READ_MULTIPLE_VARIABLE_RSP	= 0x21, //core_5.2
	ATT_OP_MULTIPLE_HANDLE_VALUE_NTF	= 0x23, //core_5.2

	ATT_OP_WRITE_CMD					= 0x52,
	ATT_OP_SIGNED_WRITE_CMD				= 0xD2,
}att_pdu_type;



/******************************************** GAP ***************************************************************/

// https://www.bluetooth.com/specifications/assigned-numbers/generic-access-profile/
// EIR Data Type, Advertising Data Type (AD Type) and OOB Data Type Definitions

typedef enum {
	DT_FLAGS								= 0x01,		//	Flag
	DT_INCOMPLETE_LIST_16BIT_SERVICE_UUID		= 0x02,		//	Incomplete List of 16-bit Service Class UUIDs
	DT_COMPLETE_LIST_16BIT_SERVICE_UUID	    = 0x03,		//	Complete List of 16-bit Service Class UUIDs
	DT_INCOMPLT_LIST_32BIT_SERVICE_UUID    	= 0x04,		//	Incomplete List of 32-bit Service Class UUIDs
	DT_COMPLETE_LIST_32BIT_SERVICE_UUID		= 0x05,		//	Complete List of 32-bit Service Class UUIDs
	DT_INCOMPLT_LIST_128BIT_SERVICE_UUID   	= 0x06,		//	Incomplete List of 128-bit Service Class UUIDs
	DT_COMPLETE_LIST_128BIT_SERVICE_UUID	= 0x07,		//	Complete List of 128-bit Service Class UUIDs
	DT_SHORTENED_LOCAL_NAME					= 0x08,		//	Shortened Local Name
	DT_COMPLETE_LOCAL_NAME					= 0x09,		//	Complete Local Name
	DT_TX_POWER_LEVEL						= 0x0A,		//	Tx Power Level

	DT_CLASS_OF_DEVICE						= 0x0D,		//	Class of Device
	DT_SERVICE_DATA							= 0x16,		//	Service Data
	DT_APPEARANCE							= 0x19,		//	Appearance

	DT_CHM_UPT_IND							= 0x28,		//	Channel Map Update Indication
	DT_BIGINFO								= 0x2C,		//	BIGInfo
	DT_BROADCAST_CODE						= 0x2D,		// 	Broadcast_Code
	DT_3D_INFORMATION_DATA					= 0x3D,		//	3D Information Data

	DT_MANUFACTURER_SPECIFIC_DATA 	= 0xFF,     //	Manufacturer Specific Data
}data_type_t;








/**
 * @brief	6 = header(2)+l2cap_len(2)+CID(2)
 */
#define		CAL_L2CAP_BUFF_SIZE(n)				(((n + 6) + 3)/4 * 4)

/**
 * @brief      get SDK and Lib version.User should get at least 5 bytes,first 5 bytes show the SDK
 * 			   version and the rest is reserved for future.
 * 			   For example, if the number you get is {3,4,0,0,1} after call this API(DEC), it stands for
 * 			   the SDK version is 3.4.0.0 patch 1.
 * @param[in]  pbuf - the point of buffer to store version message.
 * @param[in]  number - the length of version message,should be 5 to 16.
 * @return     0:success  1:number is invalid
 */
unsigned char blc_get_sdk_version(unsigned char *pbuf,unsigned char number);


#endif
