#ifndef  BOARD_H
#define  BOARD_H

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct {
	char 	space;
	int  color;
} Board;

void board_filling(Board *mass);
void output_board(Board *array_chess);
void makemove(Board *mass);
int check_input(char letter_1, int number_1, char letter_2, int number_2, char tire);
int decode(char letter, int number);
int check_move(Board *array_chess, int index_1, int index_2);
int check_step(Board *array_chess, int index_1, int index_2);
int swap(Board *array_chess, int index_1, int index_2, char flag_swap, int priority);

#endif
