
//
// To jest przyk³adowy kod z rozdzia³u 3.7 "Nazwy" ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

//int Main() // b³¹d: brak funkcji main
int main()
{
    //String s = "¯egnaj, okrutny œwiecie!"; // b³¹d: nieznany typ String
    string s = "¯egnaj, okrutny œwiecie! ";

    //cOut << S << '\n';                     // b³¹d: nieznane identyfikatory cOut i S
    cout << s << '\n';

    //int if = 7;                            // b³¹d: if jest s³owem kluczowym
    //int string = 7;                        // To sprowadzi na Ciebie k³opoty.
}

//------------------------------------------------------------------------------
