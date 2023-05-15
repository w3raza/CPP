 #include <iostream>
#include <string>

class Point 
{ 
public: 
	Point() : _x(0.0),  _y(0.0), _Opis("")
	{}

	Point(double x, double y, std::string Opis = "") : _x(x), _y(y), _Opis(Opis)
	, _cxx_11 {1010}
	{}

	void print() const;

private: 
	double _x; 
	double _y; 
	std::string _Opis;

	int _cxx_11 ; //wg std c++11
}; 
/////////////////////////////////////////////////////////////////////////
void Point::print() const
{ 
	if(_Opis.length() > 0)
		std::cout << _Opis << "(x, y) = " << _x << ", " <<  _y << ", " <<  _cxx_11 << std::endl;
	else
		std::cout << "<bez_nazwy> " << "(x, y) = " << _x << ", " <<  _y << ", " <<  _cxx_11 << std::endl;
} 
/////////////////////////////////////////////////////////////////////////

int main()
{
	Point aPoint;
	Point bPoint(1, 1, "bPoint");
	Point cPoint = Point(2, 2, "cPoint");
	Point dPoint(3, 3);
	
	aPoint.print();
	bPoint.print();
	cPoint.print();
	dPoint.print();
}
