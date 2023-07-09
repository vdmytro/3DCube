#pragma once

struct Vector3d
{
	double X = 0.0, Y = 0.0, Z = 0.0;
	//---------------------------------------------------------
	Vector3d() {}
	Vector3d(double x, double y, double z) : X(x), Y(y), Z(z) {}
	Vector3d(int x, int y, int z) : Vector3d((double)x, (double)y, (double)z) {}
	//---------------------------------------------------------
	bool operator==(const Vector3d& vec);
	bool operator!=(const Vector3d& vec);
	Vector3d& operator=(const Vector3d& vec);
	Vector3d operator+(const Vector3d& vec) const;
	Vector3d operator-(const Vector3d& vec) const;
	Vector3d operator+(double value) const;
	Vector3d operator-(double value) const;
	Vector3d operator*(double value) const;
	Vector3d operator/(double value) const;
	Vector3d& operator+=(const Vector3d& vec);
	Vector3d& operator*=(const Vector3d& vec);
	Vector3d& operator+=(double value);
	Vector3d& operator*=(double value);
	//---------------------------------------------------------
	double getSize() const;
	Vector3d Norm() const;
	Vector3d InvertNorm() const;
	//---------------------------------------------------------
	Vector3d& Rotate(double angle,Vector3d axis);
};

static const Vector3d VectorX{ 1.0,0.0,0.0 };
static const Vector3d VectorY{ 0.0,1.0,0.0 };
static const Vector3d VectorZ{ 0.0,0.0,1.0 };