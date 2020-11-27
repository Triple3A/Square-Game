#include "Start.h"
#include "graphics.h"
#include "Draw_line.h"
#include <stdio.h>
#include <stdlib.h>
#include "Square.h"
#include "map.h"
#include "turn.h"
#include "Check_inputs.h"
#include "Undo.h"

int Start_game(char turn)
{
	char copy_turn = turn;
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
	char v_h, pre_v_h;
	int row, column;
	int flag = 0, a = 0, pre_a;
	int square = 0, square_A = 0, square_B = 0;
	show_map();
	while (square_A + square_B < (the_number_of_columns - 1) * (the_number_of_rows - 1))
	{
		show_turn(turn);
		printf("Player %c. Please enter coordinates :\n", turn);
		flag = 0;
		/*"flag = 1" means inputs are correct*/
		while (flag == 0)
		{
			scanf("\n%c", &v_h);
			pre_a = a;
			a = 0;
			switch (v_h)
			{
			case '0':
				scanf("%d %d", &row, &column);
				if (row == 0)
				{
					if (column == 0)
					{
						printf("The game is restarted\n");
						Start_game(copy_turn);
						return 0;
					}
					else if (column == 1)
					{
						main_menu();
						return 0;
					}
					else if (column == 2)
						return 1;
				}
				flag = check_inputs_horizontal(turn, row, column, map);
				/*if the inputs are correct check if the square is created*/
				if (flag == 1)
				{
					a = square_check_horizontal(turn, row, column, map);
					horizontal_line(column, row, turn);
				}
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
			case '1':
				scanf("%d %d", &row, &column);
				flag = check_input_vertical(turn, row, column, map);
				/*if the inputs are correct check if the square is created*/
				if (flag == 1)
				{
					a = square_check_vertical(turn, row, column, map);
					vertical_line(column, row, turn);
				}
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
			case 'u':
				Undo(pre_v_h, row, column, map);
				flag = 1;
				if (turn == 'A')
					square_A -= pre_a;
				else
					square_B -= pre_a;
				if (pre_a != 0) turn = change_turn(turn);
				break;
			default:
				printf("Wrong input. Player %c. Please enter coordinates again :\n", turn);
				break;
			}
			pre_v_h = v_h;
		}
		if (square == 0)
			turn = change_turn(turn);
		square = 0;
	}
	printf("Player A : %d\n", square_A);
	printf("Player B : %d\n", square_B);
	if (square_A > square_B)
		printf("Player A won the game!\n");
	else
		printf("Player B won the game!\n");
	show_winner(square_A, square_B);
	return 0;
}