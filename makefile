program: build/board.o build/output_board.o
	gcc -o program build/board.o build/output_board.o

build/board.o: board.c
	gcc -c board.c -o build/board.o

build/output.o: output_board.c
	gcc -c  output.c -o build/output_board.o