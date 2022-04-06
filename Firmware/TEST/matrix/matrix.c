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
	
	spi_select(SPI_Enable);
	spi_transfer(MATRIX_CMD_MODE);
	spi_transfer(MATRIX_DATA_MODE_ENABLE);
	spi_select(SPI_Disable);
	
	// Initial sequence
	unsigned char buffer[7] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
	
	for (unsigned char y=0; y < 7; y++)
	{
		for (unsigned char x=0; x < 5; x++)
		{
			buffer[y] |= (1<<(4 - x));
			matrix_buffer(buffer);
			_delay_ms(200);
		}
	}
}

void matrix_buffer(unsigned char *buffer)
{
	for (unsigned char i=0; i < 7; i++)
	{
		spi_select(SPI_Enable);
		spi_transfer((MATRIX_CMD_ROW_START + i));
		spi_transfer(buffer[i]);
		spi_select(SPI_Disable);
	}
}

void matrix_char(char data)
{
	spi_select(SPI_Enable);
	spi_transfer(MATRIX_CMD_ASCII);
	spi_transfer(data);
	spi_select(SPI_Disable);
}

void matrix_string(const char *data)
{
	do 
	{
		matrix_char(*data++);
		_delay_ms(MATRIX_STRING_PAUSE);
		
	} while (*data != '\0');
}

void matrix_clear()
{
	spi_select(SPI_Enable);
	spi_transfer(MATRIX_CMD_CLEAR);
	spi_transfer(0x00);
	spi_select(SPI_Disable);
}

void matrix_prom_write(unsigned char address, unsigned char *buffer)
{
	matrix_buffer(buffer);
	
	spi_select(SPI_Enable);
	spi_transfer(MATRIX_EEPROM_WRITE | (0x0F & address));
	spi_transfer(0x00);
	spi_select(SPI_Disable);
	_delay_ms(50);
}

void matrix_prom_read(unsigned char address)
{
	spi_select(SPI_Enable);
	spi_transfer(MATRIX_EEPROM_READ | (0x0F & address));
	spi_transfer(0x00);
	spi_select(SPI_Disable);
	_delay_ms(50);
}