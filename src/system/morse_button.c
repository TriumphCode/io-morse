/*
 * morse_button.c
 *
 *  Created on: Aug 16, 2018
 *      Author: lukaszsx
 */

#include "system/morse_button.h"

#define BUTTON_PIN			GPIO_PIN_13
#define BUTTON_GPIO_PORT	GPIOC
#define BUTTON_GPIO_CLK_ENABLE()           __HAL_RCC_GPIOC_CLK_ENABLE()

void Morse_Button_Init(void)
{
	BUTTON_GPIO_CLK_ENABLE();

	GPIO_InitTypeDef gpio;

	gpio.Pin = BUTTON_PIN;
	gpio.Mode = GPIO_MODE_INPUT;
	gpio.Pull = GPIO_PULLUP;
	gpio.Speed = GPIO_SPEED_FREQ_VERY_HIGH;

	HAL_GPIO_Init(GPIOC,&gpio);
}

GPIO_PinState Morse_Button_State(void)
{
	return HAL_GPIO_ReadPin(BUTTON_GPIO_PORT, BUTTON_PIN);
}
