/*
 * gpio.c
 *
 * Created: 27/02/2026 14:07:07
 *  Author: Ruan Victor Bonan
 */ 
#include "gpio.h"
#include <xc.h>

void GPIO_initialize() {
	DDRB = (1<<DDB0);// CONFIGURA O PINO PB0 COMO SAIDA
}

void GPIO_blinkled () {
	PORTB = (1<<PORTB0); //aciona o pino PB0
}