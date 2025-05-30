/********************************************************************************************************
 * @file    app.c
 *
 * @brief   This is the source file for BLE SDK
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
#include "tl_common.h"
#include "drivers.h"
#include "stack/ble/ble.h"


#include "app.h"
#include "app_buffer.h"
#include "../default_att.h"



#if (FEATURE_TEST_MODE == TEST_POWER_ADV)


#define MY_APP_ADV_CHANNEL			BLT_ENABLE_ADV_ALL
#define MY_ADV_INTERVAL_MIN			ADV_INTERVAL_30MS
#define MY_ADV_INTERVAL_MAX			ADV_INTERVAL_35MS

#define MY_RF_POWER_INDEX			RF_POWER_P2p87dBm





u32	advertise_begin_tick;














/**
 * @brief      callback function of LinkLayer Event "BLT_EV_FLAG_CONNECT"
 * @param[in]  e - LinkLayer Event type
 * @param[in]  p - data pointer of event
 * @param[in]  n - data length of event
 * @return     none
 */
void task_connect(u8 e, u8 *p, int n)
{

	bls_l2cap_requestConnParamUpdate (CONN_INTERVAL_10MS, CONN_INTERVAL_10MS, 99, CONN_TIMEOUT_4S);  // 1 S

	#if (UI_LED_ENABLE)
		gpio_write(GPIO_LED_RED, LED_ON_LEVEL);
	#endif
}



/**
 * @brief      callback function of LinkLayer Event "BLT_EV_FLAG_TERMINATE"
 * @param[in]  e - LinkLayer Event type
 * @param[in]  p - data pointer of event
 * @param[in]  n - data length of event
 * @return     none
 */
void task_terminate(u8 e,u8 *p, int n) //*p is terminate reason
{
	if(*p == HCI_ERR_CONN_TIMEOUT){

	}
	else if(*p == HCI_ERR_REMOTE_USER_TERM_CONN){  //0x13

	}
	else if(*p == HCI_ERR_CONN_TERM_MIC_FAILURE){

	}
	else{

	}


	#if (UI_LED_ENABLE)
		gpio_write(GPIO_LED_RED, !LED_ON_LEVEL);  //light off
	#endif

	advertise_begin_tick = clock_time();
}



/**
 * @brief      callback function of LinkLayer Event "BLT_EV_FLAG_SUSPEND_EXIT"
 * @param[in]  e - LinkLayer Event type
 * @param[in]  p - data pointer of event
 * @param[in]  n - data length of event
 * @return     none
 */
void task_suspend_exit (u8 e, u8 *p, int n)
{
	rf_set_power_level_index (MY_RF_POWER_INDEX);
}



/**
 * @brief      power management code for application
 * @param[in]  none
 * @return     none
 */
void blt_pm_proc(void)
{
	#if(BLE_APP_PM_ENABLE)
		#if (PM_DEEPSLEEP_RETENTION_ENABLE)
			bls_pm_setSuspendMask (SUSPEND_ADV | DEEPSLEEP_RETENTION_ADV | SUSPEND_CONN | DEEPSLEEP_RETENTION_CONN);
		#else
			bls_pm_setSuspendMask (SUSPEND_ADV | SUSPEND_CONN);
		#endif

		#if(UI_KEYBOARD_ENABLE)
			if(scan_pin_need || key_not_released )
			{
				bls_pm_setManualLatency(0);
			}
		#endif
	#endif//END of  BLE_APP_PM_ENABLE
}




