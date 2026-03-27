/*
 * main.c
 *
 * Created: 3/27/2026 1:54:24 PM
 *  Author: Aluno
 */ 
#define F_CPU 16000000
#include <xc.h>
#include "util/delay.h"

int main(void)
{
		UBRR0 = 103;						//CONFIGURAR BAUD RATE para 9600
		UCSR0A = (0<<U2X0);
		UCSR0B = (1<<TXEN0)|(0<<UCSZ02);	// HABILITA TRANSMISSOR
		UCSR0C = (0<<UMSEL01)|(0<<UMSEL00)  // MODO ASSÍNCRONO
		|(0<<UPM01)|(0<<UPM00)				// HABILITA PARIDADE PAR
		|(0<<USBS0)							// 1 BIT DE STOP
		|(1<<UCSZ01)|(1<<UCSZ00);			// FRAMES DE 8 BITS
	while(1){
		UDR0 = 0X5A;
		_delay_ms(10); 
	}
}