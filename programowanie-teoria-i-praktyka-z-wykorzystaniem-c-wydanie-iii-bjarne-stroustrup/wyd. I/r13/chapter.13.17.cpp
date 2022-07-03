
//
// To jest przyk³adowy kod z podrozdzia³u 13.17 „Typ Image” ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "Simple_window.h"  // Do³¹cza nasz¹ bibliotekê okien.
#include "Graph.h"          // Do³¹cza narzêdzia graficzne.

//------------------------------------------------------------------------------

int main()
try
{
    using namespace Graph_lib;   // Nasze narzêdzia graficzne znajduj¹ siê w bibliotece Graph_lib

    Simple_window win(Point(100,100),600,400,"Obrazy");

    Image rita(Point(0,0),"rita.jpg");
    Image path(Point(0,0),"rita_path.gif");
    path.set_mask(Point(50,250),600,400); // wybór prawdopodobnego miejsca l¹dowania

    win.attach(path);
    win.attach(rita);

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
