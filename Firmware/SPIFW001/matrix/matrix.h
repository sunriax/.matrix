
#ifndef MATRIX_H_
#define MATRIX_H_

#include <stdlib.h>
#include <avr/io.h>
#include <avr/pgmspace.h>

void matrix_setup();
void matrix_column(unsigned char column);
void matrix_column_clear();
void matrix_row(unsigned char row);
void matrix_row_clear();
void matrix_char2buffer(char character, volatile unsigned char *buffer);

#endif /* SETUP_H_ */