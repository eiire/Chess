all: program bin/test

program: build/board.o build/output_board.o build/makemove.o build/checks.o
	gcc -Wall build/board.o build/output_board.o build/makemove.o build/checks.o -o program

build/board.o: src/board.c
	gcc -Wall -c src/board.c -o build/board.o

build/output_board.o: src/output_board.c
	gcc -Wall -c src/output_board.c -o build/output_board.o

build/makemove.o: src/makemove.c
	gcc -Wall -c src/makemove.c -o build/makemove.o

build/checks.o: src/checks.c
	gcc -Wall -c src/checks.c -o build/checks.o




bin/test: build/output_board.o build/makemove.o build/checks.o build/test.o build/ctest.o
	gcc -Wall build/output_board.o build/makemove.o build/checks.o build/test.o build/ctest.o -o bin/test

build/test.o: test/test.c
	gcc -Wall -c test/test.c -o build/test.o -Ithirdparty -Isrc

build/ctest.o: test/ctest.c
	gcc -Wall -c test/ctest.c -o build/ctest.o -Ithirdparty

test: bin/test
	bin/test




.PHONY: clean
clean: 
	rm -rf build/*.o