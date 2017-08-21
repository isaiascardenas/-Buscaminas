#pragma once
#include "BoardBlock.h"

typedef struct
{
    int rows;
    int columns;
    BoardBlock **matrix;
    void (*showBoard)(int, int, BoardBlock**);
    void (*changeBlock)(int, int, char, BoardBlock**);
    
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
        	printf("%c ", matrix[i][j].content);
    	}
    	printf("\n");
	}
}

void ChangeBlock(int x, int y, char content, BoardBlock **matrix) {
    matrix[x][y].setContent(content, &matrix[x][y].content);
}

int CanChange(int x, int y, int rows, int columns, BoardBlock **matrix) {
    if (x > rows || y > columns)
    {
        /* code */
    }
    
    return 0;
}

Board initBoard(int rows, int columns) {
    BoardBlock **tempMatrix;
    tempMatrix = malloc(sizeof(BoardBlock*)*rows);

    for(int i=0;i<rows; i++) 
        tempMatrix[i] = malloc(sizeof(BoardBlock)*columns); 
    Board board = {
        rows,
        columns,
        tempMatrix,
        ShowBoard,
        ChangeBlock
    };
    return board;
}
