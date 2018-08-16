/*
 * morse_button.h
 *
 *  Created on: Aug 16, 2018
 *      Author: lukaszsx
 */
#include "stm32l0xx.h"

#ifndef SYSTEM_MORSE_BUTTON_H_
#define SYSTEM_MORSE_BUTTON_H_

void Morse_Button_Init(void);
GPIO_PinState Morse_Button_State(void);

#endif /* SYSTEM_MORSE_BUTTON_H_ */
