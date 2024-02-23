/*
 * TIMER_priv.h
 *
 *  Created on: Feb 23, 2024
 *      Author: HP
 */

#ifndef MCAL_TIMER_TIMER_PRIV_H_
#define MCAL_TIMER_TIMER_PRIV_H_

#define TCCR0	 *((volatile u8*)0x53)
#define TCNT0	 *((volatile u8*)0x52)
#define TIFR	 *((volatile u8*)0x58)
#define TIMSK	 *((volatile u8*)0x59)

#define OCR0	 *((volatile u8*)0x5C)



#define OVF  4
#define CTC  7
#define PWM  9

#define DISCONNECTED 0
#define TOG_PIN 10
#define NON_INVERTED 8



#endif /* MCAL_TIMER_TIMER_PRIV_H_ */
