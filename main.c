#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

#define CANTCELLS 5
#define ALIVE '#'
#define DEAD ' '

int randint(int n, int m){
return n + rand() % (m-n+1);
}

char** init_matrix(int filas, int columnas){
char** ret = malloc(sizeof(char*)*(filas+2));
for (int i = 0; i <= filas+2; i++){
ret[i] = malloc(sizeof(char)*(columnas+2));
for (int j = 0; j <= columnas+2; j++){
ret[i][j] = DEAD;
}
ret[i][columnas+2] = '\0';
}
return ret;
}

void randomize(char** matrix, int filas, int columnas){
for (int i = 1; i <= filas; i++){
for (int j = 1; j <= columnas; j++){
if (randint(0, CANTCELLS) == 1) matrix[i][j] = ALIVE;
}
}
}

char dead_alive(char** array, int fila, int columna){
if (array[fila][columna] == ALIVE){
int vecinos = -1;
for (int f = fila-1; f <= fila+1; f++){
for (int c = columna-1; c <= columna+1; c++){
if (array[f][c] == ALIVE) vecinos++;
}
}
if (vecinos<2 || vecinos>3) return DEAD;
return ALIVE;
}
else {
int vecinos = 0;
for (int f = fila-1; f <= fila+1; f++){
for (int c = columna-1; c <= columna+1; c++){
if (array[f][c] == ALIVE) vecinos++;
}
}
if (vecinos == 3) return ALIVE;
return DEAD;
}
}

void next_frame(char** actual, char** next, int filas, int columnas){
for (int i = 1; i <= filas; i++){
for (int j = 1; j <= columnas; j++){
next[i][j] = dead_alive(actual, i, j);
}
}
}

int main(void){
initscr();

int filas = LINES;
int columnas = COLS;

char** actual = init_matrix(filas, columnas);
char** next = init_matrix(filas, columnas);

randomize(actual, filas, columnas);

for (int i = 1; i <= filas; i++){
mvprintw(i, 0, "%s", actual[i]);
}

endwin();
return 0;
}
