#ifndef _CSHAPE_H_
#define _CSHAPE_H_

#include <iostream>

namespace OOP {

class Shape {
public:
	Shape()
	{std::cout << "Konstruktor Shape\n"; }

	~Shape()
	{std::cout << "Destruktor Shape\n"; }

	double GetX() const;
	double GetY() const;
	void SetX(double m_x);
	void SetY(double m_y);
	double Pole() const
	{ return 0.0; }

protected:
	double m_x,m_y;
};

/////////////////////////////////////////////////////////////////////////
inline double Shape::GetX() const {
	return m_x;
}

/////////////////////////////////////////////////////////////////////////
inline double Shape::GetY() const {
	return m_y;
}

/////////////////////////////////////////////////////////////////////////
inline void Shape::SetX(double x) {
	m_x = x;
}

/////////////////////////////////////////////////////////////////////////
inline void Shape::SetY(double y) {
	m_y = y;
}

}//end of namespace OOP
#endif