/*
 * LCD_Program.c
 *
 *  Created on: Aug 10, 2022
 *      Author: Abdulrahman
 */

#include "LCD_Private.h"
#include "LCD_Interface.h"
#include "LCD_Configuration.h"
#include "GPIO_interface.h"
#include "STD_Types.h"
#include "Delay_interface.h"

void H_LCD_void_LCDInit(void)
{
	//set pin mode
	MGPIO_vSetPinMode(LCD_RS_PORT , LCD_RS_PIN , OUTPUT);
	MGPIO_vSetPinMode(LCD_EN_PORT , LCD_EN_PIN , OUTPUT);
	
	//set pin output mode
	MGPIO_vSetPinOutPutType(LCD_RS_PORT , LCD_RS_PIN , PUSH_PULL);
	MGPIO_vSetPinOutPutType(LCD_EN_PORT , LCD_EN_PIN , PUSH_PULL);
	
	//set pin speed
	MGPIO_vSetPinOutSpeed(LCD_RS_PORT , LCD_RS_PIN , LOW_SPEED);
	MGPIO_vSetPinOutSpeed(LCD_EN_PORT , LCD_EN_PIN , LOW_SPEED);
	
	//set pin push_pull mode
	MGPIO_vSetPullType(LCD_RS_PORT , LCD_RS_PIN , NORMAL);
	MGPIO_vSetPullType(LCD_EN_PORT , LCD_EN_PIN , NORMAL);

#if LCD_MODE	==	_8_BIT_MODE
	
	//set pin mode
	MGPIO_vSetPinMode(LCD_D0_PORT , LCD_D0_PIN , OUTPUT);
	MGPIO_vSetPinMode(LCD_D1_PORT , LCD_D1_PIN , OUTPUT);
	MGPIO_vSetPinMode(LCD_D2_PORT , LCD_D2_PIN , OUTPUT);
	MGPIO_vSetPinMode(LCD_D3_PORT , LCD_D3_PIN , OUTPUT);
	MGPIO_vSetPinMode(LCD_D4_PORT , LCD_D4_PIN , OUTPUT);
	MGPIO_vSetPinMode(LCD_D5_PORT , LCD_D5_PIN , OUTPUT);
	MGPIO_vSetPinMode(LCD_D6_PORT , LCD_D6_PIN , OUTPUT);
	MGPIO_vSetPinMode(LCD_D7_PORT , LCD_D7_PIN , OUTPUT);
	
	//set pin output mode
	MGPIO_vSetPinOutPutType(LCD_D0_PORT , LCD_D0_PIN , PUSH_PULL);
	MGPIO_vSetPinOutPutType(LCD_D1_PORT , LCD_D1_PIN , PUSH_PULL);
	MGPIO_vSetPinOutPutType(LCD_D2_PORT , LCD_D2_PIN , PUSH_PULL);
	MGPIO_vSetPinOutPutType(LCD_D3_PORT , LCD_D3_PIN , PUSH_PULL);
	MGPIO_vSetPinOutPutType(LCD_D4_PORT , LCD_D4_PIN , PUSH_PULL);
	MGPIO_vSetPinOutPutType(LCD_D5_PORT , LCD_D5_PIN , PUSH_PULL);
	MGPIO_vSetPinOutPutType(LCD_D6_PORT , LCD_D6_PIN , PUSH_PULL);
	MGPIO_vSetPinOutPutType(LCD_D7_PORT , LCD_D7_PIN , PUSH_PULL);

	//set pin speed
	MGPIO_vSetPinOutSpeed(LCD_D0_PORT , LCD_D0_PIN , LOW_SPEED);
	MGPIO_vSetPinOutSpeed(LCD_D1_PORT , LCD_D1_PIN , LOW_SPEED);
	MGPIO_vSetPinOutSpeed(LCD_D2_PORT , LCD_D2_PIN , LOW_SPEED);
	MGPIO_vSetPinOutSpeed(LCD_D3_PORT , LCD_D3_PIN , LOW_SPEED);
	MGPIO_vSetPinOutSpeed(LCD_D4_PORT , LCD_D4_PIN , LOW_SPEED);
	MGPIO_vSetPinOutSpeed(LCD_D5_PORT , LCD_D5_PIN , LOW_SPEED);
	MGPIO_vSetPinOutSpeed(LCD_D6_PORT , LCD_D6_PIN , LOW_SPEED);
	MGPIO_vSetPinOutSpeed(LCD_D7_PORT , LCD_D7_PIN , LOW_SPEED);
	
	//set pin push_pull mode
	MGPIO_vSetPullType(LCD_D0_PORT , LCD_D0_PIN , NORMAL);
	MGPIO_vSetPullType(LCD_D1_PORT , LCD_D1_PIN , NORMAL);
	MGPIO_vSetPullType(LCD_D2_PORT , LCD_D2_PIN , NORMAL);
	MGPIO_vSetPullType(LCD_D3_PORT , LCD_D3_PIN , NORMAL);
	MGPIO_vSetPullType(LCD_D4_PORT , LCD_D4_PIN , NORMAL);
	MGPIO_vSetPullType(LCD_D5_PORT , LCD_D5_PIN , NORMAL);
	MGPIO_vSetPullType(LCD_D6_PORT , LCD_D6_PIN , NORMAL);
	MGPIO_vSetPullType(LCD_D7_PORT , LCD_D7_PIN , NORMAL);

	Delay_vMsIn16MHz(1000);
	H_LCD_void_LCDSendCMD(LCD_8_BIT_MODE_CMD);	//8-bit write mode

#elif	LCD_MODE	==	_4_BIT_MODE
	
	//set pin mode
	MGPIO_vSetPinMode(LCD_D4_PORT , LCD_D4_PIN , OUTPUT);
	MGPIO_vSetPinMode(LCD_D5_PORT , LCD_D5_PIN , OUTPUT);
	MGPIO_vSetPinMode(LCD_D6_PORT , LCD_D6_PIN , OUTPUT);
	MGPIO_vSetPinMode(LCD_D7_PORT , LCD_D7_PIN , OUTPUT);
	
	//set pin output mode
	MGPIO_vSetPinOutPutType(LCD_D4_PORT , LCD_D4_PIN , PUSH_PULL);
	MGPIO_vSetPinOutPutType(LCD_D5_PORT , LCD_D5_PIN , PUSH_PULL);
	MGPIO_vSetPinOutPutType(LCD_D6_PORT , LCD_D6_PIN , PUSH_PULL);
	MGPIO_vSetPinOutPutType(LCD_D7_PORT , LCD_D7_PIN , PUSH_PULL);
	
	//set pin speed
	MGPIO_vSetPinOutSpeed(LCD_D4_PORT , LCD_D4_PIN , LOW_SPEED);
	MGPIO_vSetPinOutSpeed(LCD_D5_PORT , LCD_D5_PIN , LOW_SPEED);
	MGPIO_vSetPinOutSpeed(LCD_D6_PORT , LCD_D6_PIN , LOW_SPEED);
	MGPIO_vSetPinOutSpeed(LCD_D7_PORT , LCD_D7_PIN , LOW_SPEED);
	
	//set pin push_pull mode
	MGPIO_vSetPullType(LCD_D4_PORT , LCD_D4_PIN , NORMAL);
	MGPIO_vSetPullType(LCD_D5_PORT , LCD_D5_PIN , NORMAL);
	MGPIO_vSetPullType(LCD_D6_PORT , LCD_D6_PIN , NORMAL);
	MGPIO_vSetPullType(LCD_D7_PORT , LCD_D7_PIN , NORMAL);

	Delay_vMsIn16MHz(1000);
	H_LCD_void_LCDSendCMD(LCD_4_BIT_MODE_CMD_1);	//4-bit write mode
	H_LCD_void_LCDSendCMD(LCD_4_BIT_MODE_CMD_2);
	H_LCD_void_LCDSendCMD(LCD_4_BIT_MODE_CMD_3);


#endif
	H_LCD_void_LCDSendCMD(LCD_CLR_CMD);
	H_LCD_void_LCDSendCMD(LCD_DISPLAY_ON_CMD);

}

