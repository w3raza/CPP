
//
// To jest przyk�adowy kod z rozdzia�u 3.7 "Nazwy" ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

//int Main() // b��d: brak funkcji main
int main()
{
    //String s = "�egnaj, okrutny �wiecie!"; // b��d: nieznany typ String
    string s = "�egnaj, okrutny �wiecie! ";

    //cOut << S << '\n';                     // b��d: nieznane identyfikatory cOut i S
    cout << s << '\n';

    //int if = 7;                            // b��d: if jest s�owem kluczowym
    //int string = 7;                        // To sprowadzi na Ciebie k�opoty.
}

//------------------------------------------------------------------------------
