/*
 * EXINT.h
 *
 *  Created on: Feb 10, 2024
 *      Author: HP
 */

#ifndef EXINT_H_
#define EXINT_H_

#define ISR(VECT_NUM)		void VECT_NUM (void) __attribute__ ((signal));\
							void VECT_NUM (void)

#define VECT_INT0			__vector_1
#define VECT_INT1			__vector_2
#define VECT_INT2			__vector_3
#define VECT_TIMER2_CTC		__vector_4

#endif /* EXINT_H_ */