void H_LCD_void_LCDSendCMD(u8 Copy_u8_CMD)
{
	MGPIO_vWriteData(LCD_RS_PORT , LCD_RS_PIN , _LOW);

#if LCD_MODE	==	_8_BIT_MODE
	MGPIO_vWriteData(LCD_D0_PORT , LCD_D0_PIN,Copy_u8_CMD & 1);
	MGPIO_vWriteData(LCD_D1_PORT , LCD_D1_PIN,(Copy_u8_CMD >> 1) & 1);
	MGPIO_vWriteData(LCD_D2_PORT , LCD_D2_PIN,(Copy_u8_CMD >> 2) & 1);
	MGPIO_vWriteData(LCD_D3_PORT , LCD_D3_PIN,(Copy_u8_CMD >> 3) & 1);
	MGPIO_vWriteData(LCD_D4_PORT , LCD_D4_PIN,(Copy_u8_CMD >> 4) & 1);
	MGPIO_vWriteData(LCD_D5_PORT , LCD_D5_PIN,(Copy_u8_CMD >> 5) & 1);
	MGPIO_vWriteData(LCD_D6_PORT , LCD_D6_PIN,(Copy_u8_CMD >> 6) & 1);
	MGPIO_vWriteData(LCD_D7_PORT , LCD_D7_PIN,(Copy_u8_CMD >> 7) & 1);

#elif	LCD_MODE	==	_4_BIT_MODE
	MGPIO_vWriteData(LCD_D4_PORT , LCD_D4_PIN,(Copy_u8_CMD >> 4) & 1);
	MGPIO_vWriteData(LCD_D5_PORT , LCD_D5_PIN,(Copy_u8_CMD >> 5) & 1);
	MGPIO_vWriteData(LCD_D6_PORT , LCD_D6_PIN,(Copy_u8_CMD >> 6) & 1);
	MGPIO_vWriteData(LCD_D7_PORT , LCD_D7_PIN,(Copy_u8_CMD >> 7) & 1);

	MGPIO_vWriteData(LCD_EN_PORT , LCD_EN_PIN , _HIGH);
	Delay_vMsIn16MHz(5);
	MGPIO_vWriteData(LCD_EN_PORT , LCD_EN_PIN , _LOW);
	Delay_vMsIn16MHz(5);

	Copy_u8_CMD <<= 4;
	MGPIO_vWriteData(LCD_D4_PORT , LCD_D4_PIN,(Copy_u8_CMD >> 4) & 1);
	MGPIO_vWriteData(LCD_D5_PORT , LCD_D5_PIN,(Copy_u8_CMD >> 5) & 1);
	MGPIO_vWriteData(LCD_D6_PORT , LCD_D6_PIN,(Copy_u8_CMD >> 6) & 1);
	MGPIO_vWriteData(LCD_D7_PORT , LCD_D7_PIN,(Copy_u8_CMD >> 7) & 1);

#endif
	MGPIO_vWriteData(LCD_EN_PORT , LCD_EN_PIN , _HIGH);
	Delay_vMsIn16MHz(5);
	MGPIO_vWriteData(LCD_EN_PORT , LCD_EN_PIN , _LOW);
}

