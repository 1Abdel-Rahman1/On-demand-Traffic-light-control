/*
 * App.c
 *
 *  Created on: 10 Nov 2022
 *      Author: abdel
 */


#include "App.h"

/* Function Definitions */
void App_Start(void)
{
	/* Initialize the DIO pins we need */
	Dio_Init();
	/* Set I-Bit in SREG to enable interrupts */
	sei();
	/* Initialize External Interrupts */
	ExtI_Init();
	/* Initialize Timers */
	Timers_Init();
	/* Write Initial Timer Value */
	TCNT0_Write(0x06);

	/* pedestrian_mode function is executed when an interrupts occurs */
	SetCallBack_INT0(pedestrian_mode);

	while (1)
	{
		/* Normal Mode takes place */
		/* Car's Green LED & Pedestrian's Red LED are on for 5 sec */
		Led_Off(C_YELLOW);
		Led_Off(C_RED);
		Led_Off(P_GREEN);
		Led_Off(P_YELLOW);
		Led_On(C_GREEN);
		Led_On(P_RED);
		/* Delay of 5 seconds */
		delay_5s();
		/* Both Yellow LEDs start blinking while other LEDs are turned off */
		blink_5s();
		/* Car's Red LED & Pedestrian's Green LED are on for 5 sec */
		Led_Off(C_GREEN);
		Led_Off(C_YELLOW);
		Led_Off(P_YELLOW);
		Led_Off(P_RED);
		Led_On(C_RED);
		Led_On(P_GREEN);
		/* Delay of 5 seconds */
		delay_5s();
		/* Both Yellow LEDs start blinking while other LEDs are turned off */
		blink_5s();
	}
}

void pedestrian_mode(void)
{
	/* Check whether the push button is pressed or released */
	if (Button_Read(BUTTON) == PRESSED)
	{
		/* Pedestrian Mode takes place */
		/* Check whether the Car's Red LED is on or off */
		if (Dio_ReadChannel(C_RED) == HIGH)
		{
			/* Car's Red LED & Pedestrian's Green LED are on for 5 sec */
			Led_Off(C_GREEN);
			Led_Off(C_YELLOW);
			Led_Off(P_YELLOW);
			Led_Off(P_RED);
			Led_On(C_RED);
			Led_On(P_GREEN);
			/* Delay of 5 seconds */
			delay_5s();
			/* Both Yellow LEDs start blinking while other LEDs are turned off */
			blink_5s();
			/* Normal Mode takes place again */
			App_Start();
		}
		else
		{
			Led_Off(C_YELLOW);
			Led_Off(P_YELLOW);
			/* Both Yellow LEDs start blinking while other LEDs are turned off */
			blink_5s();
			/* Car's Red LED & Pedestrian's Green LED are on for 5 sec */
			Led_Off(C_YELLOW);
			Led_Off(P_YELLOW);
			Led_On(C_RED);
			Led_On(P_GREEN);
			/* Delay of 5 seconds */
			delay_5s();
			/* Both Yellow LEDs start blinking while other LEDs are turned off */
			blink_5s();
			/* Normal Mode takes place again */
			App_Start();
		}
	}
}

/* Function to create a 0.5 sec delay */
void delay_512ms(void)
{
	/* An OverFlow Counter */
	uint8 TimerOVFcount = 0;

	for (uint8 i = 0; i < 2; i++)
	{
		Timer0_Wait_OVF();	// 1 OVF happens = 256 ms
		TimerOVFcount++;

		if (TimerOVFcount == 2)	// 2 OVFs happened = 512 ms
		{
			TimerOVFcount = 0;	// Reset OVF counter
		}
	}
}

/* Function to create a 5 sec delay */
void delay_5s(void)
{
	/* Call delay_512ms function 10 times to create a 5 sec delay */
	for (uint8 i = 0; i < 10; i++)
	{
		delay_512ms();
	}
}

/* Function to blink the Yellow LEDs */
void blink_5s(void)
{
	/* Turn off the other LEDs */
	Led_Off(C_GREEN);
	Led_Off(C_RED);
	Led_Off(P_GREEN);
	Led_Off(P_RED);
	/* Toggle both Yellow LEDs every 0.5 sec */
	for (uint8 i = 0; i < 10; i++)
	{
		Led_Toggle(C_YELLOW);
		Led_Toggle(P_YELLOW);
		delay_512ms();
	}
}
