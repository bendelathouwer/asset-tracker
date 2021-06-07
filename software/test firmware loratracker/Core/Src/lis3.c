/*
 * lis3.c
 *
 *  Created on: Jun 4, 2021
 *      Author: Ben De Lathouwer
 */
#include "lis3d.h"
#include "stm32h7xx_hal.h"
#include <stdio.h>
I2C_HandleTypeDef hi2c4;
HAL_StatusTypeDef ret;
uint8_t buf[10];


static const int lis_adder = 0x19<<1 ;// slave addres of the lis3dh


//lis3dh registers
static const int who_am_i_register = 0x0F;

int SanityCheck(void)
{
	buf[0] = who_am_i_register;
	HAL_I2C_Master_Transmit(&hi2c4, lis_adder, buf, 1, 1);

	ret = HAL_I2C_Master_Receive(&hi2c4, lis_adder, buf, 7, 1);
	if(ret != HAL_OK)
	{
		return 0;
	}
	else {
		return 1;
	}
}
