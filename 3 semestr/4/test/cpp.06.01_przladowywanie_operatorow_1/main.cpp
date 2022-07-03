#include <iostream>
#include <string>

/////////////////////////////////////////////////////////////////////////
class Fraction
{
public:
  friend std::ostream &operator<<(std::ostream &o, const Fraction &K);
  friend std::istream &operator>>(std::istream &i, Fraction &K);

  Fraction(int l = 0, int m = 1) : _l(l), _m(m)
  {
  }

  // sk³adowa funkcja operatorowa mno¿enia
  Fraction operator*(const Fraction &K) const
  {
    Fraction tmp;
    tmp._l = _l * K._l;
    tmp._m = _m * K._m;
    return tmp;
  }

  // sk³adowa funkcja operatorowa zmiany znaku
  Fraction operator-() const
  {
    Fraction tmp;
    tmp._l = -_l;
    tmp._m = _m;
    return tmp;
  }

  // sk³adowa funkcja operatorowa odejmowania
  Fraction operator-(const Fraction &K) const
  {
    Fraction tmp;
    tmp._l = _l * K._m - _m * K._l;
    tmp._m = _m * K._m;
    return tmp;
  }

private:
  int _l;
  int _m;
};

/////////////////////////////////////////////////////////////////////////
std::ostream &operator<<(std::ostream &o, const Fraction &K)
{
  return o << K._l << "/" << K._m;
}

/////////////////////////////////////////////////////////////////////////
std::istream &operator>>(std::istream &i, Fraction &K)
{
  char tmp;
  return i >> K._l >> tmp >> K._m;
}

/////////////////////////////////////////////////////////////////////////
int main()
{
  using namespace std;

  Fraction aFraction(1,2);
  Fraction bFraction(2,3);
  Fraction cFraction;

  cout << "Podaj aFraction: ";
  //cin >> aFraction;

  cout << "Podaj bFraction: ";
  //cin >> bFraction;

  // Fraction = aFraction * bFraction;
  cout << "aFraction * bFraction = " << aFraction * bFraction << endl;
/*  cout << "aFraction * bFraction = " << aFraction.operator*(bFraction) << endl;

  cout << "bFraction * 2 = " << bFraction * 2 << endl;

  // nie mo¿na wywo³aæ: 2.operator*(bFraction)
  // cout << "2 * bFraction = " << 2 * bFraction<< endl;

  cFraction = -bFraction;
  cout << "Fraction = " << cFraction << endl;

  cFraction = aFraction - bFraction;
  cout << "Fraction = " << cFraction << endl;
*/}
