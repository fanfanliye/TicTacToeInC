#include <stdio.h>
#include <stdbool.h>

#include "interface.h"
#include "draw.h"


void PrintStart() {
  printf("###############################\n");
  printf("Welcome to Tic-Tac-Toe!\n");
  printf("The game will start!\n");
}
void PrintGameOver(char* winner) {
  printf("Game Over!\n");
  printf("Winner is: %s!\n", winner);
}
void PrintEnd() {
  printf("Exiting game...\nDone!\n");
}

int GetUserInput(int panel_mat[3][3]) {
  printf("The current available panel:\n");
  DrawPanel(panel_mat, true);
  printf("Please select your location: ");
  int loc;
  scanf("%d", &loc);
  loc--;
  while (loc < 0 || loc >= 9 || panel_mat[loc / 3][loc % 3] > 0){
	printf("Not a valid location! Please select again: ");
	scanf("%d", &loc);
	loc--;
  }
  printf("OK, you select location: %d\n", loc + 1);
  return loc;
}