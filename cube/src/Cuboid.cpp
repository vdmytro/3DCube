#define _USE_MATH_DEFINES

#include "Cuboid.hpp"
#include <string>
#include <math.h>
#include <windows.h>


Cuboid::Cuboid() {
	mainPoint = cubePoint(  0.0 , 0.0  ,  0.0 );
	pointsVector.emplace_back(-50.0, 50.0, -50.0);
	pointsVector.emplace_back(-50.0, 50.0, 50.0);
	pointsVector.emplace_back(50.0, 50.0, 50.0);
	pointsVector.emplace_back(50.0, 50.0, -50.0);
	pointsVector.emplace_back(-50.0, -50.0, 50.0);
	pointsVector.emplace_back(-50.0, -50.0, -50.0);
	pointsVector.emplace_back(50.0, -50.0, 50.0);
	pointsVector.emplace_back(50.0, -50.0, -50.0);
	pointsVector.emplace_back(0.0, 0.0, 0.0);
	Current_angle = 0.0;
}

Cuboid::~Cuboid()
{
	
}

void Cuboid::SetScale(double _scale)
{
	for (cubePoint& point : pointsVector)
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
	MoveToEx(_hdc, static_cast<int>((static_cast<double>(_rt.right) / 2.0 + mainPoint.getX())), static_cast<int>((static_cast<double>(_rt.bottom) / 2.0 - mainPoint.getZ())), NULL); //+
	for (cubePoint point1 : pointsVector)
	{
		for (cubePoint point2 : pointsVector)
		{
			if (point1 != point2)
			{
				LineTo(_hdc, static_cast<int>((static_cast<double>(_rt.right) / 2.0 + point1.getX())), static_cast<int>((static_cast<double>(_rt.bottom) / 2.0 - point1.getZ())));
				LineTo(_hdc, static_cast<int>((static_cast<double>(_rt.right) / 2.0 + point2.getX())), static_cast<int>((static_cast<double>(_rt.bottom) / 2.0 - point2.getZ())));
				LineTo(_hdc, static_cast<int>((static_cast<double>(_rt.right) / 2.0 + point1.getX())), static_cast<int>((static_cast<double>(_rt.bottom) / 2.0 - point1.getZ())));
			}
		}
	}

	//LineTo(_hdc, static_cast<int>(( static_cast<double>(_rt.right) / 2.0 + FRU->getX())), static_cast<int>(( static_cast<double>(_rt.bottom) / 2.0 - FRU->getZ())));	 //+
	//LineTo(_hdc, static_cast<int>(( static_cast<double>(_rt.right) / 2.0 + FRD->getX())), static_cast<int>(( static_cast<double>(_rt.bottom) / 2.0 - FRD->getZ())));	 //+
	//LineTo(_hdc, static_cast<int>(( static_cast<double>(_rt.right) / 2.0 + FLD->getX())), static_cast<int>(( static_cast<double>(_rt.bottom) / 2.0 - FLD->getZ())));	 //+
	//LineTo(_hdc, static_cast<int>(( static_cast<double>(_rt.right) / 2.0 + FLU->getX())), static_cast<int>(( static_cast<double>(_rt.bottom) / 2.0 - FLU->getZ())));	 //+

	//LineTo(_hdc, static_cast<int>(( static_cast<double>(_rt.right) / 2.0 + BLU->getX())), static_cast<int>(( static_cast<double>(_rt.bottom) / 2.0 - BLU->getZ())));	 //-
	//LineTo(_hdc, static_cast<int>(( static_cast<double>(_rt.right) / 2.0 + BLD->getX())), static_cast<int>(( static_cast<double>(_rt.bottom) / 2.0 - BLD->getZ())));	 //-
	//LineTo(_hdc, static_cast<int>(( static_cast<double>(_rt.right) / 2.0 + FLD->getX())), static_cast<int>(( static_cast<double>(_rt.bottom) / 2.0 - FLD->getZ())));	 //+
	//LineTo(_hdc, static_cast<int>(( static_cast<double>(_rt.right) / 2.0 + FRD->getX())), static_cast<int>(( static_cast<double>(_rt.bottom) / 2.0 - FRD->getZ())));	 //+

	//LineTo(_hdc, static_cast<int>(( static_cast<double>(_rt.right) / 2.0 + BRD->getX())), static_cast<int>(( static_cast<double>(_rt.bottom) / 2.0 - BRD->getZ())));	 //-
	//LineTo(_hdc, static_cast<int>(( static_cast<double>(_rt.right) / 2.0 + BLD->getX())), static_cast<int>(( static_cast<double>(_rt.bottom) / 2.0 - BLD->getZ())));	 //-
	//LineTo(_hdc, static_cast<int>(( static_cast<double>(_rt.right) / 2.0 + BLU->getX())), static_cast<int>(( static_cast<double>(_rt.bottom) / 2.0 - BLU->getZ())));	 //-
	//LineTo(_hdc, static_cast<int>(( static_cast<double>(_rt.right) / 2.0 + BRU->getX())), static_cast<int>(( static_cast<double>(_rt.bottom) / 2.0 - BRU->getZ())));	 //-
	//LineTo(_hdc, static_cast<int>(( static_cast<double>(_rt.right) / 2.0 + BRD->getX())), static_cast<int>(( static_cast<double>(_rt.bottom) / 2.0 - BRD->getZ())));	 //-

	//LineTo(_hdc, static_cast<int>((static_cast<double>(_rt.right) / 2.0 + FRD->getX())), static_cast<int>((static_cast<double>(_rt.bottom) / 2.0 - FRD->getZ())));	 //+
	//LineTo(_hdc, static_cast<int>((static_cast<double>(_rt.right) / 2.0 + FRU->getX())), static_cast<int>((static_cast<double>(_rt.bottom) / 2.0 - FRU->getZ())));	 //+
	//LineTo(_hdc, static_cast<int>((static_cast<double>(_rt.right) / 2.0 + BRU->getX())), static_cast<int>((static_cast<double>(_rt.bottom) / 2.0 - BRU->getZ())));	 //-
}

void Cuboid::SetAngleX(double _angle) {
	for (cubePoint& point : pointsVector)
	{
		point.Rotate(_angle, Vector3dAxis::X);
	}
}

void Cuboid::SetAngleY(double _angle) {
	for (cubePoint& point : pointsVector)
	{
		point.Rotate(_angle, Vector3dAxis::Y);
	}
}

void Cuboid::SetAngleZ(double _angle) {
	for (cubePoint& point : pointsVector)
	{
		point.Rotate(_angle, Vector3dAxis::Z);
	}
}

const cubePoint& Cuboid::getCP()
{
	return pointsVector[0];
}

double Cuboid::getAngle() const {
	return Current_angle;
}
