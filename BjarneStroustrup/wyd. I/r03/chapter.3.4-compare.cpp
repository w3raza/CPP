
//
// To jest przyk�adowy kod z rozdzia�u 3.4 "Operacje i operatory" ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

// Wczytuje i por�wnuje �a�cuchy.
int main()
{
    cout << "Podaj dwa imiona.\n";
    string first;
    string second;
    cin >> first >> second; // Wczytuje dwa �a�cuchy.
    if (first == second) cout << "Podano dwa takie same imiona.\n";
    if (first < second)
        cout << first << " jest w kolejno�ci alfabetycznej przed " << second <<'\n';
    if (first > second)
        cout << first << " jest w kolejno�ci alfabetycznej za " << second <<'\n';
}

//------------------------------------------------------------------------------
