#include "Point.hpp"
#include "libs.hpp"

cubePoint::cubePoint()
{
}

/**********************************************/
cubePoint::cubePoint(double _x, double _y, double _z) 
	: Cordinates({_x,_y,_z}) 
	, Visible(true)
{
}

double cubePoint::getToC(cubePoint &_pointMain)
{
	double First = abs(Cordinates.x - _pointMain.getX());
	double Second = abs(Cordinates.y - _pointMain.getY());
	double Third = abs(Cordinates.z - _pointMain.getZ());
	double Fourth = sqrt((First*First) + (Second*Second));
	return sqrt((Fourth*Fourth)+(Third*Third));
}

void
cubePoint::setCord(double _x, double _y, double _z)
{
	this->Cordinates.x = _x;
	this->Cordinates.y = _y;
	this->Cordinates.z = _z;
}

cubePoint::~cubePoint() = default;

bool
cubePoint::isVisible() {
	return 1;
}

/**********************************************/