
//
// To jest przyk�adowy kod z rozdzia�u 2.3 "Kompilacja" ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

                                // b��d: brak dyrektywy #include
// #include "std_facilities.h"  // b��d: nie mo�na znale�� pliku nag��wka
#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

//integer main()                // b��d: nieznany typ integer
int main()
{
    //cout << "Witaj, �wiecie!\n; // b��d: brak znaku ko�cz�cego �a�cuch
    //cout <  "Witaj, �wiecie!\n";// b��d: brak definicji operatora <
    //cout << 'Witaj, �wiecie!\n';// b��d: nieprawid�owy znak ograniczaj�cy �a�cuchy
    //cout << "Witaj, �wiecie!\n" // b��d: brak �rednika
    cout << "Witaj, �wiecie!\n";
    return 0;
}

//------------------------------------------------------------------------------
