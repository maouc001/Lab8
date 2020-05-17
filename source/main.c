/*	Author: Mahdi Aouchiche
 *      Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab # 8  Exercise # 1
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */ 
 
#include <avr/io.h>
#include "timer.h"
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

unsigned short x ;      // x holds the value of ADC
unsigned char tempB;    // tempB[7,0] = ADC[7,0]
unsigned char tempD;	// tempD[1,0] = ADC[9,8]


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
    
    ADC_init();

    /* Insert your solution below */
    while (1) {
	
	x = ADC; 
	tempB = (char) x;
	tempD = (char) (x >> 8);
        
	PORTB = tempB; 
	PORTD =	tempD;
    }
    return 1;
}
