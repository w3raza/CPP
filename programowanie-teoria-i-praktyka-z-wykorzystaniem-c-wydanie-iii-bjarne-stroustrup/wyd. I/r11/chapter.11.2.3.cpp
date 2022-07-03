
//
// To jest przyk³adowy kod z podrozdzia³u 11.2.3 „Wysy³anie na wyjœcie liczb zmiennoprzecinkowych” ksi¹¿ki 
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

int main()
{
    cout << 1234.56789 << "\t\t(ogólny)\n"  // Znaki \t\t wyrównuj¹ kolumny.
         << fixed << 1234.56789 << "\t(sta³y)\n"
         << scientific << 1234.56789 << "\t(naukowy)\n";

    cout << 1234.56789 << '\t'
         << fixed << 1234.56789 << '\t'
         << scientific << 1234.56789 << '\n';
    cout << 1234.56789 << '\n';              // Format zmiennoprzecinkowy jest „trwa³y”.
    cout << general << 1234.56789 << '\t'    // Ostrze¿enie: manipulator general nie jest standardowy.
         << fixed << 1234.56789 << '\t'
         << scientific << 1234.56789 << '\n';
}

//------------------------------------------------------------------------------
