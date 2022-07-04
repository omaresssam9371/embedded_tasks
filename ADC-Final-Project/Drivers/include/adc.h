/* Define to prevent recursive inclusion */
#ifndef __INC_ADC_H_
#define __INC_ADC_H_

/* C++ detection */
#ifdef __cplusplus
extern "C" {
#endif

/* Includes */
#include "stm32f4xx.h"
#include <stdlib.h>

#define USE_POLLING 1

typedef enum { res12 = 0x00000000 ,
	res10=0x01000000
	,res8=0x02000000,
	res6=0x02000000} resolution;
typedef enum {Single = 0x0,
	Continous = 0x12} conversion_mode;
 struct ADCConfigType {
	resolution resolution;
	conversion_mode conversion_mode;
	float reference_voltage;
};

unsigned short int dataPtr;
unsigned char Ended_Conversion;
char displayText[16];
unsigned char Vref;
unsigned char notValid;
void ADC1_Config(void);
void ADC1_Main(void);
unsigned char ADC_ReadData(unsigned short int* DataPtr);
void ADC_Init(struct ADCConfigType* ADCConfigType);
void ADC_GetConversionState(unsigned char* ConversionStatePtr);
void ADC_StartConv(unsigned char ChannelNum);
void validity(void);

/* C++ detection */
#ifdef __cplusplus
}
#endif

#endif /*__INC_ADC_H_ */
