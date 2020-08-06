#include<avr/io.h>
#include<util/delay.h>
void cmd(int a)
{
  PORTD=a;
  PORTB=0x02;
  _delay_ms(500);
  PORTB=0x00;
  }
void data(char b)
{
  PORTD=b;
  PORTB=0x03;
  _delay_ms(300);
  PORTB=0x01;
  }
void display(char *p)
{
 while(*p!='\0')
 {
   data(*p);
    _delay_ms(300);
	p++;
	}
	}
void main()
{ 
  DDRA=0x00;
  DDRB=0xff;
  DDRC=0xff;
  DDRD=0xff;
  cmd(0x38);
  cmd(0x01);
  cmd(0x80);
  cmd(0x06);
  cmd(0x0E);
  while(1)
  {
    if((PINA&0x01)==0)
	{
	  PORTC=0x05;
	  _delay_ms(30);
	  display("FORWARD");
	  cmd(0x01);
	  }
     else if((PINA&0x02)==0)
	        {
	            PORTC=0x06;
	            _delay_ms(30);
	            display("REVERSE");
				cmd(0x01);
	          }
      else if((PINA&0x04)==0)
	        {
	          PORTC=0x00;
	          _delay_ms(30);
	          display("stop");
			  cmd(0x01);
	          }
    }
}
