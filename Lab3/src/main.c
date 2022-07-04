#include <stdint.h>

#define GPIOA_BASE (uint32_t)0x40020000
#define MODER_OFFSET (uint32_t)0x00
#define MODER_ADD (*((uint32_t*)(GPIOA_BASE + MODER_OFFSET)))

#define OUTPUTTYPE_OFFSET (uint32_t)0x04
#define OUTPUTTYPE_ADD (*((uint32_t*)(GPIOA_BASE + OUTPUTTYPE_OFFSET)))

#define INPUTTYPE_OFFSET (uint32_t)0x0C
#define INTPUTTYPE_ADD (*((uint32_t*)(GPIOA_BASE + INPUTTYPE_OFFSET)))

#define INPUT_OFFSET (uint32_t)0x10
#define INPUTData_ADD (*((uint32_t*)(GPIOA_BASE + INPUT_OFFSET)))

#define OUTDATA_OFFSET (uint32_t)0x14
#define OUTDATA_ADD (*((uint32_t*)(GPIOA_BASE + OUTPUTTYPE_OFFSET)))

#define	RCC_BASE 0x40023800
#define AHB1ENR_OFFSET 0x30
#define AHB1ENR_ADD (*((uint32_t*)(RCC_BASE+AHB1ENR_OFFSET)))


int main(void)
{
	//Enable clock to GPIOB
	AHB1ENR_ADD |=(1<<1);

	//for button pin 3
	MODER_ADD &=~(1<<6);
	MODER_ADD &=~(1<<7);
	INTPUTTYPE_ADD |= (1<<6);
	INTPUTTYPE_ADD &=~(1<<7);

	//RGB pin 5
	MODER_ADD |=(1<<10);
	MODER_ADD &=~(1<<11);
	OUTPUTTYPE_ADD &=~ (1<<5);

	//RGB pin 6
	MODER_ADD |=(1<<12);
	MODER_ADD &=~(1<<13);
	OUTPUTTYPE_ADD &=~ (1<<6);

	//RGB pin 7
	MODER_ADD |=(1<<14);
	MODER_ADD &=~(1<<15);
	OUTPUTTYPE_ADD &=~ (1<<7);

	unsigned int count = 0;

	while(1)
	{
		//don't do anything if the button didn't pushed
		while((INPUTData_ADD & (1<<3)) != 0){};

		//delay for debouncing
		for(unsigned int i = 0; i < 80000; i++){}

		//if the button pressed change the color of the rgb
		if(!(INPUTData_ADD &(1<<3)))
		{

			if(count == 0)
			{
				count = 1;
				OUTDATA_ADD &=~(1<<5);
				OUTDATA_ADD &=~(1<<6);
				OUTDATA_ADD &=~(1<<7);
			}

			else if(count == 1)
			{
				count = 2;
				OUTDATA_ADD &=~(1<<5);
				OUTDATA_ADD &=~(1<<6);
				OUTDATA_ADD |=(1<<7);
			}

			else if(count == 2)
			{
				count = 3;
				OUTDATA_ADD &=~(1<<5);
				OUTDATA_ADD |=(1<<6);
				OUTDATA_ADD &=~(1<<7);
			}

			else if(count == 3)
			{
				count = 4;
				OUTDATA_ADD &=~(1<<5);
				OUTDATA_ADD |=(1<<6);
				OUTDATA_ADD |=(1<<7);
			}

			else if(count == 4)
			{
				count = 5;
				OUTDATA_ADD |=(1<<5);
				OUTDATA_ADD &=~(1<<6);
				OUTDATA_ADD &=~(1<<7);
			}

			else if(count == 5)
			{
				count = 6;
				OUTDATA_ADD |=(1<<5);
				OUTDATA_ADD &=~(1<<6);
				OUTDATA_ADD |=(1<<7);
			}

			else if(count == 6)
			{
				count = 7;
				OUTDATA_ADD |=(1<<5);
				OUTDATA_ADD |=(1<<6);
				OUTDATA_ADD &=~(1<<7);
			}
			else if(count == 7)
			{
				count = 0;
				OUTDATA_ADD |=(1<<5);
				OUTDATA_ADD |=(1<<6);
				OUTDATA_ADD |=(1<<7);
			}
			//if the button is pressed keep the state and stay
			while((INPUTData_ADD & (1<<3)) == 0){};
		}


	}
}