/******************************************************************************************************
 * Here are just some ADV power example
 * The actual measured power is affected by several ADV parameters, such as:
 * 1. ADV data length: long ADV data means bigger power
 *
 * 2. ADV type:   non_connectable undirected: ADV power is small, cause only data sending involved, no
 *                                           need receiving any packet from master
 *                connectable ADV: must try to receive scan_req/scan_conn from master after sending adv
 *                                           data, so power is bigger.
 *                                               And if needing send scan_rsp to master's scan_req,
 *                                           power will increase. Here we can use whiteList to disable scan_rsp.
 *											     With connectable ADV, user should test power under a clean
 *											 and shielded environment to avoid receiving scan_req/conn_req
 *
 * 3. ADV power index: We use 0dBm in examples, higher power index will cause poser to increase
 *
 * 4. ADV interval: Bigger adv interval lead to smaller power, cause more timing for suspend/deepSleep retention
 *
 * 5. ADV channel: Power with 3 channel is bigger than power with 1 or 2 channel
 *
 *
 * If you want test ADV power with different ADV parameters from our examples, you should modify these
 *      parameters in code, and re_test by yourself.
 *****************************************************************************************************/
void app_feature_adv_power(void)
{
	//set to special ADV channel can avoid master's scan_req to get a very clean power,
	// but remember that special channel ADV packet can not be scanned by BLE master and captured by BLE sniffer
    //	blc_ll_setAdvCustomedChannel(33,34,35);


	#if   (APP_ADV_POWER_TEST_TYPE == CONNECT_12B_1S_1CHANNEL)
		// ADV data length:	12 byte
		// ADV type: 		connectable undirected ADV
		// ADV power index: 0 dBm
		// ADV interval: 	1S
		// ADV channel: 	1 channel
		u8 status = bls_ll_setAdvParam( ADV_INTERVAL_1S, ADV_INTERVAL_1S,
										ADV_TYPE_CONNECTABLE_UNDIRECTED, OWN_ADDRESS_PUBLIC,
										 0,  NULL,  BLT_ENABLE_ADV_37, ADV_FP_ALLOW_SCAN_WL_ALLOW_CONN_WL);  //no scan, no connect
	#elif  (APP_ADV_POWER_TEST_TYPE == CONNECT_12B_1S_3CHANNEL)
		// ADV data length:	12 byte
		// ADV type: 		connectable undirected ADV
		// ADV power index: 0 dBm
		// ADV interval: 	1S
		// ADV channel: 	3 channel
		u8 status = bls_ll_setAdvParam( ADV_INTERVAL_1S, ADV_INTERVAL_1S,
										ADV_TYPE_CONNECTABLE_UNDIRECTED, OWN_ADDRESS_PUBLIC,
										 0,  NULL,  BLT_ENABLE_ADV_ALL, ADV_FP_ALLOW_SCAN_WL_ALLOW_CONN_WL);  //no scan, no connect
	#elif   (APP_ADV_POWER_TEST_TYPE == CONNECT_12B_500MS_3CHANNEL)
		// ADV data length:	12 byte
		// ADV type: 		connectable undirected ADV
		// ADV power index: 0 dBm
		// ADV interval: 	500 mS
		// ADV channel: 	3 channel
		u8 status = bls_ll_setAdvParam( ADV_INTERVAL_500MS, ADV_INTERVAL_500MS,
										ADV_TYPE_CONNECTABLE_UNDIRECTED, OWN_ADDRESS_PUBLIC,
										 0,  NULL,  BLT_ENABLE_ADV_ALL, ADV_FP_ALLOW_SCAN_WL_ALLOW_CONN_WL);  //no scan, no connect
	#elif   (APP_ADV_POWER_TEST_TYPE == CONNECT_12B_30MS_3CHANNEL)
		// ADV data length:	12 byte
		// ADV type: 		connectable undirected ADV
		// ADV power index: 0 dBm
		// ADV interval: 	30 mS
		// ADV channel: 	3 channel
		u8 status = bls_ll_setAdvParam( ADV_INTERVAL_30MS, ADV_INTERVAL_30MS,
										ADV_TYPE_CONNECTABLE_UNDIRECTED, OWN_ADDRESS_PUBLIC,
										 0,  NULL,  BLT_ENABLE_ADV_ALL, ADV_FP_ALLOW_SCAN_WL_ALLOW_CONN_WL);  //no scan, no connect

	#endif

	#if (APP_ADV_POWER_TEST_TYPE == CONNECT_12B_1S_1CHANNEL || APP_ADV_POWER_TEST_TYPE == CONNECT_12B_1S_3CHANNEL || APP_ADV_POWER_TEST_TYPE == CONNECT_12B_500MS_3CHANNEL||APP_ADV_POWER_TEST_TYPE == CONNECT_12B_30MS_3CHANNEL)  // connectable undirected ADV
		//ADV data length: 12 byte
		u8 tbl_advData[12] = {
			 0x08, 0x09, 't', 'e', 's', 't', 'a', 'd', 'v',
			 0x02, 0x01, 0x05,
			};
		u8	tbl_scanRsp [] = {
				 0x08, 0x09, 'T', 'E', 'S', 'T', 'A', 'D', 'V',	//scan name
			};

		bls_ll_setAdvData( (u8 *)tbl_advData, sizeof(tbl_advData) );
		bls_ll_setScanRspData( (u8 *)tbl_scanRsp, sizeof(tbl_scanRsp));
	#endif




	#if (APP_ADV_POWER_TEST_TYPE == UNCONNECT_16B_1S_3CHANNEL  || APP_ADV_POWER_TEST_TYPE == UNCONNECT_16B_1_5S_3CHANNEL || APP_ADV_POWER_TEST_TYPE == UNCONNECT_16B_2S_3CHANNEL || APP_ADV_POWER_TEST_TYPE == UNCONNECT_31B_1S_3CHANNEL|| APP_ADV_POWER_TEST_TYPE == UNCONNECT_31B_1_5S_3CHANNEL|| APP_ADV_POWER_TEST_TYPE == UNCONNECT_31B_2S_3CHANNEL)
		#if (APP_ADV_POWER_TEST_TYPE == UNCONNECT_16B_1S_3CHANNEL  || APP_ADV_POWER_TEST_TYPE == UNCONNECT_16B_1_5S_3CHANNEL || APP_ADV_POWER_TEST_TYPE == UNCONNECT_16B_2S_3CHANNEL)  	//ADV data length: 16 byte
			u8 tbl_advData[] = {
				 15, 0x09, 't', 'e', 's', 't', 'a', 'd', 'v', '8', '9', 'A', 'B', 'C', 'D', 'E',
				};
		#elif (APP_ADV_POWER_TEST_TYPE == UNCONNECT_31B_1S_3CHANNEL|| APP_ADV_POWER_TEST_TYPE == UNCONNECT_31B_1_5S_3CHANNEL|| APP_ADV_POWER_TEST_TYPE == UNCONNECT_31B_2S_3CHANNEL)   	//ADV data length: max 31 byte
			u8 tbl_advData[] = {
				 30, 0x09, 't', 'e', 's', 't', 'a', 'd', 'v', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D'
			};
		#endif

		bls_ll_setAdvData( (u8 *)tbl_advData, sizeof(tbl_advData) );
	#endif

	#if   (APP_ADV_POWER_TEST_TYPE == UNCONNECT_16B_1S_3CHANNEL||APP_ADV_POWER_TEST_TYPE == UNCONNECT_31B_1S_3CHANNEL)
		// ADV type: non_connectable undirected ADV
		// ADV power index: 0 dBm
		// ADV interval: 1S
		// ADV channel: 3 channel
		u8 status = bls_ll_setAdvParam( ADV_INTERVAL_1S, ADV_INTERVAL_1S,
										ADV_TYPE_NONCONNECTABLE_UNDIRECTED, OWN_ADDRESS_PUBLIC,
										 0,  NULL,  BLT_ENABLE_ADV_ALL, ADV_FP_NONE);

	#elif (APP_ADV_POWER_TEST_TYPE == UNCONNECT_16B_1_5S_3CHANNEL||APP_ADV_POWER_TEST_TYPE == UNCONNECT_31B_1_5S_3CHANNEL)
		// ADV type: non_connectable undirected ADV
		// ADV power index: 0 dBm
		// ADV interval: 1.5S
		// ADV channel: 3 channel
		u8 status = bls_ll_setAdvParam( ADV_INTERVAL_1S5, ADV_INTERVAL_1S5,
										ADV_TYPE_NONCONNECTABLE_UNDIRECTED, OWN_ADDRESS_PUBLIC,
										 0,  NULL,  BLT_ENABLE_ADV_ALL, ADV_FP_NONE);

	#elif (APP_ADV_POWER_TEST_TYPE == UNCONNECT_16B_2S_3CHANNEL||APP_ADV_POWER_TEST_TYPE == UNCONNECT_31B_2S_3CHANNEL)
		// ADV type: non_connectable undirected ADV
		// ADV power index: 0 dBm
		// ADV interval: 2S
		// ADV channel: 3 channel
		u8 status = bls_ll_setAdvParam( ADV_INTERVAL_2S, ADV_INTERVAL_2S,
										ADV_TYPE_NONCONNECTABLE_UNDIRECTED, OWN_ADDRESS_PUBLIC,
										 0,  NULL,  BLT_ENABLE_ADV_ALL, ADV_FP_NONE);
	#endif
   if(BLE_SUCCESS != status)
   {
	   printf("ERRO:%S = 0x%02x",__FUNCTION__,status);
   }
}


