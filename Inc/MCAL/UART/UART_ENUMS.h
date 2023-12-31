/*======================================================================================
========================    - UART_enums.h				     ===========================
========================    - Created: 3/22/2022			 ===========================
========================    - Author: Abdelrahman_Magdy      ===========================
========================    - Version : _1_				     ===========================
========================    - Note :
									*-
									*-
=======================================================================================*/


/*====================================================================================
	- The Optiones Which Developer Choose From Which What Is Appropriate To App
=====================================================================================*/

/*=======================================================================================
=====================     guard of file will call on time in .c  	=====================
=========================================================================================*/

#ifndef _UART_ENUM_H
#define _UART_ENUM_H

/*********************************/
#define U_ENABLE              1U         /*!< -  */
#define U_DISABLE             0U         /*!< -  */
/*********************************/
#define U_EVEN_PARITY         0U         /*!< -  */
#define U_ODD_PARITY          1U         /*!< -  */
/*********************************/
#define U_DATA_8              0U         /*!< -  */
#define U_DATA_9              1U         /*!< -  */
/*********************************/
#define U_OVER_SAMPLING_16    0U         /*!< -  */
#define U_OVER_SAMPLING_8     1U         /*!< -  */
/*********************************/
#define STOP_1         		  1U         /*!< -  */
#define STOP_05        		  2U         /*!< -  */
#define STOP_2         		  3U         /*!< -  */
#define STOP_1_05      		  4U         /*!< -  */
/*********************************/
// 16 m hz , 16
typedef enum{
    B_1200   = 0x44505400,           	/*!< -  */
    B_2400   = 0x43d05800,           	/*!< -  */
    B_9600   = 0x0683,               	/*!< -  */
    B_19200  = 0x42504000,           	/*!< -  */
    B_38400  = 0x41d08000,           	/*!< -  */
    B_57600  = 0x418b0000,           	/*!< -  */
    B_115200 = 0x410b0000            	/*!< -  */
}u_BaudRate_t;
/*********************************/

typedef enum
{
	UART_1 = 1,
	UART_2 = 2,
	UART_6 = 6
}UART_NUM_t;
#endif // UART_ENUM_H
/*=======================================================================================
===============================     End of guard          ===============================
=========================================================================================*/

