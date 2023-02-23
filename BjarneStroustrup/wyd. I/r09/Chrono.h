
//
// To jest przyk�adowy kod z podrozdzia�u 9.8 �Klasa Date� ksi��ki �Programming Principles and Practice using C++� Bjarne'a Stroustrupa.
//

#include <iostream>

using namespace std;

//------------------------------------------------------------------------------

namespace Chrono {

//------------------------------------------------------------------------------

class Date {
public:
    enum Month {
        jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
    };

    class Invalid { };                 // Do zg�aszania wyj�tk�w.

    Date(int y, Month m, int d);       // Sprawdza poprawno�� daty i wykonuje inicjacj�.
    Date();                            // Konstruktor domy�lny
    // Domy�lne operacje kopiowania s� w porz�dku.

    // Operacje niemodyfikuj�ce:
    int   day()   const { return d; }
    Month month() const { return m; }
    int   year()  const { return y; }

    // Operacje modyfikuj�ce:
    void add_day(int n);        
    void add_month(int n);
    void add_year(int n);
private:
    int   y;
    Month m;
    int   d;
};

//------------------------------------------------------------------------------

bool is_date(int y, Date::Month m, int d); // true, je�li data jest poprawna.

//------------------------------------------------------------------------------

bool leapyear(int y);                  // true, je�li y jest rokiem przest�pnym.

//------------------------------------------------------------------------------

bool operator==(const Date& a, const Date& b);
bool operator!=(const Date& a, const Date& b);

//------------------------------------------------------------------------------

ostream& operator<<(ostream& os, const Date& d);
istream& operator>>(istream& is, Date& dd);

//------------------------------------------------------------------------------

} // Chrono
