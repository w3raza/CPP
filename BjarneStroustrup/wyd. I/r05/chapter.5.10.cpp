
//
// Przyk³adowy kod z rozdzia³u 5.10 "Warunki wstêpne i koñcowe" ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

int my_complicated_function(int a, int b, int c)
// Argumenty musz¹ byæ dodatnie oraz a < b < c.
{
    if (!(0<a && a<b && b<c))    // ! oznacza „nie”, a && oznacza „i”.
        error("Nieprawid³owe argumenty funkcji mcf.");
    // ...
}

//------------------------------------------------------------------------------

int main()
try
{
    //int x = my_complicated_function(1, 2, "horsefeathers");
    int y = my_complicated_function(1, 2, 3);
    int z = my_complicated_function(3, 2, 1);
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
