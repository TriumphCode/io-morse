/*
 * morse_uart.c
 *
 *  Created on: Aug 22, 2018
 *      Author: lukaszsx
 */

#include "stm32l0xx.h"
#include "system/morse_uart.h"

#define UART_GPIO_PORT        GPIOA
#define UART_RX_PIN           GPIO_PIN_2
#define UART_TX_PIN           GPIO_PIN_3
#define UART_GPIO_CLK_ENABLE()           __HAL_RCC_GPIOA_CLK_ENABLE()
#define UART_USART2_CLK_ENABLE()  		 __HAL_RCC_USART2_CLK_ENABLE()


static UART_HandleTypeDef s_UARTHandle;

HAL_StatusTypeDef Morse_Uart_Init(void)
{

	GPIO_InitTypeDef gpio;
	UART_GPIO_CLK_ENABLE();

	gpio.Pin = UART_RX_PIN;
	gpio.Mode = GPIO_MODE_AF_PP;
	HAL_GPIO_Init(UART_GPIO_PORT, &gpio);

	gpio.Pin = UART_TX_PIN;
	gpio.Mode = GPIO_MODE_INPUT;
	HAL_GPIO_Init(UART_GPIO_PORT, &gpio);


    s_UARTHandle.Instance        = USART2;
    s_UARTHandle.Init.BaudRate   = 115200;
    s_UARTHandle.Init.WordLength = UART_WORDLENGTH_8B;
    s_UARTHandle.Init.StopBits   = UART_STOPBITS_1;
    s_UARTHandle.Init.Parity     = UART_PARITY_NONE;
    s_UARTHandle.Init.HwFlowCtl  = UART_HWCONTROL_NONE;
    s_UARTHandle.Init.Mode       = UART_MODE_TX_RX;

   return HAL_UART_Init(&s_UARTHandle);
}
