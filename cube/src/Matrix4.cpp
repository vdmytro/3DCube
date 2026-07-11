#include "Matrix4.h"

Matrix4::Matrix4()
{
	for (int row = 0; row < 4; row++)
	{
		for (int col = 0; col < 4; col++)
		{
            m_data[row][col] = 0;
		}
	}
}

Matrix4& Matrix4::operator*(const Matrix4& matrix)
{
    Matrix4 result;

    for (int row = 0; row < 4; row++)
    {
        for (int col = 0; col < 4; col++)
        {
            result.m_data[row][col] =
                m_data[row][0] * matrix.m_data[0][col] +
                m_data[row][1] * matrix.m_data[1][col] +
                m_data[row][2] * matrix.m_data[2][col] +
                m_data[row][3] * matrix.m_data[3][col];
        }
    }

    return result;
}

float* Matrix4::operator[](size_t idx)
{
    return m_data[idx];
}

Vector4d Matrix4::operator*(const Vector4d& v) const
{
	return Vector4d(
		m_data[0][0] * v.X + m_data[0][1] * v.Y + m_data[0][2] * v.Z + m_data[0][3] * v.W,
        m_data[1][0] * v.X + m_data[1][1] * v.Y + m_data[1][2] * v.Z + m_data[1][3] * v.W,
        m_data[2][0] * v.X + m_data[2][1] * v.Y + m_data[2][2] * v.Z + m_data[2][3] * v.W,
        m_data[3][0] * v.X + m_data[3][1] * v.Y + m_data[3][2] * v.Z + m_data[3][3] * v.W
	);
}