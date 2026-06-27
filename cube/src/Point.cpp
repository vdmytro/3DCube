#define _USE_MATH_DEFINES

#include "Point.hpp"
#include "Vector3d.h"
#include <math.h>


Point::Point()
{
	Cordinates = Vector3d{ 0,0,0 };
	Visible = true;
}

/**********************************************/
Point::Point(double _x, double _y, double _z)  
	: Point()
{
	Cordinates = Vector3d{ _x,_y,_z };
}

double Point::getToC(Point &_pointMain)
{
	double First = fabs(Cordinates.X - _pointMain.getX());
	double Second = fabs(Cordinates.Y - _pointMain.getY());
	double Third = fabs(Cordinates.Z - _pointMain.getZ());
	double Fourth = sqrt((First*First) + (Second*Second));
	return sqrt((Fourth*Fourth)+(Third*Third));
}

void Point::setCord(double _x, double _y, double _z)
{
	Cordinates.X = _x;
	Cordinates.Y = _y;
	Cordinates.Z = _z;
}

Point::~Point()
{
}

Point& Point::operator*=(double _num)
{
	Cordinates *= _num;
	return *this;
}

Point& Point::operator=(const Point& point)
{
	Cordinates = point.Cordinates;
	Visible = point.Visible;
	return *this;
}

void Point::Rotate(double _angle, Vector3dAxis _axis)
{
	Cordinates.Rotate(_angle, _axis);
}

bool
Point::isVisible() {
	return 1;
}


double Point::getX() const
{
	return Cordinates.X;
}

double Point::getY() const
{
	return Cordinates.Y;
}

double Point::getZ() const
{
	return Cordinates.Z;
}

Point Point::ProjectPoint(const Point& point, double fov, double aspectRatio, double near, double far, double cameraDistance)
{
	double scale = tan(fov * 0.5 * M_PI / 180) * near;
	double r = aspectRatio * scale;
	double l = -r;
	double t = scale;
	double b = -t;

	double x = (2 * near / (r - l)) * point.getX() / point.getZ();
	double y = (2 * near / (t - b)) * point.getY() / point.getZ();
	double z = -(far + near) / (far - near) * point.getZ() - (2 * far * near) / (far - near);

	return Point(x * cameraDistance, y * cameraDistance, z);
}


/**********************************************/