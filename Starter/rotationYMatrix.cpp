#include "matrix4x4.h"

RotationYMatrix::RotationYMatrix(double angle) : Matrix4x4(cos(angle), 0, sin(angle), 0,
	0, 1, 0, 0,
	-sin(angle), 0, cos(angle), 0,
	0, 0, 0, 1) {}
