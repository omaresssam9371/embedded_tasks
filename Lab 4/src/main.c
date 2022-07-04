#include<stdint.h>
#include "stm32f4xx.h"
#include "gpio.h"

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


	//Button INPUT-PIN 7
	GPIO_Init(GPIOA,0,0,0);

	unsigned int count = 0;

	// super loop
	while(1)
	{
		unsigned int reading1 = GPIO_Read(GPIOA,0);

		// approximatly  5 ms before 2nd reading for debouncing
		for(unsigned int i = 0; i < 5000; i++)
		{}

		unsigned char reading2 = GPIO_Read(GPIOA,0) ;

		if(reading1 && reading2 != reading1)
		{
			switch (count)
			{
				case 0:
					GPIO_Write(GPIOA,1,1);
					GPIO_Write(GPIOA,2,1);
					GPIO_Write(GPIOA,3,1);
					GPIO_Write(GPIOA,4,1);
					GPIO_Write(GPIOA,5,1);
					GPIO_Write(GPIOA,6,1);
					GPIO_Write(GPIOA,7,0);
					count ++;
					break;

				case 1:
					GPIO_Write(GPIOA,1,0);
					GPIO_Write(GPIOA,2,1);
					GPIO_Write(GPIOA,3,1);
					GPIO_Write(GPIOA,4,0);
					GPIO_Write(GPIOA,5,0);
					GPIO_Write(GPIOA,6,0);
					GPIO_Write(GPIOA,7,0);
					count ++;
					break;

				case 2:
					GPIO_Write(GPIOA,1,1);
					GPIO_Write(GPIOA,2,1);
					GPIO_Write(GPIOA,3,0);
					GPIO_Write(GPIOA,4,1);
					GPIO_Write(GPIOA,5,1);
					GPIO_Write(GPIOA,6,0);
					GPIO_Write(GPIOA,7,1);
					count ++;
					break;

				case 3:
					GPIO_Write(GPIOA,1,1);
					GPIO_Write(GPIOA,2,1);
					GPIO_Write(GPIOA,3,1);
					GPIO_Write(GPIOA,4,1);
					GPIO_Write(GPIOA,5,0);
					GPIO_Write(GPIOA,6,0);
					GPIO_Write(GPIOA,7,1);
					count ++;
					break;
				case 4:
					GPIO_Write(GPIOA,1,0);
					GPIO_Write(GPIOA,2,1);
					GPIO_Write(GPIOA,3,1);
					GPIO_Write(GPIOA,4,0);
					GPIO_Write(GPIOA,5,0);
					GPIO_Write(GPIOA,6,1);
					GPIO_Write(GPIOA,7,1);
					count ++;
					break;

				case 5:
					GPIO_Write(GPIOA,1,1);
					GPIO_Write(GPIOA,2,0);
					GPIO_Write(GPIOA,3,1);
					GPIO_Write(GPIOA,4,1);
					GPIO_Write(GPIOA,5,0);
					GPIO_Write(GPIOA,6,1);
					GPIO_Write(GPIOA,7,1);
					count ++;
					break;

				case 6:
					GPIO_Write(GPIOA,1,1);
					GPIO_Write(GPIOA,2,0);
					GPIO_Write(GPIOA,3,1);
					GPIO_Write(GPIOA,4,1);
					GPIO_Write(GPIOA,5,1);
					GPIO_Write(GPIOA,6,1);
					GPIO_Write(GPIOA,7,1);
					count ++;
					break;

				case 7:
					GPIO_Write(GPIOA,1,1);
					GPIO_Write(GPIOA,2,1);
					GPIO_Write(GPIOA,3,1);
					GPIO_Write(GPIOA,4,0);
					GPIO_Write(GPIOA,5,0);
					GPIO_Write(GPIOA,6,0);
					GPIO_Write(GPIOA,7,0);
					count ++;
					break;

				case 8:
					GPIO_Write(GPIOA,1,1);
					GPIO_Write(GPIOA,2,1);
					GPIO_Write(GPIOA,3,1);
					GPIO_Write(GPIOA,4,1);
					GPIO_Write(GPIOA,5,1);
					GPIO_Write(GPIOA,6,1);
					GPIO_Write(GPIOA,7,1);
					count ++;
					break;

				case 9:
					GPIO_Write(GPIOA,1,1);
					GPIO_Write(GPIOA,2,1);
					GPIO_Write(GPIOA,3,1);
					GPIO_Write(GPIOA,4,0);
					GPIO_Write(GPIOA,5,0);
					GPIO_Write(GPIOA,6,1);
					GPIO_Write(GPIOA,7,1);
					count = 0;
					break;
				}

			}

		}

}
