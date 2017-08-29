HEADERS = ./src/functions.h ./src/Board.h ./src/BoardBlock.h ./src/Buscaminas.h

all: main.c $(HEADERS)
	gcc -o index.out ./src/functions.c ./src/Board.c ./src/Buscaminas.c ./src/BoardBlock.c main.c

clean:
	-rm -f index.out
	-rm -f solución.out
run: 
	./index.out
