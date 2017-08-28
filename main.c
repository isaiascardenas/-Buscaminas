#include <stdio.h>
#include <stdlib.h>

#include "Board.h"
#include "functions.h"
#include "BoardBlock.h"

int main() {
    int x, y, rows, columns, bombs, win, play = 0;
    char input;
    Board board;

    validateBoard(&rows, &columns, &bombs);

    board = initBoard(rows, columns);

    for (x = 0; x < rows; x++) {
        for (y = 0; y < columns; y++) {
        	board.matrix[x][y] = initBoardBlock();
        }
    }

    showBoard(board);
    input = validateInput(board, &x, &y);
    setBombs(board, bombs, x, y);
    setNumbers(board);

    if(input == 'O') {
        if (board.matrix[x][y].hidden) {
            unHide(board, x, y);
        }
    } else if (input == 'X' && board.matrix[x][y].hidden) {
        if (board.matrix[x][y].check) {
            board.matrix[x][y].hidden  = 1;
            board.matrix[x][y].check = 0;
        } else {
            board.matrix[x][y].hidden = 0;
            board.matrix[x][y].check = 1;
        }
    }
    writeFile(board);
    showBoard(board);

    while(!play) {

        input = validateInput(board, &x, &y);

        if(input == 'O') {
            if (board.matrix[x][y].hidden) {
                play = unHide(board, x, y);
            }
        } else {
            if (board.matrix[x][y].check) {
                board.matrix[x][y].hidden  = 1;
                board.matrix[x][y].check = 0;
            } else {
                board.matrix[x][y].hidden = 0;
                board.matrix[x][y].content = input;
                board.matrix[x][y].check = 1;
            }
        }

        if (hiddenCount(board) == bombs) {
            play = 1;
            win = 1;
            if (board.matrix[x][y].bomb) {
                win = 0;
            }
        }
        showBoard(board);
    }

    if (win) {
        printf("\n\nGanaste :) !!\nFelicidades\n");
    } else {
        printf("\n\nPerdiste :\'( ...\nInténtalo de nuevo\n");
    }
    getchar();
    return 0;
}
