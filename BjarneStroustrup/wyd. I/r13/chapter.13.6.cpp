
//
// To jest przyk³adowy kod z podrozdzia³u 13.6 „Typ Open_polyline”" ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "Simple_window.h"  // Do³¹cza nasz¹ bibliotekê okien.
#include "Graph.h"          // Do³¹cza narzêdzia graficzne.

//------------------------------------------------------------------------------

int main()
try
{
    using namespace Graph_lib;   // Nasze narzêdzia graficzne znajduj¹ siê w bibliotece Graph_lib

    Simple_window win(Point(100,100),600,400,"Otwarta ³amana");    

    Open_polyline opl;

    opl.add(Point(100,100));
    opl.add(Point(150,200));
    opl.add(Point(250,250));
    opl.add(Point(300,200));

    win.attach(opl);
    win.wait_for_button();       // Wyœwietl!
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
