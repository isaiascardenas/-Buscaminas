#include "BoardBlock.h"
#include "Board.h"
#include <string.h>
#include <stdio.h>

void showBoard(Board board) {
    int i, j;

    if (board.rows < 11) {
        printf("\n | ");
        for (j = 0; j < board.columns; ++j) {
            printf("%d ", j);
        }
        printf("\n–|");
        for (j = 0; j < board.columns; ++j) {
            printf("––");
        }
        printf("–\n");
        for (i = 0; i < board.rows; ++i) {
            printf("%d| ",i );
            for (j = 0; j < board.columns; ++j) {
                if (!board.matrix[i][j].hidden && board.matrix[i][j].check) {
                    printf("X ");
                } else if (board.matrix[i][j].hidden) {
                    printf("~ ");
                } else {
                    printf("%c ", board.matrix[i][j].content);
                }
            }
            printf("\n");
        }
    } else {
        printf("\n  | ");
        for (j = 0; j < board.columns; ++j) {
            if (j < 10) {
                printf(" ");
            }
            printf("%d ", j);
        }
        printf("\n––|");
        for (j = 0; j < board.columns; ++j) {
            printf("–––");
        }
        printf("–\n");
        for (i = 0; i < board.rows; ++i) {
            if (i < 10) {
                printf(" ");
            }
            printf("%d| ",i );
            for (j = 0; j < board.columns; ++j) {
                if (!board.matrix[i][j].hidden && board.matrix[i][j].check) {
                    printf(" X ");
                } else if (board.matrix[i][j].hidden) {
                    printf(" ~ ");
                } else {
                    printf("%2c ", board.matrix[i][j].content);
                }
            }
            printf("\n");
        }
    }
}
int sumBombs(Board board, int x, int y) {
    int sum = 0;

    if (y-1 >= 0 && board.matrix[x][y-1].bomb)
        sum++;
    if (y-1 >= 0 && x+1 < board.rows && board.matrix[x+1][y-1].bomb)
        sum++;
    if (x+1 < board.rows && board.matrix[x+1][y].bomb)
        sum++;
    if (y+1 < board.columns && x+1 < board.rows && board.matrix[x+1][y+1].bomb)
        sum++;
    if (y+1 < board.columns && board.matrix[x][y+1].bomb)
        sum++;
    if (y+1 < board.columns && x-1 >= 0 && board.matrix[x-1][y+1].bomb)
        sum++;
    if (x-1 >= 0 && board.matrix[x-1][y].bomb)
        sum++;
    if (y-1 >= 0 && x-1 >=0 && board.matrix[x-1][y-1].bomb)
        sum++;
    return sum;
}

void setNumbers(Board board) {
    int number = 0;
    for (int i = 0; i < board.rows; ++i) {
        for (int j = 0; j < board.columns; ++j) {
            number = sumBombs(board, i, j);
            if (number > 0 && !board.matrix[i][j].bomb) {
                board.matrix[i][j].content = (char)number+'0';
            }
        }
    }
}

void setBombs(Board board, int bombs, int xUser, int yUser) {
    int x, y, countBombs = 0;
    while(countBombs < bombs) {
        x = rand()% board.rows;
        y = rand()% board.columns;
        if (! board.matrix[x][y].bomb && x!=xUser && y!=yUser) {
            board.matrix[x][y].bomb = 1;
            board.matrix[x][y].content = '*';
            countBombs++;
        }
    }
} 

int unHide(Board board, int x, int y) {
    if (x+1>board.rows || y+1>board.columns || x<0 || y<0 || !board.matrix[x][y].hidden) {
        return 0;
    } else if (board.matrix[x][y].content == '*') {
        board.matrix[x][y].hidden = 0;
        return 1;
    } else if (board.matrix[x][y].content != '\'') {
        board.matrix[x][y].hidden = 0;
        return 0;
    }

    board.matrix[x][y].hidden = 0;

    return unHide(board, x+1, y) +
    unHide(board, x-1, y) +
    unHide(board, x, y+1) +
    unHide(board, x, y-1);
}

int hiddenCount(Board board) {
    int count = 0;
    for (int i = 0; i < board.rows; ++i) {
        for (int j = 0; j < board.columns; ++j) {
            if (board.matrix[i][j].hidden) {
                count++;
            }
        }
    }
    return count;
}

Board initBoard(int rows, int columns) {
    BoardBlock **tempMatrix;
    tempMatrix = malloc(sizeof(BoardBlock*)*rows);

    for(int i=0; i<rows; i++) {
        tempMatrix[i] = malloc(sizeof(BoardBlock)*columns); 
    }
    Board board = {
        rows,
        columns,
        tempMatrix
    };
    return board;
}
