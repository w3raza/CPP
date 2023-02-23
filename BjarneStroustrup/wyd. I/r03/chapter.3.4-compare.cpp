
//
// To jest przyk³adowy kod z rozdzia³u 3.4 "Operacje i operatory" ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

// Wczytuje i porównuje ³añcuchy.
int main()
{
    cout << "Podaj dwa imiona.\n";
    string first;
    string second;
    cin >> first >> second; // Wczytuje dwa ³añcuchy.
    if (first == second) cout << "Podano dwa takie same imiona.\n";
    if (first < second)
        cout << first << " jest w kolejnoœci alfabetycznej przed " << second <<'\n';
    if (first > second)
        cout << first << " jest w kolejnoœci alfabetycznej za " << second <<'\n';
}

//------------------------------------------------------------------------------
