#pragma once

#include <Windows.h>
#include <string>
#include <vector>

#include "Point.hpp"

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
	const cubePoint& getCP();
	//ReDrawCube(HDC)
	void SetScale(double _scale);
private:
	cubePoint mainPoint;
	std::vector<cubePoint> pointsVector;
	double Current_angle;
};
