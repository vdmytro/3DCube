#pragma once
#include "libs.hpp"
#include "Point.hpp"



class Cuboid
{
public:
	Cuboid();
	~Cuboid();
	void DrawCube(HWND&,HDC&,RECT&);
	// rotate methosds using matrix
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
	cubePoint getCP();
	//ReDrawCube(HDC)
	void SetScale(double _scale);
	const cubePoint& getPointByName(const std::string& _name) const;
private:
	cubePoint mainPoint;
	cubePoint FLU, FLD, FRU, FRD, BLU, BLD, BRU, BRD, Center;
	double Current_angle;
};

inline
cubePoint Cuboid::getCP()
{
	return FLU;
}
inline
double Cuboid::getAngle() const {
	return Current_angle;
}



