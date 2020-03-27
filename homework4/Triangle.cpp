#include "Triangle.h"

Triangle::Triangle(const Point& a = { 1, 0 }, const Point& b = { 0, 1 }, const Point& c = { 2, 1 }, const Color& color = Color::RED)
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
