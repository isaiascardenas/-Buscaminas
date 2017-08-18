#include <stdio.h>
#include <stdlib.h>
#include "Board.h"
#include "BoardBlock.h"

int main() {
    int i, j, rows, columns;
    Board board;
    BoardBlock **matrix;

    printf("Type the matrix rows:   ");
    scanf("%d", &rows);
    printf("Type the matrix columns:    ");
    scanf("%d", &columns);

    board = initBoard(rows, columns);

    // matrix = createMatrix(rows, columns);

    for (i = 0; i < rows; i++) {
        for (j = 0; j < columns; j++) {
        	board.matrix[i][j] = initBoardBlock();
        }
    }

    board.showBoard(rows, columns, board.matrix);

    // BoardBlock board = initBoardBlock();
    // printf("content1: %c\n", board.content);
    // board.setContent('h', &board.content);
    // printf("content2: %c\n", board.content);

}

