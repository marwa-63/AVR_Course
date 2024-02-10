/*
 * EXINT_priv.h
 *
 *  Created on: Feb 10, 2024
 *      Author: HP
 */

#ifndef EXINT_PRIV_H_
#define EXINT_PRIV_H_

#define RISING_EDGE			3
#define FALLING_EDGE		2
#define ANY_LOGIC			1
#define LOW_LEVEL			0

#define SREG				*((u8*)0x5F)
#define MCUCR				*((u8*)0x55)
#define MCUCSR				*((u8*)0x54)
#define GICR				*((u8*)0x5B)
#define GIFR				*((u8*)0x5A)

#define ISC2 6

#define ACTIVE 1
#define DEACTIVE 0



#endif /* EXINT_PRIV_H_ */
