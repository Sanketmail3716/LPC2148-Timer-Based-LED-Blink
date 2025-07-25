#include<lpc214X.h>           
#include<stdbool.h> 
#include"PLL.h"
void Timer(unsigned int time);
 #define led 17       
bool flag=0;
void main (void)
{
	PINSEL0=0x00000000;
	PINSEL1=0x00000000;
	PINSEL2=0x00000000;
	PLL_SET();
IODIR0|=(1<<led);	
	
    while(1)                
    {
		  IOSET0=(1<<led);
			flag=0;
			Timer(500);
			IOCLR0=(1<<led);
			flag=1;
			Timer(500);
			
			
			
		}
}

void Timer(unsigned int time)
{
  T0CTCR=0x00;
	T0PR=59999;

	T0TCR=0x02;
	T0TCR=0x01;
	while(T0TC<time);
	T0TCR=0x00;
		
}