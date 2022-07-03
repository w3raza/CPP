
//
// To jest przyk�adowy kod z rozdzia�u 3.5.1 "Przyk�ad usuwania powtarzaj�cych si� s��w" ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

int main()
{
    string previous = " ";       // poprzednie s�owo; zainicjowane "nies�owem"
    string current;              // bie��ce s�owo
    while (cin>>current) {       // wczytanie strumienia s��w
        if (previous == current) // sprawdzenie, czy dane s�owo jest takie samo, jak ostatnie
            cout << "Powt�rzone s�owo: " << current << '\n';
        previous = current;
    }
}

//------------------------------------------------------------------------------
