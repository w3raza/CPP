
//
// To jest przyk³adowy kod z podrozdzia³u 13.3 "Linie" ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "Simple_window.h"  // Do³¹cza nasz¹ bibliotekê okien.
#include "Graph.h"          // Do³¹cza narzêdzia graficzne.

//------------------------------------------------------------------------------

int main()
try
{
    using namespace Graph_lib;    // Nasze narzêdzia graficzne znajduj¹ siê w bibliotece Graph_lib

    Simple_window win1(Point(100,100),600,400,"Linie: +");    

    Lines x;
    x.add(Point(100,100), Point(200,100));   // Pierwsza linia: pozioma.
    x.add(Point(150,50), Point(150,150));    // Druga linia: pionowa.

    win1.attach(x);                          // Wi¹¿e linie z oknem.
    win1.wait_for_button();                  // Wyœwietl!
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
