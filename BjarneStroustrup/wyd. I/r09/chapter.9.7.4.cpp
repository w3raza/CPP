
//
// To jest przyk³adowy kod z podrozdzia³u 9.7.4 „Sta³e funkcje sk³adowe” ksi¹¿ki 
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

    int   day()   const;         // Sta³a sk³adowa: nie mo¿e modyfikowaæ obiektów.
    Month month() const;         // Sta³a sk³adowa: nie mo¿e modyfikowaæ obiektów.
    int   year()  const;         // Sta³a sk³adowa: nie mo¿e modyfikowaæ obiektów.

    void add_day(int n);         // Niesta³a sk³adowa: mo¿e modyfikowaæ obiekty.
    void add_month(int n);       // Niesta³a sk³adowa: mo¿e modyfikowaæ obiekty.
    void add_year(int n);        // Niesta³a sk³adowa: mo¿e modyfikowaæ obiekty.
private:
    int   y;                     // Rok
    Month m;
    int   d;                     // Dzieñ miesi¹ca
};

//------------------------------------------------------------------------------

int Date::day() const
{
    //++d;        // B³¹d: próba zmodyfikowania obiektu za pomoc¹ sta³ej funkcji sk³adowej.
    return d;
}

//------------------------------------------------------------------------------

void Date::add_day(int n) {}

//------------------------------------------------------------------------------

void some_function(Date& d, const Date& start_of_term)
{
    int a = d.day();             // ok
    int b = start_of_term.day(); // Powinno byæ dobrze (czemu?).
    d.add_day(3);                // dobrze
    //start_of_term.add_day(3);  // b³¹d
}

//------------------------------------------------------------------------------

int main()
{
    Date d(2000, Date::jan, 20);
    const Date cd(2001, Date::feb, 21);

    cout << d.day() << " - " << cd.day() << endl;        // ok
    d.add_day(1);                // ok
    //cd.add_day(1);             // B³¹d: cd jest const.
    some_function(d,cd);
    //some_function(cd,d);       // B³¹d: cd jest const.
    return 0;
}

//------------------------------------------------------------------------------
