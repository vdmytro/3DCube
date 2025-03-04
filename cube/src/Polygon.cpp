#include "Polygon.h"
#include "Point.hpp"

Render::Polygon::Polygon()
{
}

Render::Polygon::Polygon(Point& p1, Point& p2, Point& p3)
	: Polygon()
{
	polygonPonts[0] = &p1;
	polygonPonts[1] = &p2;
	polygonPonts[2] = &p3;
}

Render::Polygon::Polygon(const Polygon& polygon)
{
	polygonPonts[0] = polygon.polygonPonts[0];
	polygonPonts[1] = polygon.polygonPonts[1];
	polygonPonts[2] = polygon.polygonPonts[2];
}

Render::Polygon::~Polygon()
{

}

Render::Polygon& Render::Polygon::operator=(const Polygon& polygon)
{
	polygonPonts[0] = polygon.polygonPonts[0];
	polygonPonts[1] = polygon.polygonPonts[1];
	polygonPonts[2] = polygon.polygonPonts[2];
	return *this;
}

void Render::Polygon::Draw(HWND&, HDC& _hdc, RECT& _rt)
{
	MoveToEx(_hdc, static_cast<int>((static_cast<double>(_rt.right) / 2.0 + polygonPonts[0]->getX())), static_cast<int>((static_cast<double>(_rt.bottom) / 2.0 - polygonPonts[0]->getZ())), NULL);
	LineTo(_hdc, static_cast<int>((static_cast<double>(_rt.right) / 2.0 + polygonPonts[1]->getX())), static_cast<int>((static_cast<double>(_rt.bottom) / 2.0 - polygonPonts[1]->getZ())));
	LineTo(_hdc, static_cast<int>((static_cast<double>(_rt.right) / 2.0 + polygonPonts[2]->getX())), static_cast<int>((static_cast<double>(_rt.bottom) / 2.0 - polygonPonts[2]->getZ())));
	LineTo(_hdc, static_cast<int>((static_cast<double>(_rt.right) / 2.0 + polygonPonts[0]->getX())), static_cast<int>((static_cast<double>(_rt.bottom) / 2.0 - polygonPonts[0]->getZ())));
}

void Render::Polygon::AddPoints(Point& p1, Point& p2, Point& p3)
{
	polygonPonts[0] = &p1;
	polygonPonts[1] = &p2;
	polygonPonts[2] = &p3;
}

