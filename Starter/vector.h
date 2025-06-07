#pragma once
#include <cmath>

class Vector3
{
public:
	double x;
	double y;
	double z;

	Vector3(double x, double y, double z);
	Vector3();

	double len() const;
	void normalize();
	Vector3 crossProduct(Vector3 rhs);

	Vector3 operator-();
	Vector3& operator+=(const Vector3& rhs);
	Vector3& operator-=(const Vector3& rhs);
	friend Vector3 operator+(Vector3 lhs, const Vector3& rhs);
	friend Vector3 operator-(Vector3 lhs, const Vector3& rhs);
	friend Vector3 operator*(double lhs, const Vector3& rhs);
	friend Vector3 operator*(Vector3 lhs, const double& rhs);
	friend Vector3 operator/(Vector3 lhs, const double& rhs);
	friend double operator*(Vector3 lhs, const Vector3& rhs);
};

class Vector4
{
public:
	double x;
	double y;
	double z;
	double t;

	Vector4(double x, double y, double z, double t);
	Vector4(Vector3 v);

	double len() const;
	void normalize();

	Vector4 operator-();
	Vector4& operator+=(const Vector4& rhs);
	Vector4& operator-=(const Vector4& rhs);
	friend Vector4 operator+(Vector4 lhs, const Vector4& rhs);
	friend Vector4 operator-(Vector4 lhs, const Vector4& rhs);
	friend Vector4 operator*(double lhs, const Vector4& rhs);
	friend Vector4 operator*(Vector4 lhs, const double& rhs);
	friend Vector4 operator/(Vector4 lhs, const double& rhs);
	friend double operator*(Vector4 lhs, const Vector4& rhs);
};
