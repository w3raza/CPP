
//
// To jest przyk�adowy kod z podrozdzia�u 6.9 "Strktura programu" ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

class Token {
public:
    char kind;        // Rodzaj tokenu.
    double value;     // Dla liczb: warto��.
    Token(char ch)    // Tworzy token ze znaku.
        :kind(ch), value(0) { }    
    Token(char ch, double val)     // Tworzy token ze znaku i liczby typu double.
        :kind(ch), value(val) { }
};

//------------------------------------------------------------------------------

class Token_stream {
public: 
    Token_stream();   // Tworzy Token_stream wczytuj�cy ze strumienia cin.
    Token get();      // Pobiera token (funkcja get() jest zdefiniowana w innym miejscu).
    void putback(Token t);    // Wstawia token z powrotem.
private:
    bool full;        // Sprawdza czy w buforze jest token.
    Token buffer;     // Przechowuje token wstawiony z powrotem za pomoc� funkcji putback().
};

//------------------------------------------------------------------------------

// Konstruktor ustawia tylko warto�� full w taki spos�b, aby wskazywa�a, �e bufor jest pusty:
Token_stream::Token_stream()
:full(false), buffer(0)    // Bufor jest pusty
{
}

//------------------------------------------------------------------------------

// Funkcja sk�adowa putback() wstawia sw�j argument z powrotem do bufora strumienia Token_stream:
void Token_stream::putback(Token t)
{
    if (full) error("Funkcja putback() pr�buje wstawi� token do pe�nego bufora.");
    buffer = t;       // Kopiuje t do bufora.
    full = true;      // Bufor jest pe�ny.
}

//------------------------------------------------------------------------------

Token Token_stream::get()
{
    if (full) {       // Sprawdza czy jest ju� gotowy token.
        // Usuwa token z bufora.
        full=false;
        return buffer;
    } 

    char ch;
    cin >> ch;    // Operator >> pomija bia�e znaki (spacje, znaki nowego wiersza, tabulatory itp.).

    switch (ch) {
    case ';':    // Oznacza drukowanie
    case 'q':    // Oznacza koniec
    case '(': case ')': case '+': case '-': case '*': case '/': 
        return Token(ch);        // Ka�dy znak reprezentuje samego siebie.
    case '.':
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
        {    
            cin.putback(ch);         // Wstawia cyfr� z powrotem do strumienia wej�ciowego.
            double val;
            cin >> val;              // Odczytuje liczb� zmiennoprzecinkow�.
            return Token('8',val);   // Znak 8 reprezentuje liczb�.
        }
    default:
        error("Nieprawid�owy token");
    }
}

//------------------------------------------------------------------------------

Token_stream ts;        /// Dostarcza funkcji get() i putback().

//------------------------------------------------------------------------------

double expression();    // Deklaracja, dzi�ki kt�rej funkcja primary() mo�e wywo�a� funkcj� expression().

//------------------------------------------------------------------------------

// Obs�uga liczb i nawias�w.
double primary()
{
    Token t = ts.get();
    switch (t.kind) {
    case '(':    // Obs�uga '(' wyra�enie ')'
        {    
            double d = expression();
            t = ts.get();
            if (t.kind != ')') error("')' by� oczekiwany.");
            return d;
        }
    case '8':            // Do reprezentowania liczb s�u�y znak 8.
        return t.value;  // Zwraca warto�� liczby.
    default:
        error("Oczekiwano czynnika.");
    }
}

//------------------------------------------------------------------------------

// Obs�uga *, / i %.
double term()
{
    double left = primary();
    Token t = ts.get();        // Pobiera nast�pny token ze strumienia wej�ciowego.

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
            ts.putback(t);     // Wstawia t z powrotem do strumienia token�w.
            return left;
        }
    }
}

//------------------------------------------------------------------------------

// Obs�uga + i -.
double expression()
{
    double left = term();      // Wczytuje i oblicza warto�� sk�adnika.
    Token t = ts.get();        // Pobiera nast�pny token ze strumienia wej�ciowego.

    while(true) {    
        switch(t.kind) {
        case '+':
            left += term();    // Oblicza warto�� sk�adnika i dodaje.
            t = ts.get();
            break;
        case '-':
            left -= term();    // Oblicza warto�� sk�adnika i odejmuje.
            t = ts.get();
            break;
        default: 
            ts.putback(t);     // Wstawia t z powrotem do strumienia token�w.
            return left;       // Nie ma wi�cej znak�w = i -. Zwraca wynik.
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
    cerr << "B��d: " << e.what() << '\n'; 
    return 1;
}
catch (...) {
    cerr << "Nieznany wyj�tek!\n"; 
    return 2;
}

//------------------------------------------------------------------------------
