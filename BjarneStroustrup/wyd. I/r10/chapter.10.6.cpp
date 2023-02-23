
//
// To jest przyk³adowy kod z podrozdzia³u 10.6 „Obs³uga b³êdów wejœcia i wyjœcia” ksi¹¿ki 
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

using namespace std;

//------------------------------------------------------------------------------

int main()
try
{
    int i = 0;
    cin >> i;
    if (!cin) {    // Ten kod bêdzie wykonywany, tylko gdy nie powiedzie siê operacja wejœciowa.
        if (cin.bad()) error("Z³y stan strumienia cin."); // Uszkodzony strumieñ: wynosimy siê st¹d!
        if (cin.eof()) {
            // Nie ma wiêcej danych wejœciowych.
            // W taki sposób powinny koñczyæ siê serie operacji wejœciowych.
        }
        if (cin.fail()) {   // Strumieñ napotka³ coœ, czego siê nie spodziewa³.
            cin.clear();    // Przygotowanie na wiêcej danych.
            // Odzyskiwanie sprawnoœci.
        }
    }
}
catch (exception& e) {
    cerr << "B³¹d: " << e.what() << '\n'; 
    return 1;
}
catch (...) {
    cerr << "Nieznany wyj¹tek!\n"; 
    return 2;
}

//------------------------------------------------------------------------------
