/********************************************************************************************************
 * @file    hci_cmd.h
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
#ifndef HCI_CMD_H_
#define HCI_CMD_H_


#include "stack/ble/ble_format.h"


/**
 *  @brief  Bluetooth Core Specification version
 */
typedef enum{
	BLUETOOTH_CORE_4_2			=	0x08,
	BLUETOOTH_CORE_5_0			=	0x09,
	BLUETOOTH_CORE_5_1			=	0x0A,
	BLUETOOTH_CORE_5_2			=	0x0B,
	BLUETOOTH_CORE_5_3			=	0x0C,
}core_version_t;


/**
 *  @brief  Command Parameters for "7.1.6 Disconnect command"
 */
typedef struct {
	u16	connHandle;
	u8	reason;
} hci_disconnect_cmdParam_t;

/**
 *  @brief  Return Parameters for "7.3.93 Read Authenticated Payload Timeout command"
 */
typedef struct{
	u8		status;
	u16		connHandle;
	u16		auth_pdu_timeout;
} hci_readAuthPduTimeout_retParam_t;

/**
 *  @brief  Command & Return Parameters for "7.3.94 HCI write authenticated payload timeout"
 */
typedef struct
{
	u16 connHandle; //The actual usage is 12bit
	u16 timeout;   // unit: 10ms
} hci_writeAuthPayloadTimeout_cmdParam_t;

typedef struct
{
	u8 status;
	u16 connHandle; //The actual usage is 12bit
} hci_writeAuthPayloadTimeout_retParam_t;

/**
 *  @brief  Return Parameters for "7.4.3 Read Local Supported Features command"
 */
typedef struct {
	u8	status;
	u8	LMP_features[8];
} hci_readLocSupFeatures_retParam_t;


/**
 *  @brief  Return Parameters for "7.4.6 Read BD_ADDR command"
 */
typedef struct {
	u8	status;
	u8	bd_addr[6];
} hci_readBdAddr_retParam_t;



/**
 *  @brief  Return Parameters for "7.8.2 LE Read Buffer Size command"
 */
typedef struct {
	u8	status;
	u16	acl_data_pkt_len;  // LE_ACL_Data_Packet_Length
	u8	num_le_data_pkt;   // Total_Num_LE_ACL_Data_Packets
} hci_le_readBufSize_v1_retParam_t;



/**
 *  @brief  Return Parameters for "7.8.3 LE Read Local Supported Features command"
 */
typedef struct {
	u8	status;
	u8	le_features[8];
} hci_le_readLocSupFeature_retParam_t;


/**
 *  @brief  Command Parameters for "7.8.5 LE Set Advertising Parameters command"
 */
/* Advertising Parameters structure */
typedef struct {
	u16 intervalMin;      // Minimum advertising interval for non-directed advertising, time = N * 0.625ms
	u16 intervalMax;      // Maximum advertising interval for non-directed advertising, time = N * 0.625ms
	u8  advType;          // Advertising
	u8  ownAddrType;
	u8  peerAddrType;
	u8  peerAddr[6];//BLE_ADDR_LEN];
	u8  advChannelMap;
	u8  advFilterPolicy;
} hci_le_setAdvParam_cmdParam_t;


/* Advertising_Interval, Time = N * 0.625 ms,
 * Notice that these are just part of but not all Advertising_Interval value */
typedef enum{
	ADV_INTERVAL_3_125MS     =                   5,
	ADV_INTERVAL_3_75MS      =                   6,
	ADV_INTERVAL_10MS        =                   16,
	ADV_INTERVAL_15MS        =                   24,
	ADV_INTERVAL_20MS        =                   32,
	ADV_INTERVAL_25MS        =                   40,
	ADV_INTERVAL_30MS        =                   48,
	ADV_INTERVAL_35MS        =                   56,
	ADV_INTERVAL_40MS        =                   64,
	ADV_INTERVAL_45MS        =                   72,
	ADV_INTERVAL_50MS        =                   80,
	ADV_INTERVAL_60MS        =                   96,
	ADV_INTERVAL_70MS        =                   112,
	ADV_INTERVAL_80MS        =                   128,
	ADV_INTERVAL_90MS		 =					 144,
	ADV_INTERVAL_100MS       =                   160,
	ADV_INTERVAL_150MS       =                   240,
	ADV_INTERVAL_195MS       =                   312,
	ADV_INTERVAL_200MS       =                   320,
	ADV_INTERVAL_250MS       =                   400,
	ADV_INTERVAL_300MS       =                   480,
	ADV_INTERVAL_350MS       =                   560,
	ADV_INTERVAL_400MS       =                   640,
	ADV_INTERVAL_450MS       =                   720,
	ADV_INTERVAL_500MS       =                   800,
	ADV_INTERVAL_600MS       =                   960,
	ADV_INTERVAL_700MS       =                  1120,
	ADV_INTERVAL_800MS       =                  1280,
	ADV_INTERVAL_900MS       =                  1440,
	ADV_INTERVAL_1S          =                	1600,
	ADV_INTERVAL_1S5         =                 	2400,
	ADV_INTERVAL_2S          =                	3200,
	ADV_INTERVAL_1_28_S      =                  2048,
	ADV_INTERVAL_10_24S      =                 16384,
}adv_inter_t;


/* Advertisement Type */
typedef enum{
  ADV_TYPE_CONNECTABLE_UNDIRECTED             = 0x00,  // ADV_IND
  ADV_TYPE_CONNECTABLE_DIRECTED_HIGH_DUTY     = 0x01,  // ADV_INDIRECT_IND (high duty cycle)
  ADV_TYPE_SCANNABLE_UNDIRECTED               = 0x02 , // ADV_SCAN_IND
  ADV_TYPE_NONCONNECTABLE_UNDIRECTED          = 0x03 , // ADV_NONCONN_IND
  ADV_TYPE_CONNECTABLE_DIRECTED_LOW_DUTY      = 0x04,  // ADV_INDIRECT_IND (low duty cycle)
}adv_type_t;

/* Own Address Type */
typedef enum{
	OWN_ADDRESS_PUBLIC = 0,
	OWN_ADDRESS_RANDOM = 1,
	OWN_ADDRESS_RESOLVE_PRIVATE_PUBLIC = 2,
	OWN_ADDRESS_RESOLVE_PRIVATE_RANDOM = 3,
}own_addr_type_t;

/* Advertising_Channel_Map */
typedef enum{
	BLT_ENABLE_ADV_37	=		BIT(0),
	BLT_ENABLE_ADV_38	=		BIT(1),
	BLT_ENABLE_ADV_39	=		BIT(2),
	BLT_ENABLE_ADV_ALL	=		(BLT_ENABLE_ADV_37 | BLT_ENABLE_ADV_38 | BLT_ENABLE_ADV_39),
}adv_chn_map_t;

