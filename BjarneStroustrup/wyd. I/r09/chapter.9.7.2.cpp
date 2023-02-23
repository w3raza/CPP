
//
// To jest przyk³adowy kod z podrozdzia³u 9.7.2 „Kopiowanie” ksi¹¿ki 
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include <iostream>

using namespace std;

//------------------------------------------------------------------------------

// Prosta klasa Date (z u¿yciem typu Month).
class Date {
public:
    enum Month {
        jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
    };

    Date(int yy, Month mm, int dd) : y(yy), m(mm), d(dd) // Sprawdza poprawnoœæ daty i wykonuje inicjacjê.
    {
        // ...
    }

    friend ostream& operator<<(ostream& os, const Date& d)
    {
        return os << '(' << d.y << ',' << d.m << ',' << d.d << ')';
    }

private:
    int   y; // Rok
    Month m;
    int   d; // dzieñ
};

//------------------------------------------------------------------------------

int main()
{
    Date holiday(1978, Date::jul, 4);     // inicjacja
    Date d2 = holiday;
    Date d3 = Date(1978, Date::jul, 4);

    holiday = Date(1978, Date::dec, 24);  // przypisanie
    d3 = holiday;

    cout << Date(1978, Date::dec, 24);
    return 0;
}

//------------------------------------------------------------------------------
