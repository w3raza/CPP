
//
// To jest przyk�adowy kod z podrozdzia�u 16.8 "Debugowanie kodu GUI" ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "Simple_window.h"  // Do��cza nasz� bibliotek� okien.
#include "GUI.h"
#include "Point.h"

using namespace Graph_lib;

//------------------------------------------------------------------------------

void cb_flood(Address, Address);
void cb_fire(Address, Address);

//------------------------------------------------------------------------------

// Funkcja pomocnicza do �adowania przycisk�w do menu.
void load_disaster_menu(Menu& m)
{
    Point orig(0,0);
    m.attach(new Button(orig,0,0,"pow�d�",cb_flood));
    m.attach(new Button(orig,0,0,"po�ar",cb_fire));
    // ...
}

//------------------------------------------------------------------------------

int main()
try
{
    Simple_window win(Point(100,100),600,400,"Katastrofy");
    // ...
    Menu disasters(Point(x_max()-70,30),70,20,Menu::vertical,"Katastrofy");
    load_disaster_menu(disasters);
    win.attach(disasters);
    // ...
}
catch(exception& e) {
    // Raport o b��dzie
    return 1;
}
catch(...) {
    // Raport o b��dzie
    return 2;
}

//------------------------------------------------------------------------------
