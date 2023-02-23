
//
// To jest przyk³adowy kod z podrozdzia³u 9.7.1 „Typy argumentów” ksi¹¿ki 
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include <iostream>

using namespace std;

//------------------------------------------------------------------------------

class Year {        // Rok mieœci siê w zakresie [min:max).
    static const int min = 1800;
    static const int max = 2200;
public:
    class Invalid { };
    Year(int x) : y(x) { if (x<min || max<=x) throw Invalid(); }
    int year() { return y; }
private:
    int y;
};

//------------------------------------------------------------------------------

class Date {
public:
    enum Month {
        jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
    };

    Date(Year yy, Month mm, int dd) : y(yy), m(mm), d(dd) // Sprawdza poprawnoœæ daty i wykonuje inicjacjê.
    {
        // ...
    }

    // ...
private:
    Year y;
    Month m;
    int d;   // dzieñ
};

//------------------------------------------------------------------------------

int main()
try
{
    //Date dx1(Year(1998), 4, 3);         // B³¹d: drugi argument nie jest typu Month.
    //Date dx2(Year(1998), 4, Date::mar); // B³¹d: drugi argument nie jest typu Month.
    //Date dx2(4, Date::mar, Year(1998)); // B³¹d: pierwszy argument nie jest typu Year.
    //Date dx2(Date::mar, 4, Year(1998)); // B³¹d: drugi argument nie jest typu Month.
    Date dx3(Year(1998), Date::mar, 30);  // ok

    // Ten dziwny i ma³o prawdopodobny b³¹d nie zosta³by znaleziony do czasu uruchomienia programu:
    Date dx5(Year(4), Date::mar, 1998);   // B³¹d czasu wykonywania: Year::Invalid
}
catch (Year::Invalid&) {
    cerr << "B³¹d: nieprawid³owy rok.\n"; 
    return 1;
}
catch (...) {
    cerr << "Nieznany wyj¹tek!\n"; 
    return 2;
}

//------------------------------------------------------------------------------
