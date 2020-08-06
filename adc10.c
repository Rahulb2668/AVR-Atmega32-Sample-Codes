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
 _delay_ms(500);
 PORTC=0x01;
 }
void main()
{
 int d,a,b;
 char p,q,r,s;
 ADMUX=0x60;
 DDRA=0x00;
 DDRC=0xff;
 DDRD=0xff;
 cmd(0x38);
 cmd(0x01);
 cmd(0x80);
 cmd(0x06);
 cmd(0x0E);
 while(1)
 {
   ADCSRA=0xC0;
   while((ADCSRA&0x40)==1);
   b=ADCL>>6;
   a=ADCH;
   a=a<<2;
   d=a|b;
   s=(d/1000)+48;
   p=((d%1000)/100)+48;
   q=((d%100)/10)+48;
   r=(d%10)+48;
   data(s);
   _delay_ms(300);
   data(p);
   _delay_ms(300);
   data(q);
   _delay_ms(300);
   data(r);
   _delay_ms(300);
   cmd(0x01);
   } 
   }
