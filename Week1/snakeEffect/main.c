/*

 * main.c
 *
 *  Created on: Oct 6, 2023
 *      Author: HP
 */
#include <util/delay.h>
typedef unsigned char u8;

#define DDRA *((u8*)0x3A)
#define PORTA *((u8*)0x3B)
#define PINA *(( volatile u8*)0x39)

int main(void)
{
	DDRA =0xff;
	PORTA =0;
	int i=0;
	while(1)
	{
		for(i=7;i>=0;i--)
		{
			PORTA |=(1<<i);
				_delay_ms(500);
		}
		for(i=7;i>=0;i--)
				{
					PORTA &=~(1<<i);
						_delay_ms(500);
				}
	}

	return 0;
}


