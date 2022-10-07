#include <stdio.h>

#include "interface.h"


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

