
//
// To jest przyk³adowy kod z podrozdzia³u 7.2 "Wejœcie i wyjœcie" ksi¹¿ki 
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
    Token(char ch, double val)     // Tworzy token ze znaku i liczby typu double.
        :kind(ch), value(val) { }
};

//------------------------------------------------------------------------------

class Token_stream {
public: 
    Token_stream();   // Tworzy strumieñ tokenów wczytuj¹cy dane ze strumienia cin.
    Token get();      // Pobiera token (funkcja get() zosta³a zdefiniowana w innym miejscu).
    void putback(Token t);    // Zwraca token.
private:
    bool full;        // Sprawdza czy w buforze jest token.
    Token buffer;     // Przechowuje tokeny zwrócone przez funkcjê putback().
};

//------------------------------------------------------------------------------

// Konstruktor ustawia wartoœæ full w taki sposób, ¿e oznacza pusty bufor:
Token_stream::Token_stream()
:full(false), buffer(0)    // Bufor jest pusty.
{
}

//------------------------------------------------------------------------------

// Funkcja sk³adowa putback() wstawia swój argument z powrotem do bufora Token_stream::
void Token_stream::putback(Token t)
{
    if (full) error("Funkcja putback() wstawia dane do pe³nego bufora.");
    buffer = t;       // Kopiuje t do bufora.
    full = true;      // Bufor jest pe³ny.
}

//------------------------------------------------------------------------------

Token Token_stream::get()
{
    if (full) {       // Sprawdza czy jest gotowy token.
        // Usuwa token z bufora.
        full=false;
        return buffer;
    } 

    char ch;
    cin >> ch;    // Operator >> pomija bia³e znaki (spacje, znaki nowego wiersza, tabulatory itp.).

    switch (ch) {
    case ';':    // Oznacza drukowanie.
    case 'q':    Oznacza koniec.
    case '(': case ')': case '+': case '-': case '*': case '/': 
        return Token(ch);        // Ka¿dy znak reprezentuje sam siebie.
    case '.':
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
        {    
            cin.putback(ch);         // Wstawia cyfrê z powrotem do strumienia wejœciowego.
            double val;
            cin >> val;              // Wczytuje liczbê zmiennoprzecinkow¹.
            return Token('8',val);   // Znak 8 reprezentuje liczbê.
        }
    default:
        error("Bad token");
    }
}

//------------------------------------------------------------------------------

Token_stream ts;        // Dostarcza funkcji get() i pushback().

//------------------------------------------------------------------------------

double expression();    // Dziêki tej deklaracji funkcja primary() mo¿e wywo³aæ funkcjê expression().

//------------------------------------------------------------------------------

// Obs³uga liczb i nawiasów.
double primary()
{
    Token t = ts.get();
    switch (t.kind) {
    case '(':    // Obs³uga '(' wyra¿enie ')'.
        {    
            double d = expression();
            t = ts.get();
            if (t.kind != ')') error("')' by³ oczekiwany");
            return d;
        }
    case '8':            // Znak 8 reprezentuje liczbê.
        return t.value;  // Zwraca wartoœæ liczby.
    default:
        error("Oczekiwano czynnika.");
    }
}

//------------------------------------------------------------------------------

// Obs³uga *, / oraz %.
double term()
{
    double left = primary();
    Token t = ts.get();        // Pobiera nastêpny token ze strumienia tokenów.

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
    Token t = ts.get();        // Pobiera nastêpny token ze strumienia tokenów.

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
            return left;       // Nie ma wiêcej znaków + i -. Zwraca wynik.
        }
    }
}

//------------------------------------------------------------------------------

int main()
try
{
    double val = 0;
    while (cin) {
        cout << "> ";          // Drukuje znak zachêty.
        Token t = ts.get();
        if (t.kind == 'q') break;
        if (t.kind == ';')
            cout << "= " << val << '\n'; // Drukuje wynik.
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
