/*
 * ADC_prog.c
 *
 *  Created on: Feb 8, 2024
 *      Author: HP
 */

#include "stdTypes.h"
#include "errorStates.h"

#include "ADC_config.h"
#include "ADC_priv.h"

#include "ADC_int.h"

ES_t ADC_Init()
{
	ES_t Local_enuErrorState = ES_NOK;
	// VOLTAGE REFERENCE
   #if ADC_REFERENCE_VOLTAGE == VREF_AVCC
	ADMUX |= (1<<REFS0);
	ADMUX &= ~(1<<REFS1);
  #elif ADC_REFERENCE_VOLTAGE == VREF_INTERNAL_VOLTAGE
	ADMUX |= (1<<REFS0);
	ADMUX |= (1<<REFS1);
  #elif ADC_REFERENCE_VOLTAGE == VREF_AREF
	ADMUX &= ~(1<<REFS0);
	ADMUX &= ~(1<<REFS1);
  #endif
	//ADC Adjustment
  #if ADC_ADJUSTMENT == RIGHT_ADUSTMENT
	ADMUX &= ~(1<<ADLAR);
  #elif ADC_ADJUSTMENT == LEFT_ADUSTMENT
	ADMUX |= (1<<ADLAR);
  #endif
	// ADC Channel
	ADMUX &= ~(15<<0); //clear bit 0,1,2,3
  #if ADC_CHANNEL ==  ADC_PIN0
	  ADMUX |= 0;
  #elif ADC_CHANNEL ==  ADC_PIN1
	  ADMUX |= 1;
  #elif ADC_CHANNEL ==  ADC_PIN2
	  ADMUX |= 2;
  #elif ADC_CHANNEL ==  ADC_PIN3
	  ADMUX |= 3;
  #elif ADC_CHANNEL ==  ADC_PIN4
	  ADMUX |= 4;
  #elif ADC_CHANNEL ==  ADC_PIN5
	  ADMUX |= 5;
  #elif ADC_CHANNEL ==  ADC_PIN6
	  ADMUX |= 6;
  #elif ADC_CHANNEL ==  ADC_PIN7
	  ADMUX |= 7;

  #elif ADC_CHANNEL ==   ADC0_ADC0_10X
	  ADMUX |= 0b01000;
  #elif ADC_CHANNEL ==   ADC1_ADC0_10X
	  ADMUX |= 0b01001;
  #elif ADC_CHANNEL ==   ADC0_ADC0_200X
	  ADMUX |= 0b01010;
  #elif ADC_CHANNEL ==  ADC1_ADC0_200X
	  ADMUX |= 0b01011;
  #elif ADC_CHANNEL == ADC2_ADC2_10X
	  ADMUX |= 0b01100;
  #elif ADC_CHANNEL ==  ADC3_ADC2_10X
	  ADMUX |= 0b01101;
  #elif ADC_CHANNEL ==  ADC2_ADC2_200X
 	  ADMUX |= 0b01110;
  #elif ADC_CHANNEL ==  ADC3_ADC2_200X
	  ADMUX |= 0b01111;
  #elif ADC_CHANNEL ==  ADC0_ADC011X
	  ADMUX |= 0b10000;
  #elif ADC_CHANNEL ==   ADC1_ADC1_1X
	  ADMUX |= 0b10001;
  #elif ADC_CHANNEL ==   ADC2_ADC1_1X
  	  ADMUX |= 0b10010;
  #elif ADC_CHANNEL ==  ADC3_ADC1_1X
  	  ADMUX |= 0b10011;
  #elif ADC_CHANNEL ==  ADC4_ADC1_1X
  	  ADMUX |= 0b10100;
  #elif ADC_CHANNEL ==  ADC5_ADC1_1X
  	  ADMUX |= 0b10101;
  #elif ADC_CHANNEL ==  ADC6_ADC1_1X
  	  ADMUX |= 0b10110;
  #elif ADC_CHANNEL ==  ADC7_ADC1_1X
  	  ADMUX |= 0b10111;
  #elif ADC_CHANNEL ==  ADC0_ADC2_1X
  	  ADMUX |= 0b11000;
  #elif ADC_CHANNEL ==  ADC1_ADC2_1X
  	  ADMUX |= 0b11001;
  #elif ADC_CHANNEL ==  ADC2_ADC2_1X
  	  ADMUX |= 0b11010;
  #elif ADC_CHANNEL ==  ADC3_ADC2_1X
  	  ADMUX |= 0b11011;
  #elif ADC_CHANNEL ==  ADC4_ADC2_1X
	  ADMUX |= 0b11100;
  #elif ADC_CHANNEL ==  ADC5_ADC2_1X
	  ADMUX |= 0b11101;
  #endif

	  /***ADC Prescalar**/
	  ADCSRA &= ~(7<<0); //clear bit 0,1,2
  #if ADC_PRESCALAR_SELECTION== PRESCALAR_DIVISION_FACTOR_2
	  ADCSRA |= 1;
  #elif ADC_PRESCALAR_SELECTION == PRESCALAR_DIVISION_FACTOR_4
	  ADCSRA |= 2;
  #elif ADC_PRESCALAR_SELECTION == PRESCALAR_DIVISION_FACTOR_8
	  ADCSRA |= 3;
  #elif ADC_PRESCALAR_SELECTION == PRESCALAR_DIVISION_FACTOR_16
	  ADCSRA |= 4;
  #elif ADC_PRESCALAR_SELECTION == PRESCALAR_DIVISION_FACTOR_32
	  ADCSRA |= 5;
  #elif ADC_PRESCALAR_SELECTION == PRESCALAR_DIVISION_FACTOR_64
	  ADCSRA |= 6;
  #elif ADC_PRESCALAR_SELECTION == PRESCALAR_DIVISION_FACTOR_128
	  ADCSRA |= 7;
  #endif

	  /**Enable ADC***/
	  ADCSRA |= (1<<ADEN);

	  Local_enuErrorState = ES_OK;

	  return Local_enuErrorState;


}
u16 ADC_Conversion()
{
	  u16 Local_u16Result ;
	 ADCSRA |= (1<<ADSC);

	 while(ADIF == 0);
  #if ADC_ADJUSTMENT == RIGHT_ADUSTMENT
  	Local_u16Result = ADC;
  #elif ADC_ADJUSTMENT == LEFT_ADUSTMENT
  	Local_u16Result = ADCH;
  #endif
  	 ADCSRA |= (1<<ADIF);
	 return  Local_u16Result;
}
