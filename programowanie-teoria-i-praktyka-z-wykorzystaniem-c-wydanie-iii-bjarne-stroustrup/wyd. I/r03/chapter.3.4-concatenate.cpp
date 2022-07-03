
//
// To jest przyk³adowy kod z rozdzia³u 3.4 "Operacje i operatory" ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

// Wczytuje imiê i nazwisko.
int main()
{
    cout << "Podaj imiê i nazwisko.\n";
    string first;
    string second;
    cin >> first >> second;                // Wczytuje dwa ³añcuchy.
    string name = first + ' ' + second;    // £¹czy ³añcuchy (konkatenacja ³añcuchów).
    cout << "Witaj, " << name << '\n';
}

//------------------------------------------------------------------------------
