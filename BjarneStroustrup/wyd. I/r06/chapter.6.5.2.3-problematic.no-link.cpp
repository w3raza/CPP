
//
// Przyk�adowy kod z rozdzia�u 6.5.2.3 "Wyra�enia � do trzech razy sztuka" ksi��ki
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

double term();        // Wczytuje i warto�ciuje sk�adnik.

//------------------------------------------------------------------------------

double expression()
{
    double left = term();      // Wczytuje i oblicza warto�� sk�adnika.
    Token t = get_token();     // nast�pny token
    while ( t.kind=='+' || t.kind=='-') {    // Szuka znak�w + i -.
        if (t.kind == '+')
            left += term();    // Oblicza warto�� sk�adnika i wykonuje dodawanie.
        else
            left -= term();    // Oblicza warto�� sk�adnika i wykonuje odejmowanie.
        t = get_token();
    }
    return left;               // Je�li nie ma wi�cej znak�w + lub �, zwraca odpowied�.
}

//------------------------------------------------------------------------------
