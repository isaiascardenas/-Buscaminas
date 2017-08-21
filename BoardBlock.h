#pragma once

typedef struct
{
	int hidden;
	char content;
	int bomb;
	
} BoardBlock;

BoardBlock initBoardBlock() {
	BoardBlock block =  {
		1,
		'#',
		0
	};
	return block;
}
