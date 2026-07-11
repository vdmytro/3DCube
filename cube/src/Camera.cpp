#include "Camera.h"

#include <cmath>

extern unsigned int screenWidth;
extern unsigned int screenHeight;

#define M_PI       3.14159265358979323846   // pi

Camera gCamera;

static Matrix4 BuildProjectionMatrix( float fovY, float nearPlane, float farPlane)
{
	Matrix4 p;
	float fovRadians = fovY * (float)M_PI / 180.0f;
	float f = 1.0f / tanf(fovRadians * 0.5f);

	p[0][0] = f / (static_cast<float>(screenWidth) / static_cast<float>(screenHeight));
	p[1][1] = f;

	p[2][2] = farPlane / (farPlane - nearPlane);
	p[2][3] = 1.0f;

	p[3][2] = (-nearPlane * farPlane) / (farPlane - nearPlane);

	return p;
}

Vector3d GetForward(float pitch, float yaw)
{
	float cp = cosf(pitch);
	float sp = sinf(pitch);

	float cy = cosf(yaw);
	float sy = sinf(yaw);

	return Vector3d(cp * sy,sp,	cp * cy).Norm();
}

Matrix4 Camera::BuildViewMatrix()
{
	float PitchRadians = m_Rotation.Pitch() * (float)M_PI / 180.0f;
	float YawRadians = m_Rotation.Yaw() * (float)M_PI / 180.0f;
	Vector3d forward = GetForward(PitchRadians, YawRadians);

	Vector3d worldUp = { 0,1,0 };

	Vector3d right = forward.CrossProduct(worldUp).Norm();

	Vector3d up = right.CrossProduct(forward);

	Matrix4 view{};

	view[0][0] = right.X;
	view[0][1] = right.Y;
	view[0][2] = right.Z;
	view[0][3] = -right.DotProduct(m_Location);

	view[1][0] = up.X;
	view[1][1] = up.Y;
	view[1][2] = up.Z;
	view[1][3] = -up.DotProduct(m_Location);

	view[2][0] = forward.X;
	view[2][1] = forward.Y;
	view[2][2] = forward.Z;
	view[2][3] = -forward.DotProduct(m_Location);

	view[3][0] = 0.0;
	view[3][1] = 0.0;
	view[3][2] = 0.0;
	view[3][3] = 1.0;

	return view;
}

bool Camera::WorldToScreen( const Vector3d& worldPos, int& outX, int& outY)
{
	Vector4d p =
	{
		worldPos.X,
		worldPos.Y,
		worldPos.Z,
		1.0f
	};

    Vector4d viewPos = m_ViewMatrix * p;
    Vector4d clip = m_ProjectionMatrix * viewPos;

	if (clip.W <= 0.0f)
		return true;

	float ndcX = clip.X / clip.W;
	float ndcY = clip.Y / clip.W;

	if (ndcX < -1.0f || ndcX > 1.0f)
		return true;

	if (ndcY < -1.0f || ndcY > 1.0f)
		return true;

	outX = static_cast<int>((ndcX + 1.0f) * 0.5f * screenWidth);
	outY = static_cast<int>((1.0f - ndcY) * 0.5f * screenHeight);

	return false;
}

Camera::Camera()
{
    m_ProjectionMatrix = BuildProjectionMatrix(m_fov, m_nearPlane, m_farPlane);
}

void Camera::HandleInput(WPARAM wParam)
{
    constexpr double Step = 1;
    //CAMERA TRANSFORM CONTROL
    switch (wParam)
    {
    case VK_DOWN:
        m_Location.Y -= Step;
        break;
    case VK_UP:
        m_Location.Y += Step;
        break;
    case VK_LEFT:
        m_Location.X -= Step;
        break;
    case VK_RIGHT:
        m_Location.X += Step;
        break;
    case VK_NUMPAD8:
        m_Location.Z += Step;
        break;
    case VK_NUMPAD2:
        m_Location.Z -= Step;
        break;
    default:
        break;
    }
}

void Camera::HandleMouseInput(SHORT& _X, SHORT& _Y, SHORT& _TimeX, SHORT& _TimeY)
{
    constexpr double Step = 1;
    if (_X < _TimeX) {
        m_Rotation.Z += Step;
    }
    else if (_X > _TimeX) {
        m_Rotation.Z -= Step;
    }
    if (_Y < _TimeY) {
        m_Rotation.Y += Step;
    }
    else if (_Y > _TimeY)
	{
        m_Rotation.Y -= Step;
    }
}

void Camera::Update()
{
	m_ViewMatrix = BuildViewMatrix();
}
