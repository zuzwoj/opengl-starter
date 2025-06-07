#include "matrix4x4.h"
#include <cmath>

Matrix4x4::Matrix4x4(
	double a00, double a01, double a02, double a03,
	double a10, double a11, double a12, double a13,
	double a20, double a21, double a22, double a23,
	double a30, double a31, double a32, double a33)
{
	elems[0][0] = a00;
	elems[1][0] = a10;
	elems[2][0] = a20;
	elems[3][0] = a30;

	elems[0][1] = a01;
	elems[1][1] = a11;
	elems[2][1] = a21;
	elems[3][1] = a31;

	elems[0][2] = a02;
	elems[1][2] = a12;
	elems[2][2] = a22;
	elems[3][2] = a32;

	elems[0][3] = a03;
	elems[1][3] = a13;
	elems[2][3] = a23;
	elems[3][3] = a33;
}

Matrix4x4::Matrix4x4() : Matrix4x4(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f) {}

void Matrix4x4::transpose()
{
	std::swap(elems[0][1], elems[1][0]);
	std::swap(elems[0][2], elems[2][0]);
	std::swap(elems[0][3], elems[3][0]);
	std::swap(elems[1][2], elems[2][1]);
	std::swap(elems[1][3], elems[3][1]);
	std::swap(elems[2][3], elems[3][2]);
}

void Matrix4x4::toArray(float* out)
{
	out[0] = (float)elems[0][0];
	out[1] = (float)elems[0][1];
	out[2] = (float)elems[0][2];
	out[3] = (float)elems[0][3];

	out[4] = (float)elems[1][0];
	out[5] = (float)elems[1][1];
	out[6] = (float)elems[1][2];
	out[7] = (float)elems[1][3];

	out[8] = (float)elems[2][0];
	out[9] = (float)elems[2][1];
	out[10] = (float)elems[2][2];
	out[11] = (float)elems[2][3];

	out[12] = (float)elems[3][0];
	out[13] = (float)elems[3][1];
	out[14] = (float)elems[3][2];
	out[15] = (float)elems[3][3];
}

Matrix4x4 operator*(Matrix4x4 lhs, const Matrix4x4& rhs)
{
	Matrix4x4 result = Matrix4x4(
		lhs.elems[0][0] * rhs.elems[0][0] + lhs.elems[0][1] * rhs.elems[1][0] + lhs.elems[0][2] * rhs.elems[2][0] + lhs.elems[0][3] * rhs.elems[3][0],
		lhs.elems[0][0] * rhs.elems[0][1] + lhs.elems[0][1] * rhs.elems[1][1] + lhs.elems[0][2] * rhs.elems[2][1] + lhs.elems[0][3] * rhs.elems[3][1],
		lhs.elems[0][0] * rhs.elems[0][2] + lhs.elems[0][1] * rhs.elems[1][2] + lhs.elems[0][2] * rhs.elems[2][2] + lhs.elems[0][3] * rhs.elems[3][2],
		lhs.elems[0][0] * rhs.elems[0][3] + lhs.elems[0][1] * rhs.elems[1][3] + lhs.elems[0][2] * rhs.elems[2][3] + lhs.elems[0][3] * rhs.elems[3][3],

		lhs.elems[1][0] * rhs.elems[0][0] + lhs.elems[1][1] * rhs.elems[1][0] + lhs.elems[1][2] * rhs.elems[2][0] + lhs.elems[1][3] * rhs.elems[3][0],
		lhs.elems[1][0] * rhs.elems[0][1] + lhs.elems[1][1] * rhs.elems[1][1] + lhs.elems[1][2] * rhs.elems[2][1] + lhs.elems[1][3] * rhs.elems[3][1],
		lhs.elems[1][0] * rhs.elems[0][2] + lhs.elems[1][1] * rhs.elems[1][2] + lhs.elems[1][2] * rhs.elems[2][2] + lhs.elems[1][3] * rhs.elems[3][2],
		lhs.elems[1][0] * rhs.elems[0][3] + lhs.elems[1][1] * rhs.elems[1][3] + lhs.elems[1][2] * rhs.elems[2][3] + lhs.elems[1][3] * rhs.elems[3][3],

		lhs.elems[2][0] * rhs.elems[0][0] + lhs.elems[2][1] * rhs.elems[1][0] + lhs.elems[2][2] * rhs.elems[2][0] + lhs.elems[2][3] * rhs.elems[3][0],
		lhs.elems[2][0] * rhs.elems[0][1] + lhs.elems[2][1] * rhs.elems[1][1] + lhs.elems[2][2] * rhs.elems[2][1] + lhs.elems[2][3] * rhs.elems[3][1],
		lhs.elems[2][0] * rhs.elems[0][2] + lhs.elems[2][1] * rhs.elems[1][2] + lhs.elems[2][2] * rhs.elems[2][2] + lhs.elems[2][3] * rhs.elems[3][2],
		lhs.elems[2][0] * rhs.elems[0][3] + lhs.elems[2][1] * rhs.elems[1][3] + lhs.elems[2][2] * rhs.elems[2][3] + lhs.elems[2][3] * rhs.elems[3][3],

		lhs.elems[3][0] * rhs.elems[0][0] + lhs.elems[3][1] * rhs.elems[1][0] + lhs.elems[3][2] * rhs.elems[2][0] + lhs.elems[3][3] * rhs.elems[3][0],
		lhs.elems[3][0] * rhs.elems[0][1] + lhs.elems[3][1] * rhs.elems[1][1] + lhs.elems[3][2] * rhs.elems[2][1] + lhs.elems[3][3] * rhs.elems[3][1],
		lhs.elems[3][0] * rhs.elems[0][2] + lhs.elems[3][1] * rhs.elems[1][2] + lhs.elems[3][2] * rhs.elems[2][2] + lhs.elems[3][3] * rhs.elems[3][2],
		lhs.elems[3][0] * rhs.elems[0][3] + lhs.elems[3][1] * rhs.elems[1][3] + lhs.elems[3][2] * rhs.elems[2][3] + lhs.elems[3][3] * rhs.elems[3][3]);
	return result;
}

Vector4 operator*(Matrix4x4 lhs, const Vector4& rhs)
{
	return Vector4(
		lhs.elems[0][0] * rhs.x + lhs.elems[0][1] * rhs.y + lhs.elems[0][2] * rhs.z + lhs.elems[0][3] * rhs.t,
		lhs.elems[1][0] * rhs.x + lhs.elems[1][1] * rhs.y + lhs.elems[1][2] * rhs.z + lhs.elems[1][3] * rhs.t,
		lhs.elems[2][0] * rhs.x + lhs.elems[2][1] * rhs.y + lhs.elems[2][2] * rhs.z + lhs.elems[2][3] * rhs.t,
		lhs.elems[3][0] * rhs.x + lhs.elems[3][1] * rhs.y + lhs.elems[3][2] * rhs.z + lhs.elems[3][3] * rhs.t
	);
}
