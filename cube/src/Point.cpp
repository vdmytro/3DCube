#include "Point.hpp"
#include "libs.hpp"

cubePoint::cubePoint()
{
	Cordinates = { 0,0,0 };
	Visible = true;
}

/**********************************************/
cubePoint::cubePoint(double _x, double _y, double _z) 
	: Cordinates({_x,_y,_z}) 
	, Visible(true)
{
}

double cubePoint::getToC(cubePoint &_pointMain)
{
	double First = abs(Cordinates.X - _pointMain.getX());
	double Second = abs(Cordinates.Y - _pointMain.getY());
	double Third = abs(Cordinates.Z - _pointMain.getZ());
	double Fourth = sqrt((First*First) + (Second*Second));
	return sqrt((Fourth*Fourth)+(Third*Third));
}

void cubePoint::setCord(double _x, double _y, double _z)
{
	this->Cordinates.X = _x;
	this->Cordinates.Y = _y;
	this->Cordinates.Z = _z;
}

cubePoint::~cubePoint() = default;

cubePoint& cubePoint::operator*=(double _num)
{
	Cordinates *= _num;
	return *this;
}

void cubePoint::Rotate(double _angle, Vector3d _axis )
{
	Cordinates.Rotate(_angle, _axis);
}

bool
cubePoint::isVisible() {
	return 1;
}

/**********************************************/