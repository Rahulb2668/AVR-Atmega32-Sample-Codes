#include<avr/io.h>
#include<util/delay.h>
void main()
{
  DDRC=0xFF;
  DDRD=0x00;
 
  while(1)
  {
    if((PIND&0x01)==1)
	{
	  PORTC=0x05;
	  _delay_ms(300);
	  }
     if((PIND&0x02)==1)
	 {
	   PORTC=0x06;
	   _delay_ms(300);
	   }
      if((PIND&0x04)==1)
	  {
	   PORTC=0x00;
	   _delay_ms(300);
	   }
    }	 
}
	   
