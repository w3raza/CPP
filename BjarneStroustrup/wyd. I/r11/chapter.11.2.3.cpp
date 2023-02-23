
//
// To jest przyk�adowy kod z podrozdzia�u 11.2.3 �Wysy�anie na wyj�cie liczb zmiennoprzecinkowych� ksi��ki 
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

int main()
{
    cout << 1234.56789 << "\t\t(og�lny)\n"  // Znaki \t\t wyr�wnuj� kolumny.
         << fixed << 1234.56789 << "\t(sta�y)\n"
         << scientific << 1234.56789 << "\t(naukowy)\n";

    cout << 1234.56789 << '\t'
         << fixed << 1234.56789 << '\t'
         << scientific << 1234.56789 << '\n';
    cout << 1234.56789 << '\n';              // Format zmiennoprzecinkowy jest �trwa�y�.
    cout << general << 1234.56789 << '\t'    // Ostrze�enie: manipulator general nie jest standardowy.
         << fixed << 1234.56789 << '\t'
         << scientific << 1234.56789 << '\n';
}

//------------------------------------------------------------------------------
