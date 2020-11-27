#pragma once
#define the_number_of_rows 6
#define the_number_of_columns 6

void left_square(char turn, int row, int column, char map[the_number_of_rows * 2 - 1][the_number_of_columns * 3 - 2]);
void right_square(char turn, int row, int column, char map[the_number_of_rows * 2 - 1][the_number_of_columns * 3 - 2]);
void down_square(char turn, int row, int column, char map[the_number_of_rows * 2 - 1][the_number_of_columns * 3 - 2]);
void up_square(char turn, int row, int column, char map[the_number_of_rows * 2 - 1][the_number_of_columns * 3 - 2]);
int square_check_horizontal(char turn, int row, int column, char map[the_number_of_rows * 2 - 1][the_number_of_columns * 3 - 2]);
int square_check_vertical(char turn, int row, int column, char map[the_number_of_rows * 2 - 1][the_number_of_columns * 3 - 2]);