/* Advertising_Filter_Policy */
typedef enum {
	ADV_FP_ALLOW_SCAN_ANY_ALLOW_CONN_ANY        =		0x00,  // Process scan and connection requests from all devices
	ADV_FP_ALLOW_SCAN_WL_ALLOW_CONN_ANY         =		0x01,  // Process connection requests from all devices and only scan requests from devices that are in the White List.
	ADV_FP_ALLOW_SCAN_ANY_ALLOW_CONN_WL         =		0x02,  // Process scan requests from all devices and only connection requests from devices that are in the White List..
	ADV_FP_ALLOW_SCAN_WL_ALLOW_CONN_WL          =		0x03,  // Process scan and connection requests only from devices in the White List.

	ADV_FP_NONE									=		ADV_FP_ALLOW_SCAN_ANY_ALLOW_CONN_ANY, //adv filter policy set to zero, not use whitelist
} adv_fp_type_t;  //adv_filterPolicy_type_t


#define 	ALLOW_SCAN_WL								BIT(0)
#define 	ALLOW_CONN_WL								BIT(1)




/**
 *  @brief  Command Parameters for "7.8.9 LE Set Advertising Enable command"
 */
typedef enum {
	BLC_ADV_DISABLE = 0x00,
	BLC_ADV_ENABLE  = 0x01,
} adv_en_t;




/**
 *  @brief  Command Parameters for "7.8.10 LE Set Scan Parameters command"
 */
typedef enum {
	SCAN_TYPE_PASSIVE = 0x00,
	SCAN_TYPE_ACTIVE  = 0x01,
} scan_type_t;


/* Scanning_Interval, Time = N * 0.625 ms,
 * Notice that these are just part of but not all Scanning_Interval value */
typedef enum{
	SCAN_INTERVAL_10MS              =            16,
	SCAN_INTERVAL_20MS              =            32,
	SCAN_INTERVAL_30MS              =            48,
	SCAN_INTERVAL_40MS              =            64,
	SCAN_INTERVAL_50MS              =            80,
	SCAN_INTERVAL_60MS              =            96,
	SCAN_INTERVAL_70MS              =            112,
	SCAN_INTERVAL_80MS              =            128,
	SCAN_INTERVAL_90MS              =            144,
	SCAN_INTERVAL_100MS             =            160,
	SCAN_INTERVAL_150MS             =            240,
	SCAN_INTERVAL_200MS             =            320,
	SCAN_INTERVAL_250MS             =            400,
	SCAN_INTERVAL_300MS             =            480,
	SCAN_INTERVAL_350MS             =            560,
	SCAN_INTERVAL_400MS             =            640,
	SCAN_INTERVAL_450MS             =            720,
	SCAN_INTERVAL_500MS             =            800,
	SCAN_INTERVAL_600MS             =            960,
	SCAN_INTERVAL_700MS             =            1120,
	SCAN_INTERVAL_800MS             =            1280,
	SCAN_INTERVAL_900MS             =            1440,
	SCAN_INTERVAL_1000MS            =            1600,
}scan_inter_t;

/* Scanning_Window, Time = N * 0.625 ms,
 * Notice that these are just part of but not all Scanning_Window value */
typedef enum{
	SCAN_WINDOW_10MS                =            16,
	SCAN_WINDOW_20MS                =            32,
	SCAN_WINDOW_30MS                =            48,
	SCAN_WINDOW_40MS                =            64,
	SCAN_WINDOW_50MS                =            80,
	SCAN_WINDOW_60MS                =            96,
	SCAN_WINDOW_70MS                =            112,
	SCAN_WINDOW_80MS                =            128,
	SCAN_WINDOW_90MS                =            144,
	SCAN_WINDOW_100MS               =            160,
	SCAN_WINDOW_150MS               =            240,
	SCAN_WINDOW_200MS               =            320,
	SCAN_WINDOW_250MS               =            400,
	SCAN_WINDOW_300MS               =            480,
	SCAN_WINDOW_350MS               =            560,
	SCAN_WINDOW_400MS               =            640,
	SCAN_WINDOW_450MS               =            720,
	SCAN_WINDOW_500MS               =            800,
	SCAN_WINDOW_600MS               =            960,
	SCAN_WINDOW_700MS               =            1120,
	SCAN_WINDOW_800MS               =            1280,
	SCAN_WINDOW_900MS               =            1440,
	SCAN_WINDOW_1000MS              =            1600,
}scan_wind_t;

/* Scanning_Filter_Policy */
typedef enum {
	SCAN_FP_ALLOW_ADV_ANY						=		0x00,  //except direct adv address not match
	SCAN_FP_ALLOW_ADV_WL        				=		0x01,  //except direct adv address not match
	SCAN_FP_ALLOW_UNDIRECT_ADV      			=		0x02,  //and direct adv address match initiator's resolvable private MAC
	SCAN_FP_ALLOW_ADV_WL_DIRECT_ADV_MATCH		=		0x03,  //and direct adv address match initiator's resolvable private MAC

} scan_fp_type_t;



/**
 *  @brief  Command Parameters for "7.8.11 LE Set Scan Enable command"
 */
/* LE_Scan_Enable */
typedef enum {
	BLC_SCAN_DISABLE = 0x00,
	BLC_SCAN_ENABLE  = 0x01,
} scan_en_t;

/* Filter_Duplicates */
typedef enum {
	DUP_FILTER_DISABLE = 0x00,
	DUP_FILTER_ENABLE  = 0x01,
} dupFilter_en_t;




/**
 *  @brief  Command Parameters for "7.8.12 LE Create Connection command"
 */
typedef struct{
	u16		scan_inter;
	u16		scan_wind;
	u8		fp; //init_filter_policy
  	u8		peerAddr_type;
	u8		peer_addr[6];
	u8		ownAddr_type;
  	u16		conn_min;
  	u16		conn_max;
  	u16 	connLatency;
  	u16		timeout;
  	u16		ceLen_min;
  	u16		ceLen_max;
} hci_le_createConn_cmdParam_t;



/* Initiator_Filter_Policy */
typedef enum {
	INITIATE_FP_ADV_SPECIFY        				=		0x00,  //connect ADV specified by host
	INITIATE_FP_ADV_WL         					=		0x01,  //connect ADV in whiteList
} init_fp_t;


/* Connection_Interval, Time = N * 1.25 ms,
 * Notice that these are just part of but not all Connection_Interval value */
