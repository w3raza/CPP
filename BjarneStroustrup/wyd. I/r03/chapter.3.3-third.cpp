
//
// To jest przyk�adowy kod z rozdzia�u 3.3 "Typy danych wej�ciowych" ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

int main()
{
    cout << "Podaj imi� i nazwisko.\n";
    string first;
    string second;
    cin >> first >> second;    // Wczytuje dwa �a�cuchy.
    cout << "Witaj, " << first << ' ' << second << '\n';
}

//------------------------------------------------------------------------------
