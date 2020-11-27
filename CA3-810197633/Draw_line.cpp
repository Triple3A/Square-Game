#include "graphics.h"
#include "Draw_line.h"

void horizontal_line(int column, int row, char turn)
{
	if (turn == 'A')
		setcolor(RED);
	else
		setcolor(BLUE);
	line(column * 50 + 2, row * 50, (column + 1) * 50 - 3, row * 50);
}

void vertical_line(int column, int row, char turn)
{
	if (turn == 'A')
		setcolor(RED);
	else
		setcolor(BLUE);
	line(column * 50, row * 50 + 2, column * 50, (row + 1) * 50 - 3);
}