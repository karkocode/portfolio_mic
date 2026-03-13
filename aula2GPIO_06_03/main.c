/*
 * main.c
 *
 * Created: 3/6/2026 2:36:34 PM
 *  Author: Aluno
 */ 
#define F_CPU 16000000
#include "util/delay.h"
#include <xc.h>
/* @brief Piscar um led ligado ao pino PC2 enquanto a chave ligada 
 *ao pino PD3 estiver pressionada
 */
 void Atividade(){
	DDRC |= (1<<DDC2); // configurar o pino PC2 como sa�da, colocando | nao zera os outros se por acaso tiverem acionados.
	DDRD &= (1<<DDD3);//configurar pino PD3 como entrada, usando & para zerar o pino(zerar = 0) p�ra transformar em entrada.
	
    while(1)
    { /*ler o valor da
			 entrada (PB3) para saber se vale 1 ou 0;*/
        if((PIND & (1<<PORTB3)) != 0){
			//chave fechada led vai piscar conforme o delay inserido
			_delay_ms(300);
			PORTC |= (1<<PORTC2); //ACENDE LED
			_delay_ms(700);
			PORTC &= ~(1<<PORTC2); //APAGA LED
			} else {
				//CHAVE A BERTA
				PORTC &= ~(1<<PORTC2); //APAGA LED
			}
		}
 }
int main(void){
	Atividade();
}