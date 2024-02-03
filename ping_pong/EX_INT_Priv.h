/*
 * Priv.h
 *
 *  Created on: Feb 2, 2024
 *      Author: HP
 */


#ifndef PRIV_H_
#define PRIV_H_

#include "stdTypes.h"

#define RISING_EDGE			1
#define FALLING_EDGE		0
#define ANY_LOGIC			3
#define LOW_LEVEL			2

#define SREG				*((u8*)0x5F)
#define MCUCR				*((u8*)0x55)
#define MCUCSR				*((u8*)0x54)
#define GICR				*((u8*)0x5B)
#define GIFR				*((u8*)0x5A)

#define ACTIVE 1
#define DEACTIVE 0

#endif /* PRIV_H_ */
