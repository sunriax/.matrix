/* -----------------------------------------
 * G.Raf^engineering
 * www.sunriax.at
 * -----------------------------------------
 *    Platform: .matrix display controller
 *    Hardware: ATtiny406
 * -----------------------------------------
 *     Version: 1.0 Release
 *      Author: G.Raf
 * Description:
 *   Header file .matrix display library
 * -----------------------------------------
 */

#ifndef MATRIX_H_
#define MATRIX_H_

#include <stdlib.h>
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <avr/eeprom.h>

void matrix_setup();
void matrix_column(unsigned char column);
void matrix_column_clear();
void matrix_row(unsigned char row);
void matrix_row_clear();
void matrix_char2buffer(char character, volatile unsigned char *buffer);
void matrix_buffer2eeprom(volatile unsigned char *buffer, unsigned char address);
void matrix_eeprom2buffer(volatile unsigned char *buffer, unsigned char address);

#endif /* SETUP_H_ */