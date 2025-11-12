#include <stdio.h>
#include <ncurses.h>

int main(void){
initscr();
int filas = LINES;
int columnas = COLS;
endwin();
printf("largo: %d\nalto: %d\n", columnas, filas);
return 0;
}
