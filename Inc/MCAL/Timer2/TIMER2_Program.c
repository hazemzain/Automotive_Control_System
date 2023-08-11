
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "TIMER2_Private.h"
#include "TIMER2_Interface.h"


void MTIMER_void_TIMERInit(void)
{
	/*
	 * Bits 15:0 PSC[15:0]: Prescaler value
	The counter clock frequency CK_CNT is equal to fCK_PSC / (PSC[15:0] + 1).
	PSC contains the value to be loaded in the active prescaler register at each update event
	(including when the counter is cleared through UG bit of TIMx_EGR register or through
	trigger controller when configured in “reset mode”)
	 */
	TIM2->PSC=15999;
	/*TIMx auto-reload register (TIMx_ARR)*/
	TIM2->ARR=500;
	/*: Direction*/
	CLR_BIT(TIM2->CR1,4);
	/* Auto-reload preload enable*/
	SET_BIT(TIM2->CR1,7);
	/*UIE: Update interrupt enable
	0: Update interrupt disabled
	1: Update interrupt enabled
	 */
	SET_BIT(TIM2->DIER,0);
	/* CEN: Counter enable*/
	SET_BIT(TIM2->CR1,0);
}

void MTIMER_void_TIMER5Init(void)
{
	//timer5
	//prescalar
	TIM5->PSC=1;
	
	//Channel 1 output
	CLR_BIT(TIM5->CCMR1,0);
	CLR_BIT(TIM5->CCMR1,1);
	
	//enbale Update generation
	SET_BIT(TIM5->EGR,0);
	
	/*: Direction*/
	CLR_BIT(TIM5->CR1,4);
	
	/* Auto-reload preload enable*/
	SET_BIT(TIM5->CR1,7);
	
	//pwm mode 1 channel 1
	CLR_BIT(TIM5->CCMR1,4);
	SET_BIT(TIM5->CCMR1,5);
	SET_BIT(TIM5->CCMR1,6);
	
	//output compare channel 1 preload 
	SET_BIT(TIM5->CCMR1,3);
	
	//compare channel 1 output enable
	SET_BIT(TIM5->CCER,0);
}

void M_TIMER_void_TIMER5_DUTYCYCLE(u8 Copy_DutyCycle)
{
	/*TIMx auto-reload register (TIMx_ARR)*/
	TIM5->ARR = 15999;
	
	//compare reg
	TIM5->CCR1 = ((u32)Copy_DutyCycle * 16000) /100;
	
	/* CEN: Counter enable*/
	SET_BIT(TIM5->CR1,0);
}

void MTIMER_void_TIMER3Init(void)
{
	//timer5
	//prescalar
	TIM3->PSC=319;

	//Channel 1 output
	CLR_BIT(TIM3->CCMR1,8);
	CLR_BIT(TIM3->CCMR1,9);

	//enbale Update generation
	SET_BIT(TIM3->EGR,0);

	/*: Direction*/
	CLR_BIT(TIM3->CR1,4);

	/* Auto-reload preload enable*/
	SET_BIT(TIM3->CR1,7);

	//pwm mode 1 channel 1
	CLR_BIT(TIM3->CCMR1,12);
	SET_BIT(TIM3->CCMR1,13);
	SET_BIT(TIM3->CCMR1,14);

	//output compare channel 1 preload
	SET_BIT(TIM3->CCMR1,11);

	//compare channel 1 output enable
	SET_BIT(TIM3->CCER,4);
}

void M_TIMER_void_TIMER3_DUTYCYCLE(u16 Copy_DutyCycle)
{
	/*TIMx auto-reload register (TIMx_ARR)*/
	TIM3->ARR = 999;

	//compare reg
	TIM3->CCR2 = ((u32)Copy_DutyCycle * 1000) /10000;

	/* CEN: Counter enable*/
	SET_BIT(TIM3->CR1,0);
}

void MTIMER_void_TIMER4Init(void)
{
	//timer5
	//prescalar
	TIM4->PSC=319;

	//Channel 1 output
	CLR_BIT(TIM4->CCMR1,0);
	CLR_BIT(TIM4->CCMR1,1);

	//enbale Update generation
	SET_BIT(TIM4->EGR,0);

	/*: Direction*/
	CLR_BIT(TIM4->CR1,4);

	/* Auto-reload preload enable*/
	SET_BIT(TIM4->CR1,7);

	//pwm mode 1 channel 1
	CLR_BIT(TIM4->CCMR1,4);
	SET_BIT(TIM4->CCMR1,5);
	SET_BIT(TIM4->CCMR1,6);

	//output compare channel 1 preload
	SET_BIT(TIM4->CCMR1,3);

	//compare channel 1 output enable
	SET_BIT(TIM4->CCER,0);
}

void M_TIMER_void_TIMER4_DUTYCYCLE(u16 Copy_DutyCycle)
{
	/*TIMx auto-reload register (TIMx_ARR)*/
	TIM4->ARR = 999;

	//compare reg
	TIM4->CCR1 = ((u32)Copy_DutyCycle * 1000) /10000;

	/* CEN: Counter enable*/
	SET_BIT(TIM4->CR1,0);
}
