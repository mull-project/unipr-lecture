#ifndef UNIPR_LECTURE_MATRIX4D_H
#define UNIPR_LECTURE_MATRIX4D_H

struct Matrix4D {
  Matrix4D(const double *values) {
    int k = 0;
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        r[i][j] = values[k++];
      }
    }
  }
  double r[4][4];
};

#endif // UNIPR_LECTURE_MATRIX4D_H
