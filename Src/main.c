/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2022 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Delay_interface.h"
#include "RCC_interface.h"
#include "NVIC_interface.h"
#include "GPIO_interface.h"
#include "UART_interface.h"
#include "UART_ENUMS.h"
#include "LCD_Interface.h"
#include "EXTI_interface.h"
#include "Touch_Sensor_Interface.h"
#include "STK_interface.h"
#include "servo.h"
#include "Ultrasomic_Interface.h"
#include "Ultrasomic_Trunk_Interface.h"
#include "TIMER2_Interface.h"
#include "TIMER2_Private.h"
#include "ADC_Interface.h"
#include "TempSensor_Interface.h"
#include "DC_Motor_Interface.h"

void A_UART2_RX_EXEC(void);
void A_EXTI_0_void_Execution(void);
void A_EXTI_1_void_Execution(void);
void Trunk_OpenClose(void);
void A_void_CloseTrunk(void);
void A_void_OpenTrunk(void);
void A_void_CloseDoor(void);
void A_void_OpenDoor(void);
void A_void_AirCond(void);

#define DC_MOTOR_DIR	DC_MOTOR_CLOCKWISE

u8 Car_Unlock_Flag = 0;
u8 Door_Open_Flag = 0;
u8 Owner_Inside_Flag = 0;

