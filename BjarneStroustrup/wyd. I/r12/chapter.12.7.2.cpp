
//
// To jest przyk�adowy kod z podrozdzia�u 12.7.2 "Prawie puste okno" ksi��ki 
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "Simple_window.h"    // Dla przycisku �Next�
#include "Graph.h" 
#include "std_lib_facilities.h"

using namespace Graph_lib;

//------------------------------------------------------------------------------

int main ()
try
{ 
    Point tl(100,100);     // Lewy g�rny r�g naszego okna.

    Simple_window win(tl,600,400,"Canvas");
    // Wsp�rz�dna ekranu tl okre�laj�ca po�o�enie lewego g�rnego rogu okna.
    // Rozmiar okna 600*400.
    // Tytu�: Kanwa.
    win.wait_for_button(); // Wy�wietl!
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
