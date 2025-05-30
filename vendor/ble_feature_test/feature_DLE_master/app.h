/********************************************************************************************************
 * @file    app.h
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
#ifndef _APP_H
#define _APP_H


#include "app_config.h"

#if (FEATURE_TEST_MODE == TEST_LL_DATA_LENGTH_EXTENSION_MASTER)


/**
 * @brief		user initialization when MCU power on or wake_up from deepSleep mode
 * @param[in]	none
 * @return      none
 */

void user_init_normal(void);




/**
 * @brief     BLE main loop
 * @param[in]  none.
 * @return     none.
 */
void main_loop (void);

/**
 * @brief     BLE main idle loop
 * @param[in]  none.
 * @return     none.
 */
int main_idle_loop (void);
#endif //end of (FEATURE_TEST_MODE == xxx)

#endif /* APP_H_ */

