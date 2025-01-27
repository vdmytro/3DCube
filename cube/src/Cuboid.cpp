#define _USE_MATH_DEFINES

#include "Cuboid.hpp"
#include "Vector3d.h"
#include "Point.hpp"
#include <string>
#include <math.h>
#include <windows.h>


Cuboid::Cuboid() {
	mainPoint = new cubePoint({   0.0 , 0.0  ,  0.0 });
	FLU =		new cubePoint({ -50.0 , 50.0 , 50.0 });
	FLD =		new cubePoint({ -50.0 , 50.0 ,-50.0 });
	FRU =		new cubePoint({	 50.0 , 50.0 , 50.0 });
	FRD =		new cubePoint({  50.0 , 50.0 ,-50.0 });
	BLU =		new cubePoint({ -50.0 ,-50.0 , 50.0 });
	BLD =		new cubePoint({ -50.0 ,-50.0 ,-50.0 });
	BRU =		new cubePoint({  50.0 ,-50.0 , 50.0 });
	BRD =		new cubePoint({  50.0 ,-50.0 ,-50.0 });
	Center =	new cubePoint({   0.0 ,  0.0 ,  0.0 });
	Current_angle = 0.0;
}

Cuboid::~Cuboid()
{
	delete mainPoint;
	delete FLU;
	delete FLD;
	delete FRU;
	delete FRD;
	delete BLU;
	delete BLD;
	delete BRU;
	delete BRD;
	delete Center;
}

void Cuboid::SetScale(double _scale)
{
	*FLU *= _scale;
	*FLD *= _scale;
	*FRU *= _scale;
	*FRD *= _scale;
	*BLU *= _scale;
	*BLD *= _scale;
	*BRU *= _scale;
	*BRD *= _scale;
}

