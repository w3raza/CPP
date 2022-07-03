
//
// To jest przyk³adowy kod z podrozdzia³u 18.4 "Uzyskiwanie dostêpu do elementów wektora" ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

//------------------------------------------------------------------------------

class vector {
    int sz;          // rozmiar
    double* elem;    // wskaŸnik na elementy
public:
    vector(int s) :sz(s), elem(new double[s]) { } // konstruktor
    ~vector() { delete[] elem; }                  // destruktor
    // ...
    double operator[](int n) { return elem[n]; }  // zwraca element
};

//------------------------------------------------------------------------------

int main()
{
    vector v(10);
    int x = v[2];    // dobrze
    //v[3] = x;        // b³¹d: v[3] nie jest l-wartoœci¹
}

//------------------------------------------------------------------------------
