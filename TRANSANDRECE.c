#include<avr/io.h>
#include<util/delay.h>
char rece()
{
 while((UCSRA&0x80)==0);
 return(UDR);
 }
 void trans(char b)
 {
   UDR=b;
   while((UCSRA&0x40)==0);
   }
void main()
{
 char a;
 DDRD=0x02;
 UCSRA=0x00;
 UCSRB=0x18;
 UCSRC=0x06;
 UBRRL=51;
 UBRRH=0;
while(1)
{
  a=rece();
  _delay_ms(500);
  trans(a);
  }
}
