#include "matrix4x4.h"

ScaleMatrix::ScaleMatrix(double sx, double sy, double sz) : DiagonalMatrix(sx, sy, sz, 1) {}
