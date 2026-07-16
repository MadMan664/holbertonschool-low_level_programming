#include "main.h"

/**
 * print_chessboard - prints a chessboard
 * @a: pointer to an 8x8 array of chars representing the board
 */
void print_chessboard(char (*a)[8])
{
	int row;
	int col;

	row = 0;
	while (row < 8)
	{
		col = 0;
		while (col < 8)
		{
			_putchar(a[row][col]);
			col++;
		}
		_putchar('\n');
		row++;
	}
}
