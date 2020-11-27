#include "graphics.h"
#include <stdio.h>
#include "Square.h"

/*square is created in the left side of the line*/
void left_square(char turn, int row, int column, char map[the_number_of_rows * 2 - 1][the_number_of_columns * 3 - 2])
{
	if (turn == 'A')
	{
		map[(row) * 2 - 1][(column-1) * 3 - 1] = 'A';
		setcolor(RED);
	}
	else
	{
		map[(row) * 2 - 1][(column - 1) * 3 - 1] = 'B';
		setcolor(BLUE);
	}
	circle(column * 50 - 25, row * 50 + 25, 20);
	if (turn == 'A')
	{
		setfillstyle(SOLID_FILL, RED);
		floodfill(column * 50 - 25, row * 50 + 25, RED);
	}
	else
	{
		setfillstyle(SOLID_FILL, BLUE);
		floodfill(column * 50 - 25, row * 50 + 25, BLUE);
	}
}
/*square is created in the right side of the line*/
void right_square(char turn, int row, int column, char map[the_number_of_rows * 2 - 1][the_number_of_columns * 3 - 2])
{
	if (turn == 'A')
	{
		map[row * 2 - 1][column * 3 - 1] = 'A';
		setcolor(RED);
	}
	else
	{
		map[row * 2 - 1][column * 3 - 1] = 'B';
		setcolor(BLUE);
	}
	circle(column * 50 + 25, row * 50 + 25, 20);
	if (turn == 'A')
	{
		setfillstyle(SOLID_FILL, RED);
		floodfill(column * 50 + 25, row * 50 + 25, RED);
	}
	else
	{
		setfillstyle(SOLID_FILL, BLUE);
		floodfill(column * 50 + 25, row * 50 + 25, BLUE);
	}
}
/*square is created in the bottom of the line*/
void down_square(char turn, int row, int column, char map[the_number_of_rows * 2 - 1][the_number_of_columns * 3 - 2])
{
	if (turn == 'A')
	{
		map[row * 2 - 1][column * 3 - 1] = 'A';
		setcolor(RED);
	}
	else
	{
		map[row * 2 - 1][column * 3 - 1] = 'B';
		setcolor(BLUE);
	}
	circle(column * 50 + 25, row * 50 + 25, 20);
	if (turn == 'A')
	{
		setfillstyle(SOLID_FILL, RED);
		floodfill(column * 50 + 25, row * 50 + 25, RED);
	}
	else
	{
		setfillstyle(SOLID_FILL, BLUE);
		floodfill(column * 50 + 25, row * 50 + 25, BLUE);
	}
}
/*square is created in the top of the line*/
void up_square(char turn, int row, int column, char map[the_number_of_rows * 2 - 1][the_number_of_columns * 3 - 2])
{
	if (turn == 'A')
	{
		map[(row - 1) * 2 - 1][(column) * 3 - 1] = 'A';
		setcolor(RED);
	}
	else
	{
		map[(row - 1) * 2 - 1][(column) * 3 - 1] = 'B';
		setcolor(BLUE);
	}
	circle(column * 50 + 25, row * 50 - 25, 20);
	if (turn == 'A')
	{
		setfillstyle(SOLID_FILL, RED);
		floodfill(column * 50 + 25, row * 50 - 25, RED);
	}
	else
	{
		setfillstyle(SOLID_FILL, BLUE);
		floodfill(column * 50 + 25, row * 50 - 25, BLUE);
	}
}

int square_check_horizontal(char turn, int row, int column, char map[the_number_of_rows * 2 - 1][the_number_of_columns * 3 - 2])
{
	int f = 0;
	if (row == 1)
	{
		/*check the square*/
		if (map[row * 2 - 1][column * 3 - 3] == '|' && map[row * 2 - 1][column * 3] == '|' && map[row * 2][column * 3 - 2] == '-')
		{
			down_square(turn, row, column, map);
			f++;
		}
	}
	else if (row == the_number_of_rows)
	{
		/*check th square*/
		if (map[(row - 1) * 2 - 1][column * 3 - 3] == '|' && map[(row - 1) * 2 - 1][column * 3] == '|' && map[(row - 1) * 2 - 2][column * 3 - 1] == '-')
		{
			up_square(turn, row, column, map);
			f++;
		}
	}
	else
	{
		/*check the square*/
		if (map[row * 2 - 1][column * 3 - 3] == '|' && map[row * 2 - 1][column * 3] == '|' && map[row * 2][column * 3 - 1] == '-')
		{
			down_square(turn, row, column, map);
			f++;
		}
		/*check the square*/
		if (map[(row - 1) * 2 - 1][column * 3 - 3] == '|' && map[(row - 1) * 2 - 1][column * 3] == '|' && map[(row - 1) * 2 - 2][column * 3 - 1] == '-')
		{
			up_square(turn, row, column, map);
			f++;
		}
	}
	return f;
}

int square_check_vertical(char turn, int row, int column, char map[the_number_of_rows * 2 - 1][the_number_of_columns * 3 - 2])
{
	int f = 0;
	if (column == 1)
	{
		/*check the square*/
		if (map[row * 2 - 2][column * 3 - 1] == '-' && map[row * 2][column * 3 - 1] == '-' && map[row * 2 - 1][column * 3] == '|')
		{
			right_square(turn, row, column, map);
			f++;
		}
	}
	else if (column == the_number_of_columns)
	{
		/*check the square*/
		if (map[row * 2 - 2][(column - 1) * 3 - 1] == '-' && map[row * 2][(column - 1) * 3 - 1] == '-' && map[row * 2 - 1][(column - 1) * 3 - 3] == '|')
		{
			f++;
			left_square(turn, row, column, map);
		}
	}
	else
	{
		/*check the square*/
		if (map[row * 2 - 2][column * 3 - 1] == '-' && map[row * 2][column * 3 - 1] == '-' && map[row * 2 - 1][column * 3] == '|')
		{
			f++;
			right_square(turn, row, column, map);
		}
		/*check the square*/
		if (map[row * 2 - 2][(column - 1) * 3 - 1] == '-' && map[row * 2][(column - 1) * 3 - 1] == '-' && map[row * 2 - 1][(column - 1) * 3 - 3] == '|')
		{
			f++;
			left_square(turn, row, column, map);
		}
	}
	return f;
}


