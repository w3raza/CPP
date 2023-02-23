
//
// To jest przyk³adowy kod z podrozdzia³u 13.13 „Typ Ellipse” ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "Simple_window.h"  // Do³¹cza nasz¹ bibliotekê okien.
#include "Graph.h"          // Do³¹cza narzêdzia graficzne.

//------------------------------------------------------------------------------

int main()
try
{
    using namespace Graph_lib;   // Nasze narzêdzia graficzne znajduj¹ siê w bibliotece Graph_lib

    Simple_window win(Point(100,100),600,400,"Elipsy");

    Ellipse e1(Point(200,200),50,50);
    Ellipse e2(Point(200,200),100,50);
    Ellipse e3(Point(200,200),100,150);

    win.attach(e1);
    win.attach(e2);
    win.attach(e3);

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