int main(void)
{
	u8 Local_u8_GPIO = 0;

	MRCC_vInitSystemCLK();

	//enable GPIO CLK
	for(Local_u8_GPIO = _PERIPHERAL_EN_GPIOA; Local_u8_GPIO <= _PERIPHERAL_EN_GPIOD ; Local_u8_GPIO++)
	{
		//if(Local_u8_GPIO < 5 || Local_u8_GPIO > 6)
		MRCC_vEnableClock(AHB1 , Local_u8_GPIO);
	}

	MRCC_vEnableClock(APB2 , PERIPHERAL_EN_SYSCFG);
	MRCC_vEnableClock(APB1 , PERIPHERAL_EN_TIM2);
	MRCC_vEnableClock(APB1 , PERIPHERAL_EN_TIM5);
	MRCC_vEnableClock(APB1 , PERIPHERAL_EN_TIM3);
	MRCC_vEnableClock(APB1 , PERIPHERAL_EN_TIM4);
	MRCC_vEnableClock(APB1 , PERIPHERAL_EN_UART2);
	MRCC_vEnableClock(APB2 , PERIPHERAL_EN_ADC1);

	MNVIC_vEnableIRQ(USART2_IRQn);
	MNVIC_vEnableIRQ(TIM2_IRQn);
	MNVIC_vEnableIRQ(EXTI0_IRQn);
	MNVIC_vEnableIRQ(EXTI1_IRQn);

	MTIMER_void_TIMERInit();
	MTIMER_void_TIMER5Init();
	MTIMER_void_TIMER3Init();
	MTIMER_void_TIMER4Init();

	MSTK_vInit();

	MUART_vInit();
	MUART_vEnable(UART_2);
	MUSART1_VidSetCallBack(A_UART2_RX_EXEC);

	H_TempSensor_void_Init();

	//leds
	MGPIO_vSetPinMode(GPIOB_PORT , GPIO_PIN_2 , OUTPUT);
	MGPIO_vSetPinMode(GPIOB_PORT , GPIO_PIN_10 , OUTPUT);
	MGPIO_vSetPinMode(GPIOB_PORT , GPIO_PIN_1 , OUTPUT);
	MGPIO_vSetPinMode(GPIOB_PORT , GPIO_PIN_5 , OUTPUT);

	MGPIO_vSetPinOutPutType(GPIOB_PORT , GPIO_PIN_2 , PUSH_PULL);
	MGPIO_vSetPinOutPutType(GPIOB_PORT , GPIO_PIN_10 , PUSH_PULL);
	MGPIO_vSetPinOutPutType(GPIOB_PORT, GPIO_PIN_1 , PUSH_PULL);
	MGPIO_vSetPinOutPutType(GPIOB_PORT , GPIO_PIN_5 , PUSH_PULL);

	MGPIO_vSetPullType(GPIOB_PORT , GPIO_PIN_2 , NORMAL);
	MGPIO_vSetPullType(GPIOB_PORT , GPIO_PIN_10 , NORMAL);
	MGPIO_vSetPullType(GPIOB_PORT , GPIO_PIN_1 , NORMAL);
	MGPIO_vSetPullType(GPIOB_PORT , GPIO_PIN_5 , NORMAL);

	MGPIO_vSetPinOutSpeed(GPIOB_PORT , GPIO_PIN_2 , MEDIUM_SPEED);
	MGPIO_vSetPinOutSpeed(GPIOB_PORT , GPIO_PIN_10 , MEDIUM_SPEED);
	MGPIO_vSetPinOutSpeed(GPIOB_PORT , GPIO_PIN_1 , MEDIUM_SPEED);
	MGPIO_vSetPinOutSpeed(GPIOB_PORT , GPIO_PIN_5 , MEDIUM_SPEED);

	//uart
	MGPIO_vSetPinMode(GPIOA_PORT , GPIO_PIN_2 , ALT);
	MGPIO_vSetPinMode(GPIOA_PORT , GPIO_PIN_3 , ALT);
	MGPIO_vSetPinAltFn(GPIOA_PORT , GPIO_PIN_2 , _ALTFN_7);
	MGPIO_vSetPinAltFn(GPIOA_PORT , GPIO_PIN_3 , _ALTFN_7);

	//timer5 pwm
	MGPIO_vSetPinMode(GPIOA_PORT , GPIO_PIN_0 , ALT);
	MGPIO_vSetPinAltFn(GPIOA_PORT , GPIO_PIN_0 , _ALTFN_2);

	//timer3 pwm (door)
	MGPIO_vSetPinMode(GPIOA_PORT , GPIO_PIN_7 , ALT);
	MGPIO_vSetPinAltFn(GPIOA_PORT , GPIO_PIN_7 , _ALTFN_2);

	//timer4 pwm (trunk)
	MGPIO_vSetPinMode(GPIOB_PORT , GPIO_PIN_6 , ALT);
	MGPIO_vSetPinAltFn(GPIOB_PORT , GPIO_PIN_6 , _ALTFN_2);

	//Touch in
	H_Touch_Sensor_void_Init();
	H_Touch_Sensor_void_SetCallBack(A_EXTI_0_void_Execution);
	//Touch out
	H_Touch_Sensor_2_void_Init();
	H_Touch_Sensor_2_void_SetCallBack(A_EXTI_1_void_Execution);

	H_VUltrasonicInit();

	H_VUltrasonic_Trunk_Init();

	H_LCD_void_LCDInit();

	H_DC_MOTOR_void_Init();
	H_DC_MOTOR_void_Direction(DC_MOTOR_DIR);

	u8 data = 'a';
	MUART_u8SendData(UART_2 , &data);

	H_LCD_void_LCDSendChar('m');

    /* Loop forever */
	while(1)
	{
		A_void_AirCond();
		Trunk_OpenClose();
	}
}

void A_UART2_RX_EXEC(void)
{
	u8 Local_u8_READ = 0;
	Local_u8_READ = MUART_u8ReadData(UART_2);
	H_LCD_void_LCDSendChar(Local_u8_READ);
	if(Local_u8_READ == '1')
	{
		MGPIO_vWriteData(GPIOB_PORT , GPIO_PIN_5 , _HIGH);
		//unlock car
		Car_Unlock_Flag = 1;
	}
	else if (Local_u8_READ == '2')
	{
		MGPIO_vWriteData(GPIOB_PORT , GPIO_PIN_5 , LOW);
		//lock car
		Car_Unlock_Flag = 0;
	}
}

void A_EXTI_0_void_Execution(void)
{
	if (Door_Open_Flag == 1 && Car_Unlock_Flag == 1)
	{
	//close door
	Door_Open_Flag = 0;
	A_void_CloseDoor();
	MGPIO_vWriteData(GPIOB_PORT , GPIO_PIN_2 , LOW);
	}
	else if (Door_Open_Flag == 0 && Owner_Inside_Flag == 1)
	{
		//open door
		Door_Open_Flag = 1;
		MGPIO_vWriteData(GPIOB_PORT , GPIO_PIN_2 , _HIGH);
		A_void_OpenDoor();
	}
}

