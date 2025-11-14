#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ncurses.h>
#include "header.h"

// time between frames
#define TIMER 75

int main(void){
	initscr();
	srand((unsigned)time(NULL));

	int filas = LINES;
	int columnas = COLS;

	char** actual = init_matrix(filas, columnas);
	char** next = init_matrix(filas, columnas);
	char** temp;

	randomize(actual, filas, columnas);

	timeout(TIMER);
	for(;;){
		for (int i = 1; i <= filas; i++){
			mvaddstr(i-1, 0, &actual[i][1]);
		}
		refresh();
		char ch = getch();
		if (ch == 'q' || ch == 'Q') break;
		next_frame(actual, next, filas, columnas);

		temp = actual;
		actual = next;
		next = temp;
	}


	getch();
	endwin();
	return 0;
}
