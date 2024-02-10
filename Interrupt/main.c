/*
 * main.c

 *
 *  Created on: Feb 10, 2024
 *      Author: HP
 */
#include "stdTypes.h"
#include "errorStates.h"

#include "DIO_int.h"
#include "EXINT_int.h"
#include "LCD_int.h"

#include "util/delay.h"

void EXINT0(void)
{
	DIO_enuSetPinValue(DIO_u8PORTD,DIO_u8PIN7, DIO_u8LOW);
							//_delay_ms(1000);
							LCD_enuDisplayChar('a');
}

int main(void)
{
	DIO_enuInit();
	EXINT_Init();
	LCD_enuInit();

	//Button
	DIO_enuSetPinDirection(DIO_u8PORTD,DIO_u8PIN2, DIO_u8INPUT);
	//LED
	DIO_enuSetPinDirection(DIO_u8PORTD,DIO_u8PIN7, DIO_u8OUTPUT);

	EXINTGLOBAL_Enable();
	EXINT_Enable(0);
	EXINT_Callback(EXINT0,0);

	u8 Switch_Read;
	while(1)
	{

				DIO_enuSetPinValue(DIO_u8PORTD,DIO_u8PIN7, DIO_u8HIGH);

				 DIO_enuGetPinValue(DIO_u8PORTD,DIO_u8PIN2,&Switch_Read);
					if( Switch_Read == 0  )
					{
						while( DIO_enuGetPinValue(DIO_u8PORTD,DIO_u8PIN2,&Switch_Read) && Switch_Read == 0  )
						EXINT_Callback(EXINT0,0);


					}

	}

	return 0;
}

