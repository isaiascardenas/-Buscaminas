#pragma once
#include "BoardBlock.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int rows;
    int columns;
    BoardBlock **matrix;  
} Board;

void showBoard(Board board);

int sumBombs(Board board, int x, int y);

void setNumbers(Board board);

void setBombs(Board board, int bombs, int xUser, int yUser);

int unHide(Board board, int x, int y);

int hiddenCount(Board board);

Board initBoard(int rows, int columns);
