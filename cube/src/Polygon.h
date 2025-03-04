#pragma once
#include <Windows.h>

class Point;

namespace Render
{
	class Polygon
	{
	public:
		Polygon();
		Polygon(const Polygon& polygon);
		Polygon(Point& p1, Point& p2, Point& p3);
		~Polygon();

		Polygon& operator=(const Polygon& polygon);

		void Draw(HWND&, HDC&, RECT&);
		void AddPoints(Point& p1, Point& p2, Point& p3);
	private:
		Point* polygonPonts[3];
	};
}

