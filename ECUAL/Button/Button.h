/*
 * Button.h
 *
 *  Created on: 10 Nov 2022
 *      Author: abdel
 */

#ifndef ECUAL_BUTTON_BUTTON_H_
#define ECUAL_BUTTON_BUTTON_H_

#include "../../MCAL/DIO/DIO.h"

typedef enum
{
	RELEASED, PRESSED
}ButtonState_type;

ButtonState_type Button_Read(channel_type channel);

#endif /* ECUAL_BUTTON_BUTTON_H_ */
