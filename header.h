int randint(int n, int m);

char** init_matrix(int rows, int columns);

void randomize(char** matrix, int filas, int columnas);

char dead_alive(char** matrix, int row, int column);

void next_frame(char** actual_matrix, char** next_matrix, int rows, int columns);
