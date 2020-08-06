#include<avr/io.h>
#include<util/delay.h>
void cmd(int a)
{
  PORTC=a;
  PORTA=0x02;
  _delay_ms(600);
  PORTA=0x00;
  }
void data(char b)
{
 PORTC=b;
 PORTA=0x03;
 _delay_ms(600);
 PORTA=0x01;
 }
void trans(char b)
{
UDR=b;
while(UCSRA&0X																																									)
}
void main()
{  char a;
 DDRC=0xff;
 DDRA=0xff;
 DDRD=0x00;

 UCSRA=0x00;
 UCSRB=0x10;
 UCSRC=0x06;
 UBRRL=51;
 UBRRH=0;
 cmd(0x38);
 cmd(0x01);
 cmd(0x80);
 cmd(0x06);
 cmd(0x0E);
 data('d');
 while(1)
 {
 while((UCSRA&0x80)==0);
data('b');
 a=UDR;
 trans(a);
 data(a);
  _delay_ms(300);
 
 }
 }
