#include "STD_TYPES.h"
#include "Touch_Sensor_Private.h"
#include "Touch_Sensor_Interface.h"
#include "Touch_Sensor_Config.h"
#include "EXTI_interface.h"
#include "GPIO_interface.h"

void H_Touch_Sensor_void_Init(void)
{
	#if TOUCH_READ_MODE	==	EXTI
	MEXTI_vEnableLine(OUTPUT_LINE);
	MEXTI_vEventTrigger(OUTPUT_LINE , EXTI_RAISING);
	MEXTI_vPortConfig(OUTPUT_PORT , OUTPUT_LINE);

	#elif TOUCH_READ_MODE	==	POLLING
	MGPIO_vSetPinMode(OUTPUT_PORT , OUTPUT_PIN , INPUT);
	MGPIO_vSetPinOutPutType(OUTPUT_PORT , OUTPUT_PIN , PUSH_PULL);
	MGPIO_vSetPullType(OUTPUT_PORT , OUTPUT_PIN , NORMAL);
	MGPIO_vSetPinOutSpeed(OUTPUT_PORT , OUTPUT_PIN , MEDIUM_SPEED);
	
	#endif
}

void H_Touch_Sensor_2_void_Init(void)
{
	MEXTI_vEnableLine(OUTPUT_2_LINE);
	MEXTI_vEventTrigger(OUTPUT_2_LINE , EXTI_RAISING);
	MEXTI_vPortConfig(OUTPUT_2_PORT , OUTPUT_2_LINE);
}

u8 H_Touch_Sensor_void_Read(void)
{
	u8 Local_u8_TouchRead=0;
	Local_u8_TouchRead = MGPIO_u8ReadData(OUTPUT_PORT , OUTPUT_PIN);
	return Local_u8_TouchRead;
}

void H_Touch_Sensor_void_SetCallBack(void (*ptr)(void))
{
	MEXTI0_vSetCallBack(ptr);
}

void H_Touch_Sensor_2_void_SetCallBack(void (*ptr)(void))
{
	MEXTI1_vSetCallBack(ptr);
}
