/*
 * DIO_config.h
 *
 *  Created on: 10 Nov 2022
 *      Author: abdel
 */

#ifndef MCAL_DIO_DIO_CONFIG_H_
#define MCAL_DIO_DIO_CONFIG_H_

#include "DIO_Types.h"

// Specify The Number of Used DIO Pins
#define PIN_COUNT	7

typedef struct
{
	port_type port;
	pin_type pin;
	direction_type direction;
	pullup_type pullup;
}pin_config;

extern pin_config pin_array[PIN_COUNT];

#endif /* MCAL_DIO_DIO_CONFIG_H_ */
