#include "Point.hpp"
#include "Vector3d.h"
#include <math.h>


cubePoint::cubePoint()
{
	Cordinates = new Vector3d{ 0,0,0 };
	Visible = true;
}

/**********************************************/
cubePoint::cubePoint(double _x, double _y, double _z)  
	:	Visible(true)
{
	Cordinates = new Vector3d{ _x,_y,_z };
}

double cubePoint::getToC(cubePoint &_pointMain)
{
	double First = fabs(Cordinates->X - _pointMain.getX());
	double Second = fabs(Cordinates->Y - _pointMain.getY());
	double Third = fabs(Cordinates->Z - _pointMain.getZ());
	double Fourth = sqrt((First*First) + (Second*Second));
	return sqrt((Fourth*Fourth)+(Third*Third));
}

void cubePoint::setCord(double _x, double _y, double _z)
{
	this->Cordinates->X = _x;
	this->Cordinates->Y = _y;
	this->Cordinates->Z = _z;
}

cubePoint::~cubePoint()
{
	delete Cordinates;
}

cubePoint& cubePoint::operator*=(double _num)
{
	*Cordinates *= _num;
	return *this;
}

void cubePoint::Rotate(double _angle, Vector3d _axis )
{
	Cordinates->Rotate(_angle, _axis);
}

bool
cubePoint::isVisible() {
	return 1;
}


double cubePoint::getX() const
{
	return this->Cordinates->X;
}

double cubePoint::getY() const
{
	return this->Cordinates->Y;
}

double cubePoint::getZ() const
{
	return this->Cordinates->Z;
}

/**********************************************/