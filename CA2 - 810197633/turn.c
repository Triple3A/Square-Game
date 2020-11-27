#include <stdio.h>
#include "turn.h"

char change_turn(char turn)
{
	if (turn == 'A') return 'B';
	else return 'A';
}