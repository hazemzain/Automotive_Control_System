/*========================================================================================
===========================   - Ultrasonic_CFG.h    =============================
===========================   - Created: 30/6/2022	     =============================
===========================   - Author: Wave4 G3    =============================
===========================   - Version : _1_		     =============================
===========================   - Note :
========================================================================================*/

#ifndef Ultrasonic_CFG_H_
#define Ultrasonic_CFG_H_

/*Port_Option:
	1:_PORT_A
	2:_PORT_B
	3:_PORT_C
	4:_PORT_D
	5:_PORT_E
	6:_PORT_A
	*/
/* Pin_Option:
		0  :_PIN_0 
		1  :_PIN_1 
		2  :_PIN_2 
		3  :_PIN_3 
		4  :_PIN_4 
		5  :_PIN_5 
		6  :_PIN_6 
		7  :_PIN_7 
		8  :_PIN_8 
		9  :_PIN_9 
		10 :_PIN_10
		11 :_PIN_11
		12 :_PIN_12
		13 :_PIN_13
		14 :_PIN_14
		15 :_PIN_15
*/
#define TRIGER_PORT GPIOC_PORT
#define TRIGER_PIN	GPIO_PIN_8

#define ECHO_PORT  GPIOC_PORT
#define ECHO_PIN   GPIO_PIN_6



#endif