typedef enum{
	CONN_INTERVAL_7P5MS              =            6,
	CONN_INTERVAL_8P75MS             =            7,
	CONN_INTERVAL_10MS               =            8,
	CONN_INTERVAL_11P25MS            =            9,
	CONN_INTERVAL_12P5MS             =            10,
	CONN_INTERVAL_13P75MS            =            11,
	CONN_INTERVAL_15MS               =            12,
	CONN_INTERVAL_16P25MS            =            13,
	CONN_INTERVAL_17P5MS             =            14,
	CONN_INTERVAL_18P75MS            =            15,
	CONN_INTERVAL_20MS               =            16,
	CONN_INTERVAL_21P25MS            =            17,
	CONN_INTERVAL_22P5MS             =            18,
	CONN_INTERVAL_23P75MS            =            19,
	CONN_INTERVAL_25MS               =            20,
	CONN_INTERVAL_26P25MS            =            21,
	CONN_INTERVAL_27P5MS             =            22,
	CONN_INTERVAL_28P75MS            =            23,
	CONN_INTERVAL_30MS               =            24,
	CONN_INTERVAL_31P25MS            =            25,
	CONN_INTERVAL_32P5MS             =            26,
	CONN_INTERVAL_33P75MS            =            27,
	CONN_INTERVAL_35MS             	 =            28,
	CONN_INTERVAL_36P25MS            =            29,
	CONN_INTERVAL_37P5MS             =            30,
	CONN_INTERVAL_38P75MS            =            31,
	CONN_INTERVAL_40MS               =            32,
	CONN_INTERVAL_41P25MS            =            33,
	CONN_INTERVAL_42P5MS             =            34,
	CONN_INTERVAL_43P75MS            =            35,
	CONN_INTERVAL_45MS               =            36,
	CONN_INTERVAL_46P25MS            =            37,
	CONN_INTERVAL_47P5MS             =            38,
	CONN_INTERVAL_48P75MS            =            39,
	CONN_INTERVAL_50MS               =            40,
	CONN_INTERVAL_55MS               =            44,
	CONN_INTERVAL_60MS               =            48,
	CONN_INTERVAL_62P5MS			 =            50,
	CONN_INTERVAL_65MS               =            52,
	CONN_INTERVAL_70MS               =            56,
	CONN_INTERVAL_75MS               =            60,
	CONN_INTERVAL_80MS               =            64,
	CONN_INTERVAL_85MS               =            68,
	CONN_INTERVAL_90MS               =            72,
	CONN_INTERVAL_95MS               =            78,
	CONN_INTERVAL_100MS              =            80,
	CONN_INTERVAL_110MS              =            88,
	CONN_INTERVAL_120MS              =            96,
	CONN_INTERVAL_130MS              =            104,
	CONN_INTERVAL_140MS              =            112,
	CONN_INTERVAL_150MS              =            120,
	CONN_INTERVAL_160MS              =            128,
	CONN_INTERVAL_170MS              =            136,
	CONN_INTERVAL_180MS              =            144,
	CONN_INTERVAL_190MS              =            152,
	CONN_INTERVAL_200MS              =            160,
	CONN_INTERVAL_250MS              =            200,
	CONN_INTERVAL_300MS              =            240,
	CONN_INTERVAL_320MS              =            256,
}conn_inter_t;


/* Supervision_Timeout, Time = N * 10 ms,
 * Notice that these are just part of but not all Supervision_Timeout value */
typedef enum{
	CONN_TIMEOUT_500MS				 =			  50,
	CONN_TIMEOUT_1S					 =		 	  100,
	CONN_TIMEOUT_1S5				 =		 	  150,
	CONN_TIMEOUT_2S					 =		 	  200,
	CONN_TIMEOUT_2S5				 =		 	  250,
	CONN_TIMEOUT_3S					 =		 	  300,
	CONN_TIMEOUT_3S5				 =		 	  350,
	CONN_TIMEOUT_4S					 =		 	  400,
	CONN_TIMEOUT_4S5				 =		 	  450,
	CONN_TIMEOUT_5S					 =		 	  500,
	CONN_TIMEOUT_6S					 =		 	  600,
	CONN_TIMEOUT_7S					 =		 	  700,
	CONN_TIMEOUT_8S					 =		 	  800,
	CONN_TIMEOUT_9S					 =		 	  900,
	CONN_TIMEOUT_10S				 =			  1000,
	CONN_TIMEOUT_15S				 =			  1500,
	CONN_TIMEOUT_20S				 =			  2000,
}conn_tm_t;



/**
 *  @brief  Command Parameters for "7.8.16 LE Add Device To White List command"
 */
typedef struct{
	u8		adr_type;
	u8		addr[6];
} hci_le_addDeviceWhitelist_cmdParam_t;

/**
 *  @brief  Command Parameters for "7.8.17 LE Remove Device From White List command"
 */
typedef struct{
	u8		adr_type;
	u8		addr[6];
} hci_le_removeDeviceWhitelist_cmdParam_t;



/**
 *  @brief  Return Parameters for "7.8.46 LE Read Maximum Data Length command"
 */
typedef struct {
	u8         status;
	u16        support_max_tx_oct;
	u16        support_max_tx_time;
	u16        support_max_rx_oct;
	u16        support_max_rx_time;
} hci_le_readMaxDataLengthCmd_retParam_t;





/**
 *  @brief  Return Parameters for "7.8.47 LE Read PHY command"
 */
typedef struct {
	u8         status;
	u8         handle[2];
	u8         tx_phy;
	u8         rx_phy;
} hci_le_readPhyCmd_retParam_t;



/**
 *  @brief  Command Parameters for "7.8.48 LE Set Default PHY command"
 */


/**
 *  @brief  Command Parameters for "7.8.49 LE Set PHY command"
 */

typedef struct {
	u16 connHandle;
	u8 	all_phys;
	u8 	tx_phys;
	u8 	rx_phys;
	u16 phy_options;
} hci_le_setPhyCmd_param_t;



/**
 * @brief       this function is used to set PHY type for connection
 * @param[in]   *para -  Command Parameters for "7.8.49 LE Set PHY command"
 * @return      0 : success
 * 				other : fail
 */
ble_sts_t blc_hci_le_setPhy(hci_le_setPhyCmd_param_t* para);

/**
 * @brief       this function is used to read PHY type for connection
 * @param[in]   connHandle -  Connection Handle
 * @param[in]   *para -  Command Parameters for "7.8.47 LE Read PHY command"
 * @return      0 : success
 * 				other : fail
 */
ble_sts_t blc_hci_le_readPhy(u16 connHandle, hci_le_readPhyCmd_retParam_t  *para);




typedef enum {
	CODED_PHY_PREFER_NONE 	= 0,
	CODED_PHY_PREFER_S2		= 1,
	CODED_PHY_PREFER_S8 	= 2,
} le_ci_prefer_t;   //LE coding indication prefer







/**
 *  @brief  Command Parameters for "7.8.53 LE Set Extended Advertising Parameters command"
 */
typedef struct {
	u8		adv_handle;
    u16		advEvt_props;
    u8	 	pri_advIntMin[3];
	u8		pri_advIntMax[3];
    u8 		pri_advChnMap;
    u8		ownAddrType;
    u8 		peerAddrType;
    u8  	peerAddr[6];
    u8		advFilterPolicy;
    u8 		adv_tx_pow;
    u8		pri_adv_phy;
    u8		sec_adv_max_skip;
    u8		sec_adv_phy;
    u8		adv_sid;
    u8		scan_req_noti_en;
}hci_le_setExtAdvParam_cmdParam_t;

/* Advertising_Handle */
typedef enum{
	ADV_HANDLE0		= 0x00,
	ADV_HANDLE1		= 0x01,
	ADV_HANDLE2		= 0x02,
	ADV_HANDLE3		= 0x03,
}adv_handle_t;



