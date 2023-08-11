/*
 * LCD_Configuration.h
 *
 *  Created on: Aug 10, 2022
 *      Author: Abdulrahman
 */

#ifndef HAL_LCD_LCD_CONFIGURATION_H_
#define HAL_LCD_LCD_CONFIGURATION_H_

/******_LCD_MODE_OPTIONS: _4_BIT_MODE , _8_BIT_MODE ********************/
#define LCD_MODE		_4_BIT_MODE

/*
choose port:
GPIOA_PORT
GPIOB_PORT
GPIOC_PORT
GPIOD_PORT
GPIOE_PORT
GPIOH_PORT
*/

#define LCD_RS_PORT			GPIOD_PORT
#define LCD_EN_PORT         GPIOD_PORT
			   
#define LCD_D0_PORT			GPIOD_PORT
#define LCD_D1_PORT         GPIOD_PORT
#define LCD_D2_PORT         GPIOD_PORT
#define LCD_D3_PORT         GPIOD_PORT
#define LCD_D4_PORT         GPIOD_PORT
#define LCD_D5_PORT         GPIOD_PORT
#define LCD_D6_PORT         GPIOD_PORT
#define LCD_D7_PORT         GPIOD_PORT

#define LCD_RS_PIN		GPIO_PIN_2
#define LCD_EN_PIN		GPIO_PIN_0

#if(LCD_MODE == _8_BIT_MODE)
#define LCD_D0_PIN		GPIO_PIN_0
#define LCD_D1_PIN		GPIO_PIN_1
#define LCD_D2_PIN		GPIO_PIN_2
#define LCD_D3_PIN		GPIO_PIN_3
#define LCD_D4_PIN		GPIO_PIN_4
#define LCD_D5_PIN		GPIO_PIN_5
#define LCD_D6_PIN		GPIO_PIN_6
#define LCD_D7_PIN		GPIO_PIN_7

#elif(LCD_MODE == _4_BIT_MODE)
#define LCD_D4_PIN		GPIO_PIN_4
#define LCD_D5_PIN		GPIO_PIN_5
#define LCD_D6_PIN		GPIO_PIN_6
#define LCD_D7_PIN		GPIO_PIN_7

#endif

#endif /* HAL_LCD_LCD_CONFIGURATION_H_ */
