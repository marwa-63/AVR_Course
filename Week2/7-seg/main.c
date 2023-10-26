/*
 * 7segbutton.c
 *
 * Created: 10/26/2023 12:15:02 PM
 * Author : HP
 */ 

#include <util/delay.h>

#define DDRA  		*((u8*)0x3A)
#define PORTA		*((u8*)0x3B)
#define PINA		*((volatile u8*)0x39)

#define DDRB  		*((u8*)0x37)
#define PORTB		*((u8*)0x38)
#define PINB		*((volatile u8*)0x36)

#define DDRD  		*((u8*)0x31)
typedef unsigned char u8;

int
main(void)
{
	u8 segCthd []= { 0x3f, 0x06, 0x5B,
		0x4F, 0x66, 0x6D,
		0x7D, 0x07, 0x7F,
	0x6F};
	DDRA = 0xff;
	PORTA=0;
	//sw0 in
	DDRB &= ~1;
	//pull up
	PORTB |=1;

	//sw1 in
	DDRB &= ~(1<<1);
	//pull up
	PORTB |=(1<<1);
	u8 i=0;
	 
	 
	while(1)
	{
		 
		 
		

		 
		if( ((PINB)&1 )==0 )
		{
			 
			while(((PINB)&1 )==0 );	
			if(i<9)
			i++;
			PORTA = segCthd[i];
				 
		}
		if( ((PINB>>1)&1 )==0 )
		{
			while(((PINB>>1)&1 )==0 );
			if(i>0) i--;
			PORTA = segCthd[i];
			
		}

	}

}

