/*
 * Timers.h
 *
 *  Created on: 10 Nov 2022
 *      Author: abdel
 */

#ifndef MCAL_TIMERS_TIMERS_H_
#define MCAL_TIMERS_TIMERS_H_

#include "../DIO/DIO.h"
#include "Timers_config.h"

void Timers_Init(void);
void TCNT0_Write(uint8 value);
void OCR0_Write(uint8 value);
void Timer0_Wait_OVF(void);
void Timer0_Wait_OCF(void);
//void SetCallBack_TOV0(void (*p2f)(void));
//void SetCallBack_OCF0(void (*p2f)(void));

#endif /* MCAL_TIMERS_TIMERS_H_ */
