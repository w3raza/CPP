
//
// Przyk�adowy kod z rozdzia�u 6.8.1 "Implementacja typu Token_stream" ksi��ki
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

int main()
try
{
    Token_stream ts;
    ts.putback(')');
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
