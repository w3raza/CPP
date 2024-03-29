
//
// To jest przyk�adowy kod z podrozdzia�u 13.14 �Typ Marked_polyline" ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "Simple_window.h"  // Do��cza nasz� bibliotek� okien.
#include "Graph.h"          // Do��cza narz�dzia graficzne.

//------------------------------------------------------------------------------

int main()
try
{
    using namespace Graph_lib;   // Nasze narz�dzia graficzne znajduj� si� w bibliotece Graph_lib

    Simple_window win(Point(100,100),600,400,"�amana z punktami");

    Marked_polyline mpl("1234");
    mpl.add(Point(100,100));
    mpl.add(Point(150,200));
    mpl.add(Point(250,250));
    mpl.add(Point(300,200));

    win.attach(mpl);

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
