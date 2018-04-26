#include <ctest.h>
#include <board.h>

CTEST(numOfRemain , test_step_hourse)
{
	// WHEN
	Board *array_chess = (Board *)malloc(sizeof(Board)*8*8);
	board_filling(array_chess);

	// GIVEN
	int check = check_move(array_chess, 1, 18);
	int check_folse = check_move(array_chess, 1, 22);

	// THEN
	int expected = 1;
	int expected_folse = 0;

	ASSERT_EQUAL(expected, check);
	ASSERT_EQUAL(expected_folse, check_folse);
}

CTEST(numOfRemain, test_step)
{
	// WHEN
	Board *array_chess = (Board *)malloc(sizeof(Board)*8*8);
	board_filling(array_chess);

	// GIVEN
	int check_one = check_step(array_chess, 11, 52);
	int check_two = check_step(array_chess, 11, 19);
	int check_three = check_step(array_chess, 11, 11);

	// THEN
	int expected_one = 1;
	int expected_two = 2;
	int expected_three = 3;

	ASSERT_EQUAL(expected_one, check_one);
	ASSERT_EQUAL(expected_two, check_two);
	ASSERT_EQUAL(expected_three, check_three);
}

CTEST(numOfRemain, test_pawn)
{
	// WHEN
	Board *array_chess = (Board *)malloc(sizeof(Board)*8*8);
	board_filling(array_chess);

	// GIVEN
	int check_p = check_move(array_chess, 12, 20);
	int check_p_folse = check_move(array_chess, 12, 19);

	// THEN
	int expected = 1;
	int expected_folse = 0;

	ASSERT_EQUAL(check_p, expected);
	ASSERT_EQUAL(check_p_folse, expected_folse);
}

CTEST(numOfRemain, check_decode)
{
	// WHEN
	Board *array_chess = (Board *)malloc(sizeof(Board)*8*8);
	board_filling(array_chess);

	// GIVEN
	int check = decode('b', 3);

	//THEN
	int expected = 17;

	ASSERT_EQUAL(check, expected);
}

CTEST(numOfRemain, check_priority_step)
{
	// WHEN
	Board *array_chess = (Board *)malloc(sizeof(Board)*8*8);
	board_filling(array_chess);

	// GIVEN
	int check = swap(array_chess, 0, 1, 0, 1);
	int check_2 = swap(array_chess, 63, 1, 0, 0);

	//THEN
	int expected = 0;
	int expected_2 = 1;

	ASSERT_EQUAL(check, expected);
	ASSERT_EQUAL(check_2, expected_2);
}

CTEST(numOfRemain, framework)
{
	// WHEN
	Board *array_chess = (Board *)malloc(sizeof(Board)*8*8);
	board_filling(array_chess);

	// GIVEN
	int check = check_input('e', 4, 'e', 5, '-');
	int check_2 = check_input('p', 4, 'e', 5, '-');

	//THEN
	int expected = 0;
	int expected_2 = 1;

	ASSERT_EQUAL(check, expected);
	ASSERT_EQUAL(check_2, expected_2);
}