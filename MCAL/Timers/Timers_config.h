/*
 * Timers_config.h
 *
 *  Created on: 10 Nov 2022
 *      Author: abdel
 */

#ifndef MCAL_TIMERS_TIMERS_CONFIG_H_
#define MCAL_TIMERS_TIMERS_CONFIG_H_

// Select Timer0 Mode
#define NORMAL_MODE		0
#define PC_PWM_MODE		1
#define CTC_MODE		2
#define FAST_PWM_MODE	3

#define TIMER0_MODE	NORMAL_MODE

// Select Compare Output Mode
#define NON_INVERTING	0
#define INVERTING		1

#define COMPARE_OUTPUT_MODE	NON_INVERTING

// Clock Select
#define NO_CLOCK_SOURCE			0
#define NO_PRESCALING			1
#define PRESCALER_8				2
#define PRESCALER_64			3
#define PRESCALER_256			4
#define PRESCALER_1024			5
#define EXT_CLOCK_FALLING_EDGE	6
#define EXT_CLOCK_RISING_EDGE	7

#define CLOCK_SELECT PRESCALER_1024

#endif /* MCAL_TIMERS_TIMERS_CONFIG_H_ */
