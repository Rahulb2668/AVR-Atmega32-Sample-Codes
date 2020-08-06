#include<avr/io.h>
#include<util/delay.h>
void cmd(int a)
{
  PORTC=a;
  PORTA=0x02;
  _delay_ms(300);
  PORTA=0x00;
  }
void data(char b)
{
 PORTC=b;
 PORTA=0x03;
 _delay_ms(300);
 PORTA=0x01;
 _delay_ms(300);
 }
 char keypad()
 {while(1)
 {
    int e;
    PORTD=0xFE;
	e=PIND&0xF0;
	switch(e)
	{
	  case(0xE0):return('1');
	  case(0xD0):return('2');
	  case(0xB0):return('3');
      case(0x70):return('4');
	  }
    PORTD=0xFD;
	e=PIND&0xF0;
	switch(e)
	{
      case(0xE0):return('5');
	  case(0xD0):return('6');
	  case(0xB0):return('7');
      case(0x70):return('8');
	 }
	 PORTD=0xFB;
	 e=PIND&0xF0;
	 switch(e)
	 {
      case(0xE0):return('9');
	  case(0xD0):return('A');
	  case(0xB0):return('B');
      case(0x70):return('C');  
	  }
	  PORTD=0xF7;
	  e=PIND&0xF0;
	  switch(e)
	  {
	   case(0xE0):return('D');
	  case(0xD0):return('E');
	  case(0xB0):return('F');
      case(0x70):return('G');
		}
		}
}
void main()
{
  
  char d;
  DDRA=0xff;
  DDRC=0xff;
  DDRD=0x0F;
  cmd(0x38);
  cmd(0x01);
  cmd(0x80);
  cmd(0x06);
  cmd(0x0E);
 while(1)
 { 
   cmd(0x01);
   d=keypad();
   _delay_ms(500);
   data(d);
   _delay_ms(500);

} 
}
