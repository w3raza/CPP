
//
// To jest przyk³adowy kod z podrozdzia³u 16.5 "Przyk³ad" ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include <iostream>
#include <sstream>
#include "Graph.h"        // Do³¹cza narzêdzia graficzne.
#include "GUI.h"
#include "Window.h"

using namespace Graph_lib;
using namespace std;

//------------------------------------------------------------------------------

struct Lines_window : Window {
    Lines_window(Point xy, int w, int h, const string& title );
    Open_polyline lines;
private:
    Button next_button;        // Dodaje (next_x,next_y) do linii.
    Button quit_button;
    In_box next_x;
    In_box next_y;
    Out_box xy_out;

    static void cb_next(Address, Address); // Funkcja zwrotna przycisku next_button
    void next(); 
    static void cb_quit(Address, Address); // Funkcja zwrotna przycisku quit_button
    void quit(); 
};

//------------------------------------------------------------------------------

Lines_window::Lines_window(Point xy, int w, int h, const string& title)
    :Window(xy,w,h,title),
    next_button(Point(x_max()-150,0), 70, 20, "Nastêpny punkt", cb_next),
    quit_button(Point(x_max()-70,0), 70, 20, "Koniec", cb_quit),
    next_x(Point(x_max()-310,0), 50, 20, "x:"),
    next_y(Point(x_max()-210,0), 50, 20, "y:"),
    xy_out(Point(100,0), 100, 20, "Bie¿¹cy punkt (x,y):")
{
    attach(next_button);
    attach(quit_button);
    attach(next_x);
    attach(next_y);
    attach(xy_out);
    attach(lines);
}

//------------------------------------------------------------------------------

void Lines_window::cb_quit(Address, Address pw)    // typowa
{  
       reference_to<Lines_window>(pw).quit();
} 

//------------------------------------------------------------------------------

void Lines_window::quit()
{
    hide();        // Ciekawy sposób zastosowany w FLTK do usuwania okna.
}

//------------------------------------------------------------------------------

void Lines_window::cb_next(Address, Address pw)     // typowa
{  
    reference_to<Lines_window>(pw).next();
} 

//------------------------------------------------------------------------------

void Lines_window::next()
{
    int x = next_x.get_int();
    int y = next_y.get_int();

    lines.add(Point(x,y));

    // Aktualizuje pole z bie¿¹cym punktem:
    stringstream ss;
    ss << '(' << x << ',' << y << ')';
    xy_out.put(ss.str());

      redraw();
}

//------------------------------------------------------------------------------

int main()
try {
    Lines_window win(Point(100,100),600,400,"Linie");
    return gui_main();
}
catch(exception& e) {
    cerr << "Wyj¹tek: " << e.what() << '\n';
    return 1;
}
catch (...) {
    cerr << "Jakiœ wyj¹tek\n";
    return 2;
}

//------------------------------------------------------------------------------
