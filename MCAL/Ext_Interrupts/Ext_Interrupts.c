/*
 * Ext_Interrupts.c
 *
 *  Created on: 10 Nov 2022
 *      Author: abdel
 */


#include "Ext_Interrupts.h"

void (*p2f_INT0)(void);
void (*p2f_INT1)(void);
void (*p2f_INT2)(void);

void ExtI_Init(void)
{
	// INT0 Initialization
	#if EXT_INT0_MODE == ENABLED
		ExtI_Enable(EXTI_0);

		#if INT0_SENSE_MODE == LOW_LEVEL_TRIG
			CLR_BIT(MCUCR, ISC00);
			CLR_BIT(MCUCR, ISC01);
		#elif INT0_SENSE_MODE == ANY_CHANGE_TRIG
			SET_BIT(MCUCR, ISC00);
			CLR_BIT(MCUCR, ISC01);
		#elif INT0_SENSE_MODE == FALLING_EDGE_TRIG
			CLR_BIT(MCUCR, ISC00);
			SET_BIT(MCUCR, ISC01);
		#elif INT0_SENSE_MODE == RISING_EDGE_TRIG
			SET_BIT(MCUCR, ISC00);
			SET_BIT(MCUCR, ISC01);
		#endif
	#endif

	// INT1 Initialization
	#if EXT_INT1_MODE == ENABLED
		ExtI_Enable(EXTI_1);

		#if INT1_SENSE_MODE == LOW_LEVEL_TRIG
			CLR_BIT(MCUCR, ISC10);
			CLR_BIT(MCUCR, ISC11);
		#elif INT1_SENSE_MODE == ANY_CHANGE_TRIG
			SET_BIT(MCUCR, ISC10);
			CLR_BIT(MCUCR, ISC11);
		#elif INT1_SENSE_MODE == FALLING_EDGE_TRIG
			CLR_BIT(MCUCR, ISC10);
			SET_BIT(MCUCR, ISC11);
		#elif INT1_SENSE_MODE == RISING_EDGE_TRIG
			SET_BIT(MCUCR, ISC10);
			SET_BIT(MCUCR, ISC11);
		#endif
	#endif

	// INT2 Initialization
	#if EXT_INT2_MODE == ENABLED
		ExtI_Enable(EXTI_2);

		#if INT2_SENSE_MODE == FALLING_EDGE_TRIG
			CLR_BIT(MCUCSR, ISC2);
		#elif INT2_SENSE_MODE == RISING_EDGE_TRIG
			SET_BIT(MCUCSR, ISC2);
		#endif
	#endif
}

void ExtI_Enable(ExtI_type interrupt)
{
	switch (interrupt)
	{
		case EXTI_0:
			SET_BIT(GICR, INT0);
			break;
		case EXTI_1:
			SET_BIT(GICR, INT1);
			break;
		default:
			SET_BIT(GICR, INT2);
	}
}

void ExtI_Disable(ExtI_type interrupt)
{
	switch (interrupt)
	{
		case EXTI_0:
			CLR_BIT(GICR, INT0);
			break;
		case EXTI_1:
			CLR_BIT(GICR, INT1);
			break;
		default:
			CLR_BIT(GICR, INT2);
	}
}

// Call-Back Functions
void SetCallBack_INT0(void (*p2f)(void))
{
	p2f_INT0 = p2f;
}

void SetCallBack_INT1(void (*p2f)(void))
{
	p2f_INT1 = p2f;
}

void SetCallBack_INT2(void (*p2f)(void))
{
	p2f_INT2 = p2f;
}

// Interrupt Service Routines
ISR(INT0_vect)
{
	if (p2f_INT0 != 0)
	{
		p2f_INT0();
	}
}

ISR(INT1_vect)
{
	if (p2f_INT1 != 0)
	{
		p2f_INT1();
	}
}

ISR(INT2_vect)
{
	if (p2f_INT2 != 0)
	{
		p2f_INT2();
	}
}
