
//
// Przyk�adowy kod z rozdzia�u 6.3.1 "Pierwsza pr�ba" ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

int main()
{
    cout << "Wpisz wyra�enie (obs�ugujemy operatory + i �): ";
    int lval = 0;
    int rval;
    char op;
    int res;
    cin>>lval>>op>>rval;      // Wczytuje co� w rodzaju 1 + 3.

    if (op=='+')
        res = lval + rval;    // dodawanie
    else if (op=='-')
        res = lval - rval;    // odejmowanie

    cout << "Wynik: " << res << '\n';
    keep_window_open();
    return 0;
}

//------------------------------------------------------------------------------
