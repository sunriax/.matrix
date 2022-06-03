/* -----------------------------------------
 * G.Raf^engineering
 * www.sunriax.at
 * -----------------------------------------
 *    Platform: Megacard/STK500/STK600
 *    Hardware: ATmega??-????
 * -----------------------------------------
 *     Version: 1.0 Release
 *      Author: G.Raf
 * Description:
 *   Function file for matrix library
 * -----------------------------------------
 */

#include "matrix.h"

void matrix_init()
{
	// SPI Initialization
	//      Mode: SPI_Master
	// Direction: SPI_MSB
	//  Transfer: SPI_Rising/SPI_Rising
	//
	// Details can be found in spi.c
	spi_init(SPI_Master, SPI_MSB, SPI_Rising, SPI_Rising);

	matrix_transfer_all(MATRIX_CMD_MODE);
	matrix_transfer_all(MATRIX_DATA_MODE_ENABLE);	
	
	// Initial sequence
	unsigned char buffer[7] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
	
	for (unsigned char y=0; y < 7; y++)
	{
		for (unsigned char x=0; x < 5; x++)
		{
			buffer[y] |= (1<<(4 - x));
			matrix_buffer_all(buffer);
			_delay_ms(200);
		}
	}
}

void matrix_buffer(unsigned char display, unsigned char *buffer)
{
	for (unsigned char i=0; i < 7; i++)
	{
		matrix_transfer(display, (MATRIX_CMD_ROW_START + i));
		matrix_transfer(display, buffer[i]);
	}
}

void matrix_buffer_all(unsigned char *buffer)
{
	for (unsigned char i=0; i < 7; i++)
	{
		matrix_transfer_all((MATRIX_CMD_ROW_START + i));
		matrix_transfer_all(buffer[i]);
	}
}

void matrix_char(unsigned char display, char data)
{
	matrix_transfer(display, MATRIX_CMD_ASCII);
	matrix_transfer(display, data);
}

// Find a better solution!!!
void matrix_string(const char *data)
{
	unsigned char end = 0;
	unsigned char count = 0;
	
	do 
	{
		if(count == 0 && *data == '\0')
		{
			break;
		}
		
		if(data == '\0')
		{
			end++;
		}
		
		if(end > 0)
		{
			end++;
		}
		else
		{
			matrix_char(count, *data);
			data++;
		}
		
		if((++count) >= MATRIX_DISPLAYS)
		{
			count = 0;
			end = 0;
			data -= (MATRIX_DISPLAYS - 1);
			_delay_ms(MATRIX_STRING_PAUSE);
			matrix_clear_all();
		}
//#if MATRIX_DISPLAYS < 2
		//_delay_ms(MATRIX_STRING_PAUSE);
//#else
//#endif

	} while (1);
	
	matrix_clear_all();
}

void matrix_clear(unsigned char display)
{
	matrix_transfer(display, MATRIX_CMD_CLEAR);
	matrix_transfer(display, 0x00);
}

void matrix_clear_all()
{
	matrix_transfer_all(MATRIX_CMD_CLEAR);
	matrix_transfer_all(0x00);
}

void matrix_prom_write(unsigned char display, unsigned char address, unsigned char *buffer)
{
	matrix_buffer(display, buffer);
	
	matrix_transfer(display, MATRIX_EEPROM_WRITE | (0x0F & address));
	matrix_transfer(display, 0x00);
	_delay_ms(50);
}

void matrix_prom_read(unsigned char display, unsigned char address)
{
	matrix_transfer(display, MATRIX_EEPROM_READ | (0x0F & address));
	matrix_transfer(display, 0x00);
	_delay_ms(50);
}

void matrix_transfer(unsigned char display, unsigned char transfer)
{
	spi_select(SPI_Enable);
	for (unsigned char d=0; d < MATRIX_DISPLAYS; d++)
	{
		if(d == (MATRIX_DISPLAYS - 1 - display))
		{
			spi_transfer(transfer);
		}
		else
		{
			spi_transfer(0x00);
		}
	}
	spi_select(SPI_Disable);
}

void matrix_transfer_all(unsigned char transfer)
{
	spi_select(SPI_Enable);
	for (unsigned char d=0; d < MATRIX_DISPLAYS; d++)
	{
		spi_transfer(transfer);
	}
	spi_select(SPI_Disable);
}