#include "File.h"
#include <cassert>

void run_tests() {
  File f;
  bool opened = f.open(__FILE__ ".empty");
  assert(opened);

  char buffer[5] = { 0 };
  f.getString(buffer, 4);
  assert(buffer[0] == '\0');
  assert(buffer[1] == '\0');
  assert(buffer[2] == '\0');
  assert(buffer[3] == '\0');
}

int main() {
  run_tests();
  return 0;
}
