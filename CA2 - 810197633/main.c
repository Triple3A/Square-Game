#include <stdio.h>
#include <stdlib.h>
#include "Square.h"
#include "map.h"
#include "turn.h"
#include "Check_inputs.h"
#define the_number_of_rows 6
#define the_number_of_columns 6

int main()
{
	char map[the_number_of_rows * 2 - 1][the_number_of_columns * 3 - 2];
	int i, j;
	for (i = 0; i < the_number_of_rows * 2 - 1; i++)
		for (j = 0; j < the_number_of_columns * 3 - 2; j++)
		{
			if (i % 2 == 0 && j % 3 == 0)
				map[i][j] = '*';
			else
				map[i][j] = ' ';
		}
	int v_h, row, column;
	int flag = 0, a = 0;
	int square = 0, square_A = 0, square_B = 0;
	char turn = 'A';
	while (square_A + square_B < (the_number_of_columns - 1) * (the_number_of_rows - 1))
	{
		show_map(map);
		printf("Player %c. Please enter coordinates :\n", turn);
		flag = 0;
		/*"flag = 1" means inputs are correct*/
		while (flag == 0)
		{
			scanf("%d %d %d", &v_h, &row, &column);
			switch (v_h)
			{
			case 0:
				flag = check_inputs_horizontal(turn, row, column, map);
				/*if the inputs are correct check if the square is created*/
				if (flag == 1) a = square_check_horizontal(turn, row, column, map);
				if (turn == 'A')
				{
					square_A += a;
					square = a;/*square is created*/
				}
				else
				{
					square_B += a;
					square = a;/*square is created*/
				}
				break;
			case 1:
				flag = check_input_vertical(turn, row, column, map);
				/*if the inputs are correct check if the square is created*/
				if (flag == 1) a = square_check_vertical(turn, row, column, map);
				if (turn == 'A')
				{
					square_A += a;
					square = a;/*square is created*/
				}
				else
				{
					square_B += a;
					square = a;/*square is created*/
				}
				break;
			default:
				printf("Wrong input. Player %c. Please enter coordinates again :\n", turn);
				break;
			}
		}
		if (square == 0)
			turn = change_turn(turn);
		square = 0;
	}
	show_map(map);
	printf("Player A : %d\n", square_A);
	printf("Player B : %d\n", square_B);
	if (square_A > square_B)
		printf("Player A won the game!");
	else
		printf("Player B won the game!");
	return 0;
}