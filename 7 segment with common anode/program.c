#include<reg51.h>
void delay(int a);
void main()
{
 while(1)
 { 
   P2=0XC0;
   delay(200);
   P2=0XF9;
   delay(200);
   P2=0XA4;
   delay(200);
   P2=0XB0;
   delay(200);
   P2=0X99;
   delay(200);
   P2=0X92;
   delay(200);
   P2=0X82;
   delay(200);
   P2=0XF8;
   delay(200);
   P2=0X80;
   delay(200);
   P2=0X98;
   delay(200);
  }
  }
 void delay(int a)
 {
 int i,j;
 for(i=0;i<a;i++)
 {
  for(j=0;j<250;j++)
  {
  }
  }
  }