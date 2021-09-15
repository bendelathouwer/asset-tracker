/*
 * io.c
 *
 *  Created on: Jul 29, 2021
 *      Author: Ben De Lathouwer
 */

#include "io.h"
#include"stm32l0xx_hal.h"
#include <stdio.h>



void ssr (int power)
{
	if(power==1)
	{
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_1,GPIO_PIN_SET);
	}
	if(power==0)
	{
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_1,GPIO_PIN_RESET);
	}
}

void noise(int sound)
{
	if(sound == 1)
	{
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_0,GPIO_PIN_SET);
	}
	if(sound == 0)
	{
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_0,GPIO_PIN_RESET);
	}
}
