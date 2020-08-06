#include<avr/io.h>
#include<util/delay.h>
void cmd(int a)
{
  PORTD=a;
  PORTC=0x02;
  _delay_ms(500);
  PORTC=0x00;
  }
void data(char b)
{
  PORTD=b;
  PORTC=0x03;
  _delay_ms(300);
  PORTC=0x01;
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
