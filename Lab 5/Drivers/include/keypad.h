#include "gpio.h"
#include "stm32f4xx.h"

void KeyPad_INIT(void);
void KeyPad_MANAGE(void);
char KeyPad_GET_VALUE(void);
void KeypadCallouts_KeyPressNotificaton(void);

