
//
// To jest przyk³adowy kod z podrozdzia³u 7.8.2 "Wprowadzanie nazw" ksi¹¿ki 
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

/*
    Prosty kalkulator

    Historia:

        Poprawiony przez: Bjarne Stroustrup, maj 2007
        Poprawiony przez: Bjarne Stroustrup sierpieñ 2006
        Poprawiony przez: Bjarne Stroustrup sierpieñ 2004
        Autor orygina³u: Bjarne Stroustrup
            (bs@cs.tamu.edu) wiosna 2004.

    Ten program stanowi implementacjê kalkulatora podstawowych wyra¿eñ.
    Dane wejœciowe pobiera ze strumienia cin, wyniki wysy³a do strumienia cout.

    Gramatyka danych wejœciowych:

    Calculation:
        Statement
        Print
        Quit
        Calculation Statement
    
    Statement:
        Declaration
        Expression
    
    Declaration:
        "let" Name "=" Expression

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
        Name
        ( Expression )
        - Primary
        + Primary
    Number:
        floating-point-literal


        Dane przychodz¹ ze strumienia cin przez strumieñ Token_stream o nazwie ts.
*/

//------------------------------------------------------------------------------

const char number = '8';      // t.kind==number oznacza, ¿e t jest tokenem liczbowym.
const char koniec   = 'q';    // t.kind==koniec oznacza, ¿e t jest tokenem oznaczaj¹cym zamkniêcie programu.
const char print  = ';';      // t.kind==print oznacza, ¿e t jest tokenem oznaczaj¹cym drukowanie.
const char name   = 'a';      // Token nazwy.
const char let    = 'L';      // Token deklaracji.
const string declkey = "let"; // S³owo kluczowe deklaracji.
const string prompt  = "> ";
const string result  = "= ";  // Oznacza, ¿e to co znajduje siê dalej jest wynikiem.

//------------------------------------------------------------------------------

class Token {
public:
    char kind;        // Rodzaj tokenu.
    double value;     // Dla liczb: wartoœæ.
    string name;      // Dla nazw: sama nazwa.
    Token(char ch)             : kind(ch), value(0)   {}
    Token(char ch, double val) : kind(ch), value(val) {}
    Token(char ch, string n)   : kind(ch), name(n)    {}
};

//------------------------------------------------------------------------------

class Token_stream {
public: 
    Token_stream();   // Tworzy strumieñ tokenów wczytuj¹cy dane ze strumienia cin.
    Token get();      // Pobiera token (funkcja get() zosta³a zdefiniowana w innym miejscu).
    void putback(Token t);    // Zwraca token.
    void ignore(char c);      // Ignoruje tokeny do c (w³¹cznie).
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

Token Token_stream::get() // Wczytuje znaki ze strumienia cin i tworzy tokeny.
{
    if (full) {         // Sprawdza czy jest ju¿ gotowy token.
        full=false;
        return buffer;
    }  

    char ch;
    cin >> ch;          // Operator >> pomija bia³e znaki (spacje, znaki nowego wiersza, tabulatory itp.).

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
    case '=':
        return Token(ch); // Ka¿dy znak reprezentuje sam siebie.
    case '.':             // Litera³ zmiennoprzecinkowy mo¿e zaczynaæ siê od kropki.
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':    // Litera³ liczbowy.
    {
        cin.putback(ch);// Wstawia cyfrê z powrotem do strumienia wejœciowego.
        double val;
        cin >> val;     // Wczytuje liczbê zmiennoprzecinkow¹.
        return Token(number,val);
    }
    default:
        if (isalpha(ch)) {
            string s;
            s += ch;
            while (cin.get(ch) && (isalpha(ch) || isdigit(ch))) s+=ch;
            cin.putback(ch);
            if (s == declkey) return Token(let); // S³owo kluczowe deklaracji.
            return Token(name,s);
        }
        error("Nieprawid³owy token.");
    }
}

//------------------------------------------------------------------------------

void Token_stream::ignore(char c)
    // c reprezentuje rodzaj tokenu.
{
    // Najpierw szuka w buforze:
    if (full && c==buffer.kind) {
        full = false;
        return;
    }
    full = false;

    // Szukanie w danych wejœciowych:
    char ch = 0;
    while (cin>>ch)
        if (ch==c) return;
}

//------------------------------------------------------------------------------

Token_stream ts;        // Dostarcza funkcji get() i pushback().

//------------------------------------------------------------------------------

class Variable {
public:
    string name;
    double value;
    Variable (string n, double v) :name(n), value(v) { }
};

//------------------------------------------------------------------------------

vector<Variable> var_table;

//------------------------------------------------------------------------------

double get_value(string s)
    // 
{
    for (int i = 0; i<var_table.size(); ++i)
        if (var_table[i].name == s) return var_table[i].value;
    error("get: niezdefiniowana zmienna ", s);
}

//------------------------------------------------------------------------------

void set_value(string s, double d)
    // Ustawia zmienn¹ o nazwie s na d.
{
    for (int i = 0; i<var_table.size(); ++i)
        if (var_table[i].name == s) {
            var_table[i].value = d;
            return;
        }
    error("set: niezdefiniowana zmienna. ", s);
}

//------------------------------------------------------------------------------

bool is_declared(string var)
    // Sprawdza czy var jest ju¿ w var_table.
{
    for (int i = 0; i<var_table.size(); ++i)
        if (var_table[i].name == var) return true;
    return false;
}

//------------------------------------------------------------------------------

double define_name(string var, double val)
    // Dodaje (var,val) do var_table.
{
    if (is_declared(var)) error(var," zadeklarowana dwukrotnie.");
    var_table.push_back(Variable(var,val));
    return val;
}

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
    case name:
        return get_value(t.name); // Zwraca wartoœæ zmiennej.
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

double declaration()
    // Obs³uga: nazwa = wyra¿enie
    // Deklaracja zmiennej o nazwie name o wartoœci pocz¹tkowej expression.
{
    Token t = ts.get();
    if (t.kind != name) error ("Oczekiwano name w deklaracji.");
    string var_name = t.name;

    Token t2 = ts.get();
    if (t2.kind != '=') error("Brakuje znaku = w deklaracji", var_name);

    double d = expression();
    define_name(var_name,d);
    return d;
}

//------------------------------------------------------------------------------

double statement()
{
    Token t = ts.get();
    switch (t.kind) {
    case let:
        return declaration();
    default:
        ts.putback(t);
        return expression();
    }
}

//------------------------------------------------------------------------------

void clean_up_mess()
{ 
    ts.ignore(print);
}

//------------------------------------------------------------------------------

void calculate()
{
    while (cin)
      try {
        cout << prompt;
        Token t = ts.get();
        while (t.kind == print) t=ts.get();  // Najpierw ignoruje wszystkie znaki drukowania.
        if (t.kind == koniec) return;        // koniec
        ts.putback(t);
        cout << result << statement() << endl;
    }
    catch (exception& e) {
        cerr << e.what() << endl;        // Drukuje komunikat o b³êdzie.
        clean_up_mess();
    }
}

//------------------------------------------------------------------------------

int main()
try {
    calculate();
    keep_window_open();    // Rozwi¹zuje problem zamykania okna konsoli w systemie Windows.
    return 0;
}
catch (runtime_error& e) {
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
