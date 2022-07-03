
//
// Przyk�adowy kod z rozdzia�u 6.5.4 "Podstawowe elementy wyra�e�" ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

class Token {
public:
    char kind;        // rodzaj tokenu
    double value;     // Dla liczb: warto��. 
    Token(char ch)    // Tworzy Token ze znaku.
        :kind(ch), value(0) { }    
    Token(char ch, double val)     // Tworzy Token ze znaku i warto�ci typu double.
        :kind(ch), value(val) { }
};

//------------------------------------------------------------------------------

Token get_token();    // Wczytuje token ze strumienia cin.

//------------------------------------------------------------------------------

double expression();  // Wczytuje i warto�ciuje wyra�enie.

//------------------------------------------------------------------------------

double primary()
{
    Token t = get_token();
    switch (t.kind) {
    case '(':    // Obs�uga '(' expression ')'.
        {    
            double d = expression();
            t = get_token();
            if (t.kind != ')') error("Oczekiwano ')'.");
            return d;
        }
    case '8':           // Za pomoc� znaku '8' reprezentujemy liczby.
        return t.value; // Zwraca warto�� liczby.
    default:
        error("Oczekwiano czynnika.");
    }
}

//------------------------------------------------------------------------------
