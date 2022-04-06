/* -----------------------------------------
 * G.Raf^engineering
 * www.sunriax.at
 * -----------------------------------------
 *    Platform: Megacard/STK500/STK600
 *    Hardware: ATmega16
 * -----------------------------------------
 *     Version: 1.0 Release
 *      Author: G.Raf
 * Description:
 *   Testing the .matrix display over SPI
 * -----------------------------------------
 */ 

#define F_CPU 12000000UL    // System clock (required for delay)

// System libraries
#include <avr/io.h>
#include <util/delay.h>

// User libraries
#include "matrix/matrix.h"

int main(void)
{   
	matrix_init();
	
	_delay_ms(1000);
	
	matrix_clear();
	
	_delay_ms(1000);
	
	unsigned char buffer[] = {
		0b01000,
		0b01000,
		0b01000,
		0b01000,
		0b01000,
		0b01000,
		0b11111
	};
	
	matrix_prom_write(MATRIX_EEPROM_CHAR0, buffer);
	
	_delay_ms(1000);
	
    while (1) 
    {
	    matrix_string("B");
	    matrix_buffer(buffer);
		_delay_ms(1000);
	    matrix_string("E");
	    matrix_prom_read(MATRIX_EEPROM_CHAR0);
		_delay_ms(1000);
		matrix_string("T");
    }
}