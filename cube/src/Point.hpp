#pragma once

struct Vector3d;

/***********************************************************************************/

class cubePoint
{
public:
	cubePoint();
	cubePoint(double _x, double _y, double _z);
	double getX() const;
	double getY() const; 
	double getZ() const;
	double getToC(cubePoint&);
	bool isVisible();
	void setCord(double, double, double);
	~cubePoint();
	cubePoint& operator*=(double _num);
	void Rotate(double _angle, Vector3d _axis);

private:
	Vector3d* Cordinates; 
	bool Visible;

};

/***********************************************************************************/

