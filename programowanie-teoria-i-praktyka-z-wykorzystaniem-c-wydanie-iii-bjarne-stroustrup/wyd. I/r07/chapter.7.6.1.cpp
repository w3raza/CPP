
//
// To jest przyk³adowy kod z podrozdzia³u 7.6.1 "Sta³e symboliczne" ksi¹¿ki 
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

const char number = '8';    // t.kind==number oznacza, ¿e t jest tokenem liczbowym.
const char koniec   = 'q';    // t.kind==koniec oznacza, ¿e t jest tokenem oznaczaj¹cym zamkniêcie programu.
const char print  = ';';    // t.kind==print oznacza, ¿e t jest tokenem oznaczaj¹cym drukowanie.
const string prompt = "> ";
const string result = "= "; // Oznacza, ¿e to co znajduje siê dalej jest wynikiem.

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
    case print:    // Oznacza drukowanie.
    case koniec:     Oznacza koniec.
    case '(': case ')': case '+': case '-': case '*': case '/': case '%': 
        return Token(ch);        // Ka¿dy znak reprezentuje sam siebie.
    case '.':
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
        {    
            cin.putback(ch);         // Wstawia cyfrê z powrotem do strumienia wejœciowego.
            double val;
            cin >> val;              // Wczytuje liczbê zmiennoprzecinkow¹.
            return Token(number,val);// „liczba”
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
    case '(':           // Obs³uga '(' wyra¿enie ')'.
        {
            double d = expression();
            t = ts.get();
            if (t.kind != ')') error("')' by³ oczekiwany");
            return d;
        }
    case number:    
        return t.value;    // Zwraca wartoœæ liczby.
    case '-':
        return - primary();
    case '+':
        return primary();
    default:
        error("Oczekiwano czynnika.");
    }
}

//------------------------------------------------------------------------------

// Obs³uga *, / oraz %.
double term()
{
    double left = primary();
    Token t = ts.get(); // Pobiera nastêpny token ze strumienia tokenów.

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
        case '%':
            {    
                int i1 = narrow_cast<int>(left);
                int i2 = narrow_cast<int>(term());
                if (i2 == 0) error("%: Dzielenie przez zero.");
                left = i1%i2; 
                t = ts.get();
                break;
            }
        default: 
            ts.putback(t);        // Wstawia t z powrotem do strumienia tokenów.
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
    while (cin) {
        cout << prompt;
        Token t = ts.get();
        while (t.kind == print) t=ts.get();
        if (t.kind == koniec) {
            keep_window_open();
            return 0;
        }
        ts.putback(t);
        cout << result << expression() << endl;
    }

    keep_window_open();
    return 0;
}
catch (exception& e) {
    cerr << e.what() << endl;
    keep_window_open("~~");
    return 1;
}
catch (...) {
    cerr << "Wyj¹tek \n";
    keep_window_open("~~");
    return 2;
}

//------------------------------------------------------------------------------
