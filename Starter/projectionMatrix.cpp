#include "matrix4x4.h"
#include <cmath>

ProjectionMatrix::ProjectionMatrix(double fov, double aspect, double near, double far) 
	: Matrix4x4(1/(aspect * tan(fov/2)), 0.0f, 0.0f, 0.0f, 0.0f, 1/(tan(fov/2)), 0.0f, 0.0f, 0.0f, 0.0f, (far + near)/(near - far), 2 * far * near/(near - far), 0.0f, 0.0f, -1.0f, 0.0f) {}
	//Matrix4x4(aspect * tan(fov / 2), 0.0f, 0.0f, 0.0f, 0.0f, tan(fov / 2), 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f,  (far - near) / 2 * far * near, (far + near) / 2 * far * near) {}
