#include "matrix4x4.h"
#include <cmath>

RotationMatrix::RotationMatrix(double ax, double ay, double az) 
	: Matrix4x4(cos(ay) * cos(az), sin(ax) * sin(ay) * cos(az) - cos(ax) * sin(az), cos(ax) * sin(ay) * cos(az) + sin(ax) * sin(az), 0.0f,
		cos(ay) * sin(az), sin(ax) * sin(ay)* sin(az) + cos(ax) * cos(az), cos(ax) * sin(ay) * sin(az) - sin(ax) * cos(az), 0.0f,
		-sin(ay), sin(ax) * cos(ay), cos(ax) * cos(ay), 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f) {}
