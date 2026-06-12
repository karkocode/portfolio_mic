/*
 * main.c
 *
 * Created: 6/12/2026 2:01:34 PM
 *  Author: Aluno
 */ 

#include <xc.h>

const float VREF = 1.1f; //ref interna de 1,1V

//parametros do filtro notch com rejeiçao em w= 0.12pi
const float coeff_a[3] = {1.000, -1.414, 1.000};
const float coeff_b[3] = {1.000, -1.273, 0.810};

float x[3]; //interpretacao x[0] = x(n), x[1] = x(n-1), x[2] = x(n-2);
float y[3];

ISR(ADC_vect){
	uint16_t tADCValue = ADC;
	x[2]=x[1];
	x[1]=x[0];
	x[0] = VREF * ((float)tADCValue / 1024); //saida em mV do ADC
	y[2]=y[1];
	y[1]=y[0];
	y[0] = coeff_a[0] * x[0] + coeff_a[1] * x[1] + coeff_a[2] * x[2] + coeff_b[1] * y[1] + coeff_b[2] * y[2];
	//jogar resultado no pwm
	OCR1A = (uint16_t)(y[0]*65355);
}

int main(void)
	//configurar adc com interrupção
	//configurar pwm
{
    while(1)
    {
        //TODO:: Please write your application code 
    }
}
