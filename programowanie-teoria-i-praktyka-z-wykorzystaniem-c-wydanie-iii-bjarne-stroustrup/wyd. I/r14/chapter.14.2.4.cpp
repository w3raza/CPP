
//
// To jest przyk�adowy kod z podrozdzia�u 14.2.4 �Kopiowanie i zmienno�� ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "Simple_window.h"    // Do��cza nasz� bibliotek� okien.
#include "Graph.h"            // Do��cza do narz�dzi graficznych.

//------------------------------------------------------------------------------

void my_fct(const Open_polyline& op, const Circle& c)
{
    //Open_polyline op2 = op; // B��d: konstruktor kopiuj�cy klasy Shape jest prywatny.
    vector<Shape> v;
    //v.push_back(c);         // B��d: konstruktor kopiuj�cy klasy Shape jest prywatny.
    // ...
    //op = op2;               // B��d: operacja przypisania klasy Shape jest prywatna.
}

//------------------------------------------------------------------------------

int main()
try
{
    Point p;
    Marked_polyline mp("x");
    Circle c(p,10);
    my_fct(mp,c);             // Argument Open_polyline staje si� referencj� do Marked_polyline.
}
catch(exception& e) {
    // Raport o b��dzie.
    return 1;
}
catch(...) {
    // Raport o b��dzie.
    return 2;
}

//------------------------------------------------------------------------------
