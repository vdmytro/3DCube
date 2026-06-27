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
	double fov = 90.0; // Field of view
	double aspectRatio = static_cast<double>(_rt.right) / static_cast<double>(_rt.bottom);
	double _near = 0.00001;
	double _far = 1000000.0;
	double cameraDistance = 200.0;

	Point projectedPoints[3];
	for (int i = 0; i < 3; ++i)
	{
		projectedPoints[i] = *polygonPonts[i];//Point::ProjectPoint(*polygonPonts[i], fov, aspectRatio, _near, _far, cameraDistance);
	}

	MoveToEx(_hdc, static_cast<int>((static_cast<double>(_rt.right) / 2.0 + projectedPoints[0].getX())), static_cast<int>((static_cast<double>(_rt.bottom) / 2.0 - projectedPoints[0].getY())), NULL);
	LineTo(_hdc, static_cast<int>((static_cast<double>(_rt.right) / 2.0 + projectedPoints[1].getX())), static_cast<int>((static_cast<double>(_rt.bottom) / 2.0 - projectedPoints[1].getY())));
	LineTo(_hdc, static_cast<int>((static_cast<double>(_rt.right) / 2.0 + projectedPoints[2].getX())), static_cast<int>((static_cast<double>(_rt.bottom) / 2.0 - projectedPoints[2].getY())));
	LineTo(_hdc, static_cast<int>((static_cast<double>(_rt.right) / 2.0 + projectedPoints[0].getX())), static_cast<int>((static_cast<double>(_rt.bottom) / 2.0 - projectedPoints[0].getY())));
}

void Render::Polygon::AddPoints(Point& p1, Point& p2, Point& p3)
{
	polygonPonts[0] = &p1;
	polygonPonts[1] = &p2;
	polygonPonts[2] = &p3;
}

