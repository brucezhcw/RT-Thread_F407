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

int main(void)
{	
	set_date(2021, 5, 1);
	set_time(0, 0, 0);
	
    led_init();
    led_on();
	
	struct beep_song_data data;
    int len, i;
    char name[20];

	rt_thread_mdelay(10);
	
    beep_init();
    beep_song_decode_init();
    beep_song_get_name(&song1, name);
    rt_kprintf("Playing: %s\n",name);
    len = beep_song_get_len(&song1);
    while (i < len)
    {
        /* 解码音乐数据 */
        beep_song_get_data(&song1, i, &data);
        beep_set(data.freq, 20);
        beep_on();

        rt_thread_mdelay(data.sound_len);

        beep_off();
        rt_thread_mdelay(data.nosound_len);
        i++;
    }
	
    while (1)
    {
        led_toggle();
        rt_thread_mdelay(500);
    }
}
