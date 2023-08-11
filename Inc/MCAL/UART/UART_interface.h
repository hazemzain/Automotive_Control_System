/*======================================================================================
===========================   - GPIO_interface.h			 ===========================
===========================   - Created: 3/22/2022			 ===========================
===========================   - Author: Abdelrahman_Magdy    ===========================
===========================   - Version : _1_				 ===========================
===========================   - Note :
									  *-
									  *-
 ======================================================================================*/

/*=====================================================================================
		* What i sell To Customer
		*  The Archictect Give The API
						- The Name Of Function
						- What is The Input
						- What Is The Output
						- Macro

======================================================================================*/

/*===================================================================================
===============     guard of file will call on time in .c		   ==================
=====================================================================================*/

#ifndef UART_INTERFACE_H
#define UART_INTERFACE_H

/*===========  Include  ===========*/
#include "STD_TYPES.h"
#include "UART_ENUMS.h"
#include "UART_PRIVATE.h"


/*===========================     Function Prototypes     ===========================*/
/*===============   1-Function To 	 ===============*/
void MUART_vInit(void);
/*===============   1-Function To 	 ===============*/
void MUART_vEnable(u8 copy_u8Index);
/*===============   1-Function To 	 ===============*/
void MUART_vDisable(u8 copy_u8Index);
/*===============   1-Function To 	 ===============*/
void MUART_u8SendData(u8 copy_u8Index, u8* copy_u8Data);
/*===============   1-Function To 	 ===============*/
u8 MUART_u8ReadData(u8 copy_u8Index);
/*===============   1-Function To 	 ===============*/
UART_REG MUART_GetHandler(u8 copy_u8Index);
/*===============   1-Function To 	 ===============*/
void USART1_IRQHandler(void);
/*===============   1-Function To 	 ===============*/
void MUSART1_VidSetCallBack( void (*ptr) (void) );

#endif //UART_INTERFACE_H_
/*===================================================================================
===============     guard of file will call on time in .c		   ==================
=====================================================================================*/
