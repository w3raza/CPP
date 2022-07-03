
//
// To jest przyk³adowy kod z podrozdzia³u 6.8 "Strumienie tokenów" ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

//------------------------------------------------------------------------------

class Token {
public:
    char kind;        // Rodzaj tokenu.
    double value;     // Dla liczb: wartoœæ.
    Token(char ch)    // Tworzy token ze znaku.
        :kind(ch), value(0) { }    
    Token(char ch, double val)   // Tworzy token zeznaku i liczby typu double.
        :kind(ch), value(val) { }
};

//------------------------------------------------------------------------------

class Token_stream {
public: 
    // Interfejs u¿ytkownika.
    Token_stream();   // Tworzy Token_stream wczytuj¹cy ze strumienia cin.
    Token get();      // Pobiera token.
    void putback(Token t); // Wstawia token z powrotem.
private:
    // Szczegó³y implementacyjne
    // (niedostêpne bezpoœrednio u¿ytkownikom typu Token_stream).
};

//------------------------------------------------------------------------------

int main()
{
    Token_stream ts;    // Strumieñ tokenów o nazwie ts.
    Token t = ts.get(); // Pobiera nastêpny token ze strumienia ts.
    // ...
    ts.putback(t);      // Wstawia token t z powrotem do ts.
}

//------------------------------------------------------------------------------
