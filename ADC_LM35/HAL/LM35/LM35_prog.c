/*
 * LM35_prog.c
 *
 *  Created on: Feb 16, 2024
 *      Author: HP
 */

#include "../../LIB/stdTypes.h"
#include "../../LIB/errorStates.h"

#include "../../MCAL/DIO/DIO_int.h"
#include "../../MCAL/ADC/ADC_int.h"

#include "LM35_priv.h"
#include "LM35_config.h"

ES_t LM35_enuInit(void)
{
	ES_t Local_enuErrorState = ES_NOK;



		Local_enuErrorState=DIO_enuSetPinDirection( DIO_u8PORTA	,LM35_PIN_NUM,DIO_u8INPUT);
		ADC_Init();
		Local_enuErrorState=ADC_enuSelectChannel(LM35_PIN_NUM);


		return Local_enuErrorState;

}
ES_t LM35_enuGetTemp(s32 *Temp)
{
	ES_t Local_enuErrorState = ES_NOK;
	        u16 ADC_Read;
	        ADC_Conversion();

		    ADC_enuPollingSystem();
			ADC_enuRead(&ADC_Read);
			*Temp =(ADC_Read * 4.88) / 10.0;

			return Local_enuErrorState;

}
