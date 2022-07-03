
//
// Przyk³adowy kod z rozdzia³u 6.5.4 "Podstawowe elementy wyra¿eñ" ksi¹¿ki
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

Token get_token();    // Wczytuje token ze strumienia cin.

//------------------------------------------------------------------------------

double expression();  // Wczytuje i wartoœciuje wyra¿enie.

//------------------------------------------------------------------------------

double primary()
{
    Token t = get_token();
    switch (t.kind) {
    case '(':    // Obs³uga '(' expression ')'.
        {    
            double d = expression();
            t = get_token();
            if (t.kind != ')') error("Oczekiwano ')'.");
            return d;
        }
    case '8':           // Za pomoc¹ znaku '8' reprezentujemy liczby.
        return t.value; // Zwraca wartoœæ liczby.
    default:
        error("Oczekwiano czynnika.");
    }
}

//------------------------------------------------------------------------------
