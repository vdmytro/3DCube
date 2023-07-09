#include "Cuboid.hpp"


Cuboid::Cuboid() {
	mainPoint = { 0,0,0 };
	FLU = { -50 , 50 , 50  };
	FLD = { -50 , 50 ,-50  };
	FRU = {  50 , 50 , 50  };
	FRD = {  50 , 50 ,-50  };
	BLU = { -50 ,-50 , 50  };
	BLD = { -50 ,-50 ,-50  };
	BRU = {  50 ,-50 , 50  };
	BRD = {  50 ,-50 ,-50  };
	Center = { 0,0,0};
	Current_angle = 0;
}

Cuboid::~Cuboid() = default;

void Cuboid::SetScale(double _scale)
{
	FLU *= _scale;
	FLD *= _scale;
	FRU *= _scale;
	FRD *= _scale;
	BLU *= _scale;
	BLD *= _scale;
	BRU *= _scale;
	BRD *= _scale;
}

const cubePoint& Cuboid::getPointByName(const std::string& _name) const
{
	//FLU, FLD, FRU, FRD, BLU, BLD, BRU, BRD
	if (_name == "FLU")
		return FLU;
	if (_name == "FLD")
		return FLD;
	if (_name == "FRU")
		return FRU;
	if (_name == "FRD")
		return FRD;
	if (_name == "BLU")
		return BLU;
	if (_name == "BLD")
		return BLD;
	if (_name == "BRU")
		return BRU;
	if (_name == "BRD")
		return BRD;
	return Center;
}

void Cuboid::RotateCube(SHORT & _X, SHORT & _Y,SHORT& _Z, SHORT & _TimeX, SHORT & _TimeY, SHORT& _TimeZ) 
{
	double distance = 1.0;
	double Step = 0.02;
	if (_X < _TimeX) {

		this->SetAngleZ(Step);
		if (Current_angle >= 360)
			Current_angle = 0;
		Current_angle += (Step * 180 / M_PI);
	}
	else if (_X > _TimeX) {

		this->SetAngleZ(Step * -1);
		if (Current_angle <= 0)
			Current_angle = 360;
		Current_angle -= (Step * 180 / M_PI);
	}
	if (_Y < _TimeY) {
		this->SetAngleX(Step);
	}
	else if (_Y > _TimeY)
	{
		this->SetAngleX(Step * -1);
	}
	
}

void
Cuboid::DrawCube(HWND & _hWnd, HDC & _hdc, RECT & _rt)
{	
	MoveToEx(_hdc, _rt.right / 2 + (int)(this->FLU.getX()) , _rt.bottom / 2 - (int)(this->FLU.getZ()), NULL); //+
																									 
	LineTo(_hdc, _rt.right / 2 + (int)(this->FRU.getX()), _rt.bottom / 2 - (int)(this->FRU.getZ()));	 //+
	LineTo(_hdc, _rt.right / 2 + (int)(this->FRD.getX()), _rt.bottom / 2 - (int)(this->FRD.getZ()));	 //+
	LineTo(_hdc, _rt.right / 2 + (int)(this->FLD.getX()), _rt.bottom / 2 - (int)(this->FLD.getZ()));	 //+
	LineTo(_hdc, _rt.right / 2 + (int)(this->FLU.getX()), _rt.bottom / 2 - (int)(this->FLU.getZ()));	 //+

	LineTo(_hdc, _rt.right / 2 + (int)(this->BLU.getX()), _rt.bottom / 2 - (int)(this->BLU.getZ()));	 //-
	LineTo(_hdc, _rt.right / 2 + (int)(this->BLD.getX()), _rt.bottom / 2 - (int)(this->BLD.getZ()));	 //-
	LineTo(_hdc, _rt.right / 2 + (int)(this->FLD.getX()), _rt.bottom / 2 - (int)(this->FLD.getZ()));	 //+
	LineTo(_hdc, _rt.right / 2 + (int)(this->FRD.getX()), _rt.bottom / 2 - (int)(this->FRD.getZ()));	 //+

	LineTo(_hdc, _rt.right / 2 + (int)(this->BRD.getX()), _rt.bottom / 2 - (int)(this->BRD.getZ()));	 //-
	LineTo(_hdc, _rt.right / 2 + (int)(this->BLD.getX()), _rt.bottom / 2 - (int)(this->BLD.getZ()));	 //-
	LineTo(_hdc, _rt.right / 2 + (int)(this->BLU.getX()), _rt.bottom / 2 - (int)(this->BLU.getZ()));	 //-
	LineTo(_hdc, _rt.right / 2 + (int)(this->BRU.getX()), _rt.bottom / 2 - (int)(this->BRU.getZ()));	 //-
	LineTo(_hdc, _rt.right / 2 + (int)(this->BRD.getX()), _rt.bottom / 2 - (int)(this->BRD.getZ()));	 //-

	LineTo(_hdc, _rt.right / 2 + (int)(this->FRD.getX()), _rt.bottom / 2 - (int)(this->FRD.getZ()));	 //+
	LineTo(_hdc, _rt.right / 2 + (int)(this->FRU.getX()), _rt.bottom / 2 - (int)(this->FRU.getZ()));	 //+
	LineTo(_hdc, _rt.right / 2 + (int)(this->BRU.getX()), _rt.bottom / 2 - (int)(this->BRU.getZ()));	 //-
}

void Cuboid::SetAngleX(double _angle) {
	FLU.Rotate(_angle,VectorX);
	FLD.Rotate(_angle, VectorX);
	FRU.Rotate(_angle, VectorX);
	FRD.Rotate(_angle, VectorX);
	BLU.Rotate(_angle, VectorX);
	BLD.Rotate(_angle, VectorX);
	BRU.Rotate(_angle, VectorX);
	BRD.Rotate(_angle, VectorX);
}

void Cuboid::SetAngleY(double _angle) {
	FLU.Rotate(_angle,VectorY);
	FLD.Rotate(_angle,VectorY);
	FRU.Rotate(_angle,VectorY);
	FRD.Rotate(_angle,VectorY);
	BLU.Rotate(_angle,VectorY);
	BLD.Rotate(_angle,VectorY);
	BRU.Rotate(_angle,VectorY);
	BRD.Rotate(_angle,VectorY);
}

void Cuboid::SetAngleZ(double _angle) {
	FLU.Rotate(_angle,VectorZ);
	FLD.Rotate(_angle,VectorZ);
	FRU.Rotate(_angle,VectorZ);
	FRD.Rotate(_angle,VectorZ);
	BLU.Rotate(_angle,VectorZ);
	BLD.Rotate(_angle,VectorZ);
	BRU.Rotate(_angle,VectorZ);
	BRD.Rotate(_angle,VectorZ);
}