/*
 * hal_init.c
 *
 *  Created on: 24.06.2017
 *      Author: Lukasz Szczepaniuk
 */

#include "system/sys_init.h"

void Morse_Init(void)
{
	Morse_Led_Init();
	Morse_Button_Init();
	Morse_Uart_Init();
}


