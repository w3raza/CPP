
//
// To jest przyk�adowy kod z podrozdzia�u 6.8 "Strumienie token�w" ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

//------------------------------------------------------------------------------

class Token {
public:
    char kind;        // Rodzaj tokenu.
    double value;     // Dla liczb: warto��.
    Token(char ch)    // Tworzy token ze znaku.
        :kind(ch), value(0) { }    
    Token(char ch, double val)   // Tworzy token zeznaku i liczby typu double.
        :kind(ch), value(val) { }
};

//------------------------------------------------------------------------------

class Token_stream {
public: 
    // Interfejs u�ytkownika.
    Token_stream();   // Tworzy Token_stream wczytuj�cy ze strumienia cin.
    Token get();      // Pobiera token.
    void putback(Token t); // Wstawia token z powrotem.
private:
    // Szczeg�y implementacyjne
    // (niedost�pne bezpo�rednio u�ytkownikom typu Token_stream).
};

//------------------------------------------------------------------------------

int main()
{
    Token_stream ts;    // Strumie� token�w o nazwie ts.
    Token t = ts.get(); // Pobiera nast�pny token ze strumienia ts.
    // ...
    ts.putback(t);      // Wstawia token t z powrotem do ts.
}

//------------------------------------------------------------------------------
