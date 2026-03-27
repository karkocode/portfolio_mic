/*
 * main.c
 *
 * Created: 3/27/2026 3:54:10 PM
 *  Author: Aluno
 */ 
#define F_CPU 16000000
#include <xc.h>
#include "util/delay.h"
uint8_t gReceiveBuffer[3];

void UART_receiveMessage(uint8_t * pBuffer, int pSize){
	uint8_t * tBufferPtr = pBuffer;
	for(int i=0; i<pSize; i++){
		while((UCSR0A & (1<<RXC0)) == 0);
		uint8_t tReceivedByte = UDR0;
		*tBufferPtr = tReceivedByte;
		tBufferPtr++;
	}
}

void UART_parseMessage(uint8_t *pMessage){
	//calcular checksum
	uint8_t tChecksum = 0;
	for(int i=0; i<2; i++){
		tChecksum += pMessage[i];
	}
	if((pMessage[2] == tChecksum)){
		PORTB &= ~(1<<PORTB2);
		if(pMessage[0] == 0x20){
			if(pMessage[1] == 0x01){
				PORTB |= (1<<PORTB0);	//liga o led
			} else
			if(pMessage[1] == 0x00) {
				PORTB &= ~(1<<PORTB0); 	//desliga o led
			}
		}
		if(pMessage[0] == 0x30){
			if(pMessage[1] == 0x01){
				PORTB |= (1<<PORTB1);
			} else
		if(pMessage[1] == 0x00){
			PORTB &= ~(1<<PORTB1);
			}
		}
	} else {
		//erro de checksum
		PORTB |= (1<<PORTB2); //acende led 3
	}
}

int main(void)
{
	DDRB = (1<<DDB0)|(1<<DDB1)|(1<<DDB2);							//CONFIGURA 
	UBRR0 = 103;								//CONFIGURAR BAUD RATE para 9600
	UCSR0A = (0<<U2X0);
	UCSR0B = (1<<RXEN0)|(0<<UCSZ02);			// HABILITA TRANSMISSOR
	UCSR0C = (0<<UMSEL01)|(0<<UMSEL00)			// MODO ASSÍNCRONO
			|(1<<UPM01)|(0<<UPM00)				// HABILITA PARIDADE PAR
			|(0<<USBS0)							// 1 BIT DE STOP
			|(1<<UCSZ01)|(1<<UCSZ00);			// FRAMES DE 8 BITS
	while(1){
		UART_receiveMessage(gReceiveBuffer, 3);
		UART_parseMessage(gReceiveBuffer);
		_delay_ms(10);
	}
}