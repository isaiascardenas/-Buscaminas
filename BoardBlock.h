#pragma once

typedef struct
{
	int hidden;
	char content;
	int bomb;
	void (*setContent)(char, char*);
	
} BoardBlock;

void SetContent(char content, char *boardContent) {
	*boardContent = content;
	return ;
}

BoardBlock initBoardBlock() {
	BoardBlock board =  {
		1,
		'#',
		0,
		SetContent
	};
	return board;
}
