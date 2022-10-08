#include <stdio.h>
#include <stdbool.h>
#include "logic.h"


void InitPanelMat(int panel_mat[3][3]) {
  for (int i = 0; i < 3; i++) {
	for (int j = 0; j < 3; j++) {
	  panel_mat[i][j] = 0;
	}
  }
}

void UpdatePanelMat(int panel_mat[3][3], int loc, int user) {
  panel_mat[loc / 3][loc % 3] = user;
}

int DetermineWinner(int panel_mat[3][3]) {
  int *rptr, *cptr;
  for (int i = 0; i < 3; i++) {
	rptr = panel_mat[i];
	if (*rptr == 0) {
	  continue;
	}
	if (*rptr == *(rptr + 1) && *rptr == *(rptr + 2)) {
		return *rptr;
	  }
  }
  for (int i = 0; i < 3; i++) {
	cptr = &panel_mat[0][i];
	if (*cptr == 0) {
	  continue;
	}
	if (*cptr == *(cptr + 3) && *cptr == *(cptr + 6)) {
	  return *cptr;
	}
  }
  int center = panel_mat[1][1];
  if (center != 0) {
	if (panel_mat[0][0] == center && panel_mat[2][2] == center) {
	  return center;
	}
	if (panel_mat[2][0] == center && panel_mat[0][2] == center) {
	  return center;
	}
  }
  for (int i = 0; i < 3; i++) {
	for (int j = 0; j < 3; j++) {
	  if (panel_mat[i][j] == 0) {
		return 0;
	  }
	}
  }
  return -1;
}