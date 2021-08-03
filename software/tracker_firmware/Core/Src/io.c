/*
 * io.c
 *
 *  Created on: Jul 29, 2021
 *      Author: Ben De Lathouwer
 */

#include "io.h"
#include"stm32l0xx_hal.h"



void startup()
{
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, GPIO_PIN_RESET);
}
