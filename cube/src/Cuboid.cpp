#define _USE_MATH_DEFINES

#include "Cuboid.hpp"
#include <string>
#include <math.h>


Cuboid::Cuboid() {
	mainPoint = Point(  0.0 , 0.0  ,  0.0 );
	pointsVector.emplace_back(0.0, 0.0, 0.0);
	pointsVector.emplace_back(-50.0, 50.0, -50.0);
	pointsVector.emplace_back(-50.0, 50.0, 50.0);
	pointsVector.emplace_back(50.0, 50.0, 50.0);

	pointsVector.emplace_back(50.0, 50.0, -50.0);
	pointsVector.emplace_back(-50.0, -50.0, 50.0);
	pointsVector.emplace_back(-50.0, -50.0, -50.0);

	pointsVector.emplace_back(50.0, -50.0, 50.0);
	pointsVector.emplace_back(50.0, -50.0, -50.0);

	polygonsVector.emplace_back(pointsVector[1], pointsVector[2], pointsVector[4]);
	polygonsVector.emplace_back(pointsVector[2], pointsVector[3], pointsVector[4]);

	polygonsVector.emplace_back(pointsVector[2], pointsVector[5], pointsVector[7]);
	polygonsVector.emplace_back(pointsVector[2], pointsVector[7], pointsVector[3]);

	polygonsVector.emplace_back(pointsVector[2], pointsVector[5], pointsVector[6]);
	polygonsVector.emplace_back(pointsVector[2], pointsVector[6], pointsVector[1]);

	polygonsVector.emplace_back(pointsVector[1], pointsVector[6], pointsVector[8]);
	polygonsVector.emplace_back(pointsVector[1], pointsVector[8], pointsVector[4]);

	polygonsVector.emplace_back(pointsVector[6], pointsVector[5], pointsVector[8]);
	polygonsVector.emplace_back(pointsVector[5], pointsVector[7], pointsVector[8]);

	polygonsVector.emplace_back(pointsVector[8], pointsVector[3], pointsVector[7]);
	polygonsVector.emplace_back(pointsVector[8], pointsVector[4], pointsVector[3]);

	Current_angle = 0.0;
}

Cuboid::~Cuboid()
{
	
}

void Cuboid::SetScale(double _scale)
{
	for (Point& point : pointsVector)
	{
		point *= _scale;
	}
}


void Cuboid::RotateCube(SHORT & _X, SHORT & _Y,SHORT& _Z, SHORT & _TimeX, SHORT & _TimeY, SHORT& _TimeZ) 
{
	double distance = 1.0;
	double Step = 0.02;
	if (_X < _TimeX) {

		SetAngleZ(Step);
		if (Current_angle >= 360.0)
			Current_angle = 0.0;
		Current_angle += (Step * 180.0 / M_PI);
	}
	else if (_X > _TimeX) {

		SetAngleZ(Step * -1.0);
		if (Current_angle <= 0.0)
			Current_angle = 360.0;
		Current_angle -= (Step * 180.0 / M_PI);
	}
	if (_Y < _TimeY) {
		SetAngleX(Step);
	}
	else if (_Y > _TimeY)
	{
		SetAngleX(Step * -1.0);
	}
	
}

void Cuboid::DrawCube(HWND & _hWnd, HDC & _hdc, RECT & _rt)
{	
	for (Render::Polygon& polygon : polygonsVector)
	{
		polygon.Draw(_hWnd, _hdc, _rt);
	}
}

void Cuboid::SetAngleX(double _angle) {
	for (Point& point : pointsVector)
	{
		point.Rotate(_angle, Vector3dAxis::X);
	}
}

void Cuboid::SetAngleY(double _angle) {
	for (Point& point : pointsVector)
	{
		point.Rotate(_angle, Vector3dAxis::Y);
	}
}

void Cuboid::SetAngleZ(double _angle) {
	for (Point& point : pointsVector)
	{
		point.Rotate(_angle, Vector3dAxis::Z);
	}
}

const Point& Cuboid::getCP()
{
	return pointsVector[0];
}

double Cuboid::getAngle() const {
	return Current_angle;
}
