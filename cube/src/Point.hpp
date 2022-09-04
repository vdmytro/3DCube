#pragma once


/***********************************************************************************/
struct cord {
	double x, y, z;
};

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

private:
	cord Cordinates;
	bool Visible;

};

inline
double cubePoint::getX() const
{
	return this->Cordinates.x;
}

inline
double cubePoint::getY() const
{
	return this->Cordinates.y;
}

inline
double cubePoint::getZ() const
{
	return this->Cordinates.z;
}




/***********************************************************************************/

