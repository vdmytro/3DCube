#pragma once

struct Vector3d;
#define __devfeature__
#ifdef __devfeature__
struct Vector4d
{
	//---------------------------------------------------------
	Vector4d();
	Vector4d(double x, double y, double z, double w);
	Vector4d(int x, int y, int z, int w);

	//---------------------------------------------------------
	bool operator==(const Vector4d& vec);
	bool operator!=(const Vector4d& vec);
	Vector4d& operator=(const Vector4d& vec);
	Vector4d operator+(const Vector4d& vec) const;
	Vector4d operator-(const Vector4d& vec) const;
	Vector4d operator+(double value) const;
	Vector4d operator-(double value) const;
	Vector4d operator*(double value) const;
	Vector4d operator/(double value) const;
	Vector4d& operator+=(const Vector4d& vec);
	Vector4d& operator*=(const Vector4d& vec);
	Vector4d& operator+=(double value);
	Vector4d& operator*=(double value);
	//---------------------------------------------------------
	double getSize() const;
	//---------------------------------------------------------

	double X = 0.0, Y = 0.0, Z = 0.0, W = 0.0;
};


#endif // !__devfeature__