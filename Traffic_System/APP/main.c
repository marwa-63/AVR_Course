/*
 * main.c
 *
 *  Created on: Feb 8, 2024
 *      Author: HP
 */
#include "../LIB/stdTypes.h"
#include "../LIB/errorStates.h"
#include "util/delay.h"



#include "../MCAL/DIO/DIO_int.h"
#include "../MCAL/GIE/GIE_int.h"
#include "../MCAL/TIMER/TIMER_int.h"
#include "../MCAL/interrupt.h"


u8 Car_Red,Car_Yellow,Car_Green=1;
u8 flag;

void App(void *p)
{

	 if(Car_Green == 1)
	 {
		 Car_Green=0;
		 Car_Red=0;
		 Car_Yellow=1;
		 flag=0;

	 }
	 else if(Car_Yellow == 1)
	 	 {
	 		 Car_Yellow=0;
	 		 if(flag)
	 		 {
	 		 Car_Green=1;
	 		 Car_Red=0;
	 		 }
	 		 else
	 		 {
	 		 Car_Red=1;
	 		Car_Green=0;
	 		 }

	 	 }
	 else if(Car_Red == 1)
	 	 	 {
	 	 		 Car_Yellow=1;
	 	 		 Car_Red=0;
	 	 		 Car_Green=0;
	 	 		 flag=1;

	 	 	 }
}
int main(void)
{
	DIO_enuSetPinDirection( DIO_u8PORTA ,DIO_u8PIN0,DIO_u8OUTPUT);
	DIO_enuSetPinDirection( DIO_u8PORTA ,DIO_u8PIN1,DIO_u8OUTPUT);
	DIO_enuSetPinDirection( DIO_u8PORTA ,DIO_u8PIN2,DIO_u8OUTPUT);

	DIO_enuSetPinDirection( DIO_u8PORTD ,DIO_u8PIN0,DIO_u8OUTPUT);
	DIO_enuSetPinDirection( DIO_u8PORTD ,DIO_u8PIN1,DIO_u8OUTPUT);
	DIO_enuSetPinDirection( DIO_u8PORTD ,DIO_u8PIN2,DIO_u8OUTPUT);

	DIO_enuSetPinDirection( DIO_u8PORTD ,DIO_u8PIN6,DIO_u8INPUT);

	DIO_enuSetPortValue(DIO_u8PORTA,0x00);
	DIO_enuSetPinValue(DIO_u8PORTA ,DIO_u8PIN0,DIO_u8HIGH);

	TIMER_enuInit();
	TIMER_enuSetAsychDelay(3000,App,NULL);


	GIE_Enable();
	while(1)
	{
		u8 Switch_Read;
		DIO_enuGetPinValue( DIO_u8PORTD ,DIO_u8PIN6,&Switch_Read);
		if( Switch_Read ==0 )
		{
			if(Car_Green == 1 )
				 {
				DIO_enuSetPinValue(DIO_u8PORTD ,DIO_u8PIN2,DIO_u8HIGH);
				DIO_enuSetPinValue(DIO_u8PORTD ,DIO_u8PIN1,DIO_u8LOW);
				DIO_enuSetPinValue(DIO_u8PORTD ,DIO_u8PIN0,DIO_u8LOW);
				 }
			else if(Car_Red == 1)
			{
				DIO_enuSetPinValue(DIO_u8PORTD ,DIO_u8PIN0,DIO_u8HIGH);
				DIO_enuSetPinValue(DIO_u8PORTD ,DIO_u8PIN1,DIO_u8LOW);
				DIO_enuSetPinValue(DIO_u8PORTD ,DIO_u8PIN2,DIO_u8LOW);

			}
			else if( Car_Yellow == 1 )
				{
					DIO_enuSetPinValue(DIO_u8PORTD ,DIO_u8PIN1,DIO_u8HIGH);
					DIO_enuSetPinValue(DIO_u8PORTD ,DIO_u8PIN0,DIO_u8LOW);
					DIO_enuSetPinValue(DIO_u8PORTD ,DIO_u8PIN2,DIO_u8LOW);

				}

		}
		else if(Switch_Read == 1)
		{
			DIO_enuSetPinValue(DIO_u8PORTD ,DIO_u8PIN1,DIO_u8LOW);
		    DIO_enuSetPinValue(DIO_u8PORTD ,DIO_u8PIN0,DIO_u8LOW);
		    DIO_enuSetPinValue(DIO_u8PORTD ,DIO_u8PIN2,DIO_u8LOW);
		}



		if(Car_Green == 1)
			 {
			DIO_enuSetPinValue(DIO_u8PORTA ,DIO_u8PIN0,DIO_u8HIGH);
			DIO_enuSetPinValue(DIO_u8PORTA ,DIO_u8PIN1,DIO_u8LOW);
			DIO_enuSetPinValue(DIO_u8PORTA ,DIO_u8PIN2,DIO_u8LOW);
			 }
		 else if(Car_Red == 1)
			 	 {
			 DIO_enuSetPinValue(DIO_u8PORTA ,DIO_u8PIN2,DIO_u8HIGH);
			 DIO_enuSetPinValue(DIO_u8PORTA ,DIO_u8PIN1,DIO_u8LOW);
			 DIO_enuSetPinValue(DIO_u8PORTA ,DIO_u8PIN0,DIO_u8LOW);
			 	 }
		 else if(Car_Yellow == 1)
		 {
			 DIO_enuSetPinValue(DIO_u8PORTA ,DIO_u8PIN2,DIO_u8LOW);
			 DIO_enuSetPinValue(DIO_u8PORTA ,DIO_u8PIN0,DIO_u8LOW);
			 DIO_enuSetPinValue(DIO_u8PORTA ,DIO_u8PIN1,DIO_u8HIGH);
		 }

	}
	return 0;
}