/* Advertising Event Properties mask*/
typedef enum{
	ADVEVT_PROP_MASK_CONNECTABLE						=	BIT(0),
	ADVEVT_PROP_MASK_SCANNABLE     						=	BIT(1),
	ADVEVT_PROP_MASK_DIRECTED  							=   BIT(2),
	ADVEVT_PROP_MASK_HD_DIRECTED     					=	BIT(3),
	ADVEVT_PROP_MASK_LEGACY          					=	BIT(4),
	ADVEVT_PROP_MASK_ANON_ADV       		 			=	BIT(5),
	ADVEVT_PROP_MASK_INC_TX_PWR      					=	BIT(6),
}advEvtProp_mask_t;


#define ADVEVT_PROP_MASK_CONNECTABLE_SCANNABLE					(0x0003)  // ADVEVT_PROP_MASK_CONNECTABLE | ADVEVT_PROP_MASK_SCANNABLE
#define ADVEVT_PROP_MASK_LEGACY_SCANNABLE						(0x0012)  // ADVEVT_PROP_MASK_LEGACY | ADVEVT_PROP_MASK_SCANNABLE
#define	ADVEVT_PROP_MASK_LEGACY_DIRECTED						(0x0014)  // ADVEVT_PROP_MASK_LEGACY | ADVEVT_PROP_MASK_DIRECTED
#define	ADVEVT_PROP_MASK_LEGACY_HD_DIRECTED						(0x0018)  // ADVEVT_PROP_MASK_LEGACY | ADVEVT_PROP_MASK_HD_DIRECTED
#define ADVEVT_PROP_MASK_LEGACY_CONNECTABLE_SCANNABLE			(0x0013)  // ADVEVT_PROP_MASK_LEGACY | ADVEVT_PROP_MASK_CONNECTABLE | ADVEVT_PROP_MASK_SCANNABLE

/* Advertising Event Properties
 * See the Core_v5.0(Vol 2/Part E/7.8.53 & Vol 6/Part B/4.4.2/Table 4.1) for more information
*/
typedef enum{
  ADV_EVT_PROP_LEGACY_CONNECTABLE_SCANNABLE_UNDIRECTED 				       	= 0x0013,		//  0001 0011'b 	ADV_IND
  ADV_EVT_PROP_LEGACY_CONNECTABLE_DIRECTED_LOW_DUTY 				       	= 0x0015,		//  0001 0101'b		ADV_DIRECT_IND(low duty cycle)
  ADV_EVT_PROP_LEGACY_CONNECTABLE_DIRECTED_HIGH_DUTY 	 				    = 0x001D,		//  0001 1101'b		ADV_DIRECT_IND(high duty cycle)
  ADV_EVT_PROP_LEGACY_SCANNABLE_UNDIRECTED 							       	= 0x0012,		//  0001 0010'b		ADV_SCAN_IND
  ADV_EVT_PROP_LEGACY_NON_CONNECTABLE_NON_SCANNABLE_UNDIRECTED				= 0x0010,		//  0001 0000'b		ADV_NONCONN_IND


  ADV_EVT_PROP_EXTENDED_NON_CONNECTABLE_NON_SCANNABLE_UNDIRECTED    	    = 0x0000,		//  0000 0000'b		ADV_EXT_IND + AUX_ADV_IND/AUX_CHAIN_IND
  ADV_EVT_PROP_EXTENDED_CONNECTABLE_UNDIRECTED       				 	  	= 0x0001,		//  0000 0001'b		ADV_EXT_IND + AUX_ADV_IND/AUX_CHAIN_IND
  ADV_EVT_PROP_EXTENDED_SCANNABLE_UNDIRECTED						        = 0x0002,		//  0000 0010'b		ADV_EXT_IND + AUX_ADV_IND/AUX_CHAIN_IND
  ADV_EVT_PROP_EXTENDED_NON_CONNECTABLE_NON_SCANNABLE_DIRECTED				= 0x0004,		//  0000 0100'b		ADV_EXT_IND + AUX_ADV_IND/AUX_CHAIN_IND
  ADV_EVT_PROP_EXTENDED_CONNECTABLE_DIRECTED			       				= 0x0005,		//  0000 0101'b		ADV_EXT_IND + AUX_ADV_IND/AUX_CHAIN_IND
  ADV_EVT_PROP_EXTENDED_SCANNABLE_DIRECTED								    = 0x0006,		//  0000 0110'b		ADV_EXT_IND + AUX_ADV_IND/AUX_CHAIN_IND


  ADV_EVT_PROP_EXTENDED_MASK_ANONYMOUS_ADV 		= 0x0020,  //if this mask on(only extended ADV event can mask it), anonymous advertising
  ADV_EVT_PROP_EXTENDED_MASK_TX_POWER_INCLUDE	= 0x0040,  //if this mask on(only extended ADV event can mask it), TX power include

}advEvtProp_type_t;



/* Advertising_TX_Power */
typedef enum {
	 TX_POWER_0dBm  = 0,
	 TX_POWER_1dBm  = 1,
	 TX_POWER_2dBm 	= 2,
	 TX_POWER_3dBm 	= 3,
	 TX_POWER_4dBm 	= 4,
	 TX_POWER_5dBm 	= 5,
	 TX_POWER_6dBm 	= 6,
	 TX_POWER_7dBm 	= 7,
	 TX_POWER_8dBm 	= 8,
	 TX_POWER_9dBm  = 9,
	 TX_POWER_10dBm = 10,
} tx_power_t;



/* Advertising_SID */
typedef enum{
	ADV_SID_0		= 0x00,
	ADV_SID_1		= 0x01,
	ADV_SID_2		= 0x02,
	ADV_SID_3		= 0x03,
}adv_sid_t;




/**
 *  @brief  Command Parameters for "7.8.54 LE Set Extended Advertising Data command"
 */

/* Operation */
typedef enum {
	DATA_OPER_INTER      	=	0x00,
	DATA_OPER_FIRST      	=	0x01,
	DATA_OPER_LAST       	=	0x02,
	DATA_OPER_COMPLETE   	=	0x03,
	DATA_OPER_UNCHANGED	=  	0x04,
} data_oper_t;


/* Fragment_Preference */
typedef enum {
	DATA_FRAGM_ALLOWED			      	=	0x00,
	DATA_FRAGM_NONE_OR_MINIMIZE      	=	0x01,
} data_fragm_t;





/**
 *  @brief  Command Parameters for "7.8.56 LE Set Extended Advertising Enable command"
 */

typedef struct{
	u8		adv_handle;
	u16		duration;
	u8      max_ext_adv_evts;
} extAdvEn_Cfg_t;

typedef struct{
	u8		enable;
	u8		num_sets;
	extAdvEn_Cfg_t		cisCfg[3];  // TSKNUM_EXT_ADV
} hci_le_setExtAdvEn_cmdParam_t;



