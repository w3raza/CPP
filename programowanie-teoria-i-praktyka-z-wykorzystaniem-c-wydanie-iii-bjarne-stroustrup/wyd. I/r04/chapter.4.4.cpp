
//
// Przyk�adowy kod z rozdzia�u 4.4 "Instrukcje" ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

int main()
{
    int a = 7;
    int b = 4;

    a = b;
    ++b;
    //a = b ++ b;    // B��d sk�adni: brak �rednik�w.
    cout << a << '\n';
    1+2;    // Dodaje liczby, ale nie wykorzystuje ich sumy w �aden spos�b.
    a*b;    // Mno�y liczby, ale nie wykorzystuje ich iloczynu w �aden spos�b.

    int x = 1;
    int y = 5;

    if (x == 5);
    { y = 3; }

    cout << y << '\n';
}

//------------------------------------------------------------------------------
