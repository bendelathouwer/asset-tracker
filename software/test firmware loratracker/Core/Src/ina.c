/*
 * ina.c
 *
 *  Created on: Jun 2, 2021
 *      Author: Ben De Lathouwer
 */
#include "ina.h"
#include "stm32h7xx_hal.h"
#include <stdio.h>
I2C_HandleTypeDef hi2c4;
HAL_StatusTypeDef ret;

static const int ina_adder = 0x100;// slave addres of the ina219
//internal registers of the ina219
static const uint8_t config_reg     = 0x00;
//static const uint8_t Shunt_Volt_Reg = 0x01;
//static const uint8_t Bus_Volt_Reg   = 0x02;
//static const uint8_t Power_reg     = 0x03;
//static const uint8_t Current_reg  = 0x04;
//static const uint8_t Cal_Reg       = 0x05;

uint8_t buf[12];


//configuring the ina219
int Config_INA(void)
{
	buf[0]=config_reg;
	ret = HAL_I2C_Master_Transmit(&hi2c4, ina_adder, buf, 1, 1000);
	if(ret != HAL_OK)
	{
		return 0;

	}
	else
	{
		return 1;
	}

}
