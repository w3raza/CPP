
//
// To jest przyk³adowy kod z podrozdzia³u 17.5 „Destruktory” ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

//------------------------------------------------------------------------------
// Bardzo uproszczony wektor liczb typu double:
class vector {
    int sz;              // rozmiar
    double* elem;        // wskaŸnik elementów
public:
    vector(int s)        // konstruktor
        :sz(s),          // inicjacja sz
        elem(new double[s]) // inicjacja elem
    {
        for (int i=0; i<s; ++i) elem[i]=0; // inicjacja elementów
    }
    int size() const { return sz; }        // bie¿¹cy rozmiar wektora
    // ...
    void clean_up() { delete[] elem; elem = 0; } // pamiêæ wolna
};

//------------------------------------------------------------------------------

void f(int n)
{
    vector v(n);    // alokuje n liczb typu double
    // ... 
}

//------------------------------------------------------------------------------

void f2(int n)
{
    vector v(n);         // Definicja wektora (który alokuje n liczb typu int).
    // ... v ...
    v.clean_up();        // Funkcja clean_up() usuwa elem.
}

//------------------------------------------------------------------------------

int main()
{
    f(5);
    f2(7);
}

//------------------------------------------------------------------------------
