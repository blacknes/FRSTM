#include "stm32f10x.h"


void LED_Init(void)		   
{	
    GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD|RCC_APB2Periph_GPIOG, ENABLE);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14;			 //??LED?? D2
  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  	GPIO_Init(GPIOG, &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;			 //??LED?? D5
  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  	GPIO_Init(GPIOD, &GPIO_InitStructure);
}


void Delay(vu32 nCount)	 
{
    for(; nCount != 0; nCount--);
}

int main()
{									 
	SystemInit();					
	LED_Init();	
	while(1)						 
	{
		Delay(0xDffff);
		GPIO_ResetBits(GPIOG, GPIO_Pin_14);
		GPIO_SetBits(GPIOD, GPIO_Pin_13);
		Delay(0xDffff);
		GPIO_SetBits(GPIOG, GPIO_Pin_14);
		GPIO_ResetBits(GPIOD, GPIO_Pin_13);
	}
}