void A_EXTI_1_void_Execution(void)
{
	//MGPIO_vWriteData(GPIOB_PORT , GPIO_PIN_2 , _HIGH);
	if (Door_Open_Flag == 0 && Car_Unlock_Flag == 1)
	{
		Door_Open_Flag = 1;
		MGPIO_vWriteData(GPIOB_PORT , GPIO_PIN_2 , _HIGH);
		A_void_OpenDoor();
	}
}

void TIM2_IRQHandler()
{
	u32 Local_u32_USRead = 0;
	Local_u32_USRead = H_u16USRead();
	if(Local_u32_USRead > 50 && Car_Unlock_Flag == 0)
	{
		//normal
		MGPIO_vWriteData(GPIOB_PORT , GPIO_PIN_10 , _HIGH);
		Delay_vMsIn16MHz(100);
		MGPIO_vWriteData(GPIOB_PORT, GPIO_PIN_10, LOW);
	}
	else if(Local_u32_USRead < 50 && Car_Unlock_Flag == 0)
	{
		if(Owner_Inside_Flag == 0 )
		{
			//intruder in
			MGPIO_vWriteData(GPIOB_PORT, GPIO_PIN_1 , _HIGH);
			Delay_vMsIn16MHz(100);
			MGPIO_vWriteData(GPIOB_PORT, GPIO_PIN_1 , LOW);
		}
	}
	if(Local_u32_USRead < 50 && Car_Unlock_Flag == 1)
	{
		Owner_Inside_Flag = 1 ;
	}
	else if(Local_u32_USRead > 50 && Car_Unlock_Flag == 1)
	{
		Owner_Inside_Flag = 0 ;
	}


	CLR_BIT(TIM2->SR,0);
}

void Trunk_OpenClose(void)
{
	static u8 Trunk_open_flag = 0;
	u32 Local_u32_Read = 0;
	Local_u32_Read = H_u16US_Trunk_Read();
	if(Local_u32_Read < 20 && Trunk_open_flag == 0 && Car_Unlock_Flag == 1)
	{
		//Delay_vMsIn16MHz(100);
		while(H_u16US_Trunk_Read() < 20);
		A_void_OpenTrunk();
		Trunk_open_flag = 1;
	}
	else if(Local_u32_Read < 20 && Trunk_open_flag == 1 && Car_Unlock_Flag == 1)
	{
		//Delay_vMsIn16MHz(100);
		while(H_u16US_Trunk_Read() < 20);
		A_void_CloseTrunk();
		Trunk_open_flag = 0;
	}
}

void A_void_CloseTrunk(void)
{
	Servo_angle_Trunk(0);
}

void A_void_OpenTrunk(void)
{
	Servo_angle_Trunk(180);
}

void A_void_CloseDoor(void)
{
	Servo_angle_Door(0);
}

void A_void_OpenDoor(void)
{
	Servo_angle_Door(180);
}

void A_void_AirCond(void)
{
	u16 Local_u16_TempRead = 0;
	if(Owner_Inside_Flag == 1 && Door_Open_Flag == 0)
	{
		Local_u16_TempRead = H_TempSensor_u16_Read();
		if(Local_u16_TempRead > 30)
		{
			//full speed
			H_DC_MOTOR_void_Direction(DC_MOTOR_DIR);
			H_DC_MOTOR_void_Speed(DC_MOTOR_FULL_SPEED);
		}
		else if(Local_u16_TempRead >23 && Local_u16_TempRead < 30)
		{
			//half speed
			H_DC_MOTOR_void_Direction(DC_MOTOR_DIR);
			H_DC_MOTOR_void_Speed(DC_MOTOR_HALF_SPEED);
		}
		else
		{
			H_DC_MOTOR_void_Stop();
		}
	}
	else if(Owner_Inside_Flag == 0)
	{
		H_DC_MOTOR_void_Stop();
	}
}
