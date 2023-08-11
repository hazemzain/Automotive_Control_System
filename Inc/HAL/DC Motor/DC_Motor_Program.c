/*
 * DC_Motor_Program.c
 *
 *  Created on: Aug 31, 2022
 *      Author: Abdulrahman
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO_interface.h"
#include "Timer2_Interface.h"
#include "DC_MOTOR_Interface.h"
#include "DC_Motor_Private.h"

void H_DC_MOTOR_void_Init(void)
{
	/*CONFIGRE INPUT PIN FOR L293D*/
	MGPIO_vSetPinMode(GPIOD_PORT , GPIO_PIN_11 , OUTPUT);
	MGPIO_vSetPinOutPutType(GPIOD_PORT , GPIO_PIN_11, PUSH_PULL);
	MGPIO_vSetPullType(GPIOD_PORT , GPIO_PIN_11, NORMAL);

	MGPIO_vSetPinMode(GPIOD_PORT , GPIO_PIN_10 , OUTPUT);
	MGPIO_vSetPinOutPutType(GPIOD_PORT , GPIO_PIN_10, PUSH_PULL);
	MGPIO_vSetPullType(GPIOD_PORT , GPIO_PIN_10, NORMAL);
}

void H_DC_MOTOR_void_Direction(u8 Copy_Direction)
{
	switch(Copy_Direction)
	{
	case DC_MOTOR_CLOCKWISE:
		MGPIO_vWriteData(GPIOD_PORT , GPIO_PIN_10, _HIGH);
		MGPIO_vWriteData(GPIOD_PORT , GPIO_PIN_11, _LOW);
		break;
	case DC_MOTOR_ANTI_CLOCKWISE:
		MGPIO_vWriteData(GPIOD_PORT , GPIO_PIN_10, _LOW);
		MGPIO_vWriteData(GPIOD_PORT , GPIO_PIN_11, _HIGH);
		break;
	default:
		break;
	}
}

void H_DC_MOTOR_void_Stop(void)
{
	MGPIO_vWriteData(GPIOD_PORT , GPIO_PIN_10, _LOW);
	MGPIO_vWriteData(GPIOD_PORT , GPIO_PIN_11, _LOW);
}

void H_DC_MOTOR_void_Speed(u8 Copy_u8_Speed)
{

	switch(Copy_u8_Speed)
	{
	case DC_MOTOR_HALF_SPEED:
		//half speed
		M_TIMER_void_TIMER5_DUTYCYCLE(50);
		break;
	case DC_MOTOR_FULL_SPEED:
		//half speed
		M_TIMER_void_TIMER5_DUTYCYCLE(99);
		break;
	}
}
