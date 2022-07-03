
//
// To jest przyk�adowy kod z podrozdzia�u 9.7.4 �Sta�e funkcje sk�adowe� ksi��ki 
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

    Date(int yy, Month mm, int dd) : y(yy), m(mm), d(dd) {}

    int   day()   const;         // Sta�a sk�adowa: nie mo�e modyfikowa� obiekt�w.
    Month month() const;         // Sta�a sk�adowa: nie mo�e modyfikowa� obiekt�w.
    int   year()  const;         // Sta�a sk�adowa: nie mo�e modyfikowa� obiekt�w.

    void add_day(int n);         // Niesta�a sk�adowa: mo�e modyfikowa� obiekty.
    void add_month(int n);       // Niesta�a sk�adowa: mo�e modyfikowa� obiekty.
    void add_year(int n);        // Niesta�a sk�adowa: mo�e modyfikowa� obiekty.
private:
    int   y;                     // Rok
    Month m;
    int   d;                     // Dzie� miesi�ca
};

//------------------------------------------------------------------------------

int Date::day() const
{
    //++d;        // B��d: pr�ba zmodyfikowania obiektu za pomoc� sta�ej funkcji sk�adowej.
    return d;
}

//------------------------------------------------------------------------------

void Date::add_day(int n) {}

//------------------------------------------------------------------------------

void some_function(Date& d, const Date& start_of_term)
{
    int a = d.day();             // ok
    int b = start_of_term.day(); // Powinno by� dobrze (czemu?).
    d.add_day(3);                // dobrze
    //start_of_term.add_day(3);  // b��d
}

//------------------------------------------------------------------------------

int main()
{
    Date d(2000, Date::jan, 20);
    const Date cd(2001, Date::feb, 21);

    cout << d.day() << " - " << cd.day() << endl;        // ok
    d.add_day(1);                // ok
    //cd.add_day(1);             // B��d: cd jest const.
    some_function(d,cd);
    //some_function(cd,d);       // B��d: cd jest const.
    return 0;
}

//------------------------------------------------------------------------------
