
#include "matrix.h"

const __flash unsigned char A[] = {
	0b1111110,
	0b0001001,
	0b0001001,
	0b0001001,
	0b1111110
	};

const __flash unsigned char B[] = {
	0b1111111,
	0b1001001,
	0b1001001,
	0b1001001,
	0b0110110
};

const __flash unsigned char C[] = {
	0b0111110,
	0b1000001,
	0b1000001,
	0b1000001,
	0b1000001
};

const __flash unsigned char D[] = {
	0b1111111,
	0b1000001,
	0b1000001,
	0b1000001,
	0b0111110
};

const __flash unsigned char E[] = {
	0b1111111,
	0b1001001,
	0b1001001,
	0b1001001,
	0b1001001
};

const __flash unsigned char F[] = {
	0b0111111,
	0b0001001,
	0b0001001,
	0b0001001,
	0b0000001
};

const __flash unsigned char G[] = {
	0b0111110,
	0b1000001,
	0b1001001,
	0b1001001,
	0b1111001
};

const __flash unsigned char H[] = {
	0b1111111,
	0b0001000,
	0b0001000,
	0b0001000,
	0b1111111
};

const __flash unsigned char I[] = {
	0b0000000,
	0b1000001,
	0b1111111,
	0b1000001,
	0b0000000
};

const __flash unsigned char J[] = {
	0b0100000,
	0b1000000,
	0b1000000,
	0b1000000,
	0b0111111
};

const __flash unsigned char K[] = {
	0b1111111,
	0b0001000,
	0b0010100,
	0b0100010,
	0b1000001
};

const __flash unsigned char L[] = {
	0b1111111,
	0b1000000,
	0b1000000,
	0b1000000,
	0b1000000
};

const __flash unsigned char M[] = {
	0b1111111,
	0b0000110,
	0b1111000,
	0b0000110,
	0b1111111
};

const __flash unsigned char N[] = {
	0b1111111,
	0b0000011,
	0b0011100,
	0b1100000,
	0b1111111
};

const __flash unsigned char O[] = {
	0b0111110,
	0b1000001,
	0b1000001,
	0b1000001,
	0b0111110
};

const __flash unsigned char P[] = {
	0b1111111,
	0b0001001,
	0b0001001,
	0b0001001,
	0b0000110
};

const __flash unsigned char Q[] = {
	0b0111110,
	0b1000001,
	0b1000001,
	0b1100001,
	0b1111110
};

const __flash unsigned char R[] = {
	0b1111111,
	0b0011001,
	0b0101001,
	0b1001001,
	0b0000110
};

const __flash unsigned char S[] = {
	0b1000110,
	0b1001001,
	0b1001001,
	0b1001001,
	0b0110001
};

const __flash unsigned char T[] = {
	0b0000001,
	0b0000001,
	0b1111111,
	0b0000001,
	0b0000001
};

const __flash unsigned char U[] = {
	0b0111111,
	0b1000000,
	0b1000000,
	0b1000000,
	0b0111111
};

const __flash unsigned char V[] = {
	0b0000011,
	0b0011100,
	0b1100000,
	0b0011100,
	0b0000011
};

const __flash unsigned char W[] = {
	0b0111111,
	0b1000000,
	0b0111111,
	0b1000000,
	0b0111111
};

const __flash unsigned char X[] = {
	0b1000001,
	0b0110110,
	0b0011100,
	0b0110110,
	0b1000001
};

const __flash unsigned char Y[] = {
	0b0000001,
	0b0000010,
	0b1111100,
	0b0000010,
	0b0000001
};

const __flash unsigned char Z[] = {
	0b1100001,
	0b1010001,
	0b1001001,
	0b1000101,
	0b1000011
};

const __flash unsigned char ZERO[] = {
	0b0111110,
	0b1000001,
	0b1000001,
	0b1000001,
	0b0111110
};

const __flash unsigned char ONE[] = {
	0b0001000,
	0b0000100,
	0b0000010,
	0b1111111,
	0b0000000
};

const __flash unsigned char TWO[] = {
	0b1100010,
	0b1010001,
	0b1001001,
	0b1000101,
	0b1000010
};

const __flash unsigned char THREE[] = {
	0b0000000,
	0b1000001,
	0b1001001,
	0b1001001,
	0b0110110
};

const __flash unsigned char FOUR[] = {
	0b0011000,
	0b0010100,
	0b0010010,
	0b1111111,
	0b0010000
};

const __flash unsigned char FIVE[] = {
	0b1001111,
	0b1001001,
	0b1001001,
	0b1001001,
	0b0110001
};

const __flash unsigned char SIX[] = {
	0b0111110,
	0b1001001,
	0b1001001,
	0b1001001,
	0b0110000
};

const __flash unsigned char SEVEN[] = {
	0b1100001,
	0b0110001,
	0b0011001,
	0b0001101,
	0b0000111
};

const __flash unsigned char EIGHT[] = {
	0b0110110,
	0b1001001,
	0b1001001,
	0b1001001,
	0b0110110
};

const __flash unsigned char NINE[] = {
	0b1000110,
	0b1001001,
	0b1001001,
	0b1001001,
	0b0111110
};

void matrix_setup()
{
	PORTA.DIRSET = PIN7_bm | PIN6_bm | PIN5_bm;
	PORTB.DIRSET = PIN5_bm | PIN4_bm | PIN3_bm | PIN2_bm | PIN1_bm | PIN0_bm;
	PORTC.DIRSET = PIN3_bm | PIN2_bm | PIN1_bm | PIN0_bm;
}

