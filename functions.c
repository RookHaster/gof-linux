#include <stdio.h>
#include <stdlib.h>

// frecuency of alive cells in the initial matrix
// greater values means less alive cells.
// lowest value is 0 (zero)
#define CANTCELLS 3
#define ALIVE '#'
#define DEAD ' '

// returns a random integer between n and m (both included)
int randint(int n, int m){
	return n + rand() % (m-n+1);
}

// initializes a matrix of chars, allocating rows * columns
char** init_matrix(int rows, int columns){
	char** matrix = malloc(sizeof(char*)*(rows+2));
	for (int i = 0; i < rows+2; i++){
		matrix[i] = malloc(sizeof(char)*(columns+2));
		for (int j = 0; j < columns+2; j++){
			matrix[i][j] = DEAD;
		}
		matrix[i][columns+1] = '\0';
	}
	return matrix;
}

// randomizes a matrix with dead and alive cells
void randomize(char** matrix, int rows, int columns){
	for (int i = 1; i <= rows; i++){
		for (int j = 1; j <= columns; j++){
			if (randint(0, CANTCELLS) == 0) matrix[i][j] = ALIVE;
		}
	}
}

// returns the cell status on the next frame based on the rules
char dead_alive(char** matrix, int row, int column){
	if (matrix[row][column] == ALIVE){
		int neighbors = -1;
		for (int i = row-1; i <= row+1; i++){
			for (int j = column-1; j <= column+1; j++){
				if (matrix[i][j] == ALIVE) neighbors++;
			}
		}
	if (neighbors<2 || neighbors>3) return DEAD;
	return ALIVE;
	}
	else {
		int neighbors = 0;
		for (int i = row-1; i <= row+1; i++){
			for (int j = column-1; j <= column+1; j++){
				if (matrix[i][j] == ALIVE) neighbors++;
			}
		}
		if (neighbors == 3) return ALIVE;
		return DEAD;
	}
}

// set the next frame calling to dead_alive function for each cell in actual_matrix
void next_frame(char** actual_matrix, char** next_matrix, int rows, int columns){
	for (int i = 1; i <= rows; i++){
		for (int j = 1; j <= columns; j++){
			next_matrix[i][j] = dead_alive(actual_matrix, i, j);
		}
	}
}

// frees the memory allocated for the matrix
void free_matrix(char** matrix, int rows){
	for (int i = 0; i<rows+2; i++) free(matrix[i]);
	free(matrix);
}















