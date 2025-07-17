#include<reg51.h>
sbit led =P3^0;
sbit sw = P2^0;
void main()
{
 led =0;
 while(1)
 { 
  if(sw==0) //for pull up sw//
   {
    led =1;
   }
   else
   { 
   led=0;
   }
   }
  }