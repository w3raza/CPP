
//
// To jest przyk³adowy kod z podrozdzia³u 13.5 „Typ Line_style" ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "Simple_window.h"  // Do³¹cza nasz¹ bibliotekê okien.
#include "Graph.h"          // Do³¹cza narzêdzia graficzne.

//------------------------------------------------------------------------------

int main()
try
{
    using namespace Graph_lib;    // Nasze narzêdzia graficzne znajduj¹ siê w bibliotece Graph_lib

    Simple_window win3(Point(100,100),600,400,"Siatka");    

    int x_size = win3.x_max();    // Sprawdza rozmiar okna.
    int y_size = win3.y_max();
    int x_grid = 80;
    int y_grid = 40; 

    Lines grid;
    for (int x=x_grid; x<x_size; x+=x_grid)
        grid.add(Point(x,0),Point(x,y_size));    // Linia pionowa.
    for (int y = y_grid; y<y_size; y+=y_grid)
        grid.add(Point(0,y),Point(x_size,y));    // Linia pozioma.

    grid.set_color(Color::red);
    grid.set_style(Line_style(Line_style::dash,2));
    win3.attach(grid);                           // Wi¹¿e linie z oknem.
    win3.wait_for_button();                      // Wyœwietl!
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
