#include<reg51.h>
void delay();
void main()
{
while(1)
{
 P2=0X00;
 delay();
 P2=0X01;
 delay();
 } }
 void delay()
 {
   TMOD=0X01;
   TH0=0XDC;
   TL0=0X00;
   TR0=1;
   while(TF0==0);
   TF0=0;
   TR0=0;
 }
 
 