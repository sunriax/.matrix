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
	//
	//_delay_ms(1000);
	//
	//matrix_string("Initialisation");
	//
	//_delay_ms(1000);
	//
	//matrix_char('I');
	//
	//for (unsigned char i=0; i <= 16; i++)
	//{
		//matrix_intensity(i);
		//_delay_ms(250);
	//}
	//// Intensity gets automatically reset to 0 after 16 (0x10)
	//// is sent. Only 0x00 - 0x0F is allowed!
	//
	//_delay_ms(1000);
	//
	//matrix_char('I');
	//for (unsigned char i=0; i <= 128; i++)
	//{
		//matrix_refresh_rate(i);
		//_delay_ms(50);
	//}
	//// Refresh rate gets automatically reset to 0 after 128 (0x80)
	//// is sent. Only 0x00 - 0x7F is allowed!
	//
	//_delay_ms(1000);
	//
	unsigned char buffer[] = {
		0b00100,
		0b01110,
		0b11111,
		0b11111,
		0b11111,
		0b00000,
		0b00100
	};
	
	//unsigned char buffer[] = {
		//0b00000,
		//0b00000,
		//0b00000,
		//0b00000,
		//0b00000,
		//0b00000,
		//0b00000
	//};
	
	
	matrix_prom_write(MATRIX_EEPROM_CHAR0, buffer);
	
	_delay_ms(1000);
	//
	//matrix_string("READ");
	//
	//_delay_ms(1000);
	//
	
    while (1) 
    {
	    matrix_string("END");
	    matrix_prom_read(MATRIX_EEPROM_CHAR0);
		//matrix_buffer(buffer);
		_delay_ms(1000);
    }
}