/**
 *  @brief  Command Parameters for "7.8.61 LE Set Periodic Advertising Parameters command"
 */

/* Periodic_adv_Interval, Time = N * 1.25 ms,
 * Notice that these are just part of but not all Periodic_adv_Interval value */
typedef enum{
	PERADV_INTERVAL_7P5MS              =            6,
	PERADV_INTERVAL_8P75MS             =            7,
	PERADV_INTERVAL_10MS               =            8,
	PERADV_INTERVAL_11P25MS            =            9,
	PERADV_INTERVAL_12P5MS             =            10,
	PERADV_INTERVAL_13P75MS            =            11,
	PERADV_INTERVAL_15MS               =            12,
	PERADV_INTERVAL_16P25MS            =            13,
	PERADV_INTERVAL_17P5MS             =            14,
	PERADV_INTERVAL_18P75MS            =            15,
	PERADV_INTERVAL_20MS               =            16,
	PERADV_INTERVAL_21P25MS            =            17,
	PERADV_INTERVAL_22P5MS             =            18,
	PERADV_INTERVAL_23P75MS            =            19,
	PERADV_INTERVAL_25MS               =            20,
	PERADV_INTERVAL_26P25MS            =            21,
	PERADV_INTERVAL_27P5MS             =            22,
	PERADV_INTERVAL_28P75MS            =            23,
	PERADV_INTERVAL_30MS               =            24,
	PERADV_INTERVAL_31P25MS            =            25,
	PERADV_INTERVAL_32P5MS             =            26,
	PERADV_INTERVAL_33P75MS            =            27,
	PERADV_INTERVAL_35MS               =            28,
	PERADV_INTERVAL_36P25MS            =            29,
	PERADV_INTERVAL_37P5MS             =            30,
	PERADV_INTERVAL_38P75MS            =            31,
	PERADV_INTERVAL_40MS               =            32,
	PERADV_INTERVAL_41P25MS            =            33,
	PERADV_INTERVAL_42P5MS             =            34,
	PERADV_INTERVAL_43P75MS            =            35,
	PERADV_INTERVAL_45MS               =            36,
	PERADV_INTERVAL_46P25MS            =            37,
	PERADV_INTERVAL_47P5MS             =            38,
	PERADV_INTERVAL_48P75MS            =            39,
	PERADV_INTERVAL_50MS               =            40,
	PERADV_INTERVAL_55MS               =            44,
	PERADV_INTERVAL_60MS               =            48,
	PERADV_INTERVAL_62P5MS			   =            50,
	PERADV_INTERVAL_65MS               =            52,
	PERADV_INTERVAL_70MS               =            56,
	PERADV_INTERVAL_75MS               =            60,
	PERADV_INTERVAL_80MS               =            64,
	PERADV_INTERVAL_85MS               =            68,
	PERADV_INTERVAL_90MS               =            72,
	PERADV_INTERVAL_95MS               =            78,
	PERADV_INTERVAL_100MS              =            80,
	PERADV_INTERVAL_110MS              =            88,
	PERADV_INTERVAL_120MS              =            96,
	PERADV_INTERVAL_130MS              =            104,
	PERADV_INTERVAL_140MS              =            112,
	PERADV_INTERVAL_150MS              =            120,
	PERADV_INTERVAL_180MS              =            144,
	PERADV_INTERVAL_200MS              =            160,
	PERADV_INTERVAL_250MS              =            200,
	PERADV_INTERVAL_300MS              =            240,
	PERADV_INTERVAL_400MS              =            320,
	PERADV_INTERVAL_500MS              =            400,
	PERADV_INTERVAL_600MS              =            480,
	PERADV_INTERVAL_700MS              =            560,
	PERADV_INTERVAL_800MS              =            640,
	PERADV_INTERVAL_900MS              =            720,
	PERADV_INTERVAL_1S				   =            800,
	PERADV_INTERVAL_1S2				   =            960,
	PERADV_INTERVAL_1S4				   =            1120,
	PERADV_INTERVAL_1S5				   =            1200,
	PERADV_INTERVAL_1S6				   =            1280,
	PERADV_INTERVAL_1S8				   =            1440,
	PERADV_INTERVAL_2S				   =            1600,
	PERADV_INTERVAL_3S				   =            2400,
	PERADV_INTERVAL_4S				   =            3200,
	PERADV_INTERVAL_5S				   =            4000,
	PERADV_INTERVAL_6S				   =            4800,
	PERADV_INTERVAL_7S				   =            5600,
	PERADV_INTERVAL_8S				   =            6400,
	PERADV_INTERVAL_9S				   =            7200,
	PERADV_INTERVAL_10S				   =            8000,
}periodic_adv_inter_t;

typedef enum{

	PERD_ADV_PROP_MASK_NONE	= 0,

	PERD_ADV_PROP_MASK_TX_POWER_INCLUDE	= BIT(6),

}perd_adv_prop_t;



/**
 *  @brief  Command Parameters for "7.8.64 LE Set Extended Scan Parameters command"
 */
typedef struct{
	u8		scan_type;
	u16		scan_interval;
  	u16		scan_window;
} ext_scan_cfg_t;

typedef struct{
	u8		ownAddress_type;
	u8		scan_filter_policy;
  	u8		scan_PHYs;
  	ext_scan_cfg_t		scanCfg[2];  //at most 2 kind of PHY: 1M and Coded
} hci_le_setExtScanParam_cmdParam_t;


/* Scanning_PHYs */
typedef enum {
	SCAN_PHY_1M 		= BIT(0),
	SCAN_PHY_CODED		= BIT(2),
	SCAN_PHY_1M_CODED 	= (SCAN_PHY_1M | SCAN_PHY_CODED),
} scan_phy_t;




/**
 *  @brief  Command Parameters for "7.8.65 LE Set Extended Scan Enable command"
 */
typedef struct{
	u8		Enable;
	u8		Filter_Duplicates;
	u16		Duration;
	u16		Period;
} hci_le_setExtScanEnable_cmdParam_t;

/* Filter_Duplicates for Extended Scan*/
typedef enum {
	DUPE_FLTR_DISABLE 				= 0x00,
	DUPE_FLTR_ENABLE				= 0x01,
	DUPE_FLTR_ENABLE_RST_PERIOD		= 0x02,
} dupe_fltr_en_t;


/* Scan duration, Range: 0x0001 to 0xFFFF, Time = N * 10 ms, Time Range: 10 ms to 655.35 s,
 * Notice that these are just part of but not all Scan duration value */
