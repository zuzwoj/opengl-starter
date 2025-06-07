#include "vector.h"

Vector4::Vector4(double x, double y, double z, double t)
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->t = t;
}

Vector4::Vector4(Vector3 v)
{
	this->x = v.x;
	this->y = v.y;
	this->z = v.z;
	this->t = 1;
}

double Vector4::len() const
{
	return sqrt(x * x + y * y + z * z + t * t);
}

void Vector4::normalize()
{
	double l = len();
	if (l != 0)
	{
		x /= l;
		y /= l;
		z /= l;
		t /= l;
	}
}

Vector4 Vector4::operator-()
{
	return Vector4(-x, -y, -z, -t);
}

Vector4& Vector4::operator+=(const Vector4& rhs)
{
	this->x += rhs.x;
	this->y += rhs.y;
	this->z += rhs.z;
	this->t += rhs.t;
	return *this;
}

Vector4& Vector4::operator-=(const Vector4& rhs)
{
	this->x -= rhs.x;
	this->y -= rhs.y;
	this->z -= rhs.z;
	this->t += rhs.t;
	return *this;
}

Vector4 operator+(Vector4 lhs, const Vector4& rhs)
{
	lhs.x = rhs.x + lhs.x;
	lhs.y = rhs.y + lhs.y;
	lhs.z = rhs.z + lhs.z;
	lhs.t = rhs.t + lhs.t;
	return lhs;
}

Vector4 operator-(Vector4 lhs, const Vector4& rhs)
{
	lhs.x = rhs.x - lhs.x;
	lhs.y = rhs.y - lhs.y;
	lhs.z = rhs.z - lhs.z;
	lhs.t = rhs.t + lhs.t;
	return lhs;
}

Vector4 operator*(double lhs, const Vector4& rhs)
{
	return Vector4(rhs.x * lhs, rhs.y * lhs, rhs.z * lhs, rhs.t * lhs);
}

Vector4 operator*(Vector4 lhs, const double& rhs)
{
	return Vector4(lhs.x * rhs, lhs.y * rhs, lhs.z * rhs, lhs.t * rhs);
}

Vector4 operator/(Vector4 lhs, const double& rhs)
{
	return Vector4(lhs.x / rhs, lhs.y / rhs, lhs.z / rhs, lhs.t / rhs);
}

double operator*(Vector4 lhs, const Vector4& rhs)
{
	return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z + lhs.t * rhs.t;
}

