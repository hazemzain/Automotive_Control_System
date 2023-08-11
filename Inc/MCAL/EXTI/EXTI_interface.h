/*
   Author : Magdy
   Date   : 17-5-2022
   Version: V1
*/
/***
 *      ________   _________ _____            _____ _   _ _______ ______ _____  ______      _____ ______ 
 *     |  ____\ \ / /__   __|_   _|          |_   _| \ | |__   __|  ____|  __ \|  ____/\   / ____|  ____|
 *     | |__   \ V /   | |    | |    ______    | | |  \| |  | |  | |__  | |__) | |__ /  \ | |    | |__   
 *     |  __|   > <    | |    | |   |______|   | | | . ` |  | |  |  __| |  _  /|  __/ /\ \| |    |  __|  
 *     | |____ / . \   | |   _| |_            _| |_| |\  |  | |  | |____| | \ \| | / ____ \ |____| |____ 
 *     |______/_/ \_\  |_|  |_____|          |_____|_| \_|  |_|  |______|_|  \_\_|/_/    \_\_____|______|
 *                                                                                                       
 *                                                                                                       
 */
#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

#include "STD_TYPES.h"

typedef enum
{
	EXTI_LINE0 =0,
	EXTI_LINE1   ,
	EXTI_LINE2   ,
	EXTI_LINE3   ,
	EXTI_LINE4   ,
	EXTI_LINE5   ,
	EXTI_LINE6   ,
	EXTI_LINE7   ,
	EXTI_LINE8   ,
	EXTI_LINE9   ,
	EXTI_LINE10  ,
	EXTI_LINE11  ,
	EXTI_LINE12  ,
	EXTI_LINE13  ,
	EXTI_LINE14  ,
	EXTI_LINE15
}EXTI_LINE_t;
typedef enum
{
	EXTI_PORTA =0   ,
	EXTI_PORTB      ,
	EXTI_PORTC      ,
	EXTI_PORTD      ,
	EXTI_PORTE      ,
	EXTI_PORTH =7   ,
	
	
}EXTI_PORT_Num;
typedef enum
{
	EXTI_FALLING =0  ,
	EXTI_RAISING     ,
	EXTI_ON_CHANGE   
}EXTI_TRIG_t;
void MEXTI_vEnableLine(u8 Copy_u8Line);
void MEXTI_vDisableLine(u8 Copy_u8Line);
void MEXTI_vEventTrigger(EXTI_LINE_t Copy_eLineNum,EXTI_TRIG_t Copy_eEventTrig);
void MEXTI_vSwiTrigger(EXTI_LINE_t Copy_eLineNum);
u8 MEXTI_vGetPending(EXTI_LINE_t Copy_eLineNum);
void MEXTI_vPortConfig(EXTI_PORT_Num Copy_ePortNum,EXTI_LINE_t Copy_eLineNum);

void MEXTI1_vSetCallBack(void (*Ptr1)(void));

void MEXTI0_vSetCallBack(void (*Ptr0)(void));

#endif
