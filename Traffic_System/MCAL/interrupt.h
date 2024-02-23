/*
 * interrupt.h
 *
 *  Created on: Feb 22, 2024
 *      Author: HP
 */

#ifndef MCAL_GIE_INTERRUPT_H_
#define MCAL_GIE_INTERRUPT_H_

#define ISR(VECT_NUM)		void VECT_NUM (void) __attribute__ ((signal));\
							void VECT_NUM (void)

#define VECT_INT0			__vector_1
#define VECT_INT1			__vector_2
#define VECT_INT2			__vector_3
#define VECT_TIMER2_CTC		__vector_4
#define VECT_TIMER0_OVF		__vector_11

#endif /* MCAL_GIE_INTERRUPT_H_ */
