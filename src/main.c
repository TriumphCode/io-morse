/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/


#include "stm32l0xx.h"
#include "system/sys_init.h"
			

int main(void)
{
	Morse_Init();
	//Morse_Led_Off();
	while (1)
	{
		if (Morse_Button_State() != GPIO_PIN_SET)
		{
			Morse_Led_On();
		}
		else
		{
			Morse_Led_Off();
		}
	}
}
