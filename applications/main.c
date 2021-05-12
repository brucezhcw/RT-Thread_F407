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

/* defined the LED0 pin: PF9 */
#define LED0_PIN    GET_PIN(F, 9)
#define LED1_PIN    GET_PIN(F, 10)

int main(void)
{
    /* set LED0 pin mode to output */
    rt_pin_mode(LED0_PIN, PIN_MODE_OUTPUT);
	rt_pin_mode(LED1_PIN, PIN_MODE_OUTPUT);
	
	set_date(2021, 5, 1);
	set_time(0, 0, 0);
 
    while (1)
    {
        rt_pin_write(LED0_PIN, PIN_HIGH);
		rt_pin_write(LED1_PIN, PIN_LOW);
        rt_thread_mdelay(500);
        rt_pin_write(LED0_PIN, PIN_LOW);
		rt_pin_write(LED1_PIN, PIN_HIGH);
        rt_thread_mdelay(500);
    }
}
