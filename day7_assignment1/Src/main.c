/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>

#include <stdio.h>

#include <string.h>

#include "stm32f4xx.h"

#include "system_stm32f4xx.h"

#include "uart.h"

#include "led.h"

#include "switch.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)

  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."

#endif

extern int count;

int main(void)

{

	char scount[15];

	int cState = 0;

	int pState = 0;

	SystemInit();

	LedInit(LED_ORANGE);

	UartInit(BAUD_9600);

	SwitchInit(SWITCH);

	while(1)


		while(exti0_flag == 0)

		{ ; }

		cState = 1;

		if(cState == 1)

		{
			if(cState != pState)

			{

				count++;

				pState = cState;

			}
			else if(cState == pState)
			{
				count = count;
			}
		}
		{
		UartPuts("Count:");

		DelayMs(5);

		UartPuts(itoa(count, scount, 10));

		DelayMs(5);

		UartPuts("\r\n");

		LedBlink(LED_GREEN, 100);

		pState = 0;

		exti0_flag = 0;
		}



	return 0;
}

