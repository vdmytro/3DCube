#pragma once

struct Vector3d;

#ifdef __devfeature__
struct Vector4d
{
	//---------------------------------------------------------
	Vector4d() {}
	Vector4d(double x, double y, double z) : X(x), Y(y), Z(z) {}
	Vector4d(int x, int y, int z) : Vector4d((double)x, (double)y, (double)z) {}

	//---------------------------------------------------------
	inline const double X() { return m_X };
	inline const double X() { return m_Y };
	inline const double X() { return m_Z };
	inline const double X() { return m_W };
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

private:
	double m_X = 0.0, m_Y = 0.0, m_Z = 0.0, m_W = 0.0;
};

static const Vector4d VectorX{ 1.0, 0.0, 0.0, 1.0 };
static const Vector4d VectorY{ 0.0, 1.0, 0.0, 1.0 };
static const Vector4d VectorZ{ 0.0, 0.0, 1.0, 1.0 };

#endif // !__devfeature__