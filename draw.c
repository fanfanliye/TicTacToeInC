#include <stdio.h>
#include <stdbool.h>

#include "draw.h"

const char MARKS[3] = {' ', MARK_1, MARK_2};

void DrawGrid(int grid_mat[3][3], bool draw_remain) {
  char mark;
  for (int i = 0; i < 5; i++) {
	for (int j = 0; j < 11; j++) {
	  if (i % 2 == 0) {
		if ((j + 1) % 4 == 0) {
		  printf("|");
		} else if (j % 4 == 1) {
		  if (draw_remain) {
			mark = grid_mat[i / 2][j / 4] > 0 ? ' ' : (char)(i / 2 * 3 + j / 4 + 1 + 48);
			printf("%c", mark);
		  } else {
			printf("%c", MARKS[grid_mat[i / 2][j / 4]]);
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
