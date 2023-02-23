
//
// To jest przyk³adowy kod z podrozdzia³u 9.4.3 „Ukrywanie szczegó³ów” ksi¹¿ki 
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include <iostream>

using namespace std;

//------------------------------------------------------------------------------

// Prosty typ Date (kontrola dostêpu).
class Date {
    int y, m, d;                      // Rok, miesi¹c, dzieñ
public:
    Date(int y, int m, int d);        // Sprawdza poprawnoœæ daty i wykonuje inicjacjê.
    void add_day(int n);              // Zwiêksza Date o n dni.
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
    //birthday.m = 14;                // B³¹d: sk³adowa Date::m jest prywatna.
    cout << birthday.month() << endl; // Sposób na dostêp do m.
}

//------------------------------------------------------------------------------
