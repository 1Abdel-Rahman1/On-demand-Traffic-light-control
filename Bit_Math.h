/*
 * Bit_Math.h
 *
 *  Created on: 10 Nov 2022
 *      Author: abdel
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(REG, PIN)	(REG |= (1<<PIN))
#define CLR_BIT(REG, PIN)	(REG &= ~(1<<PIN))
#define TOG_BIT(REG, PIN)	(REG ^= (1<<PIN))
#define GET_BIT(REG, PIN)	((REG>>PIN) & 0x01)
#define ROT_L(REG, N)		(REG = (REG<<N) | (REG>>(8-N)))
#define ROT_R(REG, N)		(REG = (REG>>N) | (REG<<(8-N)))

#endif /* BIT_MATH_H_ */
