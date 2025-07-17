  #include<reg51.h>
  void delay(int a);
  void main()
  {
  while(1)
  {
   P2=0x01;
   delay(200);
   P2=0x00;
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
