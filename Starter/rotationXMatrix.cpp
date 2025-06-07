#include "matrix4x4.h"

RotationXMatrix::RotationXMatrix(double angle) : Matrix4x4(1, 0, 0, 0,
	0, cos(angle), -sin(angle), 0,
	0, sin(angle), cos(angle), 0,
	0, 0, 0, 1) {
}
