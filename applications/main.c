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

void uart3test(void *parameter)
{
    rt_device_t new_device;

    new_device = rt_device_find("uart3");

    if (new_device == RT_NULL) return ;
	
	if(rt_device_open(new_device, RT_DEVICE_FLAG_INT_TX | RT_DEVICE_FLAG_INT_RX)!=RT_EOK) return ;
	
	while(1)
	{
		rt_device_write(new_device, 0, "uart3 runing test...\r\n", 22);
		rt_thread_mdelay(1000);
	}
}

int main(void)
{
    /* set LED0 pin mode to output */
    rt_pin_mode(LED0_PIN, PIN_MODE_OUTPUT);
	rt_pin_mode(LED1_PIN, PIN_MODE_OUTPUT);
	
	set_date(2021, 5, 1);
	set_time(12, 10, 0);
 
	rt_thread_t tid;
    tid = rt_thread_create("uart3test", uart3test, RT_NULL,
                           1024, 5, 20);
    RT_ASSERT(tid != RT_NULL);
	rt_thread_startup(tid);
	
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
