#include <stdio.h>
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
}
return ret;
}

int dead_alive(char** array, int fila, int columna){
if (array[fila][columna] == ALIVE){
int vecinos = -1;
for (int f = fila-1; f <= fila+1; f++){
for (int c = columna-1; c <= columna+1; c++){
if (array[f][c] == ALIVE) vecinos++;
}
}
if (vecinos<2 || vecinos>3) return 0;
return 1;
}
else {
int vecinos = 0;
for (int f = fila-1; f <= fila+1; f++){
for (int c = columna-1; c <= columna+1; c++){
if (array[f][c] == ALIVE) vecinos++;
}
}
if (vecinos == 3) return 1;
return 0;
}
}

int main(void){
initscr();

int filas = LINES;
int columnas = COLS;

char** actual = init_matrix(filas, columnas);
char** next = init_matrix(filas, columnas);

endwin();
return 0;
}
