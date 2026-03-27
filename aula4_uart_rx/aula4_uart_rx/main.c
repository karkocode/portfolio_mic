/*
 * main.c
 *
 * Created: 3/27/2026 3:54:10 PM
 *  Author: Aluno
 */ 

#include <xc.h>

int main(void)
{
	DDRB = (1<<DDB0);							//CONFIGURA 
	UBRR0 = 103;								//CONFIGURAR BAUD RATE para 9600
	UCSR0A = (0<<U2X0);
	UCSR0B = (1<<RXEN0)|(0<<UCSZ02);			// HABILITA TRANSMISSOR
	UCSR0C = (0<<UMSEL01)|(0<<UMSEL00)			// MODO ASSÍNCRONO
			|(1<<UPM01)|(0<<UPM00)				// HABILITA PARIDADE PAR
			|(0<<USBS0)							// 1 BIT DE STOP
			|(1<<UCSZ01)|(1<<UCSZ00);			// FRAMES DE 8 BITS
	while(1){
    while( (UCSR0A & (1<<RXC0)) == 0); // ESPERAR UMA MENSAGEM CHEGar
		uint8_t tReceivedByte = UDR0;
		if(tReceivedByte == 200) {
			PORTB |= (1<<PORTB0);
		} else {
			PORTB = 0;
		}
	}
}