
//
// Przyk�adowy kod z rozdzia�u 6.5.3 "Sk�adniki" ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

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

double primary();      // Wczytuje i warto�ciuje czynnik.

//------------------------------------------------------------------------------

double term()
{
    double left = primary();
    Token t = get_token();
    while(true) {
        switch (t.kind) {
        case '*':
            left *= primary();
            t = get_token();
            break;
        case '/':
            left /= primary();
            t = get_token();
            break;
        default:
            return left;
        }
    }
}

//------------------------------------------------------------------------------
