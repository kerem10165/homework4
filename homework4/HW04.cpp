#include <iostream>
#include <vector>
#include "Triangle.h"
#include "Quadrilateral.h"
#include <random>

using namespace std;

// Rastgele olarak Triangle nesneleri olusturur ve parametre olarak verilen vektore ekler.
/* Triangle nesnelerinde yer alacak noktalarýn x ve y deðerleri [0, 100] arasýnda olabilir.
   Þeklin renk deðeri de rastgele olarak belirlenmelidir.
*/
void fillTriangles(vector<Triangle> &v, int numberOfItems = 100)
{
	const map<int,Triangle::Color> intToColorMap = {
	{0,Triangle::Color::PINK},
	{1,Triangle::Color::RED},
	{2,Triangle::Color::BLUE},
	{3,Triangle::Color::WHITE},
	{4,Triangle::Color::BLACK},
	{5,Triangle::Color::GREEN}
	};

	Point a;
	Point b;
	Point c;
	random_device rd;
	uniform_real_distribution<double> dagilim(0, 100);
	mt19937 motor(rd());
	uniform_int_distribution<int> dagilim1(0, 5);


	for (size_t i = 0; i < numberOfItems; i++)
	{
		a.x = dagilim(motor);
		a.y = dagilim(motor);
		b.x = dagilim(motor);
		b.y = dagilim(motor);
		c.x = dagilim(motor);
		c.y = dagilim(motor);

		auto renk = intToColorMap.at(dagilim1(motor));

		v.push_back(Triangle(a, b, c, renk));
	}
}

// Rastgele olarak Quadrilateral nesneleri olusturur ve parametre olarak verilen vektore ekler.
/* Quadrilateral nesnelerinde yer alacak noktalarýn x ve y deðerleri [0, 100] arasýnda olabilir.
   Þeklin renk deðeri de rastgele olarak belirlenmelidir.
*/
void fillQuads(vector<Quadrilateral> &v, int numberOfItems = 100)
{
	const map<int, Quadrilateral::Color> intToColorMap = {
	{0,Quadrilateral::Color::RED},
	{1,Quadrilateral::Color::BLUE},
	{2,Quadrilateral::Color::WHITE},
	{3,Quadrilateral::Color::BLACK},
	{4,Quadrilateral::Color::GREEN}
	};

	Point a;
	Point b;
	Point c;
	Point d;

	random_device rd;
	uniform_real_distribution<double> dagilim(0, 100);
	mt19937 motor(rd());
	uniform_int_distribution<int> dagilim1(0, 4);
	

	for (size_t i = 0; i < numberOfItems; i++)
	{
		a.x = dagilim(motor);
		a.y = dagilim(motor);
		b.x = dagilim(motor);
		b.y = dagilim(motor);
		c.x = dagilim(motor);
		c.y = dagilim(motor);
		d.x = dagilim(motor);
		d.y = dagilim(motor);

		Quadrilateral::Color renk = intToColorMap.at(dagilim1(motor));

		v.push_back(Quadrilateral(a,b,c,d,renk));
	}
}


/* Verilen Triangle veya Rectangle vektörününde çevre uzunluðu ve renk deðeri eþleþen ilk elemanýn indeksini döndürür.
Eleman bulunamazsa -1 döndürülür.*/
template<class T>
int search(const vector<T> &v, const T & key)
{
	for (size_t i = 0; i < v.size(); i++)
	{
		if (key.getPerimeter() == v[i].getPerimeter() && key.getColor() == v[i].getColor())
		{
			return 1;
		}
	}
	return -1;
}


template<class T>
int sortByPerimeter(vector<T> &v)
{
	vector <T> a;

	for (size_t i = 0; i < v.size(); i++)
	{
		T* temp = &v[0];
		for (size_t j = 0; j < v.size()-i; j++)
		{
			if (v[j].getPerimeter() > temp->getPerimeter())
			{
				temp = &v[j];
			}
		}
		a.push_back(*temp);
	}
	v = a;
	return 1;
}

