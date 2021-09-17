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

//static const uint8_t SERIAL_READ_ADDER = 0xA1;// read addres from the serial number chip
//static const uint8_t SERIAL_WRITE_ADDER = 0xA0;//write addres from the serial nuber chip

