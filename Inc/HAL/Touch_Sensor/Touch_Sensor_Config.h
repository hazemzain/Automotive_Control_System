#ifndef _TOUCH_SENSOR_CONFIG_H_
#define _TOUCH_SENSOR_CONFIG_H_

/*
choose touch mode:
1-EXTI
2-POLLING
*/

//choose output port
#define OUTPUT_PORT			EXTI_PORTB
#define OUTPUT_2_PORT		EXTI_PORTC

#define TOUCH_READ_MODE		EXTI

//choose EXTI
#define OUTPUT_LINE			EXTI_LINE0
#define OUTPUT_2_LINE		EXTI_LINE1

//choose pin (POLLING)
#define OUTPUT_PIN 		GPIO_PIN_4

#endif
