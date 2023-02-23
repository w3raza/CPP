
//
// To jest przyk³adowy kod z podrozdzia³u 10.8 „Definiowanie operatorów wyjœciowych” ksi¹¿ki 
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include <iostream>

using namespace std;

//------------------------------------------------------------------------------

class Date {
public:
    enum Month {
        jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
    };

    Date() {}                                               // Konstruktor domyœlny
    Date(int yy, Month mm, int dd) : y(yy), m(mm), d(dd) {} // Konstruktor
    Month month() const { return m; }
    int   day()   const { return d; }
    int   year()  const { return y; }

private:
    int y;
    Month m;
    int d;
};

//------------------------------------------------------------------------------

ostream& operator<<(ostream& os, const Date& d)
{
    return os << '(' << d.year()
              << ',' << d.month()
              << ',' << d.day() 
              << ')';
}

//------------------------------------------------------------------------------

int main()
{
    Date d1(1994,Date::mar,29);
    Date d2(2000,Date::feb,15);

    cout << d1;       // To samo, co operator<<(cout,d1);
    operator<<(cout,d1);
    cout << d1 << d2; // To samo, co operator<<(cout,d1) << d2;
    // To samo, co operator<<(operator<<(cout,d1),d2);
    operator<<(operator<<(cout,d1),d2);
}

//------------------------------------------------------------------------------
