
//
// To jest przyk�adowy kod z podrozdzia�u 13.17 �Typ Image� ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "Simple_window.h"  // Do��cza nasz� bibliotek� okien.
#include "Graph.h"          // Do��cza narz�dzia graficzne.

//------------------------------------------------------------------------------

int main()
try
{
    using namespace Graph_lib;   // Nasze narz�dzia graficzne znajduj� si� w bibliotece Graph_lib

    Simple_window win(Point(100,100),600,400,"Obrazy");

    Image rita(Point(0,0),"rita.jpg");
    Image path(Point(0,0),"rita_path.gif");
    path.set_mask(Point(50,250),600,400); // wyb�r prawdopodobnego miejsca l�dowania

    win.attach(path);
    win.attach(rita);

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
