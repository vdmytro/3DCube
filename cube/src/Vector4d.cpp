#include "Vector4d.h"

#include <cmath>



Vector4d::Vector4d(double x, double y, double z, double w)
	: X(x), Y(y), Z(z), W(w)
{
}

Vector4d::Vector4d(int x, int y, int z, int w)
	: X(static_cast<double>(x))
	, Y(static_cast<double>(y))
	, Z(static_cast<double>(z))
	, W(static_cast<double>(w))
{
}

Vector4d::Vector4d()
	: X(0.0)
	, Y(0.0)
	, Z(0.0)
	, W(0.0)
{
}

Vector4d Vector4d::operator+(const Vector4d& vec) const
{
	return Vector4d(
		X + vec.X,
		Y + vec.Y,
		Z + vec.Z,
		W + vec.W);
}

Vector4d Vector4d::operator+(double value) const
{
	return Vector4d(
		X + value,
		Y + value,
		Z + value,
		W + value);
}

Vector4d Vector4d::operator-(const Vector4d& vec) const
{
	return Vector4d(
		X - vec.X,
		Y - vec.Y,
		Z - vec.Z,
		W - vec.W);
}

Vector4d Vector4d::operator-(double value) const
{
	return Vector4d(
		X - value,
		Y - value,
		Z - value,
		W - value);
}

Vector4d Vector4d::operator*(double value) const
{
	return Vector4d(
		X * value,
		Y * value,
		Z * value,
		W * value);
}

Vector4d Vector4d::operator/(double value) const
{
	return Vector4d(
		X / value,
		Y / value,
		Z / value,
		W / value);
}

double Vector4d::getSize() const
{
	return std::sqrt(
		X * X +
		Y * Y +
		Z * Z +
		W * W);
}

Vector4d& Vector4d::operator*=(double value)
{
	X *= value;
	Y *= value;
	Z *= value;
	W *= value;

	return *this;
}

Vector4d& Vector4d::operator+=(double value)
{
	X += value;
	Y += value;
	Z += value;
	W += value;

	return *this;
}

Vector4d& Vector4d::operator*=(const Vector4d& vec)
{
	X *= vec.X;
	Y *= vec.Y;
	Z *= vec.Z;
	W *= vec.W;

	return *this;
}

Vector4d& Vector4d::operator+=(const Vector4d& vec)
{
	X += vec.X;
	Y += vec.Y;
	Z += vec.Z;
	W += vec.W;

	return *this;
}

Vector4d& Vector4d::operator=(const Vector4d& vec)
{
	if (this != &vec)
	{
		X = vec.X;
		Y = vec.Y;
		Z = vec.Z;
		W = vec.W;
	}

	return *this;
}

bool Vector4d::operator!=(const Vector4d& vec)
{
	return X != vec.X ||
		Y != vec.Y ||
		Z != vec.Z ||
		W != vec.W;
}

bool Vector4d::operator==(const Vector4d& vec)
{
	return X == vec.X &&
		Y == vec.Y &&
		Z == vec.Z &&
		W == vec.W;
}