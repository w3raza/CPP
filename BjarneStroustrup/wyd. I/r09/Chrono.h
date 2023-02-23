
//
// To jest przyk³adowy kod z podrozdzia³u 9.8 „Klasa Date” ksi¹¿ki „Programming Principles and Practice using C++” Bjarne'a Stroustrupa.
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

    class Invalid { };                 // Do zg³aszania wyj¹tków.

    Date(int y, Month m, int d);       // Sprawdza poprawnoœæ daty i wykonuje inicjacjê.
    Date();                            // Konstruktor domyœlny
    // Domyœlne operacje kopiowania s¹ w porz¹dku.

    // Operacje niemodyfikuj¹ce:
    int   day()   const { return d; }
    Month month() const { return m; }
    int   year()  const { return y; }

    // Operacje modyfikuj¹ce:
    void add_day(int n);        
    void add_month(int n);
    void add_year(int n);
private:
    int   y;
    Month m;
    int   d;
};

//------------------------------------------------------------------------------

bool is_date(int y, Date::Month m, int d); // true, jeœli data jest poprawna.

//------------------------------------------------------------------------------

bool leapyear(int y);                  // true, jeœli y jest rokiem przestêpnym.

//------------------------------------------------------------------------------

bool operator==(const Date& a, const Date& b);
bool operator!=(const Date& a, const Date& b);

//------------------------------------------------------------------------------

ostream& operator<<(ostream& os, const Date& d);
istream& operator>>(istream& is, Date& dd);

//------------------------------------------------------------------------------

} // Chrono
