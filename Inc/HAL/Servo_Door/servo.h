/******************************************************************
   -	.h
   - Created: /5/2022
   - Author: NTI Embedded Team
   - Version : V01
 *****************************************************************/


#ifndef servo_H
#define servo_H

         /*===========   INCLUDE LIB   ===========*/

         /*======================================*/
         /*===========  INCLUDE MCAL  ===========*/


/******************************* EXIT ***********************************/

void ON_PWM_Door(void);

void OFF_PWM_Door(void);

void Servo_angle_Door(u8 );

/******************************* ENTER ***********************************/

void ON_PWM_Trunk(void);

void OFF_PWM_Trunk(void);

void Servo_angle_Trunk(u8 );

#endif //servo_H
