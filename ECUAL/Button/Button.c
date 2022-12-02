/*
 * Button.c
 *
 *  Created on: 10 Nov 2022
 *      Author: abdel
 */


#include "Button.h"

ButtonState_type Button_Read(channel_type channel)
{
	ButtonState_type state = Dio_ReadChannel(channel);
	return state;
}
