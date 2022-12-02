/*
 * LED.h
 *
 *  Created on: 10 Nov 2022
 *      Author: abdel
 */

#ifndef ECUAL_LED_LED_H_
#define ECUAL_LED_LED_H_

#include "../../MCAL/DIO/DIO.h"

void Led_On(channel_type channel);
void Led_Off(channel_type channel);
void Led_Toggle(channel_type channel);

#endif /* ECUAL_LED_LED_H_ */