/**
 * @brief		user initialization when MCU power on or wake_up from deepSleep mode
 * @param[in]	none
 * @return      none
 */
void user_init_normal(void)
{
	/* random number generator must be initiated here( in the beginning of user_init_normal).
	 * When deepSleep retention wakeUp, no need initialize again */
	random_generator_init();  //this is must

	blc_readFlashSize_autoConfigCustomFlashSector();

	/* attention that this function must be called after "blc_readFlashSize_autoConfigCustomFlashSector" !!!*/
	blc_app_loadCustomizedParameters_normal();


	//////////////////////////// BLE stack Initialization  Begin //////////////////////////////////
	u8 mac_public[6];
	u8 mac_random_static[6];
	blc_initMacAddress(flash_sector_mac_address, mac_public, mac_random_static);

	//////////// LinkLayer Initialization  Begin /////////////////////////



	blc_ll_initBasicMCU();                      //mandatory
	blc_ll_initStandby_module(mac_public);				//mandatory
	blc_ll_initAdvertising_module();//adv module: mandatory for BLE slave,
	blc_ll_initSlaveRole_module();//slave module: mandatory for BLE slave,

	blc_ll_setAclConnMaxOctetsNumber(ACL_CONN_MAX_RX_OCTETS, ACL_CONN_MAX_TX_OCTETS);
	blc_ll_initAclConnTxFifo(app_acl_txfifo, ACL_TX_FIFO_SIZE, ACL_TX_FIFO_NUM);
	blc_ll_initAclConnRxFifo(app_acl_rxfifo, ACL_RX_FIFO_SIZE, ACL_RX_FIFO_NUM);

	//////////// LinkLayer Initialization  End /////////////////////////



	//////////// HCI Initialization  Begin /////////////////////////

	//////////// HCI Initialization  End /////////////////////////


	//////////// Controller Initialization  End /////////////////////////




	//////////// Host Initialization  Begin /////////////////////////
	/* GAP initialization must be done before any other host feature initialization !!! */
	blc_gap_peripheral_init();    //gap initialization

	/* GATT Initialization */
	my_gatt_init();


	/* L2CAP Initialization */
	blc_l2cap_register_handler(blc_l2cap_packet_receive);
	blc_l2cap_initRxDataBuffer(app_l2cap_rx_fifo, L2CAP_RX_BUFF_SIZE);

	/* SMP Initialization */
	/* SMP Initialization may involve flash write/erase(when one sector stores too much information,
	 *   is about to exceed the sector threshold, this sector must be erased, and all useful information
	 *   should re_stored) , so it must be done after battery check */
	 
	 blc_smp_setSecurityLevel(No_Security);

	//////////// Host Initialization  End /////////////////////////

//////////////////////////// BLE stack Initialization  End //////////////////////////////////





//////////////////////////// User Configuration for BLE application ////////////////////////////

     app_feature_adv_power();
     bls_ll_setAdvEnable(BLC_ADV_ENABLE);  //adv enable
	/* set rf power index, user must set it after every suspend wakeup, cause relative setting will be reset in suspend */
     rf_set_power_level_index (MY_RF_POWER_INDEX);


	bls_app_registerEventCallback (BLT_EV_FLAG_CONNECT, &task_connect);
	bls_app_registerEventCallback (BLT_EV_FLAG_TERMINATE, &task_terminate);
	bls_app_registerEventCallback (BLT_EV_FLAG_SUSPEND_EXIT, &task_suspend_exit);



	///////////////////// Power Management initialization///////////////////
	#if(BLE_APP_PM_ENABLE)
		blc_ll_initPowerManagement_module();        //pm module:      	 optional
		#if (PM_DEEPSLEEP_RETENTION_ENABLE)
			blc_ll_initDeepsleepRetention_module();//Remove it if need save ramcode, and add DeepsleepRetentionEarlyWakeupTiming to 1ms
			bls_pm_setSuspendMask (SUSPEND_ADV | DEEPSLEEP_RETENTION_ADV | SUSPEND_CONN | DEEPSLEEP_RETENTION_CONN);
			blc_pm_setDeepsleepRetentionThreshold(95, 95);
			#if (MCU_CORE_B80)
				blc_pm_setDeepsleepRetentionEarlyWakeupTiming(650);
			#elif (MCU_CORE_B80B)
				blc_pm_setDeepsleepRetentionEarlyWakeupTiming(550);
			#endif
		#else
			bls_pm_setSuspendMask (SUSPEND_ADV | SUSPEND_CONN);
		#endif
		bls_app_registerEventCallback (BLT_EV_FLAG_SUSPEND_ENTER, &task_sleep_enter);
	#else
		bls_pm_setSuspendMask (SUSPEND_DISABLE);
	#endif

	#if (UI_KEYBOARD_ENABLE)
		/////////// keyboard gpio wakeup init ////////
		u32 pin[] = KB_DRIVE_PINS;
		for (int i=0; i<(sizeof (pin)/sizeof(*pin)); i++)
		{
			cpu_set_gpio_wakeup (pin[i], Level_High,1);  //drive pin pad high wakeup deepsleep
		}

		bls_app_registerEventCallback (BLT_EV_FLAG_GPIO_EARLY_WAKEUP, &proc_keyboard);
	#endif

	////////////////////////////////////////////////////////////////////////////////////////////////

	/* Check if any Stack(Controller & Host) Initialization error after all BLE initialization done.
	 * attention that code will stuck in "while(1)" if any error detected in initialization, user need find what error happens and then fix it */
	 blc_app_checkControllerHostInitialization();


	advertise_begin_tick = clock_time();
}

