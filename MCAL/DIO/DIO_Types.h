/*
 * DIO_Types.h
 *
 *  Created on: 10 Nov 2022
 *      Author: abdel
 */

#ifndef MCAL_DIO_DIO_TYPES_H_
#define MCAL_DIO_DIO_TYPES_H_

typedef enum
{
	C_GREEN, C_YELLOW, C_RED, PORTA_3, PORTA_4, PORTA_5, PORTA_6, PORTA_7,
	P_GREEN, P_YELLOW, P_RED, PORTB_3, PORTB_4, PORTB_5, PORTB_6, PORTB_7,
	PORTC_0, PORTC_1, PORTC_2, PORTC_3, PORTC_4, PORTC_5, PORTC_6, PORTC_7,
	PORTD_0, PORTD_1, BUTTON, PORTD_3, PORTD_4, PORTD_5, PORTD_6, PORTD_7
}channel_type;

typedef enum
{
	PORT_A,
	PORT_B,
	PORT_C,
	PORT_D
}port_type;

typedef enum
{
	PIN_0, PIN_1, PIN_2, PIN_3, PIN_4, PIN_5, PIN_6, PIN_7
}pin_type;

typedef enum
{
	INPUT, OUTPUT
}direction_type;

typedef enum
{
	LOW, HIGH
}state_type;

typedef enum
{
	PULLUP_OFF, PULLUP_ON
}pullup_type;

#endif /* MCAL_DIO_DIO_TYPES_H_ */