int main()
{

	// Point class test
	auto p = Point{ 4.5, 6.2 };

	cout << p.x << " " << p.y << endl;
	cout << p.coords[0] << " " << p.coords[1] << endl;

	// Sample Quad and Triangle Objects
	
	try
	{
		auto sampleQuad = Quadrilateral{ Point(4, 5), 20, 20 };
		cout << "Color of Sample Quad:" << sampleQuad.getColorAsString() << endl;

		// Filling vectors randomly
		auto vectorOfQuads = vector<Quadrilateral>{};
		fillQuads(vectorOfQuads);

		// Search sample objects in the corresponding vectors
		cout << "Searching a quadrilateral...\n";
		cout << sampleQuad.printInfo() << endl;
		if (auto idx = search(vectorOfQuads, sampleQuad) >= 0)
			cout << "A similar object is found at index-" << idx << endl;
		else cout << "No similar object can be found" << endl;

		// Add sample Quad object to the vector and sort the vector
		vectorOfQuads.push_back(sampleQuad);
		sortByPerimeter(vectorOfQuads);

		// Search sample item again. Now, you must have a hit.
		cout << "Searching a quadrilateral...\n";
		cout << sampleQuad.printInfo() << endl;
		if (auto idx = search(vectorOfQuads, sampleQuad) >= 0)
			cout << "A similar object is found at index-" << idx << endl;
		else cout << "No similar object can be found" << endl;

	}
	
	catch (invalid_argument& ex)
	{
		cout << "Invalid triangle: " << ex.what() << endl;
	}

	try
	{
		auto sampleTriangle = Triangle{ Point(4, 5),  Point(9, 5),  Point(14, 15) };
		cout << "Color of Sample Triangle:" << sampleTriangle.getColorAsString() << endl;

		// Filling vectors randomly
		auto vectorOfTriangles = vector<Triangle>{};
		fillTriangles(vectorOfTriangles);

		// Search sample objects in the corresponding vectors
		cout << "Searching a triangle...\n";
		cout << sampleTriangle.printInfo() << endl;
		if (auto idx = search(vectorOfTriangles, sampleTriangle) >= 0)
			cout << "A similar object is found at index-" << idx << endl;
		else cout << "No similar object can be found" << endl;

		// Add sample Triangle object to the vector and sort the vector
		vectorOfTriangles.push_back(sampleTriangle);
		sortByPerimeter(vectorOfTriangles);


		// Search sample item again. Now, you must have a hit.
		cout << "Searching a triangle...\n";
		cout << sampleTriangle.printInfo() << endl;
		if (auto idx = search(vectorOfTriangles, sampleTriangle) >= 0)
			cout << "A similar object is found at index-" << idx << endl;
		else cout << "No similar object can be found" << endl;
	}
	catch (invalid_argument& ex)
	{
		cout << "Invalid triangle: " << ex.what() << endl;
	}
	


	// Invalid cases
	try
	{
		auto invalidTriangle1 = Triangle{ Point{4, 0},  Point{9, 0},  Point{14, 0} };
	}
	catch (invalid_argument & ex)
	{
		cout << "Invalid triangle: " << ex.what() << endl;
	}

	try
	{
		auto invalidTriangle2 = Triangle{ Point{4, 4},  Point{4, 4},  Point{4, 4} };
	}
	catch (invalid_argument & ex)
	{
		cout << "Invalid triangle: " << ex.what() << endl;
	}

	try
	{
		auto invalidTriangle3 = Triangle{ Point{4, 0},  Point{4, 4},  Point{4, 14} };
	}
	catch (invalid_argument & ex)
	{
		cout << "Invalid triangle: " << ex.what() << endl;
	}

	try
	{
		auto invalidQuad1 = Quadrilateral{ Point{4, 0},  Point{9, 0},  Point{14, 0}, Point{0, 0} };
	}
	catch (invalid_argument & ex)
	{
		cout << "Invalid Quad: " << ex.what() << endl;
	}


	try
	{
		auto invalidQuad1 = Quadrilateral{ Point{4, 0},  Point{9, 0},  Point{14, 0}, Point{0, 0} };
	}
	catch (invalid_argument & ex)
	{
		cout << "Invalid Quad: " << ex.what() << endl;
	}


	try
	{
		auto invalidQuad2 = Quadrilateral{ Point{4, 0},  Point{9, 0},  Point{3, 20}, Point{10, 20} };
	}
	catch (invalid_argument & ex)
	{
		cout << "Invalid Quad: " << ex.what() << endl;
	}

	return 0;
}