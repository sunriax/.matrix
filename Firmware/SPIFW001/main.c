
#define F_CPU 16000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include "matrix/matrix.h"

volatile unsigned char spi_command;
volatile unsigned char spi_data;
volatile unsigned char spi_pointer;

volatile unsigned char pixel_x;
volatile unsigned char pixel_y;
volatile unsigned char pixel_intensity;

volatile unsigned char copy;
volatile unsigned char intensity;
volatile unsigned char rate;

volatile unsigned char eeprom_save;
volatile unsigned char eeprom_load;

volatile unsigned char matrix[] = {
	0b00000,
	0b00000,
	0b00000,
	0b00000,
	0b00000,
	0b00000,
	0b00000
};

ISR(PORTA_PORT_vect)
{
	PORTA.OUTTGL = PIN5_bm;
	
	sei();	// Allow nested interrupts
	
	spi_pointer = 0;
	
	switch (spi_command)
	{
		case 0x01:	// ROW 1
		case 0x02:	// ROW 2
		case 0x03:	// ROW 3
		case 0x04:	// ROW 4
		case 0x05:	// ROW 5
		case 0x06:	// ROW 6
		case 0x07:	// ROW 7
			matrix[(spi_command - 1)] = spi_data;
		break;
		case 0x08:	// Initiate ASCII copy
			copy = spi_data;
		break;
		case 0x09:	// CLEAR
			for (unsigned char i=0; i < sizeof(matrix); i++)
			{
				matrix[i] = 0x00;
			}
		break;
		case 0x10:	// Display Enable
			if(0x01 & spi_data)
			{
				TCA0.SINGLE.CTRLA |= TCA_SINGLE_ENABLE_bm;
			}
			else
			{
				TCA0.SINGLE.CTRLA &= ~TCA_SINGLE_ENABLE_bm;
				matrix_row_clear();
				matrix_column_clear();
			}
		break;
		case 0x11:	// Display intensity
			intensity = (0x0F & spi_data);
		break;
		case 0x12:	// Display refresh rate
			TCA0.SINGLE.PER = 0xFF - (0x7F & spi_data);
		break;
		case 0x20:	// Copy matrix content to EEPROM
		case 0x21:
		case 0x22:
		case 0x23:
		case 0x24:
		case 0x25:
		case 0x26:
		case 0x27:
		case 0x28:
		case 0x29:
		case 0x2A:
		case 0x2B:
		case 0x2C:
		case 0x2D:
		case 0x2E:
		case 0x2F:
			eeprom_save = spi_command;
		break;
		case 0x30:	// Display EEPROM
		case 0x31:
		case 0x32:
		case 0x33:
		case 0x34:
		case 0x35:
		case 0x36:
		case 0x37:
		case 0x38:
		case 0x39:
		case 0x3A:
		case 0x3B:
		case 0x3C:
		case 0x3D:
		case 0x3E:
		case 0x3F:
			eeprom_load = spi_command;
		break;
		default:
		break;
	}
}

ISR(TCA0_OVF_vect)
{
	matrix_row_clear();
	matrix_column_clear();
	
	if((intensity + 1) % (++pixel_intensity))
	{
		matrix_row(pixel_y);
		
		if(0x01 & (matrix[pixel_y]>>(4-pixel_x)))
		{
			matrix_column(pixel_x);
		}
		
		pixel_x++;
		
		if(pixel_x >= 5)
		{
			pixel_y++;
			pixel_x = 0;
			
			if(pixel_y >= 7)
			{
				pixel_y = 0;
			}
		}
		
		pixel_intensity = 0;
	}
}

ISR(SPI0_INT_vect)
{	
	spi_pointer++;
	
	if(spi_pointer % 2)
	{
		spi_command = SPI0.DATA;
	}
	else
	{
		spi_data = SPI0.DATA;
		spi_pointer = 0;
	}
}


int main(void)
{
	// CLOCK Setup
	CPU_CCP = 0x9D;
	CLKCTRL.MCLKCTRLA = CLKCTRL_CLKSEL_OSC20M_gc;

	// PORT Setup
	matrix_setup();
	
	// TIMER Setup
	TCA0.SINGLE.PER = 0xFF;
	TCA0.SINGLE.INTCTRL = TCA_SINGLE_CMP0_bm;
	TCA0.SINGLE.CTRLA = TCA_SINGLE_CLKSEL_DIV1_gc;
	
	// SPI Setup
	PORTA.PIN4CTRL = PORT_PULLUPEN_bm | PORT_ISC_RISING_gc;
	SPI0.CTRLA = SPI_ENABLE_bm;
	SPI0.INTCTRL = SPI_IE_bm;
	
	// Enable interrupts globally
	sei();
	
	// Initial sequence
	for (unsigned char y=0; y < 7; y++)
	{
		for (unsigned char x=0; x < 5; x++)
		{
			matrix[y] |= (1<<(4-x));
			
			_delay_ms(25);
		}
	}
	
	while (1)
	{
		if(copy != '\0')
		{
			// Copy ASCII-char to array
			matrix_char2buffer(copy, matrix);
			copy = '\0';
		}
		
		if(eeprom_save != 0)
		{
			matrix_buffer2eeprom(matrix, (0x0F & eeprom_save));
			eeprom_save = 0;
		}
		
		if(eeprom_load != 0)
		{
			matrix_eeprom2buffer(matrix, (0x0F & eeprom_load));
			eeprom_load = 0;
		}
	}
}

