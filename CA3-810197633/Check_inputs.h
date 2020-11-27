#pragma once
#define the_number_of_rows 6
#define the_number_of_columns 6
int check_inputs_horizontal(char turn, int row, int column, char map[the_number_of_rows * 2 - 1][the_number_of_columns * 3 - 2]);
int check_input_vertical(char turn, int row, int column, char map[the_number_of_rows * 2 - 1][the_number_of_columns * 3 - 2]);