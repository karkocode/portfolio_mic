/*
 * main.c
 *
 * Created: 3/20/2026 4:39:14 PM
 *  Author: Aluno
 */ 

#define F_CPU 16000000
#include <xc.h>
#include "util/delay.h"

int main(void)
{
	UBRR0 = 8;	//BAUD rate de 9600 (com U2X0 = 0)
	UCSR0A = (0<<U2X0);
	UCSR0B = (0<<UCSZ02)|(1<<TXEN0);			//Habilita somente o tansmissor
	UCSR0C = (0<<UMSEL01)|(0<<UMSEL00)		//Modo assíncrono
			|(1<<UPM01)|(0<<UPM00)			//HABILITA PARIDADE, MODO PAR
			|(0<<USBS0)						//1 BIT DE STOP
			|(1<<UCSZ01)|(1<<UCSZ00);		//DADOS DE 8 BITS

    while(1)
    {
	UDR0 = 0x5A;	//Transmite a mensagem
	_delay_ms(100);	}
}