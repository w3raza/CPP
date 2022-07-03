
//
// Przyk�adowy kod z rozdzia�u 5.6.4 "B��dy zaw�ania zakresu" ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

int main()
try
{
    int x = 2.9;
    char c = 2000;

    int x1 = narrow_cast<int>(2.9);       // wyj�tek
    int x2 = narrow_cast<int>(2.0);       // ok
    char c1 = narrow_cast<char>(2000);    // wyj�tek
    char c2 = narrow_cast<char>(85);      // ok
}
catch (exception& e) {
    cerr << "B��d: " << e.what() << '\n'; 
    return 1;
}
catch (...) {
    cerr << "Nieznany wyj�tek!\n"; 
    return 2;
}

//------------------------------------------------------------------------------
