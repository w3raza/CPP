
//
// Przyk�adowy kod z rozdzia�u 6.5.2.1 "Wyra�enia � pierwsza pr�ba" ksi��ki
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
    double left = expression();      // Wczytuje i oblicza warto�� wyra�enia.
    Token t = get_token();           // nast�pny token
    switch (t.kind) {                // Sprawdza jaki to jest rodzaj tokenu.
    case '+':
        return left + term();        // Wczytuje i sprawdza warto�� sk�adnika,
                                     // nast�pnie wykonuje dodawanie.
    case '-':
        return left - term();        // Wczytuje i sprawdza warto�� sk�adnika,
                                     // nast�pnie wykonuje odejmowanie.
    default:
        return left;                 // Zwraca warto�� wyra�enia.
    }
}

//------------------------------------------------------------------------------
