#include "board.h"
#include <stdio.h>

void output (Board *array_chess)
{
	char width[8] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
	char white_f[8] = {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'};
	char white_p[8] = {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'};
	char black_f[8] = {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r',};
	char black_p[8] = {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'};

	// Заполнение шахматной доски
	for (int i = 0; i < 8; i++) {
		array_chess[i].space = white_f[i];
		array_chess[8*1 + i].space = white_p[i];
		array_chess[8*2 + i].space = ' ';
		array_chess[8*3 + i].space = ' ';
		array_chess[8*4 + i].space = ' ';
		array_chess[8*5 + i].space = ' ';
		array_chess[8*6 + i].space = black_p[i];
		array_chess[8*7 + i].space = black_f[i];
 	}

 	// Вывод доски
 	printf ("  A B C D E F G H\n");
 	for (int i = 0; i < 8; i++) {
 		printf("%d|", i+1);
 		for (int j = 0; j < 8; j++) {
 			printf("%c|", array_chess[i*8 + j].space);
 		}
 		printf ("\n");
 	}
}