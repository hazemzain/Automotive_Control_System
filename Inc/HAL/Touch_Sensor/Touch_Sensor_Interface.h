#ifndef _TOUCH_SENSOR_INTERFACE_H_
#define _TOUCH_SENSOR_INTERFACE_H_



void H_Touch_Sensor_void_Init(void);
void H_Touch_Sensor_2_void_Init(void);
u8 H_Touch_Sensor_void_Read(void);
void H_Touch_Sensor_void_SetCallBack(void (*)(void));
void H_Touch_Sensor_2_void_SetCallBack(void (*)(void));

#endif
