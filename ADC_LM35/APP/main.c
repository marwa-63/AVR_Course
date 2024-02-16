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
#include "../MCAL/ADC/ADC_int.h"

#include "../HAL/LCD/LCD_int.h"
#include "../HAL/LM35/LM35_int.h"

int main(void)
{


	LM35_enuInit();
	LCD_enuInit();
	LCD_enuSendCommand(0x01);
	s32 Temperature;
	while(1)
	{
		LCD_enuSendCommand(0x01);

		LM35_enuGetTemp(&Temperature);

		//f32 Analog_Result=(Digital_Result * (5000ul) ) / 1024.0;
		//Digital_Result =Analog_Result;
		LCD_enuSendCommand(0x01);
		LCD_enuDisplayIntegerNum(Temperature);
		_delay_ms(1000);



	}
	return 0;
}
