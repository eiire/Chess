#include "board.h"

void makemove (Board *array_chess)
{
	int i, j;
	int number_1, number_2;
	char letter_1, letter_2;
	int index_1, index_2;
	int flag = 1;
	char tire;
	printf("Введите координаты в формате откуда - куда: ");
	
	for (i = 0; i < 100000; i++) {

		scanf("%c%d", &letter_1, &number_1);
		scanf("%c", &tire);
		scanf("%c%d", &letter_2, &number_2);
		while (getchar() != '\n');

		// Проверка на правильность введенных данных
		if (tire == '-') {
			// Получение индексов начала и конца хода 
			index_1 = decode(letter_1, number_1);
			index_2 = decode(letter_2, number_2);
			flag = 1;
		}
		else {
			flag = 0;
			printf("Ошибка");
		}

		if (flag != 0) {
			// Перестановка элементов
			Board buffer;
			buffer = array_chess[index_2];
			array_chess[index_2] = array_chess[index_1];
			array_chess[index_1] = buffer;

			// Вывод доски
			printf("  A B C D E F G H\n");
			for (i = 0; i < 8; i++) {
    		  	printf("%d|", i+1);
    		    for (j = 0; j < 8; j++) {
    		        printf("%c|", array_chess[i*8+j].space);
    		    }
    		    printf ("\n");
    		}
    	}
	}
}

// Преобразовывает координаты в индекс элемента, находящийся в массиве(доска)
int decode (char letter, int number)
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