
//
// To jest przyk³adowy kod z podrozdzia³u 9.5 „Wyliczenia” ksi¹¿ki 
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include <iostream>

using namespace std;

//------------------------------------------------------------------------------

enum Month {
    jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dcm
};

//------------------------------------------------------------------------------

enum Day {
    monday, tuesday, wednesday, thursday, friday, saturday, sunday
};

//------------------------------------------------------------------------------

void error(const char* errmsg)
{
    cerr << errmsg << endl;
}

//------------------------------------------------------------------------------

Month int_to_month(int x)
{
    if (x<jan || dcm<x) error("Nieprawid³owy miesi¹c");
    return Month(x);
}

//------------------------------------------------------------------------------

void f(int m)
{
    Month mm = int_to_month(m);
    // ...
}

//------------------------------------------------------------------------------

int main()
try
{
    Month m = feb;
    //m = 7;             // B³¹d: nie mo¿na przypisaæ liczby typu int do obiektu Month
    int n = m;           // Dobrze: mo¿na sprawdziæ wartoœæ liczbow¹ obiektu Month.
    Month mm = Month(7); // Konwersja typu int na Month (bez sprawdzania).

    //Month bad = 9999;  // B³¹d: nie mo¿na przekonwertowaæ typu int na Month.
    f(4);
    f(99);               // B³¹d czasu wykonywania: nieprawid³owy miesi¹c.
}
catch (exception& e) {
    cerr << "B³¹d: " << e.what() << '\n'; 
    return 1;
}
catch (...) {
    cerr << "Nieznany wyj¹tek!\n"; 
    return 2;
}

//------------------------------------------------------------------------------
