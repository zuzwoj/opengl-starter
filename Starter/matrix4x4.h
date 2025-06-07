#pragma once
#include "vector.h"
#include <algorithm>

class Matrix4x4
{
protected:
	double elems[4][4];

public:
	Matrix4x4(double a00, double a01, double a02, double a03,
		double a10, double a11, double a12, double a13,
		double a20, double a21, double a22, double a23,
		double a30, double a31, double a32, double a33);
	Matrix4x4();

	void transpose();
	void toArray(float* out);

	friend Matrix4x4 operator*(Matrix4x4 lhs, const Matrix4x4& rhs);
	friend Vector4 operator*(Matrix4x4 lhs, const Vector4& rhs);
};

class IdentityMatrix : public Matrix4x4
{
public:
	IdentityMatrix();
};

class RotationMatrix : public Matrix4x4
{
public:
	RotationMatrix(double ax, double ay, double az);
};

class TranslationMatrix : public Matrix4x4
{
public:
	TranslationMatrix(double tx, double ty, double tz);
};

class DiagonalMatrix : public Matrix4x4
{
public:
	DiagonalMatrix(double a0, double a1, double a2, double a3);
};

class ScaleMatrix : public DiagonalMatrix
{
public:
	ScaleMatrix(double sx, double sy, double sz);
};

class ProjectionMatrix : public Matrix4x4
{
public:
	ProjectionMatrix(double fov, double aspect, double near, double far);
};

class RotationXMatrix : public Matrix4x4
{
public:
	RotationXMatrix(double angle);
};

class RotationYMatrix : public Matrix4x4
{
public:
	RotationYMatrix(double angle);
};
