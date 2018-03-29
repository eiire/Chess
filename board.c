#include "board.h"

int main()
{
    Board *array_chess = (Board *)malloc(sizeof(Board)*8*8);
    output(array_chess);
    makemove(array_chess);
    
    return 0;
}