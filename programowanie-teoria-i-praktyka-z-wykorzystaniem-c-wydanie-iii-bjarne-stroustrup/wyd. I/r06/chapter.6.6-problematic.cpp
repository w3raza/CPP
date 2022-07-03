
//
// Przyk³adowy kod z rozdzia³u 6.6 "Wypróbowywanie pierwszej wersji" ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

class Token {
public:
    char kind;        // rodzaj tokenu
    double value;     // Dla liczb: wartoœæ.
    Token(char ch)    // Tworzy token ze znaku.
        :kind(ch), value(0) { }    
    Token(char ch, double val)     // Tworzy Token ze znaku i wartoœci typu double.
        :kind(ch), value(val) { }
};

//------------------------------------------------------------------------------

Token get_token()    // Wczytuje token ze strumienia cin.
{
    char ch;
    cin >> ch;    // Operator >> pomija bia³e znaki (spacje, znaki nowego wiersza, tabulatory itp.)

    switch (ch) {
    case '(': case ')': case '+': case '-': case '*': case '/': 
        return Token(ch);        // Ka¿dy znak reprezentuje samego siebie.
    case '.':
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
        {    
            cin.putback(ch);         // Wstawia cyfrê z powrotem do strumienia wejœciowrgo.
            double val;
            cin >> val;              // Wczytuje liczbê zmiennoprzecinkow¹.
            return Token('8',val);   // Cyfra 8 reprezentuje liczbê.
        }
    default:
        error("Nieprawid³owy token.");
    }
}

//------------------------------------------------------------------------------

double expression();  // Wczytuje i oblicza wartoœæ wyra¿enia.

//------------------------------------------------------------------------------

double term();        // Wczytuje i oblicza wartoœæ sk³adnika.

//------------------------------------------------------------------------------

double primary()     // Wczytuje i oblicza wartoœæ czynnika.
{
    Token t = get_token();
    switch (t.kind) {
    case '(':    // Obs³uga '(' wyra¿enie ')'.
        {    
            double d = expression();
            t = get_token();
            if (t.kind != ')') error("')' by³ oczekiwany.");
            return d;
        }
    case '8':            // Do reprezentacji liczb s³u¿y znak 8.
        return t.value;  // Zwraca wartoœæ liczby.
    default:
        error("By³ oczekiwany czynnik.");
    }
}
//------------------------------------------------------------------------------

int main()
try {
    while (cin)
        cout << expression() << '\n';
    keep_window_open();
}
catch (exception& e) {
    cerr << e.what() << endl;
    keep_window_open ();
    return 1;
}
catch (...) {
    cerr << "Wyj¹tek \n";
    keep_window_open ();
    return 2;
}

//------------------------------------------------------------------------------

double expression()
{
    double left = term();      // Wczytuje i oblicza wartoœæ sk³adnika.
    Token t = get_token();     // Pobiera nastêpny token.
    while(true) {    
        switch(t.kind) {
        case '+':
            left += term();    // Oblicza wartoœæ sk³adnika i dodaje.
            t = get_token();
            break;
        case '-':
            left -= term();    // Oblicza wartoœæ sk³adnika i odejmuje.
            t = get_token();
            break;
        default:
            return left;       // Nie ma wiêcej znaków + i -: zwraca wynik.
        }
    }
}

//------------------------------------------------------------------------------

double term()
{
    double left = primary();
    Token t = get_token();     // Pobiera nastêpny token.

    while(true) {
        switch (t.kind) {
        case '*':
            left *= primary();
            t = get_token();
            break;
        case '/':
            {    
                double d = primary();
                if (d == 0) error("Dzielenie przez zero.");
                left /= d; 
                t = get_token();
                break;
            }
        default: 
            return left;
        }
    }
}

//------------------------------------------------------------------------------
