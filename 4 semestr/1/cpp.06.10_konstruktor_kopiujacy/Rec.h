#ifndef _CREC_H_
#define _CREC_H_	

#include <iostream>

#include "Shape.h"

namespace OOP {
class Rec : public Shape {
public:
	Rec(double x = 0, double y = 0) : Shape(x, y)
	{std::cout << "Konstruktor Rec\n"; }

	//tak nie mo¿e byæ
	// Rec(Rec& K)
	Rec(const Rec& K)
	{
		m_x = K.m_x;
		m_y = K.m_y;
		std::cout << "Konstruktor kopiujacy Rec\n"; 
	}

	double Pole() const;
	void rys() const;
};

/////////////////////////////////////////////////////////////////////////
inline double Rec::Pole() const
{
	return m_x * m_y;
}

/////////////////////////////////////////////////////////////////////////
inline void Rec::rys() const
{
	std::cout << "Rysuj CRrec\n";
}

}//end of namespace OOP
#endif