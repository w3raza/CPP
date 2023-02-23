
//
// To jest przyk�adowy kod z podrozdzia�u 14.1.3 �Nazewnictwo� ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "Simple_window.h"  // Do��cza nasz� bibliotek� okien.
#include "Graph.h"          // Do��cza do narz�dzi graficznych.

//------------------------------------------------------------------------------

void f(Simple_window& w)
{
    Rectangle r(Point(100,200),50,30);
    w.attach(r);
}    // Tu ko�czy si� cykl �ycia obiektu r.

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
    f(win);        // proszenie si� o k�opoty
    // ...
    win.wait_for_button();
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
