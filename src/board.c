#include "board.h"

int main()
{
    Board *array_chess = (Board *)malloc(sizeof(Board)*8*8);
    board_filling(array_chess);
    output_board(array_chess);
    makemove(array_chess);
    
    return 0;
}