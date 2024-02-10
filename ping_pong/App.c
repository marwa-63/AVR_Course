/*
 * App.c
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

u8 score1=0 , score2=0, ball_Column=2,ball_Row=2;




void Game_Init()
{
	LCD_MOVE_CURSOR(1,5);
	LCD_enuDisplayString("PING_PONG");
	LCD_MOVE_CURSOR(2,7);
	LCD_enuDisplayString("GAME");
	_delay_ms(1000);
	LCD_enuSendCommand(0x01);

	score1=0 , score2=0, ball_Column=2,ball_Row=2;

	LCD_MOVE_CURSOR(1,1);
	LCD_enuDisplayString("P1:");
	LCD_enuDisplayIntegerNum(score1);
	LCD_MOVE_CURSOR(1,12);
	LCD_enuDisplayString("P2:");
	LCD_enuDisplayIntegerNum(score2);

	LCD_MOVE_CURSOR(2,1);
	LCD_enuDisplayChar('|');
	LCD_MOVE_CURSOR(2,16);
	LCD_enuDisplayChar('|');

	LCD_MOVE_CURSOR(2,2);
	LCD_enuDisplayChar('O');


	DIO_enuSetPinDirection(DIO_u8PORTD,DIO_u8PIN2, DIO_u8INPUT);
	DIO_enuSetPinDirection(DIO_u8PORTD,DIO_u8PIN3, DIO_u8INPUT);

}

void Game()
{
	//_delay_ms(1000);

	if(score2 > score1 || ( (score2 == score1) && score2 !=0 && score1 != 0 ) )
	{
	LCD_enuSendCommand(0x01);
	LCD_MOVE_CURSOR(1,5);
	LCD_enuDisplayString("PLayer 2");
	LCD_MOVE_CURSOR(2,7);
	LCD_enuDisplayString("Won!");
	_delay_ms(1000);
	Game_Init();
	}

	else if(score1 > score2 )
		{
		LCD_enuSendCommand(0x01);
		LCD_MOVE_CURSOR(1,5);
		LCD_enuDisplayString("PLayer 1");
		LCD_MOVE_CURSOR(2,7);
		LCD_enuDisplayString("Won!");
		_delay_ms(1000);
		Game_Init();
		}


}

void EXINT0()
{
	if(ball_Column ==2)
	{
		LCD_MOVE_CURSOR(2,2);
	    LCD_enuDisplayChar(' ');

	score1++;
	LCD_MOVE_CURSOR(1,1);
	LCD_enuDisplayString("P1:");
	LCD_enuDisplayIntegerNum(score1);
	for( ball_Column=3;ball_Column<15;ball_Column++){

		LCD_MOVE_CURSOR(2,ball_Column);
		LCD_enuDisplayChar('O');
		_delay_ms(80);
		LCD_MOVE_CURSOR(2,ball_Column);
		LCD_enuDisplayChar(' ');
	}

	LCD_MOVE_CURSOR(2,ball_Column);
	LCD_enuDisplayChar('O');
	_delay_ms(500);
	}

}


void EXINT1()
{
	if(ball_Column ==15)
		{
	score2++;
	LCD_MOVE_CURSOR(1,12);
	LCD_enuDisplayString("P2:");
	LCD_enuDisplayIntegerNum(score2);
	for( ball_Column=15; ball_Column>2; ball_Column--){
		       LCD_MOVE_CURSOR(2,ball_Column);
				LCD_enuDisplayChar('O');
				_delay_ms(80);
				LCD_MOVE_CURSOR(2,ball_Column);
				LCD_enuDisplayChar(' ');
	}
	LCD_MOVE_CURSOR(2,ball_Column);
	LCD_enuDisplayChar('O');
	_delay_ms(500);
		}

}
