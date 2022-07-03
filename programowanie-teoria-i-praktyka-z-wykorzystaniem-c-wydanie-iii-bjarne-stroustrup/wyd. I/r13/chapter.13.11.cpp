
//
// To jest przyk�adowy kod z podrozdzia�u 13.11 �Typ Text� ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "Simple_window.h"  // Do��cza nasz� bibliotek� okien.
#include "Graph.h"          // Do��cza narz�dzia graficzne.

//------------------------------------------------------------------------------

int main()
try
{
    using namespace Graph_lib;   // Nasze narz�dzia graficzne znajduj� si� w bibliotece Graph_lib

    Simple_window win(Point(100,100),600,400,"Zamkni�ta �amana");    

    Closed_polyline cpl;

    cpl.add(Point(100,100));
    cpl.add(Point(150,200));
    cpl.add(Point(250,250));
    cpl.add(Point(300,200));
    cpl.add(Point(100,250));
    win.attach(cpl);

    Text t(Point(200,200),"Zamkni�ta �amana, kt�ra nie jest wielok�tem");    
    t.set_color(Color::blue);
    win.attach(t);

    win.wait_for_button();       // Wy�wietl!
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
