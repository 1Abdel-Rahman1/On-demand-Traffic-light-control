/*
 * LED.c
 *
 *  Created on: 10 Nov 2022
 *      Author: abdel
 */


#include "LED.h"

void Led_On(channel_type channel)
{
	Dio_WriteChannel(channel, HIGH);
}

void Led_Off(channel_type channel)
{
	Dio_WriteChannel(channel, LOW);
}

void Led_Toggle(channel_type channel)
{
	Dio_FlipChannel(channel);
}
