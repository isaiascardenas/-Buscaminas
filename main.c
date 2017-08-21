#include <stdio.h>
#include <stdlib.h>
#include "Board.h"
#include "functions.h"
#include "BoardBlock.h"

int main() {
    int x, y, rows, columns, bombs;
    char input;
    Board board;

    validateBoard(&rows, &columns, &bombs);

    board = initBoard(rows, columns);

    for (x = 0; x < rows; x++) {
        for (y = 0; y < columns; y++) {
        	board.matrix[x][y] = initBoardBlock();
        }
    }

    board.showBoard(rows, columns, board.matrix);
    input = validateInput(board, &x, &y);
    board.matrix[x][y].hidden = 0;
    board.matrix[x][y].content = input;
    setBombs(board, bombs, x, y);
    board.showBoard(rows, columns, board.matrix);
    while(1) {

        input = validateInput(board, &x, &y);
        board.matrix[x][y].hidden = 0;
        board.matrix[x][y].content = input;

        board.showBoard(rows, columns, board.matrix);
    }
}