void matrix_row_clear()
{
	PORTA.OUTSET = PIN7_bm | PIN6_bm;
	PORTB.OUTSET = PIN3_bm | PIN1_bm | PIN0_bm;
	PORTC.OUTSET = PIN3_bm | PIN0_bm;
}

void matrix_row(unsigned char row)
{
	switch (row)
	{
		case 1:
			PORTB.OUTCLR = PIN7_bm;
		break;
		case 2:
			PORTA.OUTCLR = PIN6_bm;
		break;
		case 3:
			PORTB.OUTCLR = PIN3_bm;
		break;
		case 4:
			PORTB.OUTCLR = PIN0_bm;
		break;
		case 5:
			PORTC.OUTCLR = PIN3_bm;
		break;
		case 6:
			PORTC.OUTCLR = PIN0_bm;
		break;
		default:
			PORTA.OUTCLR = PIN7_bm;
		break;
	}
}

void matrix_column_clear()
{
	PORTB.OUTCLR = PIN5_bm | PIN4_bm | PIN2_bm;
	PORTC.OUTCLR = PIN2_bm | PIN1_bm;
}

void matrix_column(unsigned char column)
{
	switch (column)
	{
		case 1:
			PORTC.OUTCLR = PIN1_bm;
		break;
		case 2:
			PORTB.OUTCLR = PIN4_bm;
		break;
		case 3:
			PORTB.OUTCLR = PIN5_bm;
		break;
		case 4:
			PORTC.OUTCLR = PIN2_bm;
		break;
		default:
			PORTB.OUTCLR = PIN2_bm;
		break;
	}
}

void matrix_char2buffer(char character, volatile unsigned char *buffer)
{
	char temp[5];
	
	switch (character)
	{
		case 'A':
		case 'a':
			memcpy_P(temp, A, sizeof(temp));
			break;
		case 'B':
		case 'b':
			memcpy_P(temp, B, sizeof(temp));
			break;
		case 'C':
		case 'c':
			memcpy_P(temp, C, sizeof(temp));
			break;
		case 'D':
		case 'd':
			memcpy_P(temp, D, sizeof(temp));
			break;
		case 'E':
		case 'e':
			memcpy_P(temp, E, sizeof(temp));
			break;
		case 'F':
		case 'f':
			memcpy_P(temp, F, sizeof(temp));
			break;
		case 'G':
		case 'g':
			memcpy_P(temp, G, sizeof(temp));
			break;
		case 'H':
		case 'h':
			memcpy_P(temp, H, sizeof(temp));
			break;
		case 'I':
		case 'i':
			memcpy_P(temp, I, sizeof(temp));
			break;
		case 'J':
		case 'j':
			memcpy_P(temp, J, sizeof(temp));
			break;
		case 'K':
		case 'k':
			memcpy_P(temp, K, sizeof(temp));
			break;
		case 'L':
		case 'l':
			memcpy_P(temp, L, sizeof(temp));
			break;
		case 'M':
		case 'm':
			memcpy_P(temp, M, sizeof(temp));
			break;
		case 'N':
		case 'n':
			memcpy_P(temp, N, sizeof(temp));
			break;
		case 'O':
		case 'o':
			memcpy_P(temp, O, sizeof(temp));
			break;
		case 'P':
		case 'p':
			memcpy_P(temp, P, sizeof(temp));
			break;
		case 'Q':
		case 'q':
			memcpy_P(temp, Q, sizeof(temp));
			break;
		case 'R':
		case 'r':
			memcpy_P(temp, R, sizeof(temp));
			break;
		case 'S':
		case 's':
			memcpy_P(temp, S, sizeof(temp));
			break;
		case 'T':
		case 't':
			memcpy_P(temp, T, sizeof(temp));
			break;
		case 'U':
		case 'u':
			memcpy_P(temp, U, sizeof(temp));
			break;
		case 'V':
		case 'v':
			memcpy_P(temp, V, sizeof(temp));
			break;
		case 'W':
		case 'w':
			memcpy_P(temp, W, sizeof(temp));
			break;
		case 'X':
		case 'x':
			memcpy_P(temp, X, sizeof(temp));
			break;
		case 'Y':
		case 'y':
			memcpy_P(temp, Y, sizeof(temp));
			break;
		case 'Z':
		case 'z':
			memcpy_P(temp, Z, sizeof(temp));
			break;
		case '0':
			memcpy_P(temp, ZERO, sizeof(temp));
			break;
		case '1':
			memcpy_P(temp, ONE, sizeof(temp));
			break;
		case '2':
			memcpy_P(temp, TWO, sizeof(temp));
			break;
		case '3':
			memcpy_P(temp, THREE, sizeof(temp));
			break;
		case '4':
			memcpy_P(temp, FOUR, sizeof(temp));
			break;
		case '5':
			memcpy_P(temp, FIVE, sizeof(temp));
			break;
		case '6':
			memcpy_P(temp, SIX, sizeof(temp));
			break;
		case '7':
			memcpy_P(temp, SEVEN, sizeof(temp));
			break;
		case '8':
			memcpy_P(temp, EIGHT, sizeof(temp));
			break;
		case '9':
			memcpy_P(temp, NINE, sizeof(temp));
			break;
	}
	
	for (unsigned char y=0; y < 7; y++)
	{
		buffer[y] = 0x00;
		
		for (unsigned char x=0; x < 5; x++)
		{
			buffer[y] |= (temp[x]<<(6 - y));
		}
	}
}

