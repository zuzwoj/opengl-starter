#include "vector.h"

Vector3::Vector3(double x, double y, double z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

Vector3::Vector3()
{
	this->x = 0;
	this->y = 0;
	this->z = 0;
}

double Vector3::len() const
{
	return sqrt(x * x + y * y + z * z);
}

void Vector3::normalize()
{
	double l = len();
	if (l != 0)
	{
		x /= l;
		y /= l;
		z /= l;
	}
}

Vector3 Vector3::crossProduct(Vector3 rhs)
{
	return Vector3(y * rhs.z - z * rhs.y, z * rhs.x - x * rhs.z, x * rhs.y - y * rhs.x);
}

Vector3 Vector3::operator-()
{
	return Vector3(-x, -y, -z);
}

Vector3& Vector3::operator+=(const Vector3& rhs)
{
	this->x += rhs.x;
	this->y += rhs.y;
	this->z += rhs.z;
	return *this;
}

Vector3& Vector3::operator-=(const Vector3& rhs)
{
	this->x -= rhs.x;
	this->y -= rhs.y;
	this->z -= rhs.z;
	return *this;
}

Vector3 operator+(Vector3 lhs, const Vector3& rhs)
{
	lhs.x = rhs.x + lhs.x;
	lhs.y = rhs.y + lhs.y;
	lhs.z = rhs.z + lhs.z;
	return lhs;
}

Vector3 operator-(Vector3 lhs, const Vector3& rhs)
{
	lhs.x = rhs.x - lhs.x;
	lhs.y = rhs.y - lhs.y;
	lhs.z = rhs.z - lhs.z;
	return lhs;
}

Vector3 operator*(double lhs, const Vector3& rhs)
{
	return Vector3(rhs.x * lhs, rhs.y * lhs, rhs.z * lhs);
}

Vector3 operator*(Vector3 lhs, const double& rhs)
{
	return Vector3(lhs.x * rhs, lhs.y * rhs, lhs.z * rhs);
}

Vector3 operator/(Vector3 lhs, const double& rhs)
{
	return Vector3(lhs.x / rhs, lhs.y / rhs, lhs.z / rhs);
}

double operator*(Vector3 lhs, const Vector3& rhs)
{
	return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
}
