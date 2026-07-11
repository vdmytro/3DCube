#pragma once

#include "Matrix4.h"
#include "Vector3d.h"
#include "Vector4d.h"
#include "Windows.h"


class Camera
{
public:
	Camera();

	void HandleInput(WPARAM wParam);
	void HandleMouseInput(SHORT& _X, SHORT& _Y, SHORT& _TimeX, SHORT& _TimeY);
	void Update();
	inline const Vector3d& GetLocation() const { return m_Location; }
	inline const Vector3d& GetRotation() const { return m_Rotation; }
	bool WorldToScreen(const Vector3d& worldPos, int& outX, int& outY);
private:
	Matrix4 BuildViewMatrix();

	Vector3d m_Location = ZeroVector;
	Vector3d m_Rotation = ZeroVector;
	float m_fov = 90.0f;
	float m_nearPlane = 1;
	float m_farPlane = 1000;
	Matrix4 m_ProjectionMatrix;
	Matrix4 m_ViewMatrix;
};

extern Camera gCamera;

