void showMatrix(int rows, int columns, char ** matrix) {
	int i, j;
	for (i = 0; i < rows; ++i) {
     	for (j = 0; j < columns; ++j) {
        	printf("%c ", matrix[i][j]);
    	}
    	printf("\n");
	}
}

char ** createMatrix(int rows, int columns) {
	char **matrix = malloc(sizeof(char*)*rows);
    for(int i=0;i<rows; i++) 
        matrix[i] = malloc(sizeof(char)*columns); 

    return matrix;
}
