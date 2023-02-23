
//
// To jest przyk�adowy kod z podrozdzia�u 9.7.3 �Konstruktory domy�lne� ksi��ki 
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include <vector>

using namespace std;

//------------------------------------------------------------------------------

class Date {
public:
    enum Month {
        jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
    };

    Date();                         // Konstruktor domy�lny
    Date(int yy, Month mm, int dd); // Konstruktor
    Month month() const { return m; }
    int   day()   const { return d; }
    int   year()  const { return y; }

private:
    int   y;
    Month m;
    int   d;
};

//------------------------------------------------------------------------------

const Date& default_date()
{
    static const Date dd(2001,Date::jan,1);
    return dd;
}

//------------------------------------------------------------------------------

Date::Date() :
     y(default_date().year()),
     m(default_date().month()),
     d(default_date().day())
{
}

//------------------------------------------------------------------------------

Date::Date(int yy, Month mm, int dd) :
     y(yy), m(mm), d(dd)
{
}

//------------------------------------------------------------------------------

int main()
{
    vector<Date> birthdays(10);

    // Gdyby nie konstruktor domy�lny, trzeba by by�o wszystko poda� jawnie:
    {
        vector<Date> birthdays(10,default_date());
    }
    return 0;
}

//------------------------------------------------------------------------------
