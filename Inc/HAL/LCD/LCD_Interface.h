/*
 * LCD_Interface.h
 *
 *  Created on: Aug 10, 2022
 *      Author: Abdulrahman
 */

#ifndef HAL_LCD_LCD_INTERFACE_H_
#define HAL_LCD_LCD_INTERFACE_H_

#include "STD_TYPES.h"

void H_LCD_void_LCDInit(void);
void H_LCD_void_LCDSendCMD(u8);
void H_LCD_void_LCDSendChar(u8);
void H_LCD_void_LCDSendString(u8*);
void H_LCD_void_LCDSendNumber(f64* );
void H_LCD_void_LCDClr(void);
void H_LCD_void_LCDGoTo(u8,u8);


#endif /* HAL_LCD_LCD_INTERFACE_H_ */
