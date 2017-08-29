#include "functions.h"

char validateInput(Board board, int *x, int *y) {
    char input;
	while(1) {
		printf("\nIngrese jugada >> ");
    	scanf("%d %d %c", x, y, &input);
    	if (*x<board.rows && *y<board.columns && *y>=0  && x>=0) {
            if ((input == 'O' && board.matrix[*x][*y].hidden) || (input == 'X')) {
                return input;
            } else {
                printf("\nLas jugadas válidas son X para marcar una bomba y O para descubrir la casilla\n");
            }   
	    }
        printf("\nJugada inválida, intente nuevamente");
	}
}

void validateBoard(int *rows, int *columns, int *bombs) {

    while(1) {
        printf("Ingrese cantidad de filas >> ");
        scanf("%d", rows);
        printf("Ingrese cantidad de columnas >> ");
        scanf("%d", columns);
        printf("Ingrese cantidad de bombas >> ");
        scanf("%d", bombs);

        if (*bombs < *rows * *columns - 1) {
            return ;
        } else {
            printf("\nTablero inválido, debe haber al menos 2 casillas sin bomba\n");
        }
    }
}

void writeFile(Board board) {
    FILE *file = fopen("solución.out", "w");

    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    fprintf(file, "\n");
    for (int i = 0; i < board.rows; ++i) {
        for (int j = 0; j < board.columns; ++j) {
            if (board.matrix[i][j].content == ' ') {
                fprintf(file, "%c ", '-');
            } else {
                fprintf(file, "%c ", board.matrix[i][j].content);
            }
        }
        fprintf(file, "\n");
    }
    fclose(file);
}
