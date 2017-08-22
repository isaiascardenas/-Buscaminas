#pragma once

typedef struct
{
	int hidden;
	char content;
	int bomb;
	int check;
	
} BoardBlock;

BoardBlock initBoardBlock() {
	BoardBlock block =  {
		1,
		' ',
		0,
		0
	};
	return block;
}
