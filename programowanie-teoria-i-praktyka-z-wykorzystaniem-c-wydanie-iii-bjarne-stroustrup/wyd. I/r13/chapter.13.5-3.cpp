
//
// To jest przyk�adowy kod z podrozdzia�u 13.5 �Typ Line_style� ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "Simple_window.h"  // Do��cza nasz� bibliotek� okien.
#include "Graph.h"          // Do��cza narz�dzia graficzne.

//------------------------------------------------------------------------------

int main()
try
{
    using namespace Graph_lib;    // Nasze narz�dzia graficzne znajduj� si� w bibliotece Graph_lib

    Simple_window win1(Point(100,100),600,400,"Dwie linie");    

    Line horizontal(Point(100,100),Point(200,100)); // Tworzy lini� poziom�.
    Line vertical(Point(150,50),Point(150,150));    // Tworzy lini� pionow�.

    horizontal.set_color(Color::red);
    vertical.set_color(Color::green);

    win1.attach(horizontal);      // Wi��e linie z oknem.
    win1.attach(vertical);

    win1.wait_for_button();       // Wy�wietl!
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
