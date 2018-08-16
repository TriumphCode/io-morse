/*
 * hal_led.c
 *
 *  Created on: 24.06.2017
 *      Author: Lukasz
 */

#include "stm32l0xx.h"
#include "system/morse_led.h"

#define LED2 			      0
#define LED_PIN               GPIO_PIN_5
#define LED2_GPIO_PORT        GPIOA
#define LED2_GPIO_CLK_ENABLE()           __HAL_RCC_GPIOA_CLK_ENABLE()

void Morse_Led_Init(void)
{
	GPIO_InitTypeDef  gpio;

	  /* Enable the GPIO_LED Clock */
	  LED2_GPIO_CLK_ENABLE();

	  /* Configure the GPIO_LED pin */
	  gpio.Pin = LED_PIN;
	  gpio.Mode = GPIO_MODE_OUTPUT_PP;
	  gpio.Pull = GPIO_NOPULL;
	  gpio.Speed = GPIO_SPEED_FREQ_VERY_HIGH;

	  HAL_GPIO_Init(LED2_GPIO_PORT, &gpio);

	  /* Reset PIN to switch off the LED */
	  HAL_GPIO_WritePin(LED2_GPIO_PORT, LED_PIN, GPIO_PIN_RESET);
}

void Morse_Led_On(void)
{
	HAL_GPIO_WritePin(LED2_GPIO_PORT, LED_PIN, GPIO_PIN_SET);
}

void Morse_Led_Off(void)
{
	HAL_GPIO_WritePin(LED2_GPIO_PORT, LED_PIN, GPIO_PIN_RESET);
}
