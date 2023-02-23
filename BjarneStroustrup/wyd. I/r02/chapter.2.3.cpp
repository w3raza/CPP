
//
// To jest przyk³adowy kod z rozdzia³u 2.3 "Kompilacja" ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

                                // b³¹d: brak dyrektywy #include
// #include "std_facilities.h"  // b³¹d: nie mo¿na znaleŸæ pliku nag³ówka
#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

//integer main()                // b³¹d: nieznany typ integer
int main()
{
    //cout << "Witaj, œwiecie!\n; // b³¹d: brak znaku koñcz¹cego ³añcuch
    //cout <  "Witaj, œwiecie!\n";// b³¹d: brak definicji operatora <
    //cout << 'Witaj, œwiecie!\n';// b³¹d: nieprawid³owy znak ograniczaj¹cy ³añcuchy
    //cout << "Witaj, œwiecie!\n" // b³¹d: brak œrednika
    cout << "Witaj, œwiecie!\n";
    return 0;
}

//------------------------------------------------------------------------------
