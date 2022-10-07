#include <stdio.h>

#include "draw.h"


const char MARKS[3] = {' ', 'O', 'X'};

void DrawPanel(int panel_mat[3][3]) {
  for (int i = 0; i < 5; i++) {
	for (int j = 0; j < 11; j++) {
	  if (i % 2 == 0) {
		if ((j + 1) % 4 == 0) {
		  printf("|");
		} else if ( j % 4 == 1) {
		  printf("%c", MARKS[panel_mat[i / 2][j / 4]]);
		} else {
		  printf(" ");
		}
	  } else {
		if ((j + 1) % 4 == 0) {
		  printf("|");
		} else {
		  printf("-");
		}
	  }
	}
	printf("\n");
  }
}