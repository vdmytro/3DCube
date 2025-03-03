#include "Point.hpp"
#include "Vector3d.h"
#include <math.h>


cubePoint::cubePoint()
{
	Cordinates = Vector3d{ 0,0,0 };
	Visible = true;
	static int id = -1;
	m_ID = ++id;
}

/**********************************************/
cubePoint::cubePoint(double _x, double _y, double _z)  
	: cubePoint()
{
	Cordinates = Vector3d{ _x,_y,_z };
}

double cubePoint::getToC(cubePoint &_pointMain)
{
	double First = fabs(Cordinates.X - _pointMain.getX());
	double Second = fabs(Cordinates.Y - _pointMain.getY());
	double Third = fabs(Cordinates.Z - _pointMain.getZ());
	double Fourth = sqrt((First*First) + (Second*Second));
	return sqrt((Fourth*Fourth)+(Third*Third));
}

void cubePoint::setCord(double _x, double _y, double _z)
{
	Cordinates.X = _x;
	Cordinates.Y = _y;
	Cordinates.Z = _z;
}

cubePoint::~cubePoint()
{
}

cubePoint& cubePoint::operator*=(double _num)
{
	Cordinates *= _num;
	return *this;
}

void cubePoint::Rotate(double _angle, Vector3dAxis _axis)
{
	Cordinates.Rotate(_angle, _axis);
}

bool
cubePoint::isVisible() {
	return 1;
}


double cubePoint::getX() const
{
	return Cordinates.X;
}

double cubePoint::getY() const
{
	return Cordinates.Y;
}

double cubePoint::getZ() const
{
	return Cordinates.Z;
}

bool cubePoint::operator==(const cubePoint& point)
{
	return m_ID == point.m_ID ? true : false;

}

bool cubePoint::operator!=(const cubePoint& point)
{
	return m_ID != point.m_ID ? true : false;
}

/**********************************************/