#include "gpio.h"
#include "stm32f4xx.h"

const int no_raws = 4;
const int no_cols = 3;
char rows[4]={3,4,5,6};
char cols[3]={0,1,2};
void KeypadCallouts_KeyPressNotificaton(void);
char lookupTable[4][3]={
		{1 , 2, 3},
		{4 , 5, 6},
		{7 , 8, 9},
		{'*',0,'#'}
};

char currentvalue;
char count = 0 ;
void KeyPad_INIT(void)
{
	//enable rows as input
	for (int i = 0; i < 4 ;i++){
		GPIO_Init(GPIOB,rows[i],0,1);
	}
	//enable col as output
	for (int j = 0; j < 3 ;j++){
		GPIO_Init(GPIOB,cols[j],1,1);
	}

}

void KeyPad_MANAGE(void)
{
	//nested for loop to check which button is pressed
	//if pressed wait until released then change the value;
	//call KeypadCallouts_KeyPressNotificaton

	unsigned char row, col;
	for(col = 0; col <= 2; col++)
	{
		GPIO_Write(GPIOB,col,0);
		for(row = 3; row <= 6; row++)
		{
			//col 1 row 2
			if(GPIO_Read(GPIOB,row)==0)
			{
				//delay 300 ms
				for (unsigned int i = 0; i < 30000; i++) {}

				if(GPIO_Read(GPIOB,row)==0)    //
				{
					// store i and j
					currentvalue = lookupTable[row - 3][col];
					// use the pressed key by the user
					KeypadCallouts_KeyPressNotificaton();
				}
			}

		}
		GPIO_Write(GPIOB,col,1);

	}
}

char KeyPad_GET_VALUE(void)
{
	return currentvalue;
}

void KeypadCallouts_KeyPressNotificaton(void)
{
	switch (KeyPad_GET_VALUE())
	{
		case 0:
			GPIO_Write(GPIOA,1,1);
			GPIO_Write(GPIOA,2,1);
			GPIO_Write(GPIOA,3,1);
			GPIO_Write(GPIOA,4,1);
			GPIO_Write(GPIOA,5,1);
			GPIO_Write(GPIOA,6,1);
			GPIO_Write(GPIOA,7,0);
			break;

		case 1:
			GPIO_Write(GPIOA,1,0);
			GPIO_Write(GPIOA,2,1);
			GPIO_Write(GPIOA,3,1);
			GPIO_Write(GPIOA,4,0);
			GPIO_Write(GPIOA,5,0);
			GPIO_Write(GPIOA,6,0);
			GPIO_Write(GPIOA,7,0);
			break;

		case 2:
			GPIO_Write(GPIOA,1,1);
			GPIO_Write(GPIOA,2,1);
			GPIO_Write(GPIOA,3,0);
			GPIO_Write(GPIOA,4,1);
			GPIO_Write(GPIOA,5,1);
			GPIO_Write(GPIOA,6,0);
			GPIO_Write(GPIOA,7,1);
			break;

		case 3:
			GPIO_Write(GPIOA,1,1);
			GPIO_Write(GPIOA,2,1);
			GPIO_Write(GPIOA,3,1);
			GPIO_Write(GPIOA,4,1);
			GPIO_Write(GPIOA,5,0);
			GPIO_Write(GPIOA,6,0);
			GPIO_Write(GPIOA,7,1);
			break;
		case 4:
			GPIO_Write(GPIOA,1,0);
			GPIO_Write(GPIOA,2,1);
			GPIO_Write(GPIOA,3,1);
			GPIO_Write(GPIOA,4,0);
			GPIO_Write(GPIOA,5,0);
			GPIO_Write(GPIOA,6,1);
			GPIO_Write(GPIOA,7,1);
			break;

		case 5:
			GPIO_Write(GPIOA,1,1);
			GPIO_Write(GPIOA,2,0);
			GPIO_Write(GPIOA,3,1);
			GPIO_Write(GPIOA,4,1);
			GPIO_Write(GPIOA,5,0);
			GPIO_Write(GPIOA,6,1);
			GPIO_Write(GPIOA,7,1);
			break;

		case 6:
			GPIO_Write(GPIOA,1,1);
			GPIO_Write(GPIOA,2,0);
			GPIO_Write(GPIOA,3,1);
			GPIO_Write(GPIOA,4,1);
			GPIO_Write(GPIOA,5,1);
			GPIO_Write(GPIOA,6,1);
			GPIO_Write(GPIOA,7,1);
			break;

		case 7:
			GPIO_Write(GPIOA,1,1);
			GPIO_Write(GPIOA,2,1);
			GPIO_Write(GPIOA,3,1);
			GPIO_Write(GPIOA,4,0);
			GPIO_Write(GPIOA,5,0);
			GPIO_Write(GPIOA,6,0);
			GPIO_Write(GPIOA,7,0);
			break;

		case 8:
			GPIO_Write(GPIOA,1,1);
			GPIO_Write(GPIOA,2,1);
			GPIO_Write(GPIOA,3,1);
			GPIO_Write(GPIOA,4,1);
			GPIO_Write(GPIOA,5,1);
			GPIO_Write(GPIOA,6,1);
			GPIO_Write(GPIOA,7,1);
			break;

		case 9:
			GPIO_Write(GPIOA,1,1);
			GPIO_Write(GPIOA,2,1);
			GPIO_Write(GPIOA,3,1);
			GPIO_Write(GPIOA,4,0);
			GPIO_Write(GPIOA,5,0);
			GPIO_Write(GPIOA,6,1);
			GPIO_Write(GPIOA,7,1);
			break;
	}
}

