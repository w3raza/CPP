
//
// To jest przyk³adowy kod z podrozdzia³u 13.9 „Typ Rectangle” ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "Simple_window.h"  // Do³¹cza nasz¹ bibliotekê okien.
#include "Graph.h"          // Do³¹cza narzêdzia graficzne.

//------------------------------------------------------------------------------

int main()
try
{
    using namespace Graph_lib;   // Nasze narzêdzia graficzne znajduj¹ siê w bibliotece Graph_lib

    Simple_window win(Point(100,100),600,400,"Rectangle");

    Rectangle rect00(Point(150,100),200,100); 
    Rectangle rect11(Point(50,50),Point(250,150)); 
    Rectangle rect12(Point(50,150),Point(250,250)); // nieco pod rect11
    Rectangle rect21(Point(250,50),200,100);        // po prawej rect11
    Rectangle rect22(Point(250,150),200,100);       // nieco pod rect21

    rect00.set_fill_color(Color::yellow);
    rect11.set_fill_color(Color::blue);
    rect12.set_fill_color(Color::red);
    rect21.set_fill_color(Color::green);

    rect11.move(400,0);        // na prawo od rect21
    rect11.set_fill_color(Color::white);
    
    win.attach(rect00);
    win.attach(rect11);
    win.attach(rect12);
    win.attach(rect21);

    win.set_label("rectangles 2");
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
