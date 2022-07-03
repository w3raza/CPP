
//
// Przyk�adowy kod z rozdzia�u 6.6 "Wypr�bowywanie pierwszej wersji" ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

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

class Token_stream {
public: 
    Token_stream();   // Tworzy Token_stream wczytuj�cy ze strumienia cin.
    Token get();      // Pobiera token.
    void putback(Token t); // Wstawia token z powrotem.
private:
    // szczeg�y implementacyjne
};

//------------------------------------------------------------------------------

Token_stream ts;      // globalny strumie� token�w

//------------------------------------------------------------------------------

double expression();  // Wczytuje i warto�ciuje wyra�enie.

//------------------------------------------------------------------------------

double term();        // Wczytuje i warto�ciuje sk�adnik.

//------------------------------------------------------------------------------

double primary();     // Wczytuje i warto�ciuje czynnik.

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
    cerr << "Wyj�tek \n";
    keep_window_open ();
    return 2;
}

//------------------------------------------------------------------------------

double expression()
{
    double left = term(); // Wczytuje i warto�ciuje sk�adnik.
    Token t = ts.get();   // Pobiera nast�pny token ze strumienia.

    while(true) {    
        switch(t.kind) {
    case '+':
        left += term();   // Warto�ciuje sk�adnik i wykonuje dodawanie.
        t = ts.get();
        break;
    case '-':
        left -= term();   // Warto�ciuje sk�adnik i wykonuje odejmowanie.
        t = ts.get();
        break;
    default: 
        ts.putback(t);    // Wstawia token t z powrotem do strumienia token�w.
        return left;      // Je�li nie ma wi�cej znak�w + lub �, zwraca odpowied�.
        }
    }
}

//------------------------------------------------------------------------------

double term()
{
    double left = primary();
    Token t = ts.get();   // Pobiera nast�pny token ze strumienia.

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
            ts.putback(t); // Wstawia token t z powrotem do strumienia token�w.
            return left;
        }
    }
}

//------------------------------------------------------------------------------
