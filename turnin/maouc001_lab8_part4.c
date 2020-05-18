/*	Author: Mahdi Aouchiche
 *      Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab # 8  Exercise # 4
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */ 
// Demo video: https://drive.google.com/open?id=1a8Z3WiI72nRNdZ1qib0ZvOhArCgQUvma
 
#include <avr/io.h>
#include "timer.h"
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif


unsigned short x ;      	// x holds the value of ADC
unsigned char LED,L0,L1,L2,L3,L4,L5,L6,L7; // represents the state of B0
unsigned short ADC_MAX = 0xFF ; // holds the highest ADC displayed 

enum State {Start, ON_OFF} state; 

void tick() {
	// transitions 
	switch(state) {
		case Start: 
			LED = 0x00;
			state = ON_OFF;
			break;

		case ON_OFF:
			
			
			L0 = (x >= ((1 * ADC_MAX)/8)) ? 0x01 : 0x00;
			L1 = (x >= ((2 * ADC_MAX)/8)) ? 0x01 : 0x00;
			L2 = (x >= ((3 * ADC_MAX)/8)) ? 0x01 : 0x00;
			L3 = (x >= ((4 * ADC_MAX)/8)) ? 0x01 : 0x00;
			L4 = (x >= ((5 * ADC_MAX)/8)) ? 0x01 : 0x00;
			L5 = (x >= ((6 * ADC_MAX)/8)) ? 0x01 : 0x00;
			L6 = (x >= ((7 * ADC_MAX)/8)) ? 0x01 : 0x00;
			L7 = (x >= ADC_MAX)           ? 0x01 : 0x00;
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
     
    ADC_init();

    
    state = Start; 

    /* Insert your solution below */
    while (1) {
	  
	x = ADC;
	tick();	
	LED = (L0 + (L1 << 1) + (L2 << 2) + (L3 << 3) + (L4 << 4) + (L5 << 5) + (L6 << 6) + (L7 << 7));  
	PORTB = LED; 
    }
    return 1;
}
