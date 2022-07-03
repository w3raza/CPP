
//
// Przyk³adowy kod z rozdzia³u 5.6.4 "B³êdy zawê¿ania zakresu" ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

int main()
try
{
    int x = 2.9;
    char c = 2000;

    int x1 = narrow_cast<int>(2.9);       // wyj¹tek
    int x2 = narrow_cast<int>(2.0);       // ok
    char c1 = narrow_cast<char>(2000);    // wyj¹tek
    char c2 = narrow_cast<char>(85);      // ok
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
