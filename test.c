#include <stdio.h>
#include <stdlib.h>
#include "Board.h"
#include "BoardBlock.h"

int main() {
    int x, y, rows, columns;
    char user;
    Board board;
    BoardBlock **matrix;

    printf("Type the matrix rows:   ");
    scanf("%d", &rows);
    printf("Type the matrix columns:    ");
    scanf("%d", &columns);

    board = initBoard(rows, columns);

    for (x = 0; x < rows; x++) {
        for (y = 0; y < columns; y++) {
        	board.matrix[x][y] = initBoardBlock();
        }
    }

    board.showBoard(rows, columns, board.matrix);

    while(1) {
        printf("\nIngrese jugada:   ");
        scanf("%d %d %c", &x, &y, &user);
        board.changeBlock(x, y, user, board.matrix);
        board.showBoard(rows, columns, board.matrix);
    }
}