typedef enum{
	SCAN_DURATION_CONTINUOUS         =             0,
	SCAN_DURATION_50MS				 =			   5,
	SCAN_DURATION_100MS				 =			  10,
	SCAN_DURATION_150MS				 =			  15,
	SCAN_DURATION_200MS				 =			  20,
	SCAN_DURATION_250MS				 =			  25,
	SCAN_DURATION_300MS				 =			  30,
	SCAN_DURATION_350MS				 =			  35,
	SCAN_DURATION_400MS				 =			  40,
	SCAN_DURATION_450MS				 =			  45,
	SCAN_DURATION_500MS				 =			  50,
	SCAN_DURATION_550MS				 =			  55,
	SCAN_DURATION_600MS				 =			  60,
	SCAN_DURATION_650MS				 =			  65,
	SCAN_DURATION_700MS				 =			  70,
	SCAN_DURATION_750MS				 =			  75,
	SCAN_DURATION_800MS				 =			  80,
	SCAN_DURATION_850MS				 =			  85,
	SCAN_DURATION_900MS				 =			  90,
	SCAN_DURATION_950MS				 =			  96,
	SCAN_DURATION_1S				 =		 	  100,
	SCAN_DURATION_1S2			 	 =		 	  120,
	SCAN_DURATION_1S5				 =		 	  150,
	SCAN_DURATION_1S6				 =		 	  160,
	SCAN_DURATION_1S8				 =		 	  180,
	SCAN_DURATION_2S				 =		 	  200,
	SCAN_DURATION_3S				 =		 	  300,
	SCAN_DURATION_4S				 =		 	  400,
	SCAN_DURATION_5S				 =		 	  500,
	SCAN_DURATION_6S				 =		 	  600,
	SCAN_DURATION_7S				 =		 	  700,
	SCAN_DURATION_8S				 =		 	  800,
	SCAN_DURATION_9S				 =		 	  900,
	SCAN_DURATION_10S				 =		 	  1000,
}scan_durn_t;

/* Scan period, Range: 0x0001 to 0xFFFF, Time = N * 1.28 sec, Time Range: 1.28 s to 83,884.8 s
 * Notice that these are just part of but not all Scan period value */
typedef enum{
	SCAN_WINDOW_CONTINUOUS           =             0,
	SCAN_WINDOW_1S28				 =			   1,
	SCAN_WINDOW_2S56				 =			   2,
	SCAN_WINDOW_3S84				 =			   3,
	SCAN_WINDOW_5S12				 =			   4,
	SCAN_WINDOW_6S4 				 =			   5,
	SCAN_WINDOW_7S68				 =			   6,
	SCAN_WINDOW_8S92				 =			   7,
	SCAN_WINDOW_10S24				 =			   8,
	SCAN_WINDOW_11S52				 =			   9,
	SCAN_WINDOW_12S8				 =			  10,
}scan_period_t;



/**
 *  @brief  Command Parameters for "7.8.66 LE Extended Create Connection command"
 */
typedef struct{
	u16		scan_inter;
	u16		scan_wind;
  	u16		conn_min;
  	u16		conn_max;
  	u16 	connLatency;
  	u16		timeout;
  	u16		ceLen_min;
  	u16		ceLen_max;
} ext_init_cfg_t;

typedef struct{
	u8		fp; //init_filter_policy
	u8		ownAddr_type;
  	u8		peerAddr_type;
	u8		peer_addr[6];
	u8		init_PHYs;
  	ext_init_cfg_t		initCfg[3];
} hci_le_ext_createConn_cmdParam_t;

#define EXT_CREATE_CONN_CMD_PARAM_MAX_LENGTH		(10 + 16 * 3)   //10 + sizeof(ext_init_cfg_t) * 3

/* Initiating_PHYs */
typedef enum {
	INIT_PHY_1M 			= BIT(0),
	INIT_PHY_2M 			= BIT(1),	//can not use this, at least one bit set for a PHY allowed for scanning on the primary advertising physical channel
	INIT_PHY_CODED			= BIT(2),
	INIT_PHY_1M_2M 			= (INIT_PHY_1M | INIT_PHY_2M),
	INIT_PHY_1M_CODED 		= (INIT_PHY_1M | INIT_PHY_CODED),
	INIT_PHY_2M_CODED 		= (INIT_PHY_2M | INIT_PHY_CODED),
	INIT_PHY_1M_2M_CODED 	= (INIT_PHY_1M | INIT_PHY_2M | INIT_PHY_1M_CODED),
} init_phy_t;





/**
 *  @brief  Command Parameters for "7.8.67 LE Periodic Advertising Create Sync command"
 */
typedef struct{
	u8		Options;
	u8		Advertising_SID;
	u8		Advertiser_Address_Type;
	u8		Advertiser_Address[6];
	u16		Skip;
	u16		Sync_Timeout;
	u16		Sync_CTE_Type;
} hci_le_periodicAdvCreateSync_cmdParam_t;

/**
 * @brief  Command Parameters for "7.8.80 LE Set Connectionless CTE Transmit Parameters command"
 */
typedef struct{
	u8		Advertising_Handle;
	u8		CTE_length;
	u8		CTE_type;
	u8		CTE_count;

	u8		Switch_pattern_len;
	u8		Antenna_IDs[1];
}hci_le_setConnectionless_CTETransmitParam_t;


typedef struct{
	u8		adv_handle;
	u8 		CTE_enable;
}hci_le_CTE_enable_type;

typedef struct{
	u16		Sync_Handle;
	u8		Sampling_Enable;
	u8		Slot_Duration;

	u8		Max_Sampled_CTEs;
	u8		Switching_pattern_len;
	u8		Antenna_IDs[1];
}hci_le_setConnectionless_IQsampleEn_t;


typedef struct{
	u16		conn_handle;
	u8		sampling_en;
	u8		slot_duration;
	u8		switch_pattern_len;

	u8		antenna_ids[1];
}hci_le_setConnection_CTERevParams_t;

typedef struct{
	u16		conn_handle;
	u8		CTE_type;
	u8		switching_pattern_len;
	u8		antenna_IDs[1];
}hci_le_setConnection_CTETransmitParams_t;

typedef struct{
	u8	support_switch_sample_rate;
	u8	antenna_num;
	u8	max_switch_pattern_len;
	u8	max_cte_len;
}cte_antenna_infor_t;

typedef struct{
	u16		conn_handle;
	u8		cte_req_en;
	u16		cte_req_intvl;

	u8		req_cte_len;
	u8		req_cte_type;
}hci_le_cteReqEn_t;

typedef struct{
	u16		conn_handle;
	u8		rsp_enable;
}hci_le_cteRspEn_t;


/* Options */
typedef enum {

	/* BIT(0)
	 * 0: Use the adv_sid, adv_addr_type, and adv_address parameters to determine which advertiser to listen to.
	 * 1: Use the Periodic Advertiser List to determine which advertiser to listen to. */
	SYNC_ADV_SPECIFY	 = 0,
	SYNC_ADV_FROM_LIST	 = BIT(0),

	/* BIT(1)
	   whether HCI_Periodic_Advertising_Report events for this periodic advertising train are initially enabled
	   0: enabled
	   1: disabled
	*/
	REPORTING_INITIALLY_EN	 = 0,
	REPORTING_INITIALLY_DIS	 = BIT(1),

	/* BIT(2) ~ BIT(7) reserved */
} option_msk_t;


/* Synchronization timeout, Time = N * 10 ms,
 * Notice that these are just part of but not all Synchronization timeout value */
