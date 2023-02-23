
//
// To jest przyk�adowy kod z podrozdzia�u 8.5.3 �Przekazywanie przez warto�� ksi��ki 
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------


// Przekazywanie przez warto�� (podawanie funkcji kopii przekazywanej warto�ci).
int f(int x)
{
    x = x+1;                    // Nadanie lokalnej zmiennej x nowej warto�ci.
    return x;
}

//------------------------------------------------------------------------------

int main()
{
    int xx = 0;
    cout << f(xx) << endl;      // Drukuje: 1.
    cout << xx << endl;         // Drukuje: 0; f() nie zmienia xx.

    int yy = 7;
    cout << f(yy) << endl;      // Drukuje: 8.
    cout << yy << endl;         // Drukuje: 7; f() nie zmienia yy.
}

//------------------------------------------------------------------------------
