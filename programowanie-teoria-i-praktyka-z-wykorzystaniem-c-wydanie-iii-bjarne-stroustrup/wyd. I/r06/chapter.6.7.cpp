
//
// Przyk³adowy kod z rozdzia³u 6.7 "Wypróbowywanie drugiej wersji" ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

class Token {
public:
    char kind;        // Rodzaj tokenu.
    double value;     // Dla liczb: wartoœæ.
    Token(char ch)    // Tworzy token ze znaku.
        :kind(ch), value(0) { }    
    Token(char ch, double val)     // Tworzy Token ze znaku i wartoœci typu double.
        :kind(ch), value(val) { }
};

//------------------------------------------------------------------------------

class Token_stream {
public: 
    Token_stream();   // Tworzy Token_stream wczytuj¹cy ze strumienia cin.
    Token get();      // Pobiera token (funkcja get() jest zdefiniowana w innym miejscu).
    void putback(Token t);    // Wstawia token z powrotem.
private:
    bool full;        // Sprawdza czy w buforze jest token.
    Token buffer;     // Przechowuje token wstawiony z powrotem za pomoc¹ funkcji putback().
};

//------------------------------------------------------------------------------

// Konstruktor ustawia tylko wartoœæ full w taki sposób, aby wskazywa³a, ¿e bufor jest pusty:
Token_stream::Token_stream()
:full(false), buffer(0)    // Bufor jest pusty
{
}

//------------------------------------------------------------------------------

// Funkcja sk³adowa putback() wstawia swój argument z powrotem do bufora strumienia Token_stream:
void Token_stream::putback(Token t)
{
    if (full) error("Funkcja putback() próbuje wstawiæ token do pe³nego bufora.");
    buffer = t;       // Kopiuje t do bufora.
    full = true;      // Bufor jest pe³ny.
}

//------------------------------------------------------------------------------

Token Token_stream::get()
{
    if (full) {       // Sprawdza czy jest ju¿ gotowy token.
        // Usuwa token z bufora.
        full=false;
        return buffer;
    } 

    char ch;
    cin >> ch;    // Operator >> pomija bia³e znaki (spacje, znaki nowego wiersza, tabulatory itp.).

    switch (ch) {
    case ';':    // Oznacza drukowanie
    case 'q':    // Oznacza koniec
    case '(': case ')': case '+': case '-': case '*': case '/': 
        return Token(ch);        // Ka¿dy znak reprezentuje sam siebie.
    case '.':
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
        {    
            cin.putback(ch);         // Wstawia cyfrê z powrotem do strumienia wejœciowego.
            double val;
            cin >> val;              // Odczytuje liczbê zmiennoprzecinkow¹.
            return Token('8',val);   // Znak 8 reprezentuje liczbê.
        }
    default:
        error("Nieprawid³owy token");
    }
}

//------------------------------------------------------------------------------

Token_stream ts;        // Dostarcza funkcji get() i putback().

//------------------------------------------------------------------------------

double expression();    // Deklaracja, dziêki której funkcja primary() mo¿e wywo³aæ funkcjê expression().

//------------------------------------------------------------------------------

// Obs³uga liczb i nawiasów.
double primary()
{
    Token t = ts.get();
    switch (t.kind) {
    case '(':    // Obs³uga '(' wyra¿enie ')'
        {    
            double d = expression();
            t = ts.get();
            if (t.kind != ')') error("')' by³ oczekiwany");
            return d;
        }
    case '8':            // Do reprezentowania liczb s³u¿y znak 8.
        return t.value;  // Zwraca wartoœæ liczby.
    default:
        error("Oczekiwano czynnika.");
    }
}

//------------------------------------------------------------------------------

// Obs³uga *, / i %.
double term()
{
    double left = primary();
    Token t = ts.get();        // Pobiera nastêpny token ze strumienia wejœciowego.

    while(true) {
        switch (t.kind) {
        case '*':
            left *= primary();
            t = ts.get();
            break;
        case '/':
            {    
                double d = primary();
                if (d == 0) error("Dzielenie przez zero.");
                left /= d; 
                t = ts.get();
                break;
            }
        default: 
            ts.putback(t);     // Wstawia t z powrotem do strumienia tokenów.
            return left;
        }
    }
}

//------------------------------------------------------------------------------

// Obs³uga + i -.
double expression()
{
    double left = term();      // Wczytuje i oblicza wartoœæ sk³adnika.
    Token t = ts.get();        // Pobiera nastêpny token ze strumienia wejœciowego.

    while(true) {    
        switch(t.kind) {
        case '+':
            left += term();    // Oblicza wartoœæ sk³adnika i dodaje.
            t = ts.get();
            break;
        case '-':
            left -= term();    // Oblicza wartoœæ sk³adnika i odejmuje.
            t = ts.get();
            break;
        default: 
            ts.putback(t);     // Wstawia t z powrotem do strumienia tokenów.
            return left;       // Nie ma wiêcej znaków = i -. Zwraca wynik.
        }
    }
}

//------------------------------------------------------------------------------

int main()
try
{
    double val = 0;
    while (cin) {
        Token t = ts.get();

        if (t.kind == 'q') break; // Oznacza koniec.
        if (t.kind == ';')        // Oznacza drukowanie.
            cout << "=" << val << '\n';
        else
            ts.putback(t);
        val = expression();
    }
}
catch (exception& e) {
    cerr << "B³¹d: " << e.what() << '\n'; 
    return 1;
}
catch (...) {
    cerr << "Nieznany wyj¹tek!\n"; 
    return 2;
}

//------------------------------------------------------------------------------
