#pragma once

#include "Vector3d.h"

/***********************************************************************************/

class Point
{
public:
	Point();
	Point(double _x, double _y, double _z);
	double getX() const;
	double getY() const; 
	double getZ() const;
	double getToC(Point&);
	bool isVisible();
	void setCord(double, double, double);
	~Point();
	Point& operator*=(double _num);
	Point& operator=(const Point& point);
	void Rotate(double _angle, Vector3dAxis _axis);

private:
	Vector3d Cordinates; 
	bool Visible;

};

/***********************************************************************************/

