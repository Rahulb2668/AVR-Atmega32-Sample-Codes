#include<avr/io.h>
#include<util/delay.h>
void main()
{
 DDRC=0xff;
 TCCR0=0x02;
 TCNT0=0x00;
 while(1)
 {
  PORTC=0x0f;
  
