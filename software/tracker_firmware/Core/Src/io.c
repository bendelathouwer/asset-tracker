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
	HAL_GPIO_WritePin(BUZZER_GPIO_Port, BUZZER_Pin, GPIO_PIN_RESET);
}
