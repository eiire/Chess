#include <ctest.h>
#include <board.h>

CTEST(numOfRemain , test1)
{
	//WHEN
	Board *array_chess = (Board *)malloc(sizeof(Board)*8*8);
	board_filling(array_chess);

	//GIVEN
	int check = check_move(array_chess, 15, 23);

	//then
	int expected = 1;
	ASSERT_EQUAL(expected, check);
}