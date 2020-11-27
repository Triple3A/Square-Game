#include "graphics.h"
#include <stdio.h>
#include <stdlib.h>
#include "turn.h"
#include "Start.h"
#include "map.h"

char change_turn(char turn)
{
	if (turn == 'A') return 'B';
	else return 'A';
}

void show_turn(char turn)
{
	if (turn == 'A')
	{
		setcolor(RED);
		outtextxy(144, 450, "PLAYER A ");
	}
	else
	{
		setcolor(BLUE);
		outtextxy(144, 450, "PLAYER B ");
	}
	circle(175, 415, 30);
	if (turn == 'A')
	{
		setfillstyle(SOLID_FILL, RED);
		floodfill(175, 415, RED);
	}
	else
	{
		setfillstyle(SOLID_FILL, BLUE);
		floodfill(175, 415, BLUE);
	}
}
void show_winner(int square_A, int square_B)
{
	delay(1000);
	char a[3], b[3];
	a[2] = '\0';
	b[2] = '\0';
	a[1] =(char) ((square_A % 10) + 48);
	if (square_A / 10 == 0) a[0] = ' ';
	else
		a[0] = (char) ((square_A / 10) + 48);
	b[1] = (char)((square_B % 10) + 48);
	if (square_B / 10 == 0) b[0] = ' ';
	else
		b[0] = (char)((square_B / 10) + 48);
	setfillstyle(SOLID_FILL, BLACK);
	floodfill(1, 1, GREEN);
	setcolor(RED);
	circle(50, 50, 15);
	setfillstyle(SOLID_FILL, RED);
	floodfill(50, 50, RED);
	outtextxy(70, 50, "PLAYER A:");
	outtextxy(150, 50, a);
	setcolor(BLUE);
	circle(450, 50, 15);
	setfillstyle(SOLID_FILL, BLUE);
	floodfill(450, 50, BLUE);
	outtextxy(470, 50, "PLAYER B:");
	outtextxy(550, 50, b);
	if (square_A > square_B)
	{
		setcolor(RED);
		circle(300, 200, 40);
		setfillstyle(SOLID_FILL, RED);
		floodfill(300, 200, RED);
		outtextxy(225, 250, "PLAYER A is the winner!");
	}
	else
	{
		setcolor(BLUE);
		circle(300, 200, 40);
		setfillstyle(SOLID_FILL, BLUE);
		floodfill(300, 200, BLUE);
		outtextxy(225, 250, "PLAYER B is the winner!");
	}
	setcolor(LIGHTGRAY);
	outtextxy(100, 460, "Enter \'r\' to restart the game.");
	outtextxy(100, 480, "Enter \'q\' to return to main menu.");
	outtextxy(100, 500, "Enter \'e\' to exit the game.");
	char input;
	int f = 0;
	while (f == 0)
	{
		scanf("\n%c", &input);
		switch (input)
		{
		case 'r':
			f = 1;
			printf("The gmae is restarted.\n");
			Start_game('A');
			break;
		case 'q':
			f = 1;
			main_menu();
			break;
		case 'e':
			f = 1;
			break;
		default:
			printf("Wrong input. Please input r, q or e.\n");
			break;
		}
	}
	delay(1000);
}