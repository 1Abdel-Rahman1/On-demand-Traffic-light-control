/*
 * Timers.c
 *
 *  Created on: 10 Nov 2022
 *      Author: abdel
 */


#include "Timers.h"

void (*p2f_TOV0)(void);
void (*p2f_OCF0)(void);

void Timers_Init(void)
{
	// Timer0 Mode
	#if TIMER0_MODE == NORMAL_MODE
		CLR_BIT(TCCR0, WGM00);
		CLR_BIT(TCCR0, WGM01);
	#elif TIMER0_MODE == PC_PWM_MODE
		SET_BIT(TCCR0, WGM00);
		CLR_BIT(TCCR0, WGM01);
	#elif TIMER0_MODE == CTC_MODE
		CLR_BIT(TCCR0, WGM00);
		SET_BIT(TCCR0, WGM01);
	#elif TIMER0_MODE == FAST_PWM_MODE
		SET_BIT(TCCR0, WGM00);
		SET_BIT(TCCR0, WGM01);
	#endif

	// Compare Output Mode
	#if COMPARE_OUTPUT_MODE == NON_INVERTING
		CLR_BIT(TCCR0, COM00);
		SET_BIT(TCCR0, COM01);
	#elif COMPARE_OUTPUT_MODE == INVERTING
		SET_BIT(TCCR0, COM00);
		SET_BIT(TCCR0, COM01);
	#endif

	// Clock Select
	#if CLOCK_SELECT == NO_CLOCK_SOURCE
		CLR_BIT(TCCR0, CS00);
		CLR_BIT(TCCR0, CS01);
		CLR_BIT(TCCR0, CS02);
	#elif CLOCK_SELECT == NO_PRESCALING
		SET_BIT(TCCR0, CS00);
		CLR_BIT(TCCR0, CS01);
		CLR_BIT(TCCR0, CS02);
	#elif CLOCK_SELECT == PRESCALER_8
		CLR_BIT(TCCR0, CS00);
		SET_BIT(TCCR0, CS01);
		CLR_BIT(TCCR0, CS02);
	#elif CLOCK_SELECT == PRESCALER_64
		SET_BIT(TCCR0, CS00);
		SET_BIT(TCCR0, CS01);
		CLR_BIT(TCCR0, CS02);
	#elif CLOCK_SELECT == PRESCALER_256
		CLR_BIT(TCCR0, CS00);
		CLR_BIT(TCCR0, CS01);
		SET_BIT(TCCR0, CS02);
	#elif CLOCK_SELECT == PRESCALER_1024
		SET_BIT(TCCR0, CS00);
		CLR_BIT(TCCR0, CS01);
		SET_BIT(TCCR0, CS02);
	#elif CLOCK_SELECT == EXT_CLOCK_FALLING_EDGE
		CLR_BIT(TCCR0, CS00);
		SET_BIT(TCCR0, CS01);
		SET_BIT(TCCR0, CS02);
	#elif CLOCK_SELECT == EXT_CLOCK_RISING_EDGE
		SET_BIT(TCCR0, CS00);
		SET_BIT(TCCR0, CS01);
		SET_BIT(TCCR0, CS02);
	#endif

	// Overflow Interrupt Enable
//	SET_BIT(TIMSK, TOIE0);
	// Output Compare Match Interrupt Enable
//	SET_BIT(TIMSK, OCIE0);
}


// Set TCNT0 Value
void TCNT0_Write(uint8 value)
{
	TCNT0 = value;
}

//Set OCR0 Value
void OCR0_Write(uint8 value)
{
	OCR0 = value;
}


// Wait Functions
void Timer0_Wait_OVF(void)
{
	while (GET_BIT(TIFR, TOV0) == 0);
	SET_BIT(TIFR, TOV0);
}

void Timer0_Wait_OCF(void)
{
	while (GET_BIT(TIFR, OCF0) == 0);
	SET_BIT(TIFR, OCF0);
}


// Call-Back Functions
//void SetCallBack_TOV0(void (*p2f)(void))
//{
//	p2f_TOV0 = p2f;
//}
//
//void SetCallBack_OCF0(void (*p2f)(void))
//{
//	p2f_OCF0 = p2f;
//}


// Interrupt Service Routines
//ISR(TIMER0_OVF_vect)
//{
//	if (p2f_TOV0 != 0)
//	{
//		p2f_TOV0();
//	}
//}
//
//ISR(TIMER0_COMP_vect)
//{
//	if (p2f_OCF0 != 0)
//	{
//		p2f_OCF0();
//	}
//}