const cubePoint& Cuboid::getPointByName(const std::string& _name) const
{
	//FLU, FLD, FRU, FRD, BLU, BLD, BRU, BRD
	if (_name == "FLU")
		return *FLU;
	if (_name == "FLD")
		return *FLD;
	if (_name == "FRU")
		return *FRU;
	if (_name == "FRD")
		return *FRD;
	if (_name == "BLU")
		return *BLU;
	if (_name == "BLD")
		return *BLD;
	if (_name == "BRU")
		return *BRU;
	if (_name == "BRD")
		return *BRD;
	return *Center;
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
	MoveToEx(_hdc, static_cast<int>((static_cast<double>(_rt.right) / 2.0 + FLU->getX())) , static_cast<int>((static_cast<double>(_rt.bottom) / 2.0 - FLU->getZ())), NULL); //+
																									 
	LineTo(_hdc, static_cast<int>(( static_cast<double>(_rt.right) / 2.0 + FRU->getX())), static_cast<int>(( static_cast<double>(_rt.bottom) / 2.0 - FRU->getZ())));	 //+
	LineTo(_hdc, static_cast<int>(( static_cast<double>(_rt.right) / 2.0 + FRD->getX())), static_cast<int>(( static_cast<double>(_rt.bottom) / 2.0 - FRD->getZ())));	 //+
	LineTo(_hdc, static_cast<int>(( static_cast<double>(_rt.right) / 2.0 + FLD->getX())), static_cast<int>(( static_cast<double>(_rt.bottom) / 2.0 - FLD->getZ())));	 //+
	LineTo(_hdc, static_cast<int>(( static_cast<double>(_rt.right) / 2.0 + FLU->getX())), static_cast<int>(( static_cast<double>(_rt.bottom) / 2.0 - FLU->getZ())));	 //+

	LineTo(_hdc, static_cast<int>(( static_cast<double>(_rt.right) / 2.0 + BLU->getX())), static_cast<int>(( static_cast<double>(_rt.bottom) / 2.0 - BLU->getZ())));	 //-
	LineTo(_hdc, static_cast<int>(( static_cast<double>(_rt.right) / 2.0 + BLD->getX())), static_cast<int>(( static_cast<double>(_rt.bottom) / 2.0 - BLD->getZ())));	 //-
	LineTo(_hdc, static_cast<int>(( static_cast<double>(_rt.right) / 2.0 + FLD->getX())), static_cast<int>(( static_cast<double>(_rt.bottom) / 2.0 - FLD->getZ())));	 //+
	LineTo(_hdc, static_cast<int>(( static_cast<double>(_rt.right) / 2.0 + FRD->getX())), static_cast<int>(( static_cast<double>(_rt.bottom) / 2.0 - FRD->getZ())));	 //+

	LineTo(_hdc, static_cast<int>(( static_cast<double>(_rt.right) / 2.0 + BRD->getX())), static_cast<int>(( static_cast<double>(_rt.bottom) / 2.0 - BRD->getZ())));	 //-
	LineTo(_hdc, static_cast<int>(( static_cast<double>(_rt.right) / 2.0 + BLD->getX())), static_cast<int>(( static_cast<double>(_rt.bottom) / 2.0 - BLD->getZ())));	 //-
	LineTo(_hdc, static_cast<int>(( static_cast<double>(_rt.right) / 2.0 + BLU->getX())), static_cast<int>(( static_cast<double>(_rt.bottom) / 2.0 - BLU->getZ())));	 //-
	LineTo(_hdc, static_cast<int>(( static_cast<double>(_rt.right) / 2.0 + BRU->getX())), static_cast<int>(( static_cast<double>(_rt.bottom) / 2.0 - BRU->getZ())));	 //-
	LineTo(_hdc, static_cast<int>(( static_cast<double>(_rt.right) / 2.0 + BRD->getX())), static_cast<int>(( static_cast<double>(_rt.bottom) / 2.0 - BRD->getZ())));	 //-

	LineTo(_hdc, static_cast<int>((static_cast<double>(_rt.right) / 2.0 + FRD->getX())), static_cast<int>((static_cast<double>(_rt.bottom) / 2.0 - FRD->getZ())));	 //+
	LineTo(_hdc, static_cast<int>((static_cast<double>(_rt.right) / 2.0 + FRU->getX())), static_cast<int>((static_cast<double>(_rt.bottom) / 2.0 - FRU->getZ())));	 //+
	LineTo(_hdc, static_cast<int>((static_cast<double>(_rt.right) / 2.0 + BRU->getX())), static_cast<int>((static_cast<double>(_rt.bottom) / 2.0 - BRU->getZ())));	 //-
}

void Cuboid::SetAngleX(double _angle) {
	FLU->Rotate(_angle, VectorX);
	FLD->Rotate(_angle, VectorX);
	FRU->Rotate(_angle, VectorX);
	FRD->Rotate(_angle, VectorX);
	BLU->Rotate(_angle, VectorX);
	BLD->Rotate(_angle, VectorX);
	BRU->Rotate(_angle, VectorX);
	BRD->Rotate(_angle, VectorX);
}

void Cuboid::SetAngleY(double _angle) {
	FLU->Rotate(_angle,VectorY);
	FLD->Rotate(_angle,VectorY);
	FRU->Rotate(_angle,VectorY);
	FRD->Rotate(_angle,VectorY);
	BLU->Rotate(_angle,VectorY);
	BLD->Rotate(_angle,VectorY);
	BRU->Rotate(_angle,VectorY);
	BRD->Rotate(_angle,VectorY);
}

void Cuboid::SetAngleZ(double _angle) {
	FLU->Rotate(_angle,VectorZ);
	FLD->Rotate(_angle,VectorZ);
	FRU->Rotate(_angle,VectorZ);
	FRD->Rotate(_angle,VectorZ);
	BLU->Rotate(_angle,VectorZ);
	BLD->Rotate(_angle,VectorZ);
	BRU->Rotate(_angle,VectorZ);
	BRD->Rotate(_angle,VectorZ);
}

const cubePoint* Cuboid::getCP()
{
	return FLU;
}

double Cuboid::getAngle() const {
	return Current_angle;
}
