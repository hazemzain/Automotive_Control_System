#ifndef _ADC_CFG_H_
#define _ADC_CFG_H_

/********************************/

/*
  * Option :
  * 		[1] ADC_ENABLE
  * 		[2] ADC_DISABLE
 */
#define ADC_ENABLE_MODE ADC_ENABLE


/********************************/

/********************************/
 /*
  * Option :
  * 		[1] _12_BIT_RESOLUTION_ADC
  * 		[2] _10_BIT_RESOLUTION_ADC
  * 		[3] _8_BIT_RESOLUTION_ADC
  * 		[4] _6_BIT_RESOLUTION_ADC
  */
#define ADC_RESOLUTION  _12_BIT_RESOLUTION_ADC

 /******************************************/
 
/********************************/
/*
  * Option :
  * 		[1] ADC_LEFT
  * 		[2] ADC_RIGHT
 */
#define ADC_DATA_ALIGMENT   ADC_RIGHT
/*****************************/


/********************************/

/*
  * Option :
  * 		[1]_ADC_PRESCALER_2
  * 		[2]_ADC_PRESCALER_4
  *         [3]_ADC_PRESCALER_6
  *         [4]_ADC_PRESCALER_8
 */
#define ADC_PRESCALER   _ADC_PRESCALER_2

/********************************/


/********************************/

#endif
