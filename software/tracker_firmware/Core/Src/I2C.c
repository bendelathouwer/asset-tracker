/*
 * I2C.c
 *
 *  Created on: Sep 15, 2021
 *      Author: Ben De Lathouwer
 */


#include "I2C.h"
#include"stm32l0xx_hal.h"
#include <stdio.h>
I2C_HandleTypeDef hi2c1;

// addres of the serial number
static const uint8_t SERIAL_ADDER = 0x50;
