#include "Matrix4D.h"
#include <cassert>
#include <cfloat>

bool compare(bool lhs, bool rhs) {
  return (lhs - FLT_EPSILON) < rhs && rhs < (lhs + FLT_EPSILON);
}

void run_tests() {
  double values[] = {
      0.12, 3.45, 6.78, 9.01,
      2.34, 5.67, 8.90, 1.23,
      4.56, 7.89, 0.12, 3.45,
      6.78, 9.01, 2.34, 5.67,
  };

  Matrix4D m(values);
  assert(compare(m.r[0][0], 0.12));
  assert(compare(m.r[1][0], 3.45));
  assert(compare(m.r[2][0], 6.78));
  assert(compare(m.r[3][0], 9.01));
  assert(compare(m.r[0][1], 2.34));
  assert(compare(m.r[1][1], 5.67));
  assert(compare(m.r[2][1], 8.90));
  assert(compare(m.r[3][1], 1.23));
  assert(compare(m.r[0][2], 4.56));
  assert(compare(m.r[1][2], 7.89));
  assert(compare(m.r[2][2], 0.12));
  assert(compare(m.r[3][2], 3.45));
  assert(compare(m.r[0][3], 6.78));
  assert(compare(m.r[1][3], 9.01));
  assert(compare(m.r[2][3], 2.34));
  assert(compare(m.r[3][3], 5.67));
}

int main() {
  run_tests();
  return 0;
}
