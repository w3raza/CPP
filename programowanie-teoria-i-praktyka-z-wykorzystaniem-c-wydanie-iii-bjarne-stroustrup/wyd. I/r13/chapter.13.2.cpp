
//
// To jest przyk³adowy kod z podrozdzia³u 13.2 "Klasy Point i Line" ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "Simple_window.h"  // Do³¹cza nasz¹ bibliotekê okien.
#include "Graph.h"          // Do³¹cza narzêdzia graficzne.

//------------------------------------------------------------------------------

int main()
try
{
    using namespace Graph_lib;    // Nasze narzêdzia graficzne znajduj¹ siê w bibliotece Graph_lib

    Simple_window win1(Point(100,100),600,400,"two lines");    

    Line horizontal(Point(100,100),Point(200,100)); // Tworzy liniê poziom¹.
    Line vertical(Point(150,50),Point(150,150));    // Tworzy liniê pionow¹.

    win1.attach(horizontal);      // Wi¹¿e linie z oknem.
    win1.attach(vertical);

    win1.wait_for_button();       // Wyœwietl!
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
