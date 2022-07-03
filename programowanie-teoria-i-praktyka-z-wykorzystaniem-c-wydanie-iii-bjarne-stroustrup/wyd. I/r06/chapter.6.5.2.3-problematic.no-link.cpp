
//
// Przyk³adowy kod z rozdzia³u 6.5.2.3 "Wyra¿enia — do trzech razy sztuka" ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

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

double term();        // Wczytuje i wartoœciuje sk³adnik.

//------------------------------------------------------------------------------

double expression()
{
    double left = term();      // Wczytuje i oblicza wartoœæ sk³adnika.
    Token t = get_token();     // nastêpny token
    while ( t.kind=='+' || t.kind=='-') {    // Szuka znaków + i -.
        if (t.kind == '+')
            left += term();    // Oblicza wartoœæ sk³adnika i wykonuje dodawanie.
        else
            left -= term();    // Oblicza wartoœæ sk³adnika i wykonuje odejmowanie.
        t = get_token();
    }
    return left;               // Jeœli nie ma wiêcej znaków + lub –, zwraca odpowiedŸ.
}

//------------------------------------------------------------------------------
