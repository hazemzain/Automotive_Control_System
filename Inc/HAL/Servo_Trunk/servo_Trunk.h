/******************************************************************
   -	.h
   - Created: /5/2022
   - Author: NTI Embedded Team
   - Version : V01
 *****************************************************************/


#ifndef servo_TRUNK_H
#define servo_TRUNK_H

         /*===========   INCLUDE LIB   ===========*/
         #include "STD_TYPES.h"
	 	 #include "BIT_MATH.h"
		 #include "Delay_interface.h"

         /*======================================*/
         /*===========  INCLUDE MCAL  ===========*/
		#include "RCC_interface.h"
		#include "GPIO_interface.h"
		#include "STK_interface.h"

/******************************* EXIT ***********************************/


/******************************* ENTER ***********************************/

void Trunk_Generate_PWM_Enter(u16 Copy_u16DutyCyclePercentx10, u32 Copy_u32PeriodInMilli);

void Trunk_ON_PWM_Enter(void);
	 
void Trunk_OFF_PWM_Enter(void);
	 
void Trunk_Servo_angle_Enter(u16 );

#endif //servo_H
