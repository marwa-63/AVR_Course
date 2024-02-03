/*
 * EX_INT.c
 *
 *  Created on: Feb 2, 2024
 *      Author: HP
 */
#include "EX_INT.h"

void (*CallbackPtr)(void)=NULL;
void EXINT_Init(void)
{
		MCUCR &=~(79<<0);  

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
		MCUCR|=FALLING_EDGE;
		#elif   EX_INT2_MODE == RISING_EDGE
		MCUCR|=RISING_EDGE;
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

		GIFR|=(7<<5);   
}
void EXINT_Enable(u8 EXINT_ID)
{
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
}

void EXINT_Disable(u8 EXINT_ID)
{
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
	
}

void EXINTGLOBAL_Enable(void)
{
	SREG |= (1<<7);
}
void EXINTGLOBAL_Disable(void)
{
	SREG &=~(1<<7);
}

 void EXINT_Callback(void (*Func_ptr) (void) )
 {
	 CallbackPtr=Func_ptr;
 }
 void _Vector(void)__attribute__((signal,used));
 void _Vector(void)
 {
	 if(  CallbackPtr != NULL)
	    CallbackPtr();
 }


