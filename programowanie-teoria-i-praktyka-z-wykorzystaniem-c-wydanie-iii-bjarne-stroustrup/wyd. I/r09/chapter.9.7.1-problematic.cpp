
//
// To jest przyk³adowy kod z podrozdzia³u 9.7.1 „Typy argumentów" ksi¹¿ki 
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

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

private:
    int   y; // Rok
    Month m;
    int   d; // Dzieñ
};

//------------------------------------------------------------------------------

int main()
{
    //Date d1(4,5,2005);            // B³¹d: Rok 4, dzieñ 2005.
    //Date d2(2005,4,5);            // Pi¹ty kwietnia czy czwarty maja?

    //Date dx1(1998, 4, 3);         // B³¹d: drugi argument nie jest typu Month.
    //Date dx2(1998, 4, Date::mar); // B³¹d: drugi argument nie jest typu Month.
    Date dx2(4, Date::mar, 1998);   // oops: run-time error: day 1998
    //Date dx2(Date::mar, 4, 1998); // B³¹d: drugi argument nie jest typu Month.
    Date dx3(1998, Date::mar, 30);  // ok
    return 0;
}

//------------------------------------------------------------------------------
