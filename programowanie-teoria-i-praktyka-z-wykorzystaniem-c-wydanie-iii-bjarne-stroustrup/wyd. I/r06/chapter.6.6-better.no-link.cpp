
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
    Token(char ch)    // Tworzy Token ze znaku.
        :kind(ch), value(0) { }    
    Token(char ch, double val)     // Tworzy Token ze znaku i wartoœci typu double.
        :kind(ch), value(val) { }
};

//------------------------------------------------------------------------------

class Token_stream {
public: 
    Token_stream();   // Tworzy Token_stream wczytuj¹cy ze strumienia cin.
    Token get();      // Pobiera token.
    void putback(Token t); // Wstawia token z powrotem.
private:
    // szczegó³y implementacyjne
};

//------------------------------------------------------------------------------

Token_stream ts;      // globalny strumieñ tokenów

//------------------------------------------------------------------------------

double expression();  // Wczytuje i wartoœciuje wyra¿enie.

//------------------------------------------------------------------------------

double term();        // Wczytuje i wartoœciuje sk³adnik.

//------------------------------------------------------------------------------

double primary();     // Wczytuje i wartoœciuje czynnik.

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
    double left = term(); // Wczytuje i wartoœciuje sk³adnik.
    Token t = ts.get();   // Pobiera nastêpny token ze strumienia.

    while(true) {    
        switch(t.kind) {
    case '+':
        left += term();   // Wartoœciuje sk³adnik i wykonuje dodawanie.
        t = ts.get();
        break;
    case '-':
        left -= term();   // Wartoœciuje sk³adnik i wykonuje odejmowanie.
        t = ts.get();
        break;
    default: 
        ts.putback(t);    // Wstawia token t z powrotem do strumienia tokenów.
        return left;      // Jeœli nie ma wiêcej znaków + lub –, zwraca odpowiedŸ.
        }
    }
}

//------------------------------------------------------------------------------

double term()
{
    double left = primary();
    Token t = ts.get();   // Pobiera nastêpny token ze strumienia.

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
            ts.putback(t); // Wstawia token t z powrotem do strumienia tokenów.
            return left;
        }
    }
}

//------------------------------------------------------------------------------
