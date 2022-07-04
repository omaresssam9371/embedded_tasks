#include "stm32f4xx.h"

signed char count= -1;

int main(void){
	//Set pin 0 and 1 port B as input
	GPIO_Init(GPIOB,0,0,1);
	GPIO_Init(GPIOB,1,0,1);
	////Set pin 0 and 1 port B into pull up mode
	GPIOB->PUPDR |=(1u<<0);
	GPIOB->PUPDR |=(1u<<1);

	// set port A pins as output
	GPIO_Init(GPIOA,0,1,0);
	GPIO_Init(GPIOA,1,1,0);
	GPIO_Init(GPIOA,2,1,0);
	GPIO_Init(GPIOA,3,1,0);
	GPIO_Init(GPIOA,4,1,0);
	GPIO_Init(GPIOA,5,1,0);
	GPIO_Init(GPIOA,6,1,0);

	// Enable clock access to sysconf
	RCC->APB2ENR|=(1u<<14);


	// Set Selection lines of EXTI0
	SYSCFG->EXTICR[0] |=(1u<<0);
	// Set Selection lines of EXTI1
	SYSCFG->EXTICR[0] |=(1u<<4);

	// Configure the mask bit of exti0 and exit1
	EXTI->IMR |=(1u<<0);
	EXTI->IMR |=(1u<<1);

	// Configure the Trigger  as falling trigger
	EXTI->FTSR |=(1u<<0);
	EXTI->FTSR |=(1u<<1);

	// enable EXTI0 interrupt from NVIC
	NVIC->ISER[0]|=(1u<<6);
	NVIC->ISER[0]|=(1u<<7);

	while(1)
	{}
}



void ISR_OF_EXTI0(void)
{
		count = count+1;
		CheckCount();

}
void ISR_OF_EXTI1(void)
{
		count = count-1;
		CheckCount();

}

void EXTI0_IRQHandler(void){
	ISR_OF_EXTI0();
}
void EXTI1_IRQHandler(void){
	ISR_OF_EXTI1();
}



void CheckCount(void){

if(count == 0){
		GPIO_Write(GPIOA,0,1);
		GPIO_Write(GPIOA,1,1);
		GPIO_Write(GPIOA,2,1);
		GPIO_Write(GPIOA,3,1);
		GPIO_Write(GPIOA,4,1);
		GPIO_Write(GPIOA,5,1);
		GPIO_Write(GPIOA,6,0);
}



else if(count == 1){
		GPIO_Write(GPIOA,0,0);
		GPIO_Write(GPIOA,1,1);
		GPIO_Write(GPIOA,2,1);
		GPIO_Write(GPIOA,3,0);
		GPIO_Write(GPIOA,4,0);
		GPIO_Write(GPIOA,5,0);
		GPIO_Write(GPIOA,6,0);
}

else if(count == 2){
		GPIO_Write(GPIOA,0,1);
		GPIO_Write(GPIOA,1,1);
		GPIO_Write(GPIOA,2,0);
		GPIO_Write(GPIOA,3,1);
		GPIO_Write(GPIOA,4,1);
		GPIO_Write(GPIOA,5,0);
		GPIO_Write(GPIOA,6,1);
}

else if(count == 3){
			GPIO_Write(GPIOA,0,1);
			GPIO_Write(GPIOA,1,1);
			GPIO_Write(GPIOA,2,1);
			GPIO_Write(GPIOA,3,1);
			GPIO_Write(GPIOA,4,0);
			GPIO_Write(GPIOA,5,0);
			GPIO_Write(GPIOA,6,1);
}

else if(count == 4){
			GPIO_Write(GPIOA,0,0);
			GPIO_Write(GPIOA,1,1);
			GPIO_Write(GPIOA,2,1);
			GPIO_Write(GPIOA,3,0);
			GPIO_Write(GPIOA,4,0);
			GPIO_Write(GPIOA,5,1);
			GPIO_Write(GPIOA,6,1);
}

else if(count == 5){
			GPIO_Write(GPIOA,0,1);
			GPIO_Write(GPIOA,1,0);
			GPIO_Write(GPIOA,2,1);
			GPIO_Write(GPIOA,3,1);
			GPIO_Write(GPIOA,4,0);
			GPIO_Write(GPIOA,5,1);
			GPIO_Write(GPIOA,6,1);
}

else if(count == 6){
			GPIO_Write(GPIOA,0,1);
			GPIO_Write(GPIOA,1,0);
			GPIO_Write(GPIOA,2,1);
			GPIO_Write(GPIOA,3,1);
			GPIO_Write(GPIOA,4,1);
			GPIO_Write(GPIOA,5,1);
			GPIO_Write(GPIOA,6,1);
}

else if(count == 7){
			GPIO_Write(GPIOA,0,1);
			GPIO_Write(GPIOA,1,1);
			GPIO_Write(GPIOA,2,1);
			GPIO_Write(GPIOA,3,0);
			GPIO_Write(GPIOA,4,0);
			GPIO_Write(GPIOA,5,1);
			GPIO_Write(GPIOA,6,0);
}

else if(count == 8){
		GPIO_Write(GPIOA,0,1);
		GPIO_Write(GPIOA,1,1);
		GPIO_Write(GPIOA,2,1);
		GPIO_Write(GPIOA,3,1);
		GPIO_Write(GPIOA,4,1);
		GPIO_Write(GPIOA,5,1);
		GPIO_Write(GPIOA,6,1);
}

else if(count == 9){
		GPIO_Write(GPIOA,0,1);
		GPIO_Write(GPIOA,1,1);
		GPIO_Write(GPIOA,2,1);
		GPIO_Write(GPIOA,3,1);
		GPIO_Write(GPIOA,4,0);
		GPIO_Write(GPIOA,5,1);
		GPIO_Write(GPIOA,6,1);
}
}
