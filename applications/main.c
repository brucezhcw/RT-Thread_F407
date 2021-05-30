/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2018-11-06     SummerGift   first version
 * 2018-11-19     flybreak     add stm32f407-atk-explorer bsp
 */

#include <rtthread.h>
#include <rtdevice.h>
#include <board.h>

#include "player.h"
#include "song_data.h"
#include "beep.h"
#include "decode.h"
#include "key.h"
#include "led.h"

struct player player;
struct audio_ops audio;
struct decode_ops decode;

uint16_t freq_tab[12]  = {262, 277, 294, 311, 330, 349, 369, 392, 415, 440, 466, 494}; //?'???? CDEFGAB
uint8_t beep_volume = 20;

int main(void)
{	
	set_date(2021, 5, 1);
	set_time(0, 0, 0);
	
    led_init();
    led_on();
	
    beep_init();

    for (int i = 0; i < 12; i++)
    {
        beep_set(freq_tab[i], beep_volume);
        beep_on();

        rt_thread_mdelay(500);

        beep_off();
        rt_thread_mdelay(500);
    }
	
    while (1)
    {
        led_toggle();
        rt_thread_mdelay(500);
    }
}
