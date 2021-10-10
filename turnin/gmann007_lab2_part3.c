/*	Author: lab
 *  Partner(s) Name: Gurvinder
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include “simAVRHeader.h”
#endif	

int main(void) {
	DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
	DDRB = 0xFF; PORTC = 0x00; // Configure port B's 8 pins as outputs, initialize to 0s
	unsigned char temp = 0x00; // Temporary variable to hold the value of B
	unsigned char cntavail  = 0x04; // Temporary variable to hold the value of A
         unsigned char unavail;

while(1) {
		// 1) Read input
		temp = PINA;
		// 2) Perform computation
		// if PA0 is 1, set PB1PB0 = 01, else = 10
		unavail =  (temp & 0x01)+ ((temp & 0x02) >> 1) + ((temp & 0x04) >> 2) + ((temp & 0x08) >> 3);
	       cntavail = 0x04 - unavail;	// Sets tmpB to bbbbbb01
	if(cntavail == 0x80) {
	cntavail = 0x08;	
	}
PORTC =cntavail;	
	}
	return 0;
}

