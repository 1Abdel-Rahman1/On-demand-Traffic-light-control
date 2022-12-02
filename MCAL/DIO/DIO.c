/*
 * DIO.c
 *
 *  Created on: 10 Nov 2022
 *      Author: abdel
 */


#include "DIO.h"

void Dio_Init(void)
{
	for (uint8 i = 0; i < PIN_COUNT; i++)
	{
		if (pin_array[i].port == PORT_A)
		{
			(pin_array[i].direction == OUTPUT) ? SET_BIT(DDRA, pin_array[i].pin) : CLR_BIT(DDRA, pin_array[i].pin);
			if (pin_array[i].pullup == PULLUP_ON)
			{
				SET_BIT(PORTA, pin_array[i].pin);
			}
		}
		else if (pin_array[i].port == PORT_B)
		{
			(pin_array[i].direction == OUTPUT) ? SET_BIT(DDRB, pin_array[i].pin) : CLR_BIT(DDRB, pin_array[i].pin);
			if (pin_array[i].pullup == PULLUP_ON)
			{
				SET_BIT(PORTB, pin_array[i].pin);
			}
		}
		else if (pin_array[i].port == PORT_C)
		{
			(pin_array[i].direction == OUTPUT) ? SET_BIT(DDRC, pin_array[i].pin) : CLR_BIT(DDRC, pin_array[i].pin);
			if (pin_array[i].pullup == PULLUP_ON)
			{
				SET_BIT(PORTC, pin_array[i].pin);
			}
		}
		else
		{
			(pin_array[i].direction == OUTPUT) ? SET_BIT(DDRD, pin_array[i].pin) : CLR_BIT(DDRD, pin_array[i].pin);
			if (pin_array[i].pullup == PULLUP_ON)
			{
				SET_BIT(PORTD, pin_array[i].pin);
			}
		}
	}
}

void Dio_WriteChannel(channel_type channel, state_type state)
{
	port_type port = channel / 8;
	pin_type pin = channel % 8;

	if (port == PORT_A)
	{
		(state == HIGH) ? SET_BIT(PORTA, pin) : CLR_BIT(PORTA, pin);
	}
	else if (port == PORT_B)
	{
		(state == HIGH) ? SET_BIT(PORTB, pin) : CLR_BIT(PORTB, pin);
	}
	else if (port == PORT_C)
	{
		(state == HIGH) ? SET_BIT(PORTC, pin) : CLR_BIT(PORTC, pin);
	}
	else
	{
		(state == HIGH) ? SET_BIT(PORTD, pin) : CLR_BIT(PORTD, pin);
	}
}

state_type Dio_ReadChannel(channel_type channel)
{
	port_type port = channel / 8;
	pin_type pin = channel % 8;
	state_type state = 0;

	if (port == PORT_A)
	{
		state = GET_BIT(PINA, pin);
	}
	else if (port == PORT_B)
	{
		state = GET_BIT(PINB, pin);
	}
	else if (port == PORT_C)
	{
		state = GET_BIT(PINC, pin);
	}
	else
	{
		state = GET_BIT(PIND, pin);
	}
	return state;
}

void Dio_WritePort(port_type port, uint8 level)
{
	if (port == PORT_A)
	{
		PORTA = level;
	}
	else if (port == PORT_B)
	{
		PORTB = level;
	}
	else if (port == PORT_C)
	{
		PORTC = level;
	}
	else
	{
		PORTD = level;
	}
}

void Dio_FlipChannel(channel_type channel)
{
	port_type port = channel / 8;
	pin_type pin = channel % 8;

	if (port == PORT_A)
	{
		TOG_BIT(PORTA, pin);
	}
	else if (port == PORT_B)
	{
		TOG_BIT(PORTB, pin);
	}
	else if (port == PORT_C)
	{
		TOG_BIT(PORTC, pin);
	}
	else
	{
		TOG_BIT(PORTD, pin);
	}
}
