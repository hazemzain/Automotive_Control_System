/**
 ******************************************************************************
 * @file    main.c
 * @author  Auto-generated by STM32CubeIDE
 * @version V1.0
 * @brief   Default main function.
 ******************************************************************************
 */
/*===========   INCLUDE LIB   ===========*/
#include  "STD_TYPES.h"
#include  "BIT_MATH.h"
#include "Delay_interface.h"

/*======================================*/
/*===========  INCLUDE MCAL  ===========*/
#include"RCC_interface.h"
#include"GPIO_interface.h"
//#include"SPI_interface.h"
#include"STK_interface.h"
/*======================================*/
/*===========  INCLUDE HAL   ===========*/
#include"servo_Trunk.h"


u32 G_u32_Trunk_OnTime_EN;
u32 G_u32_Trunk_OffTime_EN;

//////////////////////////////////////////////////////////////////////////////////////////////////////

void Trunk_Generate_PWM_Enter(u16 Copy_u16DutyCyclePercentx10, u32 Copy_u32PeriodInMilli)
{
	//u8 Copy_ChoosePin = 15;
	//Percentage of duty times 10 to handle the floating numbers
	G_u32_Trunk_OnTime_EN = (Copy_u16DutyCyclePercentx10 * Copy_u32PeriodInMilli);
	G_u32_Trunk_OffTime_EN = (Copy_u32PeriodInMilli*1000) - G_u32_Trunk_OnTime_EN;
	//G_u8PinNum = Copy_ChoosePin;
	MSTK_vSetIntervalPeriodic(G_u32_Trunk_OffTime_EN , Trunk_ON_PWM_Enter);
}

void Trunk_ON_PWM_Enter(void)
{
	/* Pin (14) >> EXIT  -- Pin (15) >> Enter*/
	MGPIO_vWriteData(GPIOC_PORT, GPIO_PIN_12, 1u);
	MSTK_vSetIntervalPeriodic(G_u32_Trunk_OnTime_EN, Trunk_OFF_PWM_Enter);
}

void Trunk_OFF_PWM_Enter(void)
{
	/* Pin (14) >> EXIT  -- Pin (15) >> Enter*/
	MGPIO_vWriteData(GPIOC_PORT , GPIO_PIN_12,0u);
	MSTK_vSetIntervalPeriodic(G_u32_Trunk_OffTime_EN , Trunk_ON_PWM_Enter);
}

// set nedded angel // used
void Trunk_Servo_angle_Enter(u16 angle)
{	
	switch (angle)
	{

	case 0 :
		Trunk_Generate_PWM_Enter(0, 20);	// angle 0  +90
		break;
	case 90 :
			Trunk_Generate_PWM_Enter(-300, 20);	// angle 90 //-67
			break;
	case 180 :
		Trunk_Generate_PWM_Enter(300, 20);	// angle 180  -90
		break;
	}
}