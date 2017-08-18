#pragma once
#include "BoardBlock.h"

typedef struct
{
    int rows;
    int columns;
    BoardBlock **matrix;
    void (*showBoard)(int, int, BoardBlock**);
    
} Board;

void ShowBoard(int rows, int columns, BoardBlock **matrix) {
	int i, j;
	for (i = 0; i < rows; ++i) {
     	for (j = 0; j < columns; ++j) {
        	printf("%c ", matrix[i][j].content);
    	}
    	printf("\n");
	}
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
        ShowBoard
    };
    return board;
}
