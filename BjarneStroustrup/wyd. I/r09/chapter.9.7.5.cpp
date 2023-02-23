
//
// To jest przyk³adowy kod z podrozdzia³u 9.7.5 „Sk³adowe i funkcje pomocnicze” ksi¹¿ki 
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

//------------------------------------------------------------------------------

class Date {
public:
    enum Month {
        jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
    };

    Date(int yy, Month mm, int dd) : y(yy), m(mm), d(dd) {}

    int day() const { return d; }
    Month month() const { return m; }
    int year() const { return y; }

private:
    int   y;                // Rok
    Month m;
    int   d;                // Dzieñ miesi¹ca
};

//------------------------------------------------------------------------------

// Kilka przyk³adów funkcji pomocniczych:

Date next_Sunday(const Date& d)
{
    // Uzyskuje dostêp do d za pomoc¹ d.day(), d.month() i d.year().
    // Tworzy nowy obiekt typu Date, który jest zwracany.
    return d;
}

//------------------------------------------------------------------------------

Date next_weekday(const Date& d) { /* ... */ return d; }

//------------------------------------------------------------------------------

bool leapyear(int d, int m, int y) { /* ... */ return false; }

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

namespace Chrono {
    class Date { /* ... */ };
    Date next_Sunday(const Date& d) { /* ... */ return d; }
    Date next_weekday(const Date& d) { /* ... */ return d; }
    bool leapyear(int d, int m, int y) { /* ... */ return false; }
    bool operator==(const Date& a, const Date& b) { /* ... */ return false; }
    // ...
}

//------------------------------------------------------------------------------

int main()
{
    Date d(2008,Date::feb,23);
    bool b = next_Sunday(d) != next_weekday(d);
    Chrono::Date dd;
    return 0;
}

//------------------------------------------------------------------------------
