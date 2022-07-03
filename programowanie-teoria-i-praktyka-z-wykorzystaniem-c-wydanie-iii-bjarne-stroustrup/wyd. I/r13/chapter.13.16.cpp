
//
// To jest przyk³adowy kod z podrozdzia³u 13.16 "Typ Mark" ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "Simple_window.h"  // Do³¹cza nasz¹ bibliotekê okien.
#include "Graph.h"          // Do³¹cza narzêdzia graficzne.

//------------------------------------------------------------------------------

int main()
try
{
    using namespace Graph_lib;   // Nasze narzêdzia graficzne znajduj¹ siê w bibliotece Graph_lib

    Simple_window win(Point(100,100),600,400,"Ko³a ze œrodkami.");

    Circle c1(Point(100,200),50);
    Circle c2(Point(150,200),100);
    Circle c3(Point(200,200),150);

    win.attach(c1);
    win.attach(c2);
    win.attach(c3);

    Mark m1(Point(100,200),'x');
    Mark m2(Point(150,200),'y');
    Mark m3(Point(200,200),'z');
    c1.set_color(Color::blue);
    c2.set_color(Color::red);
    c3.set_color(Color::green);
    win.attach(m1);
    win.attach(m2);
    win.attach(m3);

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
