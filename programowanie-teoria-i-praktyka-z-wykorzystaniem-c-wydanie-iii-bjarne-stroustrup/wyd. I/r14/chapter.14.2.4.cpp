
//
// To jest przyk³adowy kod z podrozdzia³u 14.2.4 „Kopiowanie i zmiennoœæ” ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "Simple_window.h"    // Do³¹cza nasz¹ bibliotekê okien.
#include "Graph.h"            // Do³¹cza do narzêdzi graficznych.

//------------------------------------------------------------------------------

void my_fct(const Open_polyline& op, const Circle& c)
{
    //Open_polyline op2 = op; // B³¹d: konstruktor kopiuj¹cy klasy Shape jest prywatny.
    vector<Shape> v;
    //v.push_back(c);         // B³¹d: konstruktor kopiuj¹cy klasy Shape jest prywatny.
    // ...
    //op = op2;               // B³¹d: operacja przypisania klasy Shape jest prywatna.
}

//------------------------------------------------------------------------------

int main()
try
{
    Point p;
    Marked_polyline mp("x");
    Circle c(p,10);
    my_fct(mp,c);             // Argument Open_polyline staje siê referencj¹ do Marked_polyline.
}
catch(exception& e) {
    // Raport o b³êdzie.
    return 1;
}
catch(...) {
    // Raport o b³êdzie.
    return 2;
}

//------------------------------------------------------------------------------
