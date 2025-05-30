/********************************************************************************************************
 * @file    app_ui.h
 *
 * @brief   This is the header file for 2.4G SDK
 *
 * @author  2.4G GROUP
 * @date    02,2025
 *
 * @par     Copyright (c) 2025, Telink Semiconductor (Shanghai) Co., Ltd. ("TELINK")
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
#ifndef APP_UI_H_
#define APP_UI_H_

#include "app_config.h"
#if (FEATURE_TEST_MODE == OTA)
#if (UI_BUTTON_ENABLE)

extern int button_not_released;

/**
 * @brief		this function is used to detect if button pressed or released.
 * @param[in]	e - event type when this function is triggered by LinkLayer event
 * @param[in]	p - event callback data pointer for when this function is triggered by LinkLayer event
 * @param[in]	n - event callback data length when this function is triggered by LinkLayer event
 * @return      none
 */
void proc_button(u8 e, u8 *p, int n);


#endif






#endif /* APP_UI_H_ */
#endif
