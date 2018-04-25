#include "board.h"

void makemove(Board *array_chess)
{
	int priority = 1;
	int number_1, number_2;
	char letter_1, letter_2;
	int index_1, index_2;
	char tire;
	while (1) {
		int flag = 1;
		printf("Введите координаты в формате откуда - куда: ");
		while (flag == 1) {
			scanf("%c%d", &letter_1, &number_1);
			scanf("%c", &tire);
			scanf("%c%d", &letter_2, &number_2);
			flag = check_input(letter_1, number_1, letter_2, number_2, tire);
			while(getchar() != '\n');
		}

		// Получение индексов начала и конца хода 
		index_1 = decode(letter_1, number_1);
		index_2 = decode(letter_2, number_2);
		int flag_2 = check_move(array_chess, index_1, index_2);
		if (flag_2 == 1) {
			int flag_swap = check_step(array_chess, index_1, index_2);
			priority = swap(array_chess, index_1, index_2, flag_swap, priority);
			output_board(array_chess);
			//printf("%d\n", priority);
		}
		//output_board(array_chess);
	}
}

int swap(Board *array_chess, int index_1, int index_2, char flag_swap, int priority) {
	if ((array_chess[index_1].color == 1) && (priority == 1)) {
		if (flag_swap == 1) {
			array_chess[index_2].space = array_chess[index_1].space;
			array_chess[index_2].color = array_chess[index_1].color;
			array_chess[index_1].space = ' ';
			array_chess[index_1].color = 3;

		} else if (flag_swap == 2) {
			Board buffer;
			buffer.space = array_chess[index_2].space;
			buffer.color = array_chess[index_2].color;
			array_chess[index_2].space = array_chess[index_1].space;
			array_chess[index_2].color = array_chess[index_1].color;
			array_chess[index_1].space = buffer.space;
			array_chess[index_1].color = buffer.color;
		}
	//printf("%d\n", priority);
	return 0;
	} else if ((array_chess[index_1].color == 0) && (priority == 0)) {
		if (flag_swap == 1) {
			array_chess[index_2].space = array_chess[index_1].space;
			array_chess[index_2].color = array_chess[index_1].color;
			array_chess[index_1].space = ' ';
			array_chess[index_1].color = 3;

		} else if (flag_swap == 2) {
			Board buffer;
			buffer.space = array_chess[index_2].space;
			buffer.color = array_chess[index_2].color;
			array_chess[index_2].space = array_chess[index_1].space;
			array_chess[index_2].color = array_chess[index_1].color;
			array_chess[index_1].space = buffer.space;
			array_chess[index_1].color = buffer.color;
		}

	return 1;
	} else {
		printf("Долбаеб\n");
		return priority;
		//printf("%d\n", priority);
	}
}

// Преобразовывает координаты в индекс элемента, находящийся в массиве(доска)
int decode(char letter, int number)
{
	int i;
	int index;
	int width[8] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
	for(i = 0; i < 8; i++) {
		if (letter == width[i]) {
			index = i;
			index = (8 * (number - 1)) + index;
		}
	}

	return index;
}