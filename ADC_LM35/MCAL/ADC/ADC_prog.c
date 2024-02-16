/*
 * ADC_prog.c
 *
 *  Created on: Feb 8, 2024
 *      Author: HP
 */

#include "../../LIB/stdTypes.h"
#include "../../LIB/errorStates.h"

#include "ADC_config.h"
#include "ADC_priv.h"


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
ES_t ADC_Conversion()
{
	ES_t Local_enuErrorState = ES_NOK;
	 ADCSRA |= (1<<ADSC);

  	Local_enuErrorState = ES_OK;
	 return Local_enuErrorState;
}
ES_t ADC_enuPollingSystem(void)
{
	ES_t Local_enuErrorState = ES_NOK;

	while( ( (ADCSRA >> ADIF)&1 ) == 0);
    ADCSRA |= (1<<ADIF);
	 Local_enuErrorState = ES_OK;

	return Local_enuErrorState;

}

ES_t ADC_enuReadHighValue(u8 * Copy_pu8Value)
{
	ES_t Local_enuErrorState = ES_NOK;

    #if ADC_ADJUSTMENT == RIGHT_ADUSTMENT
	* Copy_pu8Value = ADCL >> 2;
	* Copy_pu8Value |= (ADCH << 6);
    #elif ADC_ADJUSTMENT == LEFT_ADUSTMENT
	* Copy_pu8Value = ADCH;
    #endif

	 Local_enuErrorState = ES_OK;
		return Local_enuErrorState;
}

ES_t ADC_enuRead(u16 * Copy_pu16Value)
{
	ES_t Local_enuErrorState = ES_NOK;

    #if ADC_ADJUSTMENT == RIGHT_ADUSTMENT
	* Copy_pu16Value = ADCL;
	* Copy_pu16Value |= ( (u16)ADCH << 8 );
   #elif ADC_ADJUSTMENT == LEFT_ADUSTMENT
	* Copy_pu16Value = ADC;
   #endif

	  Local_enuErrorState = ES_OK;
		return Local_enuErrorState;
}

ES_t ADC_enuCallBack(void(*Copy_pfunAppFun)(void*) , void * Copy_pvidAppParameter)
{
	ES_t Local_enuErrorState = ES_NOK;
		return Local_enuErrorState;
}

ES_t ADC_enuSelectChannel(u8 Copy_u8ChannelID)
{
	ES_t Local_enuErrorState = ES_NOK;
	if( Copy_u8ChannelID >= 0 &&  Copy_u8ChannelID < 30)
	{
		ADMUX &= ~(31<<0); //clear bit 0,1,2,3,4
		ADMUX |= Copy_u8ChannelID;
		Local_enuErrorState = ES_OK;

	}
		return Local_enuErrorState;
}

ES_t ADC_enuEnableTriggeringMode(u8 Copy_u8TriggeringSource)
{
	ES_t Local_enuErrorState = ES_NOK;

		ADCSRA &=~(1<<ADATE);

		switch(Copy_u8TriggeringSource)
		{
		case FREE_RUNNING:
			SFIOR &=~(1<<5);
			SFIOR &=~(1<<6);
			SFIOR &=~(1<<7);
			break;
		case EXTI0_TRIG:
			SFIOR &=~(1<<5);
			SFIOR |= (1<<6);
			SFIOR &=~(1<<7);
			break;
		}

		ADCSRA |=(1<<ADATE);

		Local_enuErrorState = ES_OK;
		return Local_enuErrorState;
}

ES_t ADC_enuDisableTriggeringMode(void)
{
	ES_t Local_enuErrorState = ES_NOK;

	   ADCSRA &=~(1<<ADATE);

	  Local_enuErrorState = ES_OK;
		return Local_enuErrorState;
}

ES_t ADC_enuEnableInterruptMode(void)
{
	ES_t Local_enuErrorState = ES_NOK;
	  ADCSRA |=(1<<ADIE);
	  Local_enuErrorState = ES_OK;
		return Local_enuErrorState;
}
