
//
// Przyk�adowy kod z rozdzia�u 6.3.4 "U�ywanie token�w" ksi��ki
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

vector<Token> tok;    // Tutaj b�dziemy zapisywa� tokeny.

//------------------------------------------------------------------------------

int main()
{
    while (cin) {
        Token t = get_token();
        tok.push_back(t);
    }
    // ...
    // Teraz mo�emy znale�� operacj� mno�enia za pomoc� prostej p�tli:

    for (int i = 0; i<tok.size(); ++i) {
        if (tok[i].kind=='*') {    // Znale�li�my operator mno�enia!
            double d = tok[i-1].value*tok[i+1].value;
            // Co teraz?
        }
    }
}

//------------------------------------------------------------------------------
