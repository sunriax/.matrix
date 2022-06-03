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
	DDRA = 0x00;
	PORTA = 0x0F;
	
	matrix_init();
	
	_delay_ms(1000);
	
	matrix_clear_all();
	
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
	
	// Only one time necessary
	//matrix_prom_write(0, MATRIX_EEPROM_CHAR0, buffer);
	//matrix_prom_write(1, MATRIX_EEPROM_CHAR0, buffer);
	
	_delay_ms(1000);
	
	char c = 'A';
	
    while (1) 
    {	
		if(!(PINA & (1<<PINA0)))
		{
			_delay_ms(5);
			
			c++;
			
			if(c == 127)
			{
				matrix_prom_read(0, MATRIX_EEPROM_CHAR0);
				matrix_prom_read(1, MATRIX_EEPROM_CHAR0);
			}
			else if(c > 127)
			{
				c = 32;
				matrix_char(0, c);
				matrix_char(1, c);
			} 
			else
			{
				matrix_char(0, c);
				matrix_char(1, c);
			}
			
			while(!(PINA & (1<<PINA0)));
		}
		else if(!(PINA & (1<<PINA1)))
		{
			_delay_ms(5);
			
			c--;
			
			if(c == 31)
			{
				matrix_prom_read(0, MATRIX_EEPROM_CHAR0);
				matrix_prom_read(1, MATRIX_EEPROM_CHAR0);
			}
			else if(c < 31)
			{
				c = 126;
				matrix_char(0, c);
				matrix_char(1, c);
			}
			else
			{
				matrix_char(0, c);
				matrix_char(1, c);
			}
			
			while(!(PINA & (1<<PINA1)));
		}
		else if(!(PINA & (1<<PINA2)))
		{
			_delay_ms(5);
			
			matrix_buffer_all(buffer);
		
			while(!(PINA & (1<<PINA2)));
		}
		else if(!(PINA & (1<<PINA3)))
		{
			_delay_ms(5);
			
			matrix_string("ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 !\"#$%&'()*+,-./:;<=>?@[\\]^_{|}~");
		
			while(!(PINA & (1<<PINA3)));
		}
		_delay_ms(5);
    }
}