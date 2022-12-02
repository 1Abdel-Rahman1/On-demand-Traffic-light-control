/*
 * DIO.h
 *
 *  Created on: 10 Nov 2022
 *      Author: abdel
 */

#ifndef MCAL_DIO_DIO_H_
#define MCAL_DIO_DIO_H_

#include <avr/io.h>
#include <avr/interrupt.h>
#include "../../Types.h"
#include "../../Bit_Math.h"
#include "DIO_Types.h"
#include "DIO_config.h"

void Dio_Init(void);
void Dio_WriteChannel(channel_type channel, state_type state);
state_type Dio_ReadChannel(channel_type channel);
void Dio_WritePort(port_type port, uint8 level);
void Dio_FlipChannel(channel_type channel);

#endif /* MCAL_DIO_DIO_H_ */
