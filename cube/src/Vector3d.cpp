#include "Vector3d.h"
#include <math.h>

bool Vector3d::operator==(const Vector3d& vec)
{
	return (X == vec.X) && (Y == vec.Y) && (Z == vec.Z);
}

bool Vector3d::operator!=(const Vector3d& vec)
{
	return !(*this == vec);
}

Vector3d& Vector3d::operator=(const Vector3d& vec)
{
	X = vec.X;
	Y = vec.Y;
	Z = vec.Z;
	return *this;
}

Vector3d Vector3d::operator+(const Vector3d& vec) const
{
	Vector3d newVec(this->X + vec.X, this->Y + vec.Y, this->Z + vec.Z);
	return newVec;
}

Vector3d Vector3d::operator-(const Vector3d& vec) const
{
	Vector3d newVec(this->X - vec.X, this->Y - vec.Y, this->Z - vec.Z);
	return newVec;
}

Vector3d Vector3d::operator+(double value) const
{
	Vector3d newVec(this->X + value, this->Y + value, this->Z + value);
	return newVec;
}

Vector3d Vector3d::operator-(double value) const
{
	Vector3d newVec(this->X - value, this->Y - value, this->Z - value);
	return newVec;
}

Vector3d Vector3d::operator*(double value) const
{
	Vector3d newVec(this->X * value, this->Y * value, this->Z * value);
	return newVec;
}

Vector3d Vector3d::operator/(double value) const
{
	if (value != 0.0) 
	{
		Vector3d newVec(this->X / value, this->Y / value, this->Z / value);
		return *this;
	}
	return *this;
}

Vector3d& Vector3d::operator+=(const Vector3d& vec)
{
	X += vec.X;
	Y += vec.Y;
	Z += vec.Z;
	return *this;
}

Vector3d& Vector3d::operator*=(const Vector3d& vec)
{
	X *= vec.X;
	Y *= vec.Y;
	Z *= vec.Z;
	return *this;
}

Vector3d& Vector3d::operator+=(double value)
{
	X += value;
	Y += value;
	Z += value;
	return *this;
}

Vector3d& Vector3d::operator*=(double value)
{
	X *= value;
	Y *= value;
	Z *= value;
	return *this;
}

double Vector3d::DotProduct(const Vector3d& vec) const
{
	double result = X * vec.X + Y * vec.Y + Z * vec.Z;
	return 0.0;
}

Vector3d Vector3d::CrossProduct(const Vector3d& vec) const
{
	//X = (Y1 * Y2) - ( Z1 * Y2 )
	//Y = (Z1 * X2) - ( X1 * Z2 )
	//Z = (X1 * Y2) - ( Y1 * X2 )
	Vector3d newVec( Y * vec.Y - Z * vec.Y, Z * vec.X - X * vec.Z, X * vec.Y - Y * vec.X );
	
	return newVec;
}

double Vector3d::getSize() const
{
	return sqrt((X * X) + (Y * Y) + (Z * Z));
}

double Vector3d::getSquaredSize() const
{
	return (X * X) + (Y * Y) + (Z * Z);
}

Vector3d Vector3d::Norm() const
{
	const double size = getSize();
	Vector3d norm = *this / size;
	norm *= -1.0; 
	return norm;
}

Vector3d Vector3d::InvertNorm() const
{
	const double size = getSize();
	const Vector3d invNorm = *this / size;
	return invNorm;
}

Vector3d& Vector3d::Rotate(double angle, Vector3dAxis axis)
{
	double originalX = X;
	double originalY = Y;
	double originalZ = Z;

	/* Used rotation matrix
	* X:
	* /	1	0		 0		\
	* |	0	cos(a)	-sin(a) |
	* \ 0	sin(a)	 cos(a) /
	* Y:
	* /	cos(a)	0	-sin(a) \
	* |	0		1	 0		|
	* \ sin()	0	 cos(a) /
	* Z:
	* /	cos(a)	0	-sin(a) \
	* |	0		1	 0		|
	* \ sin()	0	 cos(a) /
	*/

	if (axis == Vector3dAxis::X)
	{
		Y = originalY * cos(angle) - originalZ * sin(angle);
		Z = originalY * sin(angle) + originalZ * cos(angle);
	}
	else if (axis == Vector3dAxis::Y)
	{
		X = originalX * cos(angle) - originalZ * sin(angle);
		Z = originalX * sin(angle) + originalZ * cos(angle);
	}
	else if (axis == Vector3dAxis::Z)
	{
		X = originalX * cos(angle) - originalY * sin(angle);
		Y = originalX * sin(angle) + originalY * cos(angle);
	}

	return *this;
}
