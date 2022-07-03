
//
// To jest przyk�adowy kod z podrozdzia�u 17.5 �Destruktory� ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

//------------------------------------------------------------------------------
// Bardzo uproszczony wektor liczb typu double:
class vector {
    int sz;              // rozmiar
    double* elem;        // wska�nik element�w
public:
    vector(int s)        // konstruktor
        :sz(s),          // inicjacja sz
        elem(new double[s]) // inicjacja elem
    {
        for (int i=0; i<s; ++i) elem[i]=0; // inicjacja element�w
    }
    int size() const { return sz; }        // bie��cy rozmiar wektora
    // ...
    void clean_up() { delete[] elem; elem = 0; } // pami�� wolna
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
    vector v(n);         // Definicja wektora (kt�ry alokuje n liczb typu int).
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
