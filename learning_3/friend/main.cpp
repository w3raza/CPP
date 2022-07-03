//fun feind ma dostęp do wszystkich składowych klasy
//przyjaźń klas jest jednostrona

//#include <iostream>
// class Punkt
// {
// public :
// 	friend void raport(const Punkt& pPunkt);

// 	Punkt (double a, double b)
// 	{ _x = a ; _y = b ; }

// 	void print() const;
//   	void move(double a, double b);

// private:
// 	double  _x ,_y ;
// };

// void Punkt::print() const
// {
// 	std::cout << "_x, _y = " << _x << ", " << _y << std::endl ;
// }
// /*******************************************************/
// void Punkt::move(double a, double b)
// {
// 	_x = a;
// 	_y = b;
// }
// /*******************************************************/

// void raport(const Punkt& pPunkt)
// {
// 	std::cout << "Prywatne skladowe Punkt: _x, _y = " << pPunkt._x << ", " << pPunkt._y << std::endl;
// }

// int main()
// {
// 	Punkt aPunkt(1,1);
// 	raport(aPunkt);
// 	aPunkt.print();

// 	aPunkt.move(10,10);
// 	raport(aPunkt);
// 	aPunkt.print();
// }
#include <iostream>
//przyjaźń obustronna kompilator musi znac wcześniej deklarację tej klasy

//Deklaracja wyprzedzająca.
class PointCollection;

class Point
{
public:
	friend class PointCollection;

	Point()
	{
		_x = 0.0;
		_y = 0.0;
	}

private:
	double _x;
	double _y;
};
/////////////////////////////////////////////////////////////////////////
class PointCollection
{
public:
	PointCollection(const int nSize)
	{
		f = new Point[nSize];
		this->nSize = nSize;
	}

	~PointCollection(void)
	{
		delete[] f;
	}

	void Set(const double x, const double y);
	void print(void);

private:
	Point *f;
	int nSize;
};
/////////////////////////////////////////////////////////////////////////
void PointCollection::Set(const double x, const double y)
{
	for (int i = 0; i < nSize; i++)
	{
		(f + i)->_x = x * i;
		(f + i)->_y = y * i;
	}
}
/////////////////////////////////////////////////////////////////////////
void PointCollection::print(void)
{
	for (int i = 0; i < nSize; i++)
		std::cout << "_x = " << (f + i)->_x << ", _y = " << (f + i)->_y << std::endl;
}
/////////////////////////////////////////////////////////////////////////
int main()
{
	PointCollection aPointCollection(20);
	aPointCollection.Set(1, 2);
	aPointCollection.print();
}
