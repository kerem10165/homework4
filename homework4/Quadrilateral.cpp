#include "Quadrilateral.h"
#include <exception>
#include <stdexcept>
#include <iostream>


/*
a her zaman sol �st c her zaman sa� alt� g�sterece�i i�in c'yi -1,-1 yapt�m ve b noktas� a noktas�n�n x'i c noktas�n�n y'si olacakt�r 
ayn� �ekilde d noktas� da a noktas�n�n y'si c noktas�n�n da x'i olacakt�r 

a		d
			
			kenar g�sterimi

b		c

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

//verilen uzunluk ve geni�li�e g�re kenar ayarlamas� ve renk atamas� yap�ld�
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


Quadrilateral::Quadrilateral(const Point& a, const Point& b, const Point& c, const Point& d, const Color& color)
{
	setA(a);
	setB(b);
	setC(c);
	setD(d);

	this->color = color;

	isValid();
}

Quadrilateral::Quadrilateral(const array<Point, NUMBER_OF_CORNERS>& pts, const Color& color)
{
	setA(pts[0]);
	setB(pts[1]);
	setC(pts[2]);
	setD(pts[3]);

	this->color = color;

	isValid();
}

//getter fonksiyonlar
Point Quadrilateral::getA() const noexcept
{
	return a;
}

Point Quadrilateral::getB() const noexcept
{
	return b;
}

Point Quadrilateral::getC() const noexcept
{
	return c;
}

Point Quadrilateral::getD() const noexcept
{
	return d;
}

Quadrilateral::Color Quadrilateral::getColor() const noexcept
{
	return color;
}

string Quadrilateral::getColorAsString() const noexcept
{
	return colorToStringMap.at(color);
}

//her bir kenar� hesaplay�p d�nd�ren fonksiyon
double Quadrilateral::getPerimeter() const noexcept
{
	double x = a.distanceTo(b);
	double y = a.distanceTo(d);
	double z = b.distanceTo(d);
	double q = c.distanceTo(d);

	return x+y+z+q;
}

bool Quadrilateral::isValid() const
{
/*
	c alt kenar ve sa� k�s�mda d ise sa� �st k�s�mda olacakt�r b ise
	sol altta a ise sol �stte olacakt�r e�er �ak��ma veye bu durumlar�n tersi varsa hata verecektir
*/
	if (c.y >= d.y || b.y >= a.y)
	{
		throw invalid_argument("dortgen degildir veya verilen sartlar saglanmiyor");
	}


	else
	{
		if (a.x - b.x == 0)//e�im s�f�r oldu�u i�in �zel durum
		{
			if (c.x == a.x || d.x == a.x)//e�er kenarlar �st �ste biniyorsa 
			{
				throw invalid_argument("dortgen degildir veya verilen sartlar saglanmiyor");
			}
		}


		/*
		A		
	
	
	D
						bu ko�ul oluyorsa sa�lanm�yor
		C			
				B
		
		
		burada verilen ko�ul c ve d noktas�n�n ab kenar�n�n sa��nda olmas�d�r bu durumu hesaplamak i�in de ab do�rusunun denklemini bulup c ve d noktas�n�n bu do�runun ayn� y de�erlerinde sa��nda oldu�unu kontrol etmek

		*/
		else
		{
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
		}
	}
	

	return false;
}

//setter fonksiyonlar
bool Quadrilateral::setA(const Point& pt)
{
	a.x = pt.x;
	a.y = pt.y;

	isValid();

	return false;
}

bool Quadrilateral::setB(const Point& pt)
{
	b.x = pt.x;
	b.y = pt.y;

	isValid();

	return false;
}

bool Quadrilateral::setC(const Point& pt)
{
	c.x = pt.x;
	c.y = pt.y;

	isValid();

	return false;
}

bool Quadrilateral::setD(const Point& pt)
{
	d.x = pt.x;
	d.y = pt.y;

	isValid();

	return false;
}

double Quadrilateral::printInfo() const noexcept
{
	cout << endl << "Ractangle" << endl << "Number of points: " << NUMBER_OF_CORNERS << endl ;
	cout << "Points: " << "(" << a.x << ", " << a.y << "), (" << b.x << ", " << b.y << "), (" << c.x << ", " << c.y << "), (" << d.x << ", " << d.y << ")" << endl;
	cout << "Perimeter: " << getPerimeter() << endl;
	cout << "Color: " << colorToStringMap.at(color);
	return 0.0;
}