void H_LCD_void_LCDSendChar(u8 Copy_u8_Char)
{
	MGPIO_vWriteData(LCD_RS_PORT , LCD_RS_PIN , _HIGH);

#if LCD_MODE	==	_8_BIT_MODE
	MGPIO_vWriteData(LCD_D0_PORT , LCD_D0_PIN,Copy_u8_Char & 1);
	MGPIO_vWriteData(LCD_D1_PORT , LCD_D1_PIN,(Copy_u8_Char >> 1) & 1);
	MGPIO_vWriteData(LCD_D2_PORT , LCD_D2_PIN,(Copy_u8_Char >> 2) & 1);
	MGPIO_vWriteData(LCD_D3_PORT , LCD_D3_PIN,(Copy_u8_Char >> 3) & 1);
	MGPIO_vWriteData(LCD_D4_PORT , LCD_D4_PIN,(Copy_u8_Char >> 4) & 1);
	MGPIO_vWriteData(LCD_D5_PORT , LCD_D5_PIN,(Copy_u8_Char >> 5) & 1);
	MGPIO_vWriteData(LCD_D6_PORT , LCD_D6_PIN,(Copy_u8_Char >> 6) & 1);
	MGPIO_vWriteData(LCD_D7_PORT , LCD_D7_PIN,(Copy_u8_Char >> 7) & 1);

#elif	LCD_MODE	==	_4_BIT_MODE
	MGPIO_vWriteData(LCD_D4_PORT , LCD_D4_PIN,(Copy_u8_Char >> 4) & 1);
	MGPIO_vWriteData(LCD_D5_PORT , LCD_D5_PIN,(Copy_u8_Char >> 5) & 1);
	MGPIO_vWriteData(LCD_D6_PORT , LCD_D6_PIN,(Copy_u8_Char >> 6) & 1);
	MGPIO_vWriteData(LCD_D7_PORT , LCD_D7_PIN,(Copy_u8_Char >> 7) & 1);

	MGPIO_vWriteData(LCD_EN_PORT , LCD_EN_PIN , _HIGH);
	Delay_vMsIn16MHz(5);
	MGPIO_vWriteData(LCD_EN_PORT , LCD_EN_PIN , _LOW);
	Delay_vMsIn16MHz(5);

	Copy_u8_Char <<= 4;
	MGPIO_vWriteData(LCD_D4_PORT , LCD_D4_PIN,(Copy_u8_Char >> 4) & 1);
	MGPIO_vWriteData(LCD_D5_PORT , LCD_D5_PIN,(Copy_u8_Char >> 5) & 1);
	MGPIO_vWriteData(LCD_D6_PORT , LCD_D6_PIN,(Copy_u8_Char >> 6) & 1);
	MGPIO_vWriteData(LCD_D7_PORT , LCD_D7_PIN,(Copy_u8_Char >> 7) & 1);

#endif
	MGPIO_vWriteData(LCD_EN_PORT , LCD_EN_PIN , _HIGH);
	Delay_vMsIn16MHz(5);
	MGPIO_vWriteData(LCD_EN_PORT , LCD_EN_PIN , _LOW);

}

