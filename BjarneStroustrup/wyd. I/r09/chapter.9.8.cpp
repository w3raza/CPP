
//
// To jest przyk³adowy kod z podrozdzia³u 9.8 „Klasa Date” ksi¹¿ki 
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include <iostream>

using namespace std;

// file Chrono.h

namespace Chrono {

//------------------------------------------------------------------------------

class Date {
public:
    enum Month {
        jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
    };

    class Invalid { };                 // Do zg³aszania wyj¹tków

    Date(int y, Month m, int d);       // Sprawdza poprawnoœæ daty i wykonuje inicjacjê.
    Date();                            // Konstruktor domyœlny
    // Domyœlne operacje kopiowania s¹ wystarczaj¹ce.

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

//------------------------------------------------------------------------------

// Definicje znajduj¹ siê w pliku Chrono.cpp:

// Chrono.cpp

namespace Chrono {

// Definicje funkcji sk³adowych:

//------------------------------------------------------------------------------

Date::Date(int yy, Month mm, int dd)
    : y(yy), m(mm), d(dd)
{
    if (!is_date(yy,mm,dd)) throw Invalid();
}

//------------------------------------------------------------------------------

const Date& default_date()
{
    static const Date dd(2001,Date::jan,1); // Pocz¹tek XXI wieku.
    return dd;
}

//------------------------------------------------------------------------------

Date::Date()
    :y(default_date().year()),
     m(default_date().month()),
     d(default_date().day())
{
}

//------------------------------------------------------------------------------

void Date:: add_day(int n)
{
    // ...
}

//------------------------------------------------------------------------------

void Date::add_month(int n)
{
    // ...
}

//------------------------------------------------------------------------------

void Date::add_year(int n)
{
    if (m==feb && d==29 && !leapyear(y+n)) { // Uwaga na lata przestêpne!
        m = mar;        // U¿ycie daty 1 marca zamiast 29 lutego.
        d = 1;
    }
    y+=n;
}

//------------------------------------------------------------------------------

// Funkcje pomocnicze.

bool is_date(int y, Date::Month  m, int d)
{
    // Za³o¿enie, ¿e y jest poprawna.

    if (d<=0) return false;            // d musi byæ dodatnia.

    int days_in_month = 31;            // Wiêkszoœæ miesiêcy ma 31 dni.

    switch (m) {
case Date::feb:                        // Liczba dni w lutym jest zmienna.
    days_in_month = (leapyear(y))?29:28;
    break;
case Date::apr: case Date::jun: case Date::sep: case Date::nov:
    days_in_month = 30;                // Reszta ma po 30 dni.
    break;
    }

    if (days_in_month<d) return false;

    return true;
} 

//------------------------------------------------------------------------------

bool leapyear(int y)
{
    return false;
}

//------------------------------------------------------------------------------

bool operator==(const Date& a, const Date& b)
{
    return a.year()==b.year()
        && a.month()==b.month()
        && a.day()==b.day();
}

//------------------------------------------------------------------------------

bool operator!=(const Date& a, const Date& b)
{
    return !(a==b);
}

//------------------------------------------------------------------------------

ostream& operator<<(ostream& os, const Date& d)
{
    return os << '(' << d.year()
              << ',' << d.month()
              << ',' << d.day() 
              << ')';
}

//------------------------------------------------------------------------------

istream& operator>>(istream& is, Date& dd)
{
    int y, m, d;
    char ch1, ch2, ch3, ch4;
    is >> ch1 >> y >> ch2 >> m >> ch3 >> d >> ch4;
    if (!is) return is;
    if (ch1!='(' || ch2!=',' || ch3!=',' || ch4!=')') { // B³¹d formatu
        is.clear(ios_base::failbit);                    // Ustawia bit oznaczaj¹cy niepowodzenie.
        return is;
    }
    dd = Date(y,Date::Month(m),d);     // Aktualizuje dd.
    return is;
}

//------------------------------------------------------------------------------

enum Day {
    sunday, monday, tuesday, wednesday, thursday, friday, saturday
};

//------------------------------------------------------------------------------

Day day_of_week(const Date& d)
{
    // ...
    return sunday;
}

//------------------------------------------------------------------------------

Date next_Sunday(const Date& d)
{
    // ...
    return d;
}

//------------------------------------------------------------------------------

Date next_weekday(const Date& d)
{
    // ...
    return d;
}

//------------------------------------------------------------------------------

} // Chrono

//------------------------------------------------------------------------------

int main()
try
{
    Chrono::Date holiday(1978, Chrono::Date::jul, 4); // inicjacja
    Chrono::Date d2 = Chrono::next_Sunday(holiday);
    Chrono::Day  d  = day_of_week(d2);
    cout << "Wartoœæ holiday: " << holiday << " Wartoœæ d2: " << d2 << endl;
    return holiday != d2;
}
catch (Chrono::Date::Invalid&) {
    cerr << "B³¹d: nieprawid³owa data\n"; 
    return 1;
}
catch (...) {
    cerr << "Nieznany wyj¹tek!\n"; 
    return 2;
}

//------------------------------------------------------------------------------
