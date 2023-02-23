
//
// To jest przyk�adowy kod z podrozdzia�u 8.5.8 �Implementacja wywo�a� funkcji� ksi��ki 
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

class Token {
public:
    char kind;        // rodzaj tokenu
    double value;     // Dla liczb" warto��
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

double primary(Token_stream& ts);
double term(Token_stream& ts);

double expression(Token_stream& ts)
{
    double left = term(ts);
    Token t = ts.get();
    // ...
    return left;
}

//------------------------------------------------------------------------------

double term(Token_stream& ts)
{
    double left = primary(ts);
    Token t = ts.get();
    switch (t.kind) {
    // ...
        case '/':
        {
            double d = primary(ts);
            // ...
        }
    // ...
    }

    return left;
}

//------------------------------------------------------------------------------

double primary(Token_stream& ts)
{
    Token t = ts.get ();
    switch (t.kind) {
    case ' (':
        {    double d = expression(ts);
            // ...
        }
        // ...
    }

    return 0.0;
}

//------------------------------------------------------------------------------