void H_LCD_void_LCDSendString(u8* Copy_u8_Ptr)
{
	u8 Local_u8_Counter = 0;
	while(Copy_u8_Ptr[Local_u8_Counter] != '\0')
	{
		H_LCD_void_LCDSendChar(Copy_u8_Ptr[Local_u8_Counter]);
		Local_u8_Counter++;
	}
}

void H_LCD_void_LCDSendNumber(f64 *Copy_f64_Number)
{
	u32 Local_u32_Temp;
	u8 Local_u8_Temp2 = 0;
	u8 Local_u8_Arr[16];
	s8 Local_s8_IntCounter = 0;
	u8 Local_u8_FloatCounter;
	if(*Copy_f64_Number < 0)
	{
		H_LCD_void_LCDSendChar('-');
		(*Copy_f64_Number) *= -1;
	}
	Local_u32_Temp = *Copy_f64_Number;
	*Copy_f64_Number = *Copy_f64_Number - Local_u32_Temp; // -> Copy_f64_Number = 0 ?
	do
	{
		Local_u8_Arr[Local_s8_IntCounter] = Local_u32_Temp % 10;
		Local_u32_Temp = Local_u32_Temp / 10;
		Local_s8_IntCounter++;
	} while(Local_u32_Temp != 0);

	Local_u8_FloatCounter = Local_s8_IntCounter;

	if(*Copy_f64_Number != 0)
	{
	while(Local_u8_FloatCounter < 15)
	{
		*Copy_f64_Number = (*Copy_f64_Number) * 10;
		Local_u8_Temp2 = *Copy_f64_Number;
		Local_u8_Arr[Local_u8_FloatCounter] = Local_u8_Temp2;
		*Copy_f64_Number = *Copy_f64_Number - Local_u8_Temp2;
		Local_u8_FloatCounter++;
	}
	Local_u8_Temp2 = 1;
	}

	Local_u8_FloatCounter = Local_s8_IntCounter;
	/*do
		{
			Local_u8_Arr[Local_u8_FloatCounter] = Local_u32_Temp2 % 10;
			Local_u32_Temp2 = Local_u32_Temp2 / 10;
			Local_u8_FloatCounter--;
		}
	while(Local_u8_FloatCounter >= Local_s8_IntCounter);*/

	Local_s8_IntCounter--;

	while(Local_s8_IntCounter > -1)
	{
		H_LCD_void_LCDSendChar(Local_u8_Arr[Local_s8_IntCounter]+48);
		Local_s8_IntCounter--;
	}
	if(Local_u8_Temp2 == 1)
	{
	H_LCD_void_LCDSendChar('.');
	while(Local_u8_FloatCounter < 15)
		{
			H_LCD_void_LCDSendChar(Local_u8_Arr[Local_u8_FloatCounter]+48);
			Local_u8_FloatCounter++;
		}
	}
}

void H_LCD_void_LCDClr(void)
{
	H_LCD_void_LCDSendCMD(LCD_CLR_CMD);
}

void H_LCD_void_LCDGoTo(u8 Copy_u8_Row,u8 Copy_u8_Culumn)
{
	u8 Local_u8_Arr[2] = {0x80 , 0xC0};
	H_LCD_void_LCDSendCMD(Local_u8_Arr[Copy_u8_Row] + Copy_u8_Culumn);
}
