
//
// To jest przyk�adowy kod z podrozdzia�u 9.4.3 �Ukrywanie szczeg��w� ksi��ki 
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include <iostream>

using namespace std;

//------------------------------------------------------------------------------

// Prosty typ Date (kontrola dost�pu).
class Date {
    int y, m, d;                      // Rok, miesi�c, dzie�
public:
    Date(int y, int m, int d);        // Sprawdza poprawno�� daty i wykonuje inicjacj�.
    void add_day(int n);              // Zwi�ksza Date o n dni.
    int month() { return m; }
    int day()   { return d; }
    int year()  { return y; }
};

//------------------------------------------------------------------------------

Date::Date(int y, int m, int d) : y(y), m(m), d(d) {}

//------------------------------------------------------------------------------

int main()
{
    Date birthday(1970, 12, 30);      // ok
    //birthday.m = 14;                // B��d: sk�adowa Date::m jest prywatna.
    cout << birthday.month() << endl; // Spos�b na dost�p do m.
}

//------------------------------------------------------------------------------
