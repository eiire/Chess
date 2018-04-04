all: program

program: build/board.o build/output_board.o build/makemove.o
	gcc -Wall build/board.o build/output_board.o build/makemove.o -o program

build/board.o: board.c
	gcc -Wall -c board.c -o build/board.o

build/output_board.o: output_board.c
	gcc -Wall -c output_board.c -o build/output_board.o

build/makemove.o: makemove.c
	gcc -Wall -c makemove.c -o build/makemove.o

.PHONY: clean
clean: 
	rm -rf build/*.o