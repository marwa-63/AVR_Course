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



/***ADC Channel:-***/
/*
 *  ---->single channel:
 *  ADC_PIN0
 *  ADC_PIN1
 *  ADC_PIN2
 *  ADC_PIN3 .....
 *
 *  ---->Differential channel:
 * /// positiveEdgePin_NegatibeEdgePin_Gain
 *    ADC0_ADC0_10X
 *    ADC1_ADC0_10X
 *    ADC0_ADC0_200X
 *    ADC1_ADC0_200X
 *    ADC2_ADC2_10X
 *    ADC3_ADC2_10X
 *    ADC2_ADC2_200X
 *    ADC3_ADC2_200X
 *    ADC0_ADC1_1X
 *    ADC1_ADC1_1X
 *    ADC2_ADC1_1X
 *    ADC3_ADC1_1X
 *    ADC4_ADC1_1X
 *    ADC5_ADC1_1X
 *    ADC6_ADC1_1X
 *    ADC7_ADC1_1X
 *    ADC0_ADC2_1X
 *    ADC1_ADC2_1X
 *    ADC2_ADC2_1X
 *    ADC3_ADC2_1X
 *    ADC4_ADC2_1X
 *    ADC5_ADC2_1X
 *
 */
#define ADC_CHANNEL ADC_PIN5

/*** ADC Prescalar***/

#define ADC_PRESCALAR_SELECTION PRESCALAR_DIVISION_FACTOR_8

#endif /* ADC_CONFIG_H_ */
