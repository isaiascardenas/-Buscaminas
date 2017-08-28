#pragma once

typedef struct {
    int hidden;
    char content;
    int bomb;
    int check;
    
} BoardBlock;

BoardBlock initBoardBlock();
