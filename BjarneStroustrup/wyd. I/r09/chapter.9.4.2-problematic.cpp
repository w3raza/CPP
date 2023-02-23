
//
// To jest przyk³adowy kod z podrozdzia³u 9.4.2 „Funkcje sk³adowe i konstruktory” ksi¹¿ki 
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include <iostream>

using namespace std;

//------------------------------------------------------------------------------

// Prosta struktura Date (za prosta?).
struct Date {
    int y; // Rok
    int m; // Miesi¹c roku
    int d; // Dzieñ miesi¹ca
};

//------------------------------------------------------------------------------

// Funkcje pomocnicze.

void init_day(Date& dd, int y, int m, int d)
{
    // Sprawdza, czy (y,m,d) jest poprawn¹ dat¹.
    // Jeœli tak, inicjuje ni¹ dd.
}

//------------------------------------------------------------------------------

ostream& operator<<(ostream& os, const Date& d)
{
    return os << '(' << d.y << ',' << d.m << ',' << d.d << ')';
}

//------------------------------------------------------------------------------

void f()
{
    Date today;
    // ...
    cout << today << '\n';         // U¿ycie obiektu today.
    // ...
    init_day(today, 12, 24, 2005); // B³¹d: nie ma dnia 2005 w roku 12. 
    // ...
    Date tomorrow;
    tomorrow.y = today.y;
    tomorrow.m = today.m;
    tomorrow.d = today.d+1;        // Dodaje 1 do today.
    cout << tomorrow << '\n';      // U¿ycie obiektu tomorrow.
}

//------------------------------------------------------------------------------

int main()
{
    f();
    return 0;
}

//------------------------------------------------------------------------------
