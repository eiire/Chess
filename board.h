#ifndef  BOARD_H
#define  BOARD_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int 	space;
} Board;

void output (Board *mass);

void makemove (Board *mass);

int decode (char letter, int number);

#endif