#if (PM_DEEPSLEEP_RETENTION_ENABLE)
/**
 * @brief		user initialization when MCU wake_up from deepSleep_retention mode
 * @param[in]	none
 * @return      none
 */
_attribute_ram_code_
void user_init_deepRetn(void)
{

	blc_app_loadCustomizedParameters_deepRetn();
	//////////// LinkLayer Initialization  Begin /////////////////////////
	blc_ll_initBasicMCU();                      //mandatory

//////////////////////////// User Configuration for BLE application ////////////////////////////

	/* set rf power index, user must set it after every suspend wakeup, cause relative setting will be reset in suspend */
	rf_set_power_level_index (MY_RF_POWER_INDEX);
	blc_ll_recoverDeepRetention();
	irq_enable();
	#if (UI_KEYBOARD_ENABLE)
		/////////// keyboard gpio wakeup init ////////
		u32 pin[] = KB_DRIVE_PINS;
		for (int i=0; i<(sizeof (pin)/sizeof(*pin)); i++)
		{
			cpu_set_gpio_wakeup (pin[i], Level_High,1);  //drive pin pad high wakeup deepsleep
		}
	#endif
////////////////////////////////////////////////////////////////////////////////////////////////
}
#endif






#if (UI_KEYBOARD_ENABLE)

int 	key_not_released;
u8 		key_type;
static u32 keyScanTick = 0;

extern u32	scan_pin_need;

#define CONSUMER_KEY   	   		1
#define KEYBOARD_KEY   	   		2

/**
 * @brief		this function is used to process keyboard matrix status change.
 * @param[in]	none
 * @return      none
 */
void key_change_proc(void)
{

	u8 key0 = kb_event.keycode[0];
	u8 key_buf[8] = {0,0,0,0,0,0,0,0};

	key_not_released = 1;
	if (kb_event.cnt == 2)   //two key press, do  not process
	{
	}
	else if(kb_event.cnt == 1)
	{
		if(key0 >= CR_VOL_UP )  //volume up/down
		{
			key_type = CONSUMER_KEY;
			u16 consumer_key;
			if(key0 == CR_VOL_UP){  	//volume up
				consumer_key = MKEY_VOL_UP;
			}
			else if(key0 == CR_VOL_DN){ //volume down
				consumer_key = MKEY_VOL_DN;
			}
			blc_gatt_pushHandleValueNotify (BLS_CONN_HANDLE,HID_CONSUME_REPORT_INPUT_DP_H, (u8 *)&consumer_key, 2);
		}
		else
		{
			key_type = KEYBOARD_KEY;
			key_buf[2] = key0;
			blc_gatt_pushHandleValueNotify (BLS_CONN_HANDLE,HID_NORMAL_KB_REPORT_INPUT_DP_H, key_buf, 8);
		}
	}
	else   //kb_event.cnt == 0,  key release
	{
		key_not_released = 0;
		if(key_type == CONSUMER_KEY)
		{
			u16 consumer_key = 0;
			blc_gatt_pushHandleValueNotify ( BLS_CONN_HANDLE,HID_CONSUME_REPORT_INPUT_DP_H, (u8 *)&consumer_key, 2);
		}
		else if(key_type == KEYBOARD_KEY)
		{
			key_buf[2] = 0;
			blc_gatt_pushHandleValueNotify (BLS_CONN_HANDLE,HID_NORMAL_KB_REPORT_INPUT_DP_H, key_buf, 8); //release
		}
	}
}



