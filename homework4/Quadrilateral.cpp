#include "Quadrilateral.h"
#include <exception>
#include <stdexcept>


/*
a her zaman sol �st c her zaman sa� alt� g�sterece�i i�in c'yi -1,-1 yapt�m ve b noktas� a noktas�n�n x'i c noktas�n�n y'si olacakt�r 
ayn� �ekilde d noktas� da a noktas�n�n y'si c noktas�n�n da x'i olacakt�r 
*/
Quadrilateral::Quadrilateral(const Point& a = { 0,0 }, const Point& c = { -1,-1 }, const Color& color = Quadrilateral::Color::GREEN)
{
	pts[0].x = a.x;
	pts[0].y = a.y;

	pts[1].x = a.x;
	pts[1].y = c.y;

	pts[2].x = c.x;
	pts[2].y = c.y;

	pts[3].x = c.x;
	pts[3].y = a.y;

	this->color = color;

	isValid();
}

Quadrilateral::Quadrilateral(const Point& a, double width, double height, const Color& color = Color::GREEN)
{
	pts[0].x = a.x;
	pts[0].y = a.y;

	pts[1].x = a.x;
	pts[1].y = a.y + height;

	pts[2].x = a.x + width;
	pts[2].y = pts[1].y;

	pts[3].x = pts[2].x;
	pts[3].y = a.y;

	this->color = color;

	isValid();
}

bool Quadrilateral::isValid() const
{
	if (c.y >= d.y || b.y >= a.y)
	{
		throw invalid_argument("sartlar� saglam�yor");
	}

	double egim = (a.y - b.y) / (a.x - b.x);

	int c_xkontrol = (c.y - a.y) / egim + a.x;

	int d_xkontrol = (d.y - a.y) / egim + a.x;

	if (c.x <= c_xkontrol)
	{
		throw invalid_argument("dortgen degildir");
	}

	if (d.x <= d_xkontrol)
	{
		throw invalid_argument("dortgen degildir");
	}

	return false;
}
