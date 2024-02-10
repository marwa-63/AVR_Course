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

#include "App.h"
#include "util/delay.h"


int main(void)
{
	DIO_enuInit();
	EXINT_Init();
	LCD_enuInit();


	EXINTGLOBAL_Enable();
	EXINT_Enable(0);
	EXINT_Enable(1);
	EXINT_Callback(EXINT0,0);
	EXINT_Callback(EXINT1,1);

	Game_Init();


	while(1)
	{
	  Game();
	}

	return 0;
}

