/*
 * GccApplication2.cpp
 *
 * Created: 27/02/2026 13:46:23
 * Author : Ruan Victor Bonan
 */ 

#include <xc.h>
#include "gpio.h"
#include "usart.h"

int main(void)
{
	GPIO_initialize();
	USART_initialize();

    while (1) 
    {
		GPIO_blinkled();
		USART_send();
    }
}