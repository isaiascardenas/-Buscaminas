#pragma once
#include "Board.h"

char validateInput(Board board, int *x, int *y);

void validateBoard(int *rows, int *columns, int *bombs);

void writeFile(Board board);
