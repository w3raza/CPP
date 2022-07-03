
//
// Przyk³adowy kod z rozdzia³u 5.11 "Æwiczenia" ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

int main()
try {
    // <<Twój kod>>
    keep_window_open();
    return 0;
}
catch (exception& e) {
    cerr << "B³¹d: " << e.what() << '\n'; 
    keep_window_open();
    return 1;
}
catch (...) {
    cerr << "Nieznany wyj¹tek!\n"; 
    keep_window_open();
    return 2;
}

//------------------------------------------------------------------------------
