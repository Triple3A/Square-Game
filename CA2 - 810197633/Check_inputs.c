#include <stdio.h>
#include "Check_inputs.h"
#define the_number_of_rows 6
#define the_number_of_columns 6

int check_inputs_horizontal(char turn, int row, int column, char map[the_number_of_rows * 2 - 1][the_number_of_columns * 3 - 2])
{
	if ((row > 0 && row <= the_number_of_rows) && (column > 0 && column < the_number_of_columns))
	{
		if (map[row * 2 - 2][column * 3 - 1] == ' ')
		{
			map[row * 2 - 2][column * 3 - 2] = '-';
			map[row * 2 - 2][column * 3 - 1] = '-';
			return 1;
		}
		else
		{
			printf("Wrong input. Player %c. Please enter coordinates again :\n", turn);
			return 0;
		}
	}
	else
	{
		printf("Wrong input. Player %c. Please enter coordinates again :\n", turn);
		return 0;
	}
}

int check_input_vertical(char turn, int row, int column, char map[the_number_of_rows * 2 - 1][the_number_of_columns * 3 - 2])
{
	if ((row > 0 && row < the_number_of_rows) && (column > 0 && column <= the_number_of_columns))
	{
		if (map[row * 2 - 1][column * 3 - 3] == ' ')
		{
			map[row * 2 - 1][column * 3 - 3] = '|';
			return 1;
		}
		else
		{
			printf("Wrong input. Player %c. Please enter coordinates again :\n", turn);
			return 0;
		}
	}
	else
	{
		printf("Wrong input. Player %c. Please enter coordinates again :\n", turn);
		return 0;
	}

}