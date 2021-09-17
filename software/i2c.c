/*
 * io.c
 *
 *  Created on: Jul 29, 2021
 *      Author: Ben De Lathouwer
 */

#include "i2c.h"
#include"stm32l0xx_hal.h"
#include <stdio.h>
I2C_HandleTypeDef hi2c1;

static const uint8_t SERIAL_ READ_ADDER = 0xA1;// read addres from the serial number chip
static const uint8_t SERIAL_ WRITE_ADDER = 0xA0;//write addres from the serial nuber chip