typedef enum{
	SYNC_TIMEOUT_100MS				 =			  10,
	SYNC_TIMEOUT_200MS				 =			  20,
	SYNC_TIMEOUT_300MS				 =			  30,
	SYNC_TIMEOUT_400MS				 =			  40,
	SYNC_TIMEOUT_500MS				 =			  50,
	SYNC_TIMEOUT_1S					 =		 	  100,
	SYNC_TIMEOUT_1S5				 =		 	  150,
	SYNC_TIMEOUT_2S					 =		 	  200,
	SYNC_TIMEOUT_2S5				 =		 	  250,
	SYNC_TIMEOUT_3S					 =		 	  300,
	SYNC_TIMEOUT_3S5				 =		 	  350,
	SYNC_TIMEOUT_4S					 =		 	  400,
	SYNC_TIMEOUT_4S5				 =		 	  450,
	SYNC_TIMEOUT_5S					 =		 	  500,
	SYNC_TIMEOUT_6S					 =		 	  600,
	SYNC_TIMEOUT_7S					 =		 	  700,
	SYNC_TIMEOUT_8S					 =		 	  800,
	SYNC_TIMEOUT_9S					 =		 	  900,
	SYNC_TIMEOUT_10S				 =			  1000,
	SYNC_TIMEOUT_15S				 =			  1500,
	SYNC_TIMEOUT_20S				 =			  2000,
}sync_tm_t;




typedef struct{
	u8		cis_id;
	u16		max_sdu_m2s;
	u16		max_sdu_s2m;
  	u8  	phy_m2s;
  	u8		phy_s2m;
  	u8		rtn_m2s;
  	u8		rtn_s2m;
} cigParam_cisCfg_t;

/**
 *  @brief  Command Parameters for "7.8.97 LE Set CIG Parameters command"
 */
typedef struct {
	u8  	cig_id;
	u8		sdu_int_m2s[3];
	u8		sdu_int_s2m[3];
	u8		sca;
	u8		packing;
	u8	    framing;
	u16 	max_trans_lat_m2s;
	u16 	max_trans_lat_s2m;
	u8		cis_count;	//14 B above
	cigParam_cisCfg_t		cisCfg[1];
} hci_le_setCigParam_cmdParam_t;

typedef struct{
	u8		cis_id;
	u8		nse;
	u16		max_sdu_m2s;
	u16		max_sdu_s2m;
	u16		max_pdu_m2s;
	u16		max_pdu_s2m;
  	u8  	phy_m2s;
  	u8		phy_s2m;
  	u8		bn_m2s;
  	u8		bn_s2m;
} cigParamTest_cisCfg_t;

/* Slaves_Clock_Accuracy */
typedef enum {
	PPM_251_500     =	0x00,
	PPM_151_250     =	0x01,
	PPM_101_150     =	0x02,
	PPM_76_100      =	0x03,
	PPM_51_75      	=	0x04,
	PPM_31_50      	=	0x05,
	PPM_21_30      	=	0x06,
	PPM_0_20      	=	0x07,
} slv_clk_accuracy_t;


/* Packing */
typedef enum {
	PACK_SEQUENTIAL     =	0x00,
	PACK_INTERLEAVED     =	0x01,
} packing_type_t;

/* Framing */
typedef enum {
	UNFRAMED   =	0x00,
	FRAMED     =	0x01,
} framing_t;



/**
 *  @brief  Command Parameters for "7.8.98 LE Set CIG Parameters Test command"
 */
typedef struct{
	u8		cig_id;
	u8		sdu_int_m2s[3];
  	u8		sdu_int_s2m[3];
	u8		ft_m2s;
	u8		ft_s2m;
	u16 	iso_intvl;
	u8		sca;
	u8		packing;
	u8	    framing;
  	u8		cis_count;   //15 B above
  	cigParamTest_cisCfg_t		cisCfg[0];  //14 B for one CIS configuration
} hci_le_setCigParamTest_cmdParam_t;



/**
 *  @brief  Return Parameters for "LE Set CIG Parameters command" and "LE Set CIG Parameters Test command"
 */
typedef struct {
	u8  	status;
	u8		cig_id;
	u8		cis_count;
	u16		cis_connHandle[0];  //not 4 byte aligned, but no problem
} hci_le_setCigParam_retParam_t;


/* ISO_Interval, Time = N * 1.25 ms,
 * Notice that these are just part of but not all ISO_Interval value */
typedef enum{
	ISO_INTERVAL_5MS                  =        	 4,
	ISO_INTERVAL_6P75MS               =          5,
	ISO_INTERVAL_7P5MS                =          6,
	ISO_INTERVAL_8P75MS               =          7,
	ISO_INTERVAL_10MS                 =          8,
	ISO_INTERVAL_11P25MS              =          9,
	ISO_INTERVAL_12P5MS               =          10,
	ISO_INTERVAL_15MS                 =          12,
	ISO_INTERVAL_18P75MS              =          15,
	ISO_INTERVAL_20MS                 =          16,
	ISO_INTERVAL_25MS                 =          20,
	ISO_INTERVAL_27P5MS               =          22,
	ISO_INTERVAL_30MS                 =          24,
	ISO_INTERVAL_31P25MS              =          25,
	ISO_INTERVAL_38P75MS              =          31,
	ISO_INTERVAL_40MS                 =          32,
	ISO_INTERVAL_48P75MS              =          39,
	ISO_INTERVAL_50MS                 =          40,
	ISO_INTERVAL_100MS                =          80,
}iso_inter_t;




/**
 *	@brief  Command Parameters for "7.8.99 LE Create CIS command"
 */
typedef struct
{
	u16		cis_handle;
	u16		acl_handle;
} cisConnParams_t;

typedef struct
{
	u8		cis_count;
	cisConnParams_t	cisConn[1];
}hci_le_CreateCisParams_t;



#if 0
/**
 *	@brief  Command Parameters for "7.8.102 LE Reject CIS Request command"
 */
typedef struct
{
	u16		cis_handle;
	u8		reason;
} hci_le_rejectCisReqParams_t;
#endif



/**
 *	@brief  Command Parameters for "7.8.103 LE Create BIG command"
 */
typedef struct
{
  	u8  	big_handle;			/* Used to identify the BIG */
	u8		adv_handle;			/* Used to identify the periodic advertising train */
	u8		num_bis;			/* Total number of BISes in the BIG */
  	u8  	sdu_intvl[3];		/* The interval, in microseconds, of BIS SDUs */
  	u16		max_sdu;			/* Maximum size of an SDU, in octets */
  	u16		max_trans_lat; 		/* Maximum time, in milliseconds, for transmitting an SDU */
  	u8  	rtn; 				/* The maximum number of times that every BIS Data PDU should be retransmitted */
  	u8		phy;				/* The transmitter PHY of packets */
	packing_type_t		packing;//type same as u8
	framing_t	    	framing;//type same as u8
	u8		enc;				/* Encryption flag */
	u8      broadcast_code[16]; /* The code used to derive the session key that is used to encrypt and decrypt BIS payloads */
} hci_le_createBigParams_t;




