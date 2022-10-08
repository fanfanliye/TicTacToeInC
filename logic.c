#include <stdlib.h>

#include "logic.h"

void InitGridMat(int grid_mat[3][3]) {
  for (int i = 0; i < 3; i++) {
	for (int j = 0; j < 3; j++) {
	  grid_mat[i][j] = 0;
	}
  }
}

void UpdateGridMat(int grid_mat[3][3], int loc, int player) {
  grid_mat[loc / 3][loc % 3] = player;
}

int DetermineWinner(int grid_mat[3][3]) {
  int *rptr, *cptr;
  for (int i = 0; i < 3; i++) {
	rptr = grid_mat[i];
	if (*rptr == 0) {
	  continue;
	}
	if (*rptr == *(rptr + 1) && *rptr == *(rptr + 2)) {
	  return *rptr;
	}
  }
  for (int i = 0; i < 3; i++) {
	cptr = &grid_mat[0][i];
	if (*cptr == 0) {
	  continue;
	}
	if (*cptr == *(cptr + 3) && *cptr == *(cptr + 6)) {
	  return *cptr;
	}
  }
  int center = grid_mat[1][1];
  if (center != 0) {
	if (grid_mat[0][0] == center && grid_mat[2][2] == center) {
	  return center;
	}
	if (grid_mat[2][0] == center && grid_mat[0][2] == center) {
	  return center;
	}
  }
  for (int i = 0; i < 3; i++) {
	for (int j = 0; j < 3; j++) {
	  if (grid_mat[i][j] == 0) {
		return 0;
	  }
	}
  }
  return -1;
}

int SimpleCPUAI(int grid_mat[3][3]) {
  // A simple AI that randomly choose a location from the current available spots
  int available_locs[9], count = 0;
  for (int i = 0; i < 3; i++) {
	for (int j = 0; j < 3; j++) {
	  if (grid_mat[i][j] == 0) {
		available_locs[count] = 3 * i + j;
		count++;
	  }
	}
  }
  return available_locs[rand() % count];
}
