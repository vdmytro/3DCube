#pragma once

#include <Windows.h>
#include <string>
#include <vector>

#include "Point.hpp"
#include "Polygon.h"

class Cuboid
{
public:
	Cuboid();
	~Cuboid();
	void DrawCube(HWND&,HDC&,RECT&);
	// rotate methods using matrix
	void SetAngleX(double _angle);
	void SetAngleY(double _angle);
	void SetAngleZ(double _angle);
	void RotateCube( SHORT & _X, SHORT & _Y, SHORT& _Z,
		 SHORT & _TimeX,  SHORT & _TimeY,  SHORT& _TimeZ);
	double getAngle() const;
	// test methods with static coordinates
	//void VerticalMove();
	//void HorizontalMoveLeft();
	//void HorizontalMoveRight();
	const Point& getCP();
	//ReDrawCube(HDC)
	void SetScale(double _scale);
private:
	Point mainPoint;
	std::vector<Point> pointsVector;
	std::vector<Render::Polygon> polygonsVector;
	double Current_angle;
};
