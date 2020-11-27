#include "graphics.h"
#include <stdio.h>
#include "map.h"
#include "Start.h"
void show_map(void)
{
	setfillstyle(SOLID_FILL, BLACK);
	floodfill(1, 1, GREEN);
	int i, j;
	setcolor(WHITE);
	for (i = 50; i <= the_number_of_rows *50; i+=50)
	{
		for (j = 50; j <= the_number_of_columns *50; j+=50)
		{
			circle(i, j, 2);
			setfillstyle(SOLID_FILL, WHITE);
			floodfill(i, j, WHITE);
		}
	}
	setcolor(LIGHTGRAY);
	outtextxy(350, 460, "Enter \"0 0 0\" to restart the game.");
	outtextxy(350, 480, "Enter \"0 0 1\" to return to main menu.");
	outtextxy(350, 500, "Enter \"0 0 2\" to exit the game.");
}

void main_menu(void)
{
	setfillstyle(SOLID_FILL, BLACK);
	floodfill(1, 1, GREEN);
	setcolor(LIGHTRED);
	outtextxy(100, 20, "Dots and Boxes!");
	setcolor(DARKGRAY);
	outtextxy(50, 60, "Please choose one of the following optoins:");
	setcolor(LIGHTGREEN);
	outtextxy(50, 80, "1) Start the game");
	setcolor(CYAN);
	outtextxy(50, 100, "2) Select the turn");
	setcolor(LIGHTBLUE);
	outtextxy(50, 120, "3) Exit");
	char turn;
	int option, f = 0, flag = 0;
	while (f == 0)
	{
		scanf("%d", &option);
		switch (option)
		{
		case 1:
			turn = 'A';
			f = 1;
			Start_game(turn);
			break;
		case 2:
			f = 1;
			setfillstyle(SOLID_FILL, BLACK);
			floodfill(1, 1, GREEN);
			outtextxy(50, 60, "Who is first? A or B?");
			while (flag == 0)
			{
				scanf("\n%c", &turn);
				if (turn == 'a' || turn == 'A')
				{
					turn = 'A';
					flag = 1;
				}
				else if (turn == 'b' || turn == 'B')
				{
					turn = 'B';
					flag = 1;
				}
				else
					printf("Wrong input. Please input A or B.\n");
			}
			Start_game(turn);
			break;
		case 3:
			f = 1;
			break;
		default:
			printf("Wrong input. You should input 1, 2 or 3.\n");
			break;
		}
	}
}