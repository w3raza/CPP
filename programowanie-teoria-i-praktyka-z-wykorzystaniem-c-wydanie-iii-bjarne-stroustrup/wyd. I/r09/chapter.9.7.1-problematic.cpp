
//
// To jest przyk�adowy kod z podrozdzia�u 9.7.1 �Typy argument�w" ksi��ki 
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

//------------------------------------------------------------------------------

// Prosta klasa Date (z u�yciem typu Month).
class Date {
public:
    enum Month {
        jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
    };

    Date(int yy, Month mm, int dd) : y(yy), m(mm), d(dd) // Sprawdza poprawno�� daty i wykonuje inicjacj�.
    {
        // ...
    }

private:
    int   y; // Rok
    Month m;
    int   d; // Dzie�
};

//------------------------------------------------------------------------------

int main()
{
    //Date d1(4,5,2005);            // B��d: Rok 4, dzie� 2005.
    //Date d2(2005,4,5);            // Pi�ty kwietnia czy czwarty maja?

    //Date dx1(1998, 4, 3);         // B��d: drugi argument nie jest typu Month.
    //Date dx2(1998, 4, Date::mar); // B��d: drugi argument nie jest typu Month.
    Date dx2(4, Date::mar, 1998);   // oops: run-time error: day 1998
    //Date dx2(Date::mar, 4, 1998); // B��d: drugi argument nie jest typu Month.
    Date dx3(1998, Date::mar, 30);  // ok
    return 0;
}

//------------------------------------------------------------------------------
