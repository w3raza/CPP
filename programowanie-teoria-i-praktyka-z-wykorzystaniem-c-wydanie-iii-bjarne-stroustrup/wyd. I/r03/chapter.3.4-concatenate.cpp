
//
// To jest przyk�adowy kod z rozdzia�u 3.4 "Operacje i operatory" ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

// Wczytuje imi� i nazwisko.
int main()
{
    cout << "Podaj imi� i nazwisko.\n";
    string first;
    string second;
    cin >> first >> second;                // Wczytuje dwa �a�cuchy.
    string name = first + ' ' + second;    // ��czy �a�cuchy (konkatenacja �a�cuch�w).
    cout << "Witaj, " << name << '\n';
}

//------------------------------------------------------------------------------
