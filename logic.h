#ifndef TICTACTOEINC__LOGIC_H_
#define TICTACTOEINC__LOGIC_H_

void InitGridMat(int grid_mat[3][3]);

void UpdateGridMat(int grid_mat[3][3], int loc, int player);

int DetermineWinner(int grid_mat[3][3]);

int SimpleCPUAI(int grid_mat[3][3]);

#endif //TICTACTOEINC__LOGIC_H_
