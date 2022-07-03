
//
// Przyk³adowy kod z rozdzia³u 6.5.2.1 "Wyra¿enia — druga próba" ksi¹¿ki
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
    double left = term();              // Wczytuje i oblicza wartoœæ sk³adnika.
    Token t = get_token();             // nastêpny token
    switch (t.kind) {                  // Sprawdza jaki to jest rodzaj tokenu.
    case '+':
        return left + expression();    // Wczytuje i oblicza wartoœæ wyra¿enia,
                                       // nastêpnie wykonuje dodawanie.
    case '-':
        return left - expression();    // Wczytuje i oblicza wartoœæ wyra¿enia,
                                       // nastêpnie wykonuje odejmowanie.
    default:
        return left;                   // Zwraca wartoœæ sk³adnika.
    }
}

//------------------------------------------------------------------------------
