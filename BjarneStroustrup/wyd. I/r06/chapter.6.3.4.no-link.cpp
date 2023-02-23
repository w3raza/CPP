
//
// Przyk³adowy kod z rozdzia³u 6.3.4 "U¿ywanie tokenów" ksi¹¿ki
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

vector<Token> tok;    // Tutaj bêdziemy zapisywaæ tokeny.

//------------------------------------------------------------------------------

int main()
{
    while (cin) {
        Token t = get_token();
        tok.push_back(t);
    }
    // ...
    // Teraz mo¿emy znaleŸæ operacjê mno¿enia za pomoc¹ prostej pêtli:

    for (int i = 0; i<tok.size(); ++i) {
        if (tok[i].kind=='*') {    // ZnaleŸliœmy operator mno¿enia!
            double d = tok[i-1].value*tok[i+1].value;
            // Co teraz?
        }
    }
}

//------------------------------------------------------------------------------
