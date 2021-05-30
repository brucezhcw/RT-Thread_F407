/*
* Copyright (c) 2006-2018, RT-Thread Development Team
*
* SPDX-License-Identifier: Apache-2.0
*
* Change Logs:
* Date           Author       Notes
* 2018-10-17     flybreak      the first version
*/

#ifndef BEEP_KEY_H
#define BEEP_KEY_H

#include <board.h>

#include "multi_button.h"
#include "player.h"

#define KEY_PLAY_PIN     GET_PIN(A, 0)
#define KEY_LAST_PIN     GET_PIN(E, 4)
#define KEY_NEXT_PIN     GET_PIN(E, 2)
#define KEY_PRESS_LEVEL  0

int key_init(void);                     //按键初始化

#endif
