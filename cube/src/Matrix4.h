#pragma once

#include "Vector4d.h"

struct Matrix4
{
	Matrix4();

	float m_data[4][4];

	Matrix4& operator*(const Matrix4& matrix);
	float* operator[](size_t idx);
	Vector4d operator*(const Vector4d& v) const;
};