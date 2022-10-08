#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "interface.h"
#include "draw.h"
#include "logic.h"

void PrintStart() {
  printf("###############################\n");
  printf("Welcome to Tic-Tac-Toe!\n");
  printf("The game will start!\n");
}

void GetUserName(int user_id, char *user_name) {
  printf("Please Enter the name for user %d (less than 20 chars): ", user_id);
  scanf("%s", user_name);
  printf("User %d name: %s\n", user_id, user_name);
}

void PrintGameOver(int winner_id, char *user_name_1, char *user_name_2) {
  printf("Game Over!\n");
  if (winner_id > 0) {
	printf("Winner is: %s!\n", winner_id - 1 ? user_name_2 : user_name_1);
  } else {
	printf("It is a draw!\n");
  }

}
void PrintEnd() {
  printf("Exiting game...\nDone!\n");
}

int GetUserInput(int grid_mat[3][3]) {
  printf("The current available spots:\n");
  DrawGrid(grid_mat, true);
  printf("Please select your location: ");
  int loc;
  scanf("%d", &loc);
  loc--;
  while (loc < 0 || loc >= 9 || grid_mat[loc / 3][loc % 3] > 0) {
	printf("Not a valid location! Please select again: ");
	scanf("%d", &loc);
	loc--;
  }
  printf("OK, you select location: %d\n", loc + 1);
  return loc;
}

void Game() {
  PrintStart();
  printf("Do you want to compete with Computer? (Y/N)\n");
  char play_cpu;
  char user_name_1[20], user_name_2[20];
  scanf(" %c", &play_cpu);
  if (play_cpu == 'Y' || play_cpu == 'y') {
	printf("OK, you will play against CPU.\n");
	play_cpu = 'Y';
  } else {
	printf("All right, I take that a NO.\n");
  }

  GetUserName(1, user_name_1);
  if (play_cpu == 'Y') {
	printf("User 2 will be CPU.\n");
	strcpy(user_name_2, "CPU");
  } else {
	GetUserName(2, user_name_2);
  }
  printf("######\n");
  printf("User 1: %s --- %c\n", user_name_1, MARK_1);
  printf("User 2: %s --- %c\n", user_name_2, MARK_2);
  printf("######\n");
  int grid_mat[3][3];
  InitGridMat(grid_mat);
  char play = 'Y';
  while (play == 'Y') {
	GameLoop(grid_mat, user_name_1, user_name_2, play_cpu);
	printf("Another round? (Y/N)\n");
	scanf(" %c", &play);
	if (play == 'Y' || play == 'y') {
	  printf("OK, a new game will be started!\n");
	  play = 'Y';
	  InitGridMat(grid_mat);
	} else {
	  printf("All right, I take that a NO.\n");
	}
  }
  PrintEnd();
}

void GameIterUser(int grid_mat[3][3], int user_id, char *user_name) {
  printf("-------------------\n");
  printf("It is your turn, %s:\n", user_name);
  int loc = GetUserInput(grid_mat);
  UpdateGridMat(grid_mat, loc, user_id);
  printf("Current Grid:\n");
  DrawGrid(grid_mat, false);
  printf("-------------------\n\n");
}


void GameIterCPU(int grid_mat[3][3]) {
  printf("-------------------\n");
  printf("It is CPU\'s turn!\n");
  int cpu_loc = SimpleCPUAI(grid_mat);;
  printf("He choose the location: %d\n", cpu_loc + 1);
  UpdateGridMat(grid_mat, cpu_loc, 2);
  printf("Current Grid:\n");
  DrawGrid(grid_mat, false);
  printf("-------------------\n\n");
}

void GameLoop(int grid_mat[3][3], char *user_name_1, char *user_name_2, char play_cpu) {
  printf("Let's start the game! We start from user 1.\n");
  int cur_user_id = 2;
  char *cur_user_name = user_name_2;
  while (DetermineWinner(grid_mat) == 0) {
	cur_user_id = 3 - cur_user_id;
	cur_user_name = cur_user_id == 1 ? user_name_1 : user_name_2;
	if (cur_user_id == 2 && play_cpu == 'Y') {
	  GameIterCPU(grid_mat);
	} else {
	  GameIterUser(grid_mat, cur_user_id, cur_user_name);
	}
  }
  PrintGameOver(DetermineWinner(grid_mat), user_name_1, user_name_2);
}