/**
 *	@brief  Command Parameters for "7.8.104 LE Create BIG Test command"
 */
typedef struct
{
  	u8  	big_handle;			/* Used to identify the BIG */
	u8		adv_handle;			/* Used to identify the periodic advertising train */
	u8		num_bis;			/* Total number of BISes in the BIG */
  	u8  	sdu_intvl[3];		/* The interval, in microseconds, of periodic SDUs */
  	u16     iso_intvl;			/* The time between consecutive BIG anchor points, Time = N * 1.25 ms */
  	u8		nse;				/* The total number of subevents in each interval of each BIS in the BIG */
  	u16		max_sdu;			/* Maximum size of an SDU, in octets */
  	u16		max_pdu; 			/* Maximum size, in octets, of payload */
  	u8		phy;				/* The transmitter PHY of packets, BIT(0): LE 1M; BIT(1): LE 2M; BIT(3): LE Coded PHY */
	u8		packing;
	u8		framing;
	u8		bn;					/* The number of new payloads in each interval for each BIS */
	u8		irc;				/* The number of times the scheduled payload(s) are transmitted in a given event*/
	u8		pto;				/* Offset used for pre-transmissions */
	u8		enc;				/* Encryption flag */
	u8      broadcast_code[16]; /* The code used to derive the session key that is used to encrypt and decrypt BIS payloads */
} hci_le_createBigParamsTest_t;




/**
 *	@brief  Command Parameters for "7.8.105 LE Terminate BIG command"
 */
typedef struct
{
	u8		big_handle;
	u8		reason;
} hci_le_terminateBigParams_t;




typedef struct
{
  	u8  	big_handle;			/* Used to identify the BIG */
	u16		sync_handle;		/* Identifier of the periodic advertising train */
	u8		enc;				/* Encryption flag */
	u8      broadcast_code[16]; /* The code used to derive the session key that is used to encrypt and decrypt BIS payloads */
	u8		mse;				/* The Controller can schedule reception of any number of subevents up to NSE */
  	u16		big_sync_timeout;	/* Synchronization timeout for the BIG, Time = N*10 ms, Time Range: 100 ms to 163.84 s */
  	u8  	num_bis; 			/* Total number of BISes to synchronize */
  	u8      bis[1];				/* List of indices of BISes */
} hci_le_bigCreateSyncParams_t;




/**
 *	@brief  Command Parameters for "7.8.109 LE Setup ISO Data Path command"
 */
typedef struct
{
	u16  conn_handle;
	u8   data_path_dir;
	u8   data_path_id;
	u8   codec_id_assignNum;
	u16  codec_id_compId;
	u16  codec_id_venderDef;
	u8   control_delay[3];
	u8   codec_config_len;
	u8	 codec_config[19]; /* Max buffer length 19Byte */
}hci_le_setupIsoDataPathCmdParams_t;


/**
 *	@brief  Command Parameters for "7.8.110 LE Remove ISO Data Path command"
 */
typedef struct
{
	u16 conn_handle;
	u8  data_path_dir;
}hci_le_rmvIsoDataPathCmdParams_t;


/* Data_Path_Direction */
typedef enum {
	Data_Dir_Input 	= 0x00, //Input (Host to Controller)
	Data_Dir_Output	= 0x01, //Output (Controller to Host)
} dat_path_dir_t;


/* Data_Path_ID */
typedef enum {
	Data_Path_HCI	 	= 0x00,
	//x01 to 0xFE: Logical_Channel_Number. The meaning of the logical channel is vendor specific.
} dat_path_id_t;

/**
 *  @brief  Return Parameters for "7.8.109 LE Setup ISO Data Path command"
 */
typedef struct {
	u8		status;
	u16		conn_handle; //cis/bis handle
} hci_le_setupIsoDataPathRetParams_t;

/**
 *  @brief  Return Parameters for "7.8.110 LE Remove ISO Data Path command"
 */
typedef struct {
	u8		status;
	u16		conn_handle; //cis/bis handle
} hci_le_rmvIsoDataPathRetParams_t;


/**
 * @brief Command Parameters for "7.8.111 LE ISO Transmit Test command"
 */
typedef struct
{
	u16 handle;
	u8  payload_type;
}hci_le_isoTransmitTestCmdParams_t;



/**
 * @brief Command Parameters for "7.8.112 LE ISO Receive Test command"
 */
typedef struct
{
	u16 handle;
	u8  payload_type;
}hci_le_isoReceiveTestCmdParams_t;


/**
 * @brief return parameters for LE ISO Read Test Counters command
 */
typedef struct{

	u8 status;
	u16 handle;

	u32 received_packet_count;
	u32 miss_packet_count;
	u32 failed_packet_count;

}hci_le_isoReadTestCountersCmdRetParam_t;

/**
 * @brief return parameters for LE ISO Test End command
 */
typedef struct{

	u8 status;
	u16 handle;

	u32 received_packet_count;
	u32 miss_packet_count;
	u32 failed_packet_count;

}hci_le_isoTestEndCmdRetParam_t;

typedef enum{
    BLE_PHY_1M    = BIT(0),
    BLE_PHY_2M    = BIT(1),
} le_phy_type_t;

typedef enum{
    PHY_PREFER_1M = BIT(0),
    PHY_PREFER_2M = BIT(1),
} le_phy_prefer_type_t;

typedef enum{
    PHY_TRX_PREFER    = 0,                 //has preference among TX & RX PHYs
    PHY_TX_NO_PREFER  = BIT(0),            //has no preference among TX PHYs
    PHY_RX_NO_PREFER  = BIT(1),            //has no preference among RX PHYs
    PHY_TRX_NO_PREFER = (BIT(0) | BIT(1)), //has no preference among TX & RX PHYs
} le_phy_prefer_mask_t;

/**
 *  @brief  Return Parameters for "7.8.74 LE Read Transmit Power command"
 */
typedef struct
{
    u8      status;
    s8      minTxPwrLvl;
    s8      maxTxPwrLvl;
}hci_le_rdSuppTxPwrRetParams_t;

/**
 *  @brief  Return Parameters for "7.8.75 LE Read RF Path Compensation command"
 */
typedef struct __attribute__((packed))
{
    u8      status;
    s16     txPathComp;
    s16     rxPathComp;
}hci_le_rdRfPathCompRetParams_t;

/**
 * @brief Command Parameters for "7.8.76 LE Write RF Path Compensation command"
 */
typedef struct
{
    s16     txPathComp;
    s16     rxPathComp;
}hci_le_writeRfPathCompCmdParams_t;

typedef struct __attribute__((packed))
{
	u8 		status;
	u16 	connHandle;
	s8 		rssi;
}hci_readRssi_retParam_t;

/**
 * @brief Command & Return Parameters for "7.5.4 Read RSSI command"
 */
typedef struct
{
	u16 	connHandle;
}hci_readRssi_cmdParam_t;

#endif /* HCI_CMD_H_ */
