#include <stdio.h>
#include "map.h"
#define the_number_of_rows 6
#define the_number_of_columns 6

void show_map(char map[the_number_of_rows * 2 - 1][the_number_of_columns * 3 - 2])
{
	system("cls");
	int i, j;
	for (i = 0; i < the_number_of_rows * 2 - 1; i++)
	{
		for (j = 0; j < the_number_of_columns * 3 - 2; j++)
			printf("%c", map[i][j]);
		printf("\n");
	}
}
