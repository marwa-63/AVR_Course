/*
 * EXINT_prog.c
 *
 *  Created on: Feb 10, 2024
 *      Author: HP
 */

#include "stdTypes.h"
#include "errorStates.h"

#include "EXINT_config.h"
#include "EXINT_priv.h"
#include "EXINT.h"

void (*CallbackPtr_0)(void)=NULL;
void (*CallbackPtr_1)(void)=NULL;
void (*CallbackPtr_2)(void)=NULL;


ES_t EXINT_Init(void)
{
	ES_t Local_enuErrorState = ES_NOK;
		MCUCR &=~(15<<0); //clear bit 0,1,2,3

		#if  EX_INT0_MODE == FALLING_EDGE
		MCUCR|=FALLING_EDGE;
		#elif   EX_INT0_MODE == LOW_LEVEL
		MCUCR|=LOW_LEVEL;
		#elif   EX_INT0_MODE == RISING_EDGE
		MCUCR|=RISING_EDGE;
		#elif   EX_INT0_MODE == ANY_LOGIC
		MCUCR|=ANY_LOGIC;
		#endif

		#if  EX_INT1_MODE == FALLING_EDGE
		MCUCR|=(FALLING_EDGE<<2);
		#elif  EX_INT1_MODE == LOW_LEVEL
		MCUCR|=(LOW_LEVEL<<2);
		#elif  EX_INT1_MODE == RISING_EDGE
		MCUCR|=(RISING_EDGE<<2);
		#elif   EX_INT1_MODE == ANY_LOGIC
		MCUCR|=(ANY_LOGIC<<2);
		#endif

		#if  EX_INT2_MODE == FALLING_EDGE
		MCUCSR &= ~(1<<ISC2);
		#elif   EX_INT2_MODE == RISING_EDGE
		MCUCSR |= (1<<ISC2);
		#endif


		#if EX_INT0_STATE == ACTIVE
		GICR |=(1<<6);
		#elif  EX_INT0_STATE == DEACTIVE
		GICR &=~(1<<6);
		#endif




		#if EX_INT1_STATE == ACTIVE
		GICR |=(1<<7);
		#elif  EX_INT1_STATE == DEACTIVE
		GICR &=~(1<<7);
		#endif

		#if EX_INT2_STATE == ACTIVE
		GICR |=(1<<5);
		#elif  EX_INT2_STATE == DEACTIVE
		GICR &=~(1<<5);
		#endif

		GIFR|=(7<<5); // clear bits 5,6,7 to disable interrupt flags

	  Local_enuErrorState = ES_OK;
		return Local_enuErrorState ;
}
ES_t EXINT_Enable(u8 EXINT_ID)
{
	ES_t Local_enuErrorState = ES_NOK;
	if (EXINT_ID ==0)
	{
		GICR |= (1<<6);
	}
	else if (EXINT_ID ==1)
	{
		GICR |= (1<<7);
	}
	else if (EXINT_ID ==2)
	{
		GICR |= (1<<5);
	}
	  Local_enuErrorState = ES_OK;
	return Local_enuErrorState ;
}

ES_t EXINT_Disable(u8 EXINT_ID)
{
	ES_t Local_enuErrorState = ES_NOK;
	if (EXINT_ID ==0)
	{
		GICR &=~(1<<6);
	}
	else if (EXINT_ID==1)
	{
		GICR &=~(1<<7);
	}
	else if (EXINT_ID ==2)
	{
		GICR &=~(1<<5);
	}

	 Local_enuErrorState = ES_OK;
	return Local_enuErrorState ;

}

ES_t EXINTGLOBAL_Enable(void)
{
	ES_t Local_enuErrorState = ES_NOK;
	SREG |= (1<<7);

	 Local_enuErrorState = ES_OK;
	return Local_enuErrorState ;
}
ES_t EXINTGLOBAL_Disable(void)
{
	ES_t Local_enuErrorState = ES_NOK;
	SREG &=~(1<<7);
	 Local_enuErrorState = ES_OK;
	return Local_enuErrorState ;
}

 ES_t EXINT_Callback(void (*Func_ptr) (void) , u8 EX_INT_ID )
 {
	 ES_t Local_enuErrorState = ES_NOK;
	 if(EX_INT_ID < 3)
	 {
	 switch(EX_INT_ID)
	 {
	 case 0:
		   CallbackPtr_0=Func_ptr;
		    break;
	 case 1:
	 		 CallbackPtr_1=Func_ptr;
	 		 break;
	 case 2:
	 		 CallbackPtr_2=Func_ptr;
	 		 break;

	 }
	 Local_enuErrorState = ES_OK;
	 }

	 return Local_enuErrorState ;
 }

 ISR(VECT_INT0)
 {
	 if(  CallbackPtr_0 != NULL)
	    CallbackPtr_0();
 }
 ISR(VECT_INT1)
 {
	 if(  CallbackPtr_1 != NULL)
	    CallbackPtr_1();
 }
 ISR(VECT_INT2)
 {
	 if(  CallbackPtr_2 != NULL)
	    CallbackPtr_2();
 }
