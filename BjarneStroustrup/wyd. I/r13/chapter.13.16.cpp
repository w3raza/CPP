
//
// To jest przyk�adowy kod z podrozdzia�u 13.16 "Typ Mark" ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "Simple_window.h"  // Do��cza nasz� bibliotek� okien.
#include "Graph.h"          // Do��cza narz�dzia graficzne.

//------------------------------------------------------------------------------

int main()
try
{
    using namespace Graph_lib;   // Nasze narz�dzia graficzne znajduj� si� w bibliotece Graph_lib

    Simple_window win(Point(100,100),600,400,"Ko�a ze �rodkami.");

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
