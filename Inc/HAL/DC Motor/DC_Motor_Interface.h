/*
 * DC_Motor_Interface.h
 *
 *  Created on: Aug 31, 2022
 *      Author: Abdulrahman
 */

#ifndef DC_MOTOR_DC_MOTOR_INTERFACE_H_
#define DC_MOTOR_DC_MOTOR_INTERFACE_H_

#define DC_MOTOR_CLOCKWISE			0
#define DC_MOTOR_ANTI_CLOCKWISE		1

#define DC_MOTOR_STOP				0
#define DC_MOTOR_HALF_SPEED			1
#define DC_MOTOR_FULL_SPEED			2

void H_DC_MOTOR_void_Init(void);
void H_DC_MOTOR_void_Direction(u8);
void H_DC_MOTOR_void_Stop(void);
void H_DC_MOTOR_void_Speed(u8);

#endif /* DC_MOTOR_DC_MOTOR_INTERFACE_H_ */
