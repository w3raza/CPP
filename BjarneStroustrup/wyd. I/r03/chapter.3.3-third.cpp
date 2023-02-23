
//
// To jest przyk³adowy kod z rozdzia³u 3.3 "Typy danych wejœciowych" ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

int main()
{
    cout << "Podaj imiê i nazwisko.\n";
    string first;
    string second;
    cin >> first >> second;    // Wczytuje dwa ³añcuchy.
    cout << "Witaj, " << first << ' ' << second << '\n';
}

//------------------------------------------------------------------------------
