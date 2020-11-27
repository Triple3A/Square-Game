#include "graphics.h"
#include "Draw_line.h"
#include <stdio.h>
#include <stdlib.h>
#include "Square.h"
#include "map.h"
#include "turn.h"
#include "Check_inputs.h"
#include "Start.h"
int main()
{
	initwindow(600, 600, "Dots and Boxes!");
	main_menu();	
	return 0;
}