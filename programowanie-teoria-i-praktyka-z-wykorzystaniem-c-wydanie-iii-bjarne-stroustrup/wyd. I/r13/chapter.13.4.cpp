
//
// To jest przyk�adowy kod z podrozdzia�u 13.4 �Klasa Color� ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "Simple_window.h"  // Do��cza nasz� bibliotek� okien.
#include "Graph.h"          // Do��cza narz�dzia graficzne.

//------------------------------------------------------------------------------

int main()
try
{
    using namespace Graph_lib;    // Nasze narz�dzia graficzne znajduj� si� w bibliotece Graph_lib

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
    win3.attach(grid);                           // Wi��e linie z oknem.
    win3.wait_for_button();                      // Wy�wietl!
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
