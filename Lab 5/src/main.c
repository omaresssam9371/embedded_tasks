#include<stdint.h>
#include "stm32f4xx.h"
#include "gpio.h"
#include "keypad.h"


int main(void)
{
	//7 SEG OUT-PIN
	GPIO_Init(GPIOA,1,1,0);
	GPIO_Init(GPIOA,2,1,0);
	GPIO_Init(GPIOA,3,1,0);
	GPIO_Init(GPIOA,4,1,0);
	GPIO_Init(GPIOA,5,1,0);
	GPIO_Init(GPIOA,6,1,0);
	GPIO_Init(GPIOA,7,1,0);


	//Button INPUT-PIN 0
	GPIO_Init(GPIOA,0,0,0);

	 KeyPad_INIT();

	while(1)
	{
		KeyPad_MANAGE();
		for (unsigned int i = 0; i < 50000; i++) {}

	}

}
