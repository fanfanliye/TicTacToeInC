#include <stdio.h>

#include "interface.h"
#include "draw.h"

int main() {
  PrintStart();
  int mat[3][3] = {{0, 0, 1},
				   {0, 1, 2},
				   {1, 1, 0}};
  DrawPanel(mat);
  PrintGameOver("You");
  PrintEnd();
}
