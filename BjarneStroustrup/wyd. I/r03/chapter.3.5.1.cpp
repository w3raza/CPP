
//
// To jest przyk³adowy kod z rozdzia³u 3.5.1 "Przyk³ad usuwania powtarzaj¹cych siê s³ów" ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

int main()
{
    string previous = " ";       // poprzednie s³owo; zainicjowane "nies³owem"
    string current;              // bie¿¹ce s³owo
    while (cin>>current) {       // wczytanie strumienia s³ów
        if (previous == current) // sprawdzenie, czy dane s³owo jest takie samo, jak ostatnie
            cout << "Powtórzone s³owo: " << current << '\n';
        previous = current;
    }
}

//------------------------------------------------------------------------------
