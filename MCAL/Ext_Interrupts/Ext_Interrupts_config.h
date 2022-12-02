/*
 * Ext_Interrupts_config.h
 *
 *  Created on: 10 Nov 2022
 *      Author: abdel
 */

#ifndef MCAL_EXT_INTERRUPTS_EXT_INTERRUPTS_CONFIG_H_
#define MCAL_EXT_INTERRUPTS_EXT_INTERRUPTS_CONFIG_H_

#define DISABLED	0
#define ENABLED		1

// Select External Interrupt
#define EXT_INT0_MODE	ENABLED
#define EXT_INT1_MODE	DISABLED
#define EXT_INT2_MODE	DISABLED

#define LOW_LEVEL_TRIG		0
#define ANY_CHANGE_TRIG		1
#define FALLING_EDGE_TRIG	2
#define RISING_EDGE_TRIG	3

// Select Sense Mode
#define INT0_SENSE_MODE	RISING_EDGE_TRIG
#define INT1_SENSE_MODE	RISING_EDGE_TRIG
#define INT2_SENSE_MODE	RISING_EDGE_TRIG

typedef enum
{
	EXTI_0,
	EXTI_1,
	EXTI_2
}ExtI_type;

#endif /* MCAL_EXT_INTERRUPTS_EXT_INTERRUPTS_CONFIG_H_ */
