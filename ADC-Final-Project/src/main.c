#include <LCD.h>
#include <stdlib.h>
#include <stdio.h>
#include "stm32f4xx.h"
#include "adc.h"
#include "gpio.h"


int main(void)
{
	struct ADCConfigType* par = (struct ADCConfigType*) malloc(sizeof(struct ADCConfigType));

	Ended_Conversion = 1;

	ADC1_Config();
	ADC_Init(par);

	LCD_Init();

	LCD_DisplayString("temp value = ");

	ADC_StartConv(0);
//	delay_ms(10);
	for(int k=0;k<10000;k++);


	while(1)
	{
		if (USE_POLLING){
			  notValid = ADC_ReadData(&dataPtr);
		}

		  if(!notValid){
				 LCD_MoveCursor(0,14);
				 LCD_IntToStr(dataPtr);
			   notValid = 1;
		  }

		  if(!(ADC1->CR2 & ADC_CR2_CONT)){
			  ADC1->CR2 |= ADC_CR2_SWSTART;
		  }
    }
}

void ADC_IRQHandler(void)
{
	  /* Check ADC1 EOC */
	  notValid = ADC_ReadData(&dataPtr);
}
