/*
 * ADC_config.h
 *
 *  Created on: Feb 8, 2024
 *      Author: HP
 */

#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_

/*** voltage reference options:- ***/
/* VREF_INTERNAL_VOLTAGE
 * VREF_AREF
 * VREF_AVCC
 */
#define ADC_REFERENCE_VOLTAGE VREF_AVCC

/*** Adjustments options:- ***/
/* RIGHT_ADUSTMENT
 * LEFT_ADUSTMENT
 */
#define ADC_ADJUSTMENT  RIGHT_ADUSTMENT


/*** ADC Prescalar***/

#define ADC_PRESCALAR_SELECTION PRESCALAR_DIVISION_FACTOR_128

#endif /* ADC_CONFIG_H_ */
