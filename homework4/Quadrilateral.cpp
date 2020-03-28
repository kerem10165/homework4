#include "Quadrilateral.h"
#include <exception>
#include <stdexcept>
#include <iostream>


/*
a her zaman sol üst c her zaman sað altý göstereceði için c'yi -1,-1 yaptým ve b noktasý a noktasýnýn x'i c noktasýnýn y'si olacaktýr 
ayný þekilde d noktasý da a noktasýnýn y'si c noktasýnýn da x'i olacaktýr 

a		d
			
			kenar gösterimi

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

//verilen uzunluk ve geniþliðe göre kenar ayarlamasý ve renk atamasý yapýldý
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

//her bir kenarý hesaplayýp döndüren fonksiyon
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
	c alt kenar ve sað kýsýmda d ise sað üst kýsýmda olacaktýr b ise
	sol altta a ise sol üstte olacaktýr eðer çakýþma veye bu durumlarýn tersi varsa hata verecektir
*/
	if (c.y >= d.y || b.y >= a.y)
	{
		throw invalid_argument("dortgen degildir veya verilen sartlar saglanmiyor");
	}


	else
	{
		if (a.x - b.x == 0)//eðim sýfýr olduðu için özel durum
		{
			if (c.x == a.x || d.x == a.x)//eðer kenarlar üst üste biniyorsa 
			{
				throw invalid_argument("dortgen degildir veya verilen sartlar saglanmiyor");
			}
		}


		/*
		A		
	
	
	D
						bu koþul oluyorsa saðlanmýyor
		C			
				B
		
		
		burada verilen koþul c ve d noktasýnýn ab kenarýnýn saðýnda olmasýdýr bu durumu hesaplamak için de ab doðrusunun denklemini bulup c ve d noktasýnýn bu doðrunun ayný y deðerlerinde saðýnda olduðunu kontrol etmek

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
