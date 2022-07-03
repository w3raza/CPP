
//
// To jest przyk�adowy kod z podrozdzia�u 13.9 �Typ Rectangle� ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "Simple_window.h"  // Do��cza nasz� bibliotek� okien.
#include "Graph.h"          // Do��cza narz�dzia graficzne.

//------------------------------------------------------------------------------

int main()
try
{
    using namespace Graph_lib;   // Nasze narz�dzia graficzne znajduj� si� w bibliotece Graph_lib

    Simple_window win(Point(100,100),600,400,"Prostok�t");

    Rectangle rect00(Point(150,100),200,100); 
    Rectangle rect11(Point(50,50),Point(250,150)); 
    Rectangle rect12(Point(50,150),Point(250,250)); // nieco pod rect11
    Rectangle rect21(Point(250,50),200,100);        // po prawej rect11
    Rectangle rect22(Point(250,150),200,100);       // nieco pod rect21

    rect00.set_fill_color(Color::yellow);
    rect11.set_fill_color(Color::blue);
    rect12.set_fill_color(Color::red);
    rect21.set_fill_color(Color::green);

    win.attach(rect00);
    win.attach(rect11);
    win.attach(rect12);
    win.attach(rect21);

    win.set_label("Prostok�ty");
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
