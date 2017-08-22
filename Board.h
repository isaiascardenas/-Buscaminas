#pragma once
#include "BoardBlock.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct
{
    int rows;
    int columns;
    BoardBlock **matrix;
    void (*showBoard)(int, int, BoardBlock**);
    
} Board;

void ShowBoard(int rows, int columns, BoardBlock **matrix) {
	int i, j;
    printf("\n  ");
    for (j = 0; j < columns; ++j) {
            printf("%d ", j);
        }
        printf("\n");
	for (i = 0; i < rows; ++i) {
        printf("%d ",i );
     	for (j = 0; j < columns; ++j) {
            if (matrix[i][j].hidden) {
                printf("- ");
            } else if (!matrix[i][j].hidden && matrix[i][j].check) {
                printf("X");
            } else {
                printf("%c ", matrix[i][j].content);
            }
        	
    	}
    	printf("\n");
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
            board.matrix[x][y].content = '#';
            countBombs++;
        }
    }
} 

int unHide(Board board, int x, int y) {
    if (x+1>board.rows || y+1>board.columns || x<0 || y<0 || !board.matrix[x][y].hidden) {
        return 0;
    } else if (board.matrix[x][y].content =='#') {
        board.matrix[x][y].hidden = 0;
        return 1;
    } else if (board.matrix[x][y].content !=' ') {
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
        tempMatrix,
        ShowBoard
    };
    return board;
}
