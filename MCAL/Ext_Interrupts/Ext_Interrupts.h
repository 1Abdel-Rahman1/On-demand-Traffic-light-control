/*
 * Ext_Interrupts.h
 *
 *  Created on: 10 Nov 2022
 *      Author: abdel
 */

#ifndef MCAL_EXT_INTERRUPTS_EXT_INTERRUPTS_H_
#define MCAL_EXT_INTERRUPTS_EXT_INTERRUPTS_H_

#include "../DIO/DIO.h"
#include "Ext_Interrupts_config.h"

void ExtI_Init(void);
void ExtI_Enable(ExtI_type interrupt);
void ExtI_Disable(ExtI_type interrupt);

void SetCallBack_INT0(void (*p2f)(void));
void SetCallBack_INT1(void (*p2f)(void));
void SetCallBack_INT2(void (*p2f)(void));

#endif /* MCAL_EXT_INTERRUPTS_EXT_INTERRUPTS_H_ */
