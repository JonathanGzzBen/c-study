#include <stdio.h>
#ifdef _WIN32
#include <stdlib.h>
#endif

#include "menu.h"

int main() {
#ifdef _WIN32
  system("chcp 65001 > nul");
#endif
  run_menu();
  return 0;
}