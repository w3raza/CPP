
//
// To jest przyk³adowy kod z podrozdzia³u 13.11 „Typ Text” ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "Simple_window.h"  // Do³¹cza nasz¹ bibliotekê okien.
#include "Graph.h"          // Do³¹cza narzêdzia graficzne.

//------------------------------------------------------------------------------

int main()
try
{
    using namespace Graph_lib;   // Nasze narzêdzia graficzne znajduj¹ siê w bibliotece Graph_lib

    Simple_window win(Point(100,100),600,400,"Zamkniêta ³amana");    

    Closed_polyline cpl;

    cpl.add(Point(100,100));
    cpl.add(Point(150,200));
    cpl.add(Point(250,250));
    cpl.add(Point(300,200));
    cpl.add(Point(100,250));
    win.attach(cpl);

    Text t(Point(200,200),"Zamkniêta ³amana, która nie jest wielok¹tem");    
    t.set_color(Color::blue);
    win.attach(t);

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
