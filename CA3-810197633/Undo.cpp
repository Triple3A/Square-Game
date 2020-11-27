#include "graphics.h"
#include "Undo.h"
#include "turn.h"
#include <stdio.h>

void Undo(char pre_v_h, int row, int column, char map[the_number_of_rows * 2 - 1][the_number_of_columns * 3 - 2])
{
	setcolor(BLACK);
	switch (pre_v_h)
	{
	case '0':
		map[row * 2 - 2][column * 3 - 2] = ' ';
		map[row * 2 - 2][column * 3 - 1] = ' ';
		circle(column * 50 + 25, row * 50 + 25, 20);
		setfillstyle(SOLID_FILL, BLACK);
		floodfill(column * 50 + 25, row * 50 + 25, BLACK);
		circle(column * 50 + 25, row * 50 - 25, 20);
		setfillstyle(SOLID_FILL, BLACK);
		floodfill(column * 50 + 25, row * 50 - 25, BLACK);
		line(column * 50 + 2, row * 50, (column + 1) * 50 - 3, row * 50);
		break;
	case '1':
		map[row * 2 - 1][column * 3 - 3] = ' ';
		circle(column * 50 - 25, row * 50 + 25, 20);
		setfillstyle(SOLID_FILL, BLACK);
		floodfill(column * 50 - 25, row * 50 + 25, BLACK);
		circle(column * 50 + 25, row * 50 + 25, 20);
		setfillstyle(SOLID_FILL, BLACK);
		floodfill(column * 50 + 25, row * 50 + 25, BLACK);
		line(column * 50, row * 50 + 2, column * 50, (row + 1) * 50 - 3);
		break;
	}
}