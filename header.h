// returns a random integer between n and m
int randint(int n, int m);

// initializes a matrix, allocating memory
char** init_matrix(int filas, int columnas);

// given a matrix, it randomizes the alives cells. this is intended for the fisrt frame
void randomize(char** matrix, int filas, int columnas);

// given a specific cell in the matrix and the respective matrix, it checks the status of the cell on the next frame
char dead_alive(char** array, int fila, int columna);

// applies the dead_alive() function to every cell, modifying the next frame based on the rules
void next_frame(char** actual, char** next, int filas, int columnas);
