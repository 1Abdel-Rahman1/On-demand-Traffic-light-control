/*
 * App.h
 *
 *  Created on: 10 Nov 2022
 *      Author: abdel
 */

#ifndef APPLICATION_APP_H_
#define APPLICATION_APP_H_

#include "../MCAL/DIO/DIO.h"
#include "../MCAL/Ext_Interrupts/Ext_Interrupts.h"
#include "../MCAL/Timers/Timers.h"
#include "../ECUAL/LED/LED.h"
#include "../ECUAL/Button/Button.h"

/* Function Declarations */
void App_Start(void);
//void normal_mode(void);
void pedestrian_mode(void);
void delay_512ms(void);
void delay_5s(void);
void blink_5s(void);

#endif /* APPLICATION_APP_H_ */
