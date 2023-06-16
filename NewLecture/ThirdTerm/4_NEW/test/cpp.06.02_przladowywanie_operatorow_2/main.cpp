#include <iostream>
#include <string>
//#include "Fraction.h"

class Fraction
{
public:
   friend std::ostream& operator<< (std::ostream& o, const Fraction& K);
   friend std::istream& operator>> (std::istream& i, Fraction& K);

	Fraction(int l = 0, int m = 1) : _l(l), _m(m)
		{}
	int getL() const
	{ return _l; }

	int getM() const
	{ return _m; }

	void setL(int l)
	{ _l = l;}
	
	void setM(int m)
	{ _m = m;}

	//funkcja konwertuj¹ca do float
	float toFloat() const
	{ return (float)_l/(float)_m; }

private:
	int _l;
	int _m;
};

/////////////////////////////////////////////////////////////////////////
inline std::ostream& operator<< (std::ostream& o, const Fraction& K)
{
	return o << K._l << "/" << K._m;
}

/////////////////////////////////////////////////////////////////////////
inline std::istream& operator>> (std::istream& i, Fraction& K)
{
	char tmp;
	return i >> K._l >> tmp >> K._m;
}

/////////////////////////////////////////////////////////////////////////
Fraction operator*(const Fraction &K1, const Fraction &K2)
{
	return Fraction(K1.getL() * K2.getL(), K1.getM() * K2.getM());
}

/////////////////////////////////////////////////////////////////////////
Fraction operator-(const Fraction &K)
{
	return Fraction(-K.getL(), K.getM());
}

/////////////////////////////////////////////////////////////////////////
Fraction operator-(const Fraction &K1, const Fraction &K2)
{
	return Fraction(K1.getL()*K2.getM() - K1.getM()*K2.getL(),
	              K1.getM()*K2.getM());
}

/////////////////////////////////////////////////////////////////////////
int main()
{
	using namespace std;
	
	Fraction aFraction;
	Fraction bFraction;

	//cout << "Podaj aFraction: ";
	// cin >> aFraction;
	aFraction.setL(1);
	aFraction.setM(2);
	//cout << "Podaj bFraction: ";
	// cin >> bFraction;
	bFraction.setL(2);
	bFraction.setM(3);
	cout << "input already given...\n\n";

	cout << "aFraction * bFraction = " << aFraction * bFraction << endl;
	cout << "-bFraction = " << -bFraction << endl;

	cout << "aFraction - bFraction = " << aFraction - bFraction << endl;
	cout << "1 - bFraction = " << 1 - bFraction << endl;
	cout << "bFraction - 1 = " << bFraction - 1 << endl;

	cout << "2 * bFraction = " << 2 * bFraction << endl;
	cout << "bFraction * 2 = " << bFraction * 2 << endl;
}
