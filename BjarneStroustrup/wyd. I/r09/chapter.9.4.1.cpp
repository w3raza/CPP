
//
// To jest przyk³adowy kod z podrozdzia³u 9.4.1 „Struktury i funkcje” ksi¹¿ki 
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

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

void add_day(Date& dd, int n)
{
    // Zwiêksza dd o n dni.
}

//------------------------------------------------------------------------------

void f()
{
    Date today;
    init_day(today, 12, 24, 2005); // B³¹d: nie ma dnia 2005 w roku 12.
    add_day(today,1);
}

//------------------------------------------------------------------------------

int main()
{
    Date today; // Zmienna typu Date (nazwany obiekt).

    // Ustawia datê na 24 grudnia 2005.
    today.y = 2005;
    today.m = 24;
    today.d = 12;

    Date x;
    x.y = -3;
    x.m = 13;
    x.d = 32;

    // Czy 2000 by³ rokiem przestêpnym? Na pewno?
    Date y;
    y.y = 2000;
    y.m = 2;
    y.d = 29;

    init_day(y, 2000, 1, 1);
    add_day(y, 28);
    return 0;
}

//------------------------------------------------------------------------------
