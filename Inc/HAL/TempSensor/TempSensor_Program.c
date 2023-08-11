/*
 * TempSensor_Program.c
 *
 *  Created on: Aug 17, 2022
 *      Author: Abdulrahman
 */

#include "STD_TYPES.h"
#include "GPIO_interface.h"
#include "ADC_Interface.h"
#include "TempSensor_Interface.h"

void H_TempSensor_void_Init(void)
{
	//pin pa1 analog
	MGPIO_vSetPinMode(GPIOA_PORT , GPIO_PIN_1 , ANALOUGE);
	//regular continuous mode
	M_AdcInit(_ADC_SINGLE_CONTINUS_MODE);
	M_AdcEnable();
	//ADC1 Channel regular 0 sequence
	M_AdcRegular_Sequance(CHANNEL_1 , Regular_SEQUENCE_ID_0);
	// start conversion (continuous)
	M_AdcStartConv(ADC_MODE_REGULAR);
}

u16 H_TempSensor_u16_Read(void)
{
	u16 Local_u16_Temp = 0;
	MADC_RegulerRead(&Local_u16_Temp);
	Local_u16_Temp = ((u32)Local_u16_Temp * 500) / 4095;
	return Local_u16_Temp;
}
