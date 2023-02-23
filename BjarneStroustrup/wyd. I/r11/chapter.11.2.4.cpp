
//
// To jest przyk³adowy kod z podrozdzia³u 11.2.4 „Precyzja” ksi¹¿ki 
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

int main()
{
    cout << 1234.56789 << '\t'
         << fixed << 1234.56789 << '\t'
         << scientific << 1234.56789 << '\n';
    cout << general << setprecision(5)
         << 1234.56789 << '\t'
         << fixed << 1234.56789 << '\t'
         << scientific << 1234.56789 << '\n';
    cout << general << setprecision(8)
         << 1234.56789 << '\t'
         << fixed << 1234.56789 << '\t'
         << scientific << 1234.56789 << '\n';
}

//------------------------------------------------------------------------------
