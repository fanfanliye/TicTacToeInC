#include <stdio.h>
#include <stdbool.h>

#include "draw.h"


const char MARKS[3] = {' ', 'O', 'X'};

void DrawPanel(int panel_mat[3][3], bool draw_remain) {
  char mark;
  for (int i = 0; i < 5; i++) {
	for (int j = 0; j < 11; j++) {
	  if (i % 2 == 0) {
		if ((j + 1) % 4 == 0) {
		  printf("|");
		} else if ( j % 4 == 1) {
		  if (draw_remain) {
			mark = panel_mat[i / 2][j / 4] > 0 ? ' ' : (char)(i / 2 * 3 + j / 4 + 1 + 48);
			printf("%c", mark);
		  } else {
			printf("%c", MARKS[panel_mat[i / 2][j / 4]]);
		  }
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
