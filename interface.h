#ifndef TICTACTOEINC__INTERFACE_H_
#define TICTACTOEINC__INTERFACE_H_

void PrintStart();

void GetPlayerName(int player_id, char* player_name);

void PrintGameOver(int winner_id, char* player_name_1, char* player_name_2);

void PrintEnd();

int GetPlayerInput(int grid_mat[3][3]);

void GameIterPlayer(int grid_mat[3][3], int player_id, char *player_name);

void GameIterCPU(int grid_mat[3][3]);

void Game();

void GameLoop(int grid_mat[3][3], char* player_name_1, char* player_name_2, char play_cpu);

#endif //TICTACTOEINC__INTERFACE_H_

