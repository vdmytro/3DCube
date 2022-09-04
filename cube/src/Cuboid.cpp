#include "Cuboid.hpp"


Cuboid::Cuboid() {
	scale = 1;
	mainPoint = { 0,0,0 };
	FLU = { -50 * scale, 50 * scale, 50 * scale };
	FLD = { -50 * scale, 50 * scale,-50 * scale };
	FRU = {  50 * scale, 50 * scale, 50 * scale };
	FRD = {  50 * scale, 50 * scale,-50 * scale };
	BLU = { -50 * scale,-50 * scale, 50 * scale };
	BLD = { -50 * scale,-50 * scale,-50 * scale };
	BRU = {  50 * scale,-50 * scale, 50 * scale };
	BRD = {  50 * scale,-50 * scale,-50 * scale };
	Center = { 0,0,0};
	Current_angle = 0;
}

Cuboid::~Cuboid() = default;

void Cuboid::SetScale(bool _factor)
{
	if(_factor)
		scale = 1.1;
	else
		scale = 0.9;
	
	SetAngleX(0);
	SetAngleY(0);
	SetAngleZ(0);

	scale = 1;
}

double Cuboid::GetScale()
{
	return this->scale;
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
	FLU.setCord(FLU.getX() * scale, (FLU.getY() * std::cos(_angle) - FLU.getZ() * std::sin(_angle)) * scale, (FLU.getY() * std::sin(_angle) + FLU.getZ()*std::cos(_angle)) * scale);
	FLD.setCord(FLD.getX() * scale, (FLD.getY() * std::cos(_angle) - FLD.getZ() * std::sin(_angle)) * scale, (FLD.getY() * std::sin(_angle) + FLD.getZ()*std::cos(_angle)) * scale);
	FRU.setCord(FRU.getX() * scale, (FRU.getY() * std::cos(_angle) - FRU.getZ() * std::sin(_angle)) * scale, (FRU.getY() * std::sin(_angle) + FRU.getZ()*std::cos(_angle)) * scale);
	FRD.setCord(FRD.getX() * scale, (FRD.getY() * std::cos(_angle) - FRD.getZ() * std::sin(_angle)) * scale, (FRD.getY() * std::sin(_angle) + FRD.getZ()*std::cos(_angle)) * scale);
	BLU.setCord(BLU.getX() * scale, (BLU.getY() * std::cos(_angle) - BLU.getZ() * std::sin(_angle)) * scale, (BLU.getY() * std::sin(_angle) + BLU.getZ()*std::cos(_angle)) * scale);
	BLD.setCord(BLD.getX() * scale, (BLD.getY() * std::cos(_angle) - BLD.getZ() * std::sin(_angle)) * scale, (BLD.getY() * std::sin(_angle) + BLD.getZ()*std::cos(_angle)) * scale);
	BRU.setCord(BRU.getX() * scale, (BRU.getY() * std::cos(_angle) - BRU.getZ() * std::sin(_angle)) * scale, (BRU.getY() * std::sin(_angle) + BRU.getZ()*std::cos(_angle)) * scale);
	BRD.setCord(BRD.getX() * scale, (BRD.getY() * std::cos(_angle) - BRD.getZ() * std::sin(_angle)) * scale, (BRD.getY() * std::sin(_angle) + BRD.getZ()*std::cos(_angle)) * scale);
}

void Cuboid::SetAngleY(double _angle) {
	FLU.setCord((FLU.getX() * std::cos(_angle) - FLU.getZ() * std::sin(_angle)) * scale, FLU.getY() * scale, (FLU.getX() * std::sin(_angle) + FLU.getZ()*std::cos(_angle)) * scale);
	FLD.setCord((FLD.getX() * std::cos(_angle) - FLD.getZ() * std::sin(_angle)) * scale, FLD.getY() * scale, (FLD.getX() * std::sin(_angle) + FLD.getZ()*std::cos(_angle)) * scale);
	FRU.setCord((FRU.getX() * std::cos(_angle) - FRU.getZ() * std::sin(_angle)) * scale, FRU.getY() * scale, (FRU.getX() * std::sin(_angle) + FRU.getZ()*std::cos(_angle)) * scale);
	FRD.setCord((FRD.getX() * std::cos(_angle) - FRD.getZ() * std::sin(_angle)) * scale, FRD.getY() * scale, (FRD.getX() * std::sin(_angle) + FRD.getZ()*std::cos(_angle)) * scale);
	BLU.setCord((BLU.getX() * std::cos(_angle) - BLU.getZ() * std::sin(_angle)) * scale, BLU.getY() * scale, (BLU.getX() * std::sin(_angle) + BLU.getZ()*std::cos(_angle)) * scale);
	BLD.setCord((BLD.getX() * std::cos(_angle) - BLD.getZ() * std::sin(_angle)) * scale, BLD.getY() * scale, (BLD.getX() * std::sin(_angle) + BLD.getZ()*std::cos(_angle)) * scale);
	BRU.setCord((BRU.getX() * std::cos(_angle) - BRU.getZ() * std::sin(_angle)) * scale, BRU.getY() * scale, (BRU.getX() * std::sin(_angle) + BRU.getZ()*std::cos(_angle)) * scale);
	BRD.setCord((BRD.getX() * std::cos(_angle) - BRD.getZ() * std::sin(_angle)) * scale, BRD.getY() * scale, (BRD.getX() * std::sin(_angle) + BRD.getZ()*std::cos(_angle)) * scale);
}

void Cuboid::SetAngleZ(double _angle) {
	FLU.setCord((FLU.getX() * std::cos(_angle) - FLU.getY() * std::sin(_angle)) * scale, (FLU.getX() * std::sin(_angle) + FLU.getY()*std::cos(_angle)) * scale, FLU.getZ()* scale);
	FLD.setCord((FLD.getX() * std::cos(_angle) - FLD.getY() * std::sin(_angle)) * scale, (FLD.getX() * std::sin(_angle) + FLD.getY()*std::cos(_angle)) * scale, FLD.getZ()* scale);
	FRU.setCord((FRU.getX() * std::cos(_angle) - FRU.getY() * std::sin(_angle)) * scale, (FRU.getX() * std::sin(_angle) + FRU.getY()*std::cos(_angle)) * scale, FRU.getZ()* scale);
	FRD.setCord((FRD.getX() * std::cos(_angle) - FRD.getY() * std::sin(_angle)) * scale, (FRD.getX() * std::sin(_angle) + FRD.getY()*std::cos(_angle)) * scale, FRD.getZ()* scale);
	BLU.setCord((BLU.getX() * std::cos(_angle) - BLU.getY() * std::sin(_angle)) * scale, (BLU.getX() * std::sin(_angle) + BLU.getY()*std::cos(_angle)) * scale, BLU.getZ()* scale);
	BLD.setCord((BLD.getX() * std::cos(_angle) - BLD.getY() * std::sin(_angle)) * scale, (BLD.getX() * std::sin(_angle) + BLD.getY()*std::cos(_angle)) * scale, BLD.getZ()* scale);
	BRU.setCord((BRU.getX() * std::cos(_angle) - BRU.getY() * std::sin(_angle)) * scale, (BRU.getX() * std::sin(_angle) + BRU.getY()*std::cos(_angle)) * scale, BRU.getZ()* scale);
	BRD.setCord((BRD.getX() * std::cos(_angle) - BRD.getY() * std::sin(_angle)) * scale, (BRD.getX() * std::sin(_angle) + BRD.getY()*std::cos(_angle)) * scale, BRD.getZ()* scale);
}