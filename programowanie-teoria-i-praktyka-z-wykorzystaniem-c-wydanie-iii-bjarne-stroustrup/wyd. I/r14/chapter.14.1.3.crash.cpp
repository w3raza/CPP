
//
// To jest przyk³adowy kod z podrozdzia³u 14.1.3 „Nazewnictwo” ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "Simple_window.h"  // Do³¹cza nasz¹ bibliotekê okien.
#include "Graph.h"          // Do³¹cza do narzêdzi graficznych.

//------------------------------------------------------------------------------

void f(Simple_window& w)
{
    Rectangle r(Point(100,200),50,30);
    w.attach(r);
}    // Tu koñczy siê cykl ¿ycia obiektu r.

//------------------------------------------------------------------------------

int main()
try
{
    Simple_window win(Point(100,100),600,400,"Moje okno");

    Open_polyline opl;
    opl.add(Point(100,100));
    opl.add(Point(150,200));
    opl.add(Point(250,250));

    win.attach(opl);
    // ...
    f(win);        // proszenie siê o k³opoty
    // ...
    win.wait_for_button();
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
