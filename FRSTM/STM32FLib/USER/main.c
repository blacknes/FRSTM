#include <stdio.h>  

/* STM Library need */
#include "stm32f10x.h"

/* freeRTOS need */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

#define LED0_ON()   GPIO_SetBits(GPIOG,GPIO_Pin_14);  
#define LED0_OFF()  GPIO_ResetBits(GPIOG,GPIO_Pin_14);  
  
static void prvSetupHardware( void );  
static void vLEDTask( void *pvParameters );  
void vLedInit(void); 

/** init with STM Library**/
/**
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

**/

int main()
{		
	
/**
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
**/
	
	/* Init with FreeRTOS */ 
  prvSetupHardware();  
	
  /* create a task*/
  xTaskCreate( vLEDTask, ( signed portCHAR * ) "LED", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY+3, NULL );  
  
	/* start OS */	
  vTaskStartScheduler();  
	
	return 0;
}

/*-----------------------------------------------------------*/  
void vLEDTask( void *pvParameters )  
{  
  for( ;; )  
  {  
    LED0_ON();  
    vTaskDelay( 1000/portTICK_RATE_MS );  
    LED0_OFF();  
    vTaskDelay( 1000/portTICK_RATE_MS );  
  }  
}  
  
/*-----------------------------------------------------------*/  
static void prvSetupHardware( void )  
{  
  vLedInit();  
}  
/*-----------------------------------------------------------*/  
void vLedInit( void )  
{  
  GPIO_InitTypeDef GPIO_InitStructure;  
  RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOG, ENABLE );  
 
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14;  
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;  
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;  
  GPIO_Init( GPIOG, &GPIO_InitStructure );      
} 

