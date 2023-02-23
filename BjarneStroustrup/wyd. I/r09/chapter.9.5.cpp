
//
// To jest przyk�adowy kod z podrozdzia�u 9.5 �Wyliczenia� ksi��ki 
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
    if (x<jan || dcm<x) error("Nieprawid�owy miesi�c");
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
    //m = 7;             // B��d: nie mo�na przypisa� liczby typu int do obiektu Month
    int n = m;           // Dobrze: mo�na sprawdzi� warto�� liczbow� obiektu Month.
    Month mm = Month(7); // Konwersja typu int na Month (bez sprawdzania).

    //Month bad = 9999;  // B��d: nie mo�na przekonwertowa� typu int na Month.
    f(4);
    f(99);               // B��d czasu wykonywania: nieprawid�owy miesi�c.
}
catch (exception& e) {
    cerr << "B��d: " << e.what() << '\n'; 
    return 1;
}
catch (...) {
    cerr << "Nieznany wyj�tek!\n"; 
    return 2;
}

//------------------------------------------------------------------------------
