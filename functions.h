#pragma once
#include "Board.h"

char validateInput(Board board, int *x, int *y) {
    char input;
	while(1) {
		printf("\nIngrese jugada:   ");
    	scanf("%d %d %c", x, y, &input);
    	if (*x<board.rows && *y<board.columns && *y>=0  && x>=0 )//&& board.matrix[*x][*y].hidden)
	    {
            return input;
	    }
        printf("\nJugada inválida, intente nuevamente");
	}
}

void validateBoard(int *rows, int *columns, int *bombs) {

    while(1) {
        printf("Ingrese cantidad de filas:   ");
        scanf("%d", rows);
        printf("Ingrese cantidad de columnas:    ");
        scanf("%d", columns);
        printf("Ingrese cantidad de bombas:    ");
        scanf("%d", bombs);

        if (*bombs < *rows * *columns - 1)
        {
            return ;
        } else {
            printf("\nTablero inválido, debe haber al menos 2 casillas sin bomba\n");
        }
    }
}
