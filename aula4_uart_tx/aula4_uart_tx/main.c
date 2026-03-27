/*
 * main.c
 *
 * Created: 3/27/2026 1:54:24 PM
 *  Author: Aluno
 */ 
#define F_CPU 16000000
#include <xc.h>
#include "util/delay.h"

// funçao printipal uart tx
uint8_t gMessage[3] = {200, 100, 50}; //ultimo byte é checksum

void UART_sendmessage(uint8_t * pData, int pSize) {
	uint8_t * tMsgPtr = pData;
	uint8_t tChecksum = 0;
	for(int i=0; i<4; i++)
	{
		uint8_t tMessageByte = *tMsgPtr;
		tChecksum += tMessageByte;
		UDR0 = tMessageByte;
		tMsgPtr++;
	}
	while((UCSR0A & (1<<UDRE0)) == 0);
	UDR0 = tChecksum;
}

int main(void)
{
		UBRR0 = 103;						//CONFIGURAR BAUD RATE para 9600
		UCSR0A = (0<<U2X0);
		UCSR0B = (1<<TXEN0)|(0<<UCSZ02);	// HABILITA TRANSMISSOR
		UCSR0C = (0<<UMSEL01)|(0<<UMSEL00)  // MODO ASSÍNCRONO
		|(1<<UPM01)|(0<<UPM00)				// HABILITA PARIDADE PAR
		|(0<<USBS0)							// 1 BIT DE STOP
		|(1<<UCSZ01)|(1<<UCSZ00);			// FRAMES DE 8 BITS
	while(1){
		UART_sendmessage(gMessage, 3);
		_delay_ms(10); 
	}
}