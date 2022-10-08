#include <stdlib.h>
#include <time.h>

#include "interface.h"
#include "draw.h"
#include "logic.h"

int main() {
  srand(time(NULL));
  Game();
  return 0;
}
