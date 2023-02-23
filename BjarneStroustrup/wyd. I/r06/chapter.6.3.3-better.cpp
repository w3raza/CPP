
//
// Przyk³adowy kod z rozdzia³u 6.3.3 "Implementowanie tokenów" ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

class Token {
public:
    char kind;        // rodzaj tokenu
    double value;     // Dla liczb: wartoœæ. 
    Token(char ch)    // Tworzy Token ze znaku.
        :kind(ch), value(0) { }    
    Token(char ch, double val)     // Tworzy Token ze znaku i wartoœci typu double.
        :kind(ch), value(val) { }
};

//------------------------------------------------------------------------------

int main()
{
    Token t1('+');     // Inicjacja zmiennej t1 — t1.kind = '+'.
    Token t2('8',11.5); // Inicjacja zmiennej t2 — t2.kind = '8' i t2.value = 11.5.
}

//------------------------------------------------------------------------------
