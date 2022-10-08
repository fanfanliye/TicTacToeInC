#ifndef TICTACTOEINC__INTERFACE_H_
#define TICTACTOEINC__INTERFACE_H_

#endif //TICTACTOEINC__INTERFACE_H_

void PrintStart();

void GetUserName(int user_id, char* user_name);

void PrintGameOver(int winner_id, char* user_name_1, char* user_name_2);

void PrintEnd();

int GetUserInput(int panel_mat[3][3]);

void Game();

void GameLoop(int panel_mat[3][3], char* user_name_1, char* user_name_2);