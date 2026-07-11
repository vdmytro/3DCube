#include "Polygon.h"
#include "Point.hpp"
#include "Camera.h"

extern unsigned int screenWidth;
extern unsigned int screenHeight;

void PolDraw(HDC _hdc, POINT* apt, int cpt)
{
	Polygon(_hdc, apt, cpt);
}

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
	constexpr int sz = 5;
	Vector3d projectedPoints[3];
	POINT trianglePoints[3];
	for (int i = 0; i < 3; ++i)
	{

		int x, y;
		float isBehind = gCamera.WorldToScreen(polygonPonts[i]->GetCordinates(), x, y);//Point::ProjectPoint(*polygonPonts[i], fov, aspectRatio, _near, _far, cameraDistance);
		if (!isBehind)
		{
			static char buf[80];
			Rectangle(_hdc, x - sz, y - sz, x + sz, y + sz);
			TextOut(_hdc, x, y, (LPCWSTR)buf, wsprintf((LPWSTR)buf, L"%i", polygonPonts[i]->GetIndex()));
		}
		projectedPoints[i].X = x;
		projectedPoints[i].Y = y;
		trianglePoints[i].x = x;
		trianglePoints[i].y = y;
	}

	// Create a solid blue brush
	//HBRUSH hBrush = CreateSolidBrush(RGB(rand()%255, rand() % 255, rand() % 255));
	//HGDIOBJ hOldBrush = SelectObject(_hdc, hBrush);

	// Draw the triangle
	//PolDraw(_hdc, trianglePoints, 3);

	// Clean up resources
	//SelectObject(_hdc, hOldBrush);
	//DeleteObject(hBrush);


	MoveToEx(_hdc, static_cast<int>(projectedPoints[0].X), static_cast<int>(projectedPoints[0].Y), NULL);
	LineTo(_hdc, static_cast<int>(projectedPoints[1].X), static_cast<int>(projectedPoints[1].Y));
	LineTo(_hdc, static_cast<int>(projectedPoints[2].X), static_cast<int>(projectedPoints[2].Y));
	LineTo(_hdc, static_cast<int>(projectedPoints[0].X), static_cast<int>(projectedPoints[0].Y));
}

void Render::Polygon::AddPoints(Point& p1, Point& p2, Point& p3)
{
	polygonPonts[0] = &p1;
	polygonPonts[1] = &p2;
	polygonPonts[2] = &p3;
}

