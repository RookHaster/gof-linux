#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ncurses.h>
#include "header.h"

// time between frames
#define TIMER 65

int main(void){
	initscr();
	srand((unsigned)time(NULL));

	int rows = LINES;
	int columns = COLS;

	// initializates both actual and next matrix
	char** actual_matrix = init_matrix(rows, columns);
	char** next_matrix = init_matrix(rows, columns);
	// defines a temp variable to swap actual and next matrix
	char** temp;

	randomize(actual_matrix, rows, columns);

	timeout(TIMER);
	for(;;){
		for (int i = 1; i <= rows; i++){
			// print each row
			mvaddstr(i-1, 0, &actual_matrix[i][1]);
		}
		refresh();
		// if pressed 'q' or 'Q' it breaks
		char ch = getch();
		if (ch == 'q' || ch == 'Q') break;
		//builds the next frame
		next_frame(actual_matrix, next_matrix, rows, columns);
		// swap the pointers
		temp = actual_matrix;
		actual_matrix = next_matrix;
		next_matrix = temp;
	}
	endwin();
	free_matrix(actual_matrix, rows);
	free_matrix(next_matrix, rows);
	return 0;
}
