
//
// To jest przyk³adowy kod z podrozdzia³u 10.9 „Definiowanie operatorów wejœciowych” ksi¹¿ki 
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

istream& operator>>(istream& is, Date& dd)
{
    int y, m, d;
    char ch1, ch2, ch3, ch4;
    is >> ch1 >> y >> ch2 >> m >> ch3 >> d >> ch4;
    if (!is) return is;
    if (ch1!='(' || ch2!=',' || ch3!=',' || ch4!=')') {    // B³¹d formatu
        is.clear(ios_base::failbit);
        return is;
    }
    dd = Date(y,Date::Month(m),d);    // aktualizacja dd
    return is;
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

int main()
{
    Date d;
    cout << "WprowadŸ datê: ";
    cin  >> d;
	cout << endl << "d: " << d;
}

//------------------------------------------------------------------------------
