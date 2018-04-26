#include "board.h"

int check_step(Board *array_chess, int index_1, int index_2)
{
	if ((array_chess[index_1].color == 1 && array_chess[index_2].color == 0)
			|| (array_chess[index_1].color == 0 && array_chess[index_2].color == 1)) {
		return 1;
	} else if ((array_chess[index_1].color == 1 && array_chess[index_2].color == 3)
			|| (array_chess[index_1].color == 0 && array_chess[index_2].color == 3)
			|| (array_chess[index_1].color == 3 && array_chess[index_2].color == 3)) {
		return 2;
	} else if ((array_chess[index_1].color == 1 && array_chess[index_2].color == 1)
			|| (array_chess[index_1].color == 0 && array_chess[index_2].color == 0)
			|| (array_chess[index_1].color == 3 && array_chess[index_2].color == 3)
			|| (array_chess[index_1].color == 3 && array_chess[index_2].color == 1)
			|| (array_chess[index_1].color == 3 && array_chess[index_2].color == 2)) {
		return 3;
	} else {
		return 3;
	}
}

int check_input(char letter_1, int number_1, char letter_2, int number_2, char tire)
{
	int i;
	int buffer = 0;
	int numbers[8] = {1, 2, 3, 4, 5, 6, 7, 8};
	char letters[8] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};

	if (tire != '-') {
		printf("Введены неверные данные, повторите попытку: ");
		return 1;
	}

	for (i = 0; i < 8; i++) {
		if (letter_1 == letters[i]) {
			buffer++;
		} 

		if (number_1 == numbers[i]) {
			buffer++;
		}

		if (letter_2 == letters[i]) {
			buffer++;
		}

		if (number_2 == numbers[i]) {
			buffer++;
		}
	}

	if (buffer == 4) {
		return 0;
	}
	else {
		printf("Введены неверные данные, повторите попытку: ");
		return 1;
	}
}

int check_move(Board *array_chess, int index_1, int index_2)
{
	if (array_chess[index_1].color == array_chess[index_2].color) {
		return 0;
	}

	if (array_chess[index_1].space == 'P' || array_chess[index_1].space == 'p') {
		if (array_chess[index_1].color == 1 && array_chess[index_2].color == 0) {
			if (index_1 + 9 == index_2) {
				return 1;
			} else if (index_1 + 7 == index_2) {
				return 1;
			} else {
				return 0;
			}
		} else if ((array_chess[index_1].color == 0 && array_chess[index_2].color == 1)) {
			if (index_1 - 9 == index_2) {
				return 1;
			} else if (index_1 - 7 == index_2) {
				return 1;
			} else {
				return 0;
			}
		} else if (array_chess[index_1].color == 1 && array_chess[index_2].color == 3) {
			if (index_1 + 8 == index_2) {
				return 1;
			} else if (index_1 + 16 == index_2) {
				return 1;
			} else {
				return 0;
			}
		} else if (array_chess[index_1].color == 0 && array_chess[index_2].color == 3) {
			if (index_1 - 8 == index_2) {
				return 1;
			} else if (index_1 - 16 == index_2) {
				return 1;
			} else {
				return 0;
			}
		}
	}

	if (array_chess[index_1].space == 'N' || array_chess[index_1].space == 'n') {
		if (array_chess[index_1].color == 1 && array_chess[index_2].color == 3) {
			if (index_1 + 17 == index_2) {
				return 1;
			} else if (index_1 + 10 == index_2) {
				return 1;
			} else if (index_1 - 17 == index_2) {
				return 1;
			} else if (index_1 - 10 == index_2) {
				return 1;
			} else {
				return 0;
			}
		}
	}

	return 1;
}