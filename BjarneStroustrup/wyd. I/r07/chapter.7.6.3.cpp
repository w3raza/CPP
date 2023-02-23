
//
// To jest przyk�adowy kod z podrozdzia�u 7.6.3 "Uk�ad kodu" ksi��ki 
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

/*
    Prosty kalkulator

    Historia:

        Poprawiony przez: Bjarne Stroustrup, maj 2007
        Poprawiony przez: Bjarne Stroustrup sierpie� 2006
        Poprawiony przez: Bjarne Stroustrup sierpie� 2004
        Autor orygina�u: Bjarne Stroustrup
            (bs@cs.tamu.edu) wiosna 2004.

    Ten program stanowi implementacj� kalkulatora podstawowych wyra�e�.
    Dane wej�ciowe pobiera ze strumienia cin, wyniki wysy�a do strumienia cout.

    Gramatyka danych wej�ciowych:

    Statement:
        Expression
        Print
        Quit

    Print:
        ;

    Quit:
        q 

    Expression:
        Term
        Expression + Term
        Expression - Term
    Term:
        Primary
        Term * Primary
        Term / Primary
        Term % Primary
    Primary:
        Number
        ( Expression )
        - Primary
        + Primary
    Number:
        floating-point-literal


        Dane przychodz� ze strumienia cin przez strumie� Token_stream o nazwie ts.
*/

//------------------------------------------------------------------------------

const char number = '8';    // t.kind==number oznacza, �e t jest tokenem liczbowym.
const char koniec   = 'q';    // t.kind==koniec oznacza, �e t jest tokenem oznaczaj�cym zamkni�cie programu.
const char print  = ';';    // t.kind==print oznacza, �e t jest tokenem oznaczaj�cym drukowanie.
const string prompt = "> ";
const string result = "= "; // Oznacza, �e to co znajduje si� dalej jest wynikiem.

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
    Token_stream();   // Tworzy strumie� token�w wczytuj�cy dane ze strumienia cin.
    Token get();      // Pobiera token (funkcja get() zosta�a zdefiniowana w innym miejscu).
    void putback(Token t);    // Zwraca token.
private:
    bool full;        // Sprawdza czy w buforze jest token.
    Token buffer;     // Przechowuje tokeny zwr�cone przez funkcj� putback().
};

//------------------------------------------------------------------------------

// Konstruktor ustawia warto�� full w taki spos�b, �e oznacza pusty bufor:
Token_stream::Token_stream()
:full(false), buffer(0)    // Bufor jest pusty.
{
}

//------------------------------------------------------------------------------

// Funkcja sk�adowa putback() wstawia sw�j argument z powrotem do bufora Token_stream::
void Token_stream::putback(Token t)
{
    if (full) error("Funkcja putback() wstawia dane do pe�nego bufora.");
    buffer = t;       // Kopiuje t do bufora.
    full = true;      // Bufor jest pe�ny.
}

//------------------------------------------------------------------------------

Token Token_stream::get() // Wczytuje znaki ze strumienia cin i tworzy tokeny.
{
    if (full) {         // Sprawdza czy jest ju� gotowy token.
        full=false;
        return buffer;
    }  

    char ch;
    cin >> ch;          // Operator >> pomija bia�e znaki (spacje, znaki nowego wiersza, tabulatory itp.).

    switch (ch) {
    case koniec:
    case print:
    case '(':
    case ')':
    case '+':
    case '-':
    case '*':
    case '/': 
    case '%':
        return Token(ch); // Ka�dy znak reprezentuje sam siebie.
    case '.':             // Litera� zmiennoprzecinkowy mo�e zaczyna� si� od kropki.
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':    // Litera� liczbowy.
    {
        cin.putback(ch);// Wstawia cyfr� z powrotem do strumienia wej�ciowego.
        double val;
        cin >> val;     // Wczytuje liczb� zmiennoprzecinkow�.
        return Token(number,val);// �liczba�
    }
    default:
        error("Bad token");
    }
}

//------------------------------------------------------------------------------

Token_stream ts;        // Dostarcza funkcji get() i pushback().

//------------------------------------------------------------------------------

double expression();    // Dzi�ki tej deklaracji funkcja primary() mo�e wywo�a� funkcj� expression().

//------------------------------------------------------------------------------

// Obs�uga liczb i nawias�w.
double primary()
{
    Token t = ts.get();
    switch (t.kind) {
    case '(':           // Obs�uga '(' wyra�enie ')'.
        {
            double d = expression();
            t = ts.get();
            if (t.kind != ')') error("')' by� oczekiwany");
            return d;
        }
    case number:    
        return t.value;    // Zwraca warto�� liczby.
    case '-':
        return - primary();
    case '+':
        return primary();
    default:
        error("Oczekiwano czynnika.");
    }
}

//------------------------------------------------------------------------------

// Obs�uga *, / oraz %.
double term()
{
    double left = primary();
    Token t = ts.get(); // Pobiera nast�pny token ze strumienia token�w.

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
            ts.putback(t);        // Wstawia t z powrotem do strumienia token�w.
            return left;
        }
    }
}

//------------------------------------------------------------------------------

// Obs�uga + i -.
double expression()
{
    double left = term();      // Wczytuje i oblicza warto�� sk�adnika.
    Token t = ts.get();        // Pobiera nast�pny token ze strumienia token�w.

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
            return left;       // Nie ma wi�cej znak�w + i -. Zwraca wynik.
        }
    }
}

//------------------------------------------------------------------------------

void calculate()    // P�tla obliczania warto�ci wyra�e�.
{
    while (cin) {
        cout << prompt;
        Token t = ts.get();
        while (t.kind == print) t=ts.get(); // Najpierw ignoruje wszystkie znaki drukowania.
        if (t.kind == koniec) return;         // koniec
        ts.putback(t);
        cout << result << expression() << endl;
    }
}

//------------------------------------------------------------------------------

int main()
try {
    calculate();
    keep_window_open();    // Rozwi�zuje problem zamykania okna konsoli w systemie Windows.
    return 0;
}
catch (runtime_error& e) {
    cerr << e.what() << endl;
    keep_window_open("~~");
    return 1;
}
catch (...) {
    cerr << "Wyj�tek \n";
    keep_window_open("~~");
    return 2;
}

//------------------------------------------------------------------------------
