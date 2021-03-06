#include "Triangle.h"
#include <iostream>
#include <cmath>

using namespace std;

Triangle::Triangle(const Point& a, const Point& b , const Point& c, const Color& color)
{
	pts[0].x = a.x;
	pts[0].y = a.y;

	pts[1].x = a.x;
	pts[1].y = c.y;

	pts[2].x = c.x;
	pts[2].y = c.y;

	this->color = color;

	isValid();
}

Triangle::Triangle(const vector<Point>& pts, const Color& color)
{
	if (pts.size() != 3)
	{
		throw invalid_argument("ucgen degil");
	}

	else
	{
		pts[0].x = a.x;
		pts[0].y = a.y;

		pts[1].x = a.x;
		pts[1].y = c.y;

		pts[2].x = c.x;
		pts[2].y = c.y;

		this->color = color;

		isValid();
	}
}

Triangle::Triangle(const array<Point, NUMBER_OF_CORNERS>& pts, const Color& color)
{
	pts[0].x = a.x;
	pts[0].y = a.y;

	pts[1].x = a.x;
	pts[1].y = c.y;

	pts[2].x = c.x;
	pts[2].y = c.y;

	this->color = color;

	isValid();
}

//getter fonksiyonlar

Point Triangle::getA() const noexcept
{
	return a;
}

Point Triangle::getB() const noexcept
{
	return b;
}

Point Triangle::getC() const noexcept
{
	return c;
}

int Triangle::getType()
{
	return 0;
}

Triangle::Color Triangle::getColor() const noexcept
{
	return color;
}

string Triangle::getColorAsString() const noexcept
{
	return colorToStringMap.at(color);
}

double Triangle::getPerimeter() const noexcept
{
	//kenar uzunlukları hesaplandı
	double x = a.distanceTo(b);
	double y = a.distanceTo(c);
	double z = b.distanceTo(c);

	if (isValid() == false)
	{
		return 0;
	}

	return x+y+z;
}

bool Triangle::setA(const Point& pt)
{
	a.x = pt.x;
	a.y = pt.y;
	isValid();
	return true;
}

bool Triangle::setB(const Point& pt)
{
	b.x = pt.x;
	b.y = pt.y;
	isValid();
	return true;
}

bool Triangle::setC(const Point& pt)
{
	c.x = pt.x;
	c.y = pt.y;
	isValid();
	return true;
}

bool Triangle::setColor(const Triangle::Color& color)
{
	this->color = color;
	return false;
}

bool Triangle::isValid() const
{
	double x = a.distanceTo(b);
	double y = a.distanceTo(c);
	double z = b.distanceTo(c);

	if ( x > y+z || x < abs(y-z))
	{
		throw invalid_argument("ucgen degildir");
		return false;
	}

	if ( y > x+z || y < abs(x-z))
	{
		throw invalid_argument("ucgen degildir");
		return false;
	}

	if ((a.x == b.x && a.y == b.y) || (a.x == c.x && a.y == c.y) || (b.x == c.x && b.y == c.y))
	{
		throw invalid_argument("ucgen degildir");
		return false;
	}


	if ( z > x+y || z < abs(x-y))
	{
		throw invalid_argument("ucgen degildir");
		return false;
	}

	return true;
}

double Triangle::printInfo() const noexcept
{
	cout << endl << "Triangle" << endl << "Number of points: " << NUMBER_OF_CORNERS << endl;
	cout << "Points: " << "(" << a.x << ", " << a.y << "), (" << b.x << ", " << b.y << "), (" << c.x << ", " << c.y << ')' << endl;
	cout << "Perimeter: " << getPerimeter() << endl;
	cout << "Color: " << colorToStringMap.at(color);
	return 0.0;
}
