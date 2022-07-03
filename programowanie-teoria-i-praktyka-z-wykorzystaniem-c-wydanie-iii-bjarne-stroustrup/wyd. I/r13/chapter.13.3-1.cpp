
//
// To jest przyk�adowy kod z podrozdzia�u 13.3 "Linie" ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "Simple_window.h"  // Do��cza nasz� bibliotek� okien.
#include "Graph.h"          // Do��cza narz�dzia graficzne.

//------------------------------------------------------------------------------

int main()
try
{
    using namespace Graph_lib;    // Nasze narz�dzia graficzne znajduj� si� w bibliotece Graph_lib

    Simple_window win1(Point(100,100),600,400,"Linie: +");    

    Lines x;
    x.add(Point(100,100), Point(200,100));   // Pierwsza linia: pozioma.
    x.add(Point(150,50), Point(150,150));    // Druga linia: pionowa.

    win1.attach(x);                          // Wi��e linie z oknem.
    win1.wait_for_button();                  // Wy�wietl!
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
