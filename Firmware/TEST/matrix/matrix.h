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
 *   Header file for matrix library
 * -----------------------------------------
 */

#ifndef MATRIX_H_
#define MATRIX_H_

#ifndef F_CPU
	#define F_CPU 12000000UL
#endif

#ifndef MATRIX_DISPLAYS
	#define MATRIX_DISPLAYS 2
#endif

#ifndef MATRIX_CMD_NOP			// No operation
	#define MATRIX_CMD_NOP 0x00
#endif

#ifndef MATRIX_CMD_ROW_START	// Address of 1. row
	#define MATRIX_CMD_ROW_START 0x01
#endif

#ifndef MATRIX_CMD_ASCII		// Command for ASCII char as data
	#define MATRIX_CMD_ASCII 0x08
#endif

#ifndef MATRIX_CMD_CLEAR		// Command to CLEAR the Display
	#define MATRIX_CMD_CLEAR 0x09
#endif

#ifndef MATRIX_CMD_MODE			// Display on/off command
	#define MATRIX_CMD_MODE 0x10

	#ifndef MATRIX_DATA_MODE_ENABLE
		#define MATRIX_DATA_MODE_ENABLE 0x01
	#endif

	#ifndef MATRIX_DATA_MODE_DISABLE
		#define MATRIX_DATA_MODE_DISABLE 0x00
	#endif
#endif

#ifndef MATRIX_CMD_REFRESH		// Command to setup display refresh rate (0 - 127)
	#define MATRIX_CMD_REFRESH 0x11
#endif

#ifndef MATRIX_EEPROM_READ		// EEPROM read command
	#define MATRIX_EEPROM_READ 0x20
#endif

#ifndef MATRIX_EEPROM_WRITE		// EEPROM write command
	#define MATRIX_EEPROM_WRITE 0x30
#endif

#ifndef MATRIX_EEPROM_CHAR0	// EEPROM special character address 0
	#define MATRIX_EEPROM_CHAR0 0x00
#endif

#ifndef MATRIX_EEPROM_CHAR	// EEPROM special character address
	#define MATRIX_EEPROM_CHAR0  0x00
	#define MATRIX_EEPROM_CHAR1  0x01
	#define MATRIX_EEPROM_CHAR2  0x02
	#define MATRIX_EEPROM_CHAR3  0x03
	#define MATRIX_EEPROM_CHAR4  0x04
	#define MATRIX_EEPROM_CHAR5  0x05
	#define MATRIX_EEPROM_CHAR6  0x06
	#define MATRIX_EEPROM_CHAR7  0x07
	#define MATRIX_EEPROM_CHAR8  0x08
	#define MATRIX_EEPROM_CHAR9  0x09
	#define MATRIX_EEPROM_CHAR10 0x0A
	#define MATRIX_EEPROM_CHAR11 0x0B
	#define MATRIX_EEPROM_CHAR12 0x0C
	#define MATRIX_EEPROM_CHAR13 0x0D
	#define MATRIX_EEPROM_CHAR14 0x0E
	#define MATRIX_EEPROM_CHAR15 0x0F
#endif


#ifndef MATRIX_STRING_PAUSE		// Pause between characters (ms)
	#define MATRIX_STRING_PAUSE 1000
#endif

#include <avr/io.h>
#include <util/delay.h>
#include "../spi/spi.h"

void matrix_init();
void matrix_buffer(unsigned char display, unsigned char *buffer);
void matrix_buffer_all(unsigned char *buffer);
void matrix_char(unsigned char display, char data);
void matrix_string(const char *data);
void matrix_clear(unsigned char display);
void matrix_clear_all();
void matrix_prom_write(unsigned char display, unsigned char address, unsigned char *buffer);
void matrix_prom_read(unsigned char display, unsigned char address);
void matrix_transfer(unsigned char display, unsigned char transfer);
void matrix_transfer_all(unsigned char transfer);

#endif /* MATRIX_H_ */