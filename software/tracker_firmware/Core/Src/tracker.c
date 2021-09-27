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

//suport functions
//  io functions
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


// RTC functions-
int SetTime(int hours , int minutes , int secondes , int DaylightSaving, int month, int day, int year)
{
	 RTC_TimeTypeDef sTime;
	 RTC_DateTypeDef sDate;
	 //time parameters
	 sTime.Hours   = hours;
	 sTime.Minutes = minutes;
	 sTime.Seconds = secondes;
	 sTime.StoreOperation = RTC_STOREOPERATION_RESET;
	 // date  parameters
	 sDate.Month   = month;
	 sDate.WeekDay = day;
	 sDate.Year    = year;


	 if(DaylightSaving==1)
	 {
		 sTime.DayLightSaving =RTC_DAYLIGHTSAVING_ADD1H;
	 }
	 else
	 {
		 sTime.DayLightSaving = RTC_DAYLIGHTSAVING_SUB1H;
	 }

	 if (HAL_RTC_SetTime(&hrtc, &sTime, RTC_FORMAT_BCD) != HAL_OK)
	 {
		 	 Error_Handler();
		 	 return -1;
	 }
	 if (HAL_RTC_SetDate(&hrtc, &sDate, RTC_FORMAT_BCD) != HAL_OK)
	  {
		 Error_Handler();
		 return -2;
	  }
	  HAL_RTCEx_BKUPWrite(&hrtc, RTC_BKP_DR1, 0x32F2); // backup register

	  return 0;
}
