/*
 * TIMER_prog.c
 *
 *  Created on: Feb 23, 2024
 *      Author: HP
 */

#include "../../LIB/stdTypes.h"
#include "../../LIB/errorStates.h"

#include "../interrupt.h"

#include "TIMER_config.h"
#include "TIMER_priv.h"

static u32 Global_Preload, Global_NumOVF;

static void (*Global_Ptr)(void*)=NULL;
static void *Global_Para=NULL;

ES_t TIMER_enuInit(void)
{
	ES_t Local_enuErrorState = ES_NOK;
#if TIMER_PRES == 1024
	TCCR0 &= 0xf8 ;
	TCCR0 |= 5;
#endif

#if TIMER_MODE == OVF
	TCCR0 &= ~(1<<3);
	TCCR0 &= ~(1<<6);
#elif TIMER_MODE == CTC
	TCCR0 |= (1<<3);
	TCCR0 &= ~(1<<6);
#elif TIMER_MODE == PWM
	TCCR0 |= (1<<3);
	TCCR0 |= (1<<6);
#endif

#if OC_MODE == DISCONNECTED
	TCCR0 &= ~(1<<4);
	TCCR0 &= ~(1<<5);
#elif OC_MODE == TOG_PIN
	TCCR0 |= (1<<4);
	TCCR0 &= ~(1<<5);
#elif OC_MODE == NON_INVERTED
	TCCR0 |= (1<<5);
	TCCR0 &= ~(1<<4);
#endif

	  Local_enuErrorState = ES_OK;
		return Local_enuErrorState;
}

ES_t TIMER_enuSetPreload(u8 Copy_u8Preload)
{
	ES_t Local_enuErrorState = ES_NOK;
	TCNT0 =  Copy_u8Preload;

    Local_enuErrorState = ES_OK;
	return Local_enuErrorState;
}

ES_t TIMER_enuSetAsychDelay(u32 Copy_u8Time,void(*Copy_pfunApp)(void*) , void *parameter)
{
	ES_t Local_enuErrorState = ES_NOK;

	f32  OVFTime = 256 *( (f32)TIMER_PRES / TIMER_F_CPU);
	f32 NumOVF = (Copy_u8Time) / (OVFTime);

	if( (NumOVF-(u32)NumOVF) != 0.0 )
	{
		u32 NumOVF_int = (u32)NumOVF+1;
		NumOVF = NumOVF - (u32)NumOVF;
		u32 preload = 256 - (NumOVF * 256);
		Global_NumOVF = NumOVF_int;
		Global_Preload =preload;
		TCNT0 = preload;
	}
	else
	{
		Global_NumOVF =(u32)NumOVF;
	}

	if(Copy_pfunApp != NULL)
	{
		Global_Ptr = Copy_pfunApp;
		Global_Para = parameter;
		Local_enuErrorState = ES_OK;
	}

	TIMSK |= (1<<0);


		return Local_enuErrorState;
}

ES_t TIMER_enuSetSychDelay(u32 Copy_u8Time)
{
	ES_t Local_enuErrorState = ES_NOK;

	TIMSK &= ~(1<<0);

	f32  OVFTime = 256 *( (f32)TIMER_PRES / TIMER_F_CPU);
	f32 NumOVF = (Copy_u8Time) / (OVFTime);

		if( (NumOVF-(u32)NumOVF) != 0.0 )
		{
			u32 NumOVF_int = (u32)NumOVF+1;
			NumOVF = NumOVF - (u32)NumOVF;
			u32 preload = 256 - (NumOVF * 256);
			TCNT0 = preload;
			while( NumOVF_int >0)
			{
				while ( ( (TIFR>>0) & 1 ) == 0 );
				TIFR |= (1<<0);
				NumOVF_int--;
			}
		}
		else
		{
			u32 NumOVF_int = (u32)NumOVF;
			while( NumOVF_int > 0)
				{
					while ( ( (TIFR>>0) & 1 ) == 0 );
					TIFR |= (1<<0);
					NumOVF_int--;
				}
		}
		 Local_enuErrorState = ES_OK;
		return Local_enuErrorState;
}


ES_t TIMERCTC_enuSetAsychDelay(u32 Copy_u8Time , void(*Copy_pfunApp)(void*) , void * parameter)
{
	ES_t Local_enuErrorState = ES_NOK;

	f32  OVFTime = 256 *( (f32)TIMER_PRES / TIMER_F_CPU);

	OCR0 = 256 * (Copy_u8Time) / (OVFTime);

	if(Copy_pfunApp != NULL)
		{
			Global_Ptr = Copy_pfunApp;
			Global_Para = parameter;
			Local_enuErrorState = ES_OK;
		}

		TIMSK |= (1<<0);


	 Local_enuErrorState = ES_OK;
	return Local_enuErrorState;
}

ES_t TIMERCTC_enuSetSychDelay(u32 Copy_u8Time)
{
	ES_t Local_enuErrorState = ES_NOK;

	TIMSK &= ~(1<<0);

	f32  OVFTime = 256 *( (f32)TIMER_PRES / TIMER_F_CPU);

	OCR0 = 256 * (Copy_u8Time) / (OVFTime);
 		while ( ( (TIFR>>1) & 1 ) == 0 );
					TIFR |= (1<<1);
		 Local_enuErrorState = ES_OK;
		return Local_enuErrorState;

}

ES_t TIMERCTC_enuSetVoltage(f32 Copy_u8Voltage)
{
	ES_t Local_enuErrorState = ES_NOK;
	f32 duty;
#if OC_MODE == NON_INVERTED
	duty= (5 *Copy_u8Voltage) * (5 *Copy_u8Voltage);
	OCR0= (u8)(duty * 256);
#endif
	 Local_enuErrorState = ES_OK;
	 return Local_enuErrorState;
}

ISR( VECT_TIMER0_OVF )
{
	 if( Global_Ptr != NULL)
	 {
		  static u32 Counts =0;
		 Counts++;
		 if(Counts == Global_NumOVF )
		 {
			 TCNT0 =Global_Preload;
			 Global_Ptr(Global_Para);
			 Counts =0;
		 }
	 }
}
