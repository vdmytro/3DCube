#pragma once

class cubePoint;

#include <Windows.h>
#include <string>

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
	const cubePoint* getCP();
	//ReDrawCube(HDC)
	void SetScale(double _scale);
	const cubePoint& getPointByName(const std::string& _name) const;
private:
	cubePoint* mainPoint;
	cubePoint* FLU, *FLD, *FRU, *FRD, *BLU, *BLD, *BRU, *BRD, *Center;
	double Current_angle;
};