/**
 * @brief      this function is used to detect if key pressed or released.
 * @param[in]  e - LinkLayer Event type
 * @param[in]  p - data pointer of event
 * @param[in]  n - data length of event
 * @return     none
 */

void proc_keyboard (u8 e, u8 *p, int n)
{
	if(clock_time_exceed(keyScanTick, 8000)){
		keyScanTick = clock_time();
	}
	else{
		return;
	}

	kb_event.keycode[0] = 0;
	int det_key = kb_scan_key (0, 1);

	if (det_key){
		key_change_proc();
	}
}


#endif  //end of UI_KEYBOARD_ENABLE







/**
 * @brief      callback function of LinkLayer Event "BLT_EV_FLAG_SUSPEND_ENTER"
 * @param[in]  e - LinkLayer Event type
 * @param[in]  p - data pointer of event
 * @param[in]  n - data length of event
 * @return     none
 */
void task_sleep_enter(u8 e, u8 *p, int n)
{
#if (BLE_APP_PM_ENABLE)
	if( blc_ll_getCurrentState() == BLS_LINK_STATE_CONN
		&& ((u32)(bls_pm_getSystemWakeupTick() - clock_time())) > 80 *CLOCK_16M_SYS_TIMER_CLK_1MS ){  //suspend time > 30ms.add gpio wakeup
		bls_pm_setWakeupSource(PM_WAKEUP_PAD);  //gpio CORE wakeup suspend
	}
#endif
}












/**
 * @brief     BLE main loop
 * @param[in]  none.
 * @return     none.
 */
void main_loop (void)
{

	////////////////////////////////////// BLE entry /////////////////////////////////
	blc_sdk_main_loop();

	////////////////////////////////////// UI entry /////////////////////////////////
	#if (UI_KEYBOARD_ENABLE)
		proc_keyboard (0, 0, 0);
	#endif


	////////////////////////////////////// PM Process /////////////////////////////////
	blt_pm_proc();

}



#endif //end of (FEATURE_TEST_MODE == xxx)

