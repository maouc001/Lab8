/*	Author: Mahdi Aouchiche
 *      Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab # 8  Exercise # 3
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */ 
// Demo video: https://drive.google.com/open?id=1IOQzq_eq-TbExVm_OCJ677v1iDt-2f3x
 
#include <avr/io.h>
#include "timer.h"
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

unsigned short x ;      	// x holds the value of ADC
unsigned char LED;      	// represents the state of B0
unsigned short ADC_MAX = 0xFF ; // holds the highest ADC displayed 

enum State {Start, ON_OFF} state; 

void tick() {
	// transitions 
	switch(state) {
		case Start: 
			LED = 0x01;
			state = ON_OFF;
			break;

		case ON_OFF:

			LED = (x >= ADC_MAX/2) ? 0x01 : 0x00;
			break;
	}

	// state actions
	switch(state) {
		case Start:
			break;
		case ON_OFF:
			break;
		default:
			break;
	}	
} 

void ADC_init() {
    ADCSRA |= (1 << ADEN) | (1 << ADSC) | (1<< ADATE);
    /* ADEN : setting this bit enables anables analog to digital conversion    
    *  ADSC : setting this bit starts the first conversion.
    *  ADATE: setting this bit enables auto_triggerring. Since we are in Free Running Mode,
    *         a new conversion will trigger whenever the previous conversion completes.
    */ 
}

int main(void) {
    
    /* Insert DDR and PORT initializations */
    DDRA = 0x00; PORTA = 0xFF;  // input
    DDRB = 0xFF; PORTB = 0x00;  // output
    DDRD = 0xFF; PORTD = 0x00;  // output
  	
    state = Start;  
    ADC_init();

    /* Insert your solution below */
    while (1) {
	
	x = ADC;
	tick();	
	PORTB = LED; 
    }
    return 1;
}
