/*
 * tracker.c
 *
 *  Created on: Sep 22, 2021
 *      Author: Ben De Lathouwer
 */

#include "tracker.h"
#include"stm32l0xx_hal.h"
#include <stdio.h>
I2C_HandleTypeDef hi2c1;
RTC_HandleTypeDef hrtc;
SPI_HandleTypeDef hspi1;
UART_HandleTypeDef huart1;

void ssr (int power)
{
//	if(power==1)
//	{
//		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_1,GPIO_PIN_SET);
//	}
//	if(power==0)
//	{
//		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_1,GPIO_PIN_RESET);
//	}
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
