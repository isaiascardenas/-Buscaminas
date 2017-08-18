#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include "BoardBlock.h"

int main() {
    int i, j, rows, columns;
    char **matrix;

    printf("Type the matrix rows:   ");
    scanf("%d", &rows);
    printf("Type the matrix columns:    ");
    scanf("%d", &columns);

    matrix = createMatrix(rows, columns);

    for (i = 0; i < rows; i++) {
        for (j = 0; j < columns; j++) {
        	printf("[%d, %d]   ", i, j);
        	scanf("%s", &matrix[i][j]);
        }
    }

    // showMatrix(rows, columns, matrix);

    // BoardBlock board = initBoardBlock();
    // printf("content1: %c\n", board.content);
    // board.setContent('h', &board.content);
    // printf("content2: %c\n", board.content);

}

