
//
// To jest przyk�adowy kod z podrozdzia�u 17.5 �Destruktory� ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

//------------------------------------------------------------------------------
// Bardzo uproszczony wektor liczb typu double.
class vector {
    int sz;              // rozmiar
    double* elem;        // wska�nik element�w
public:
    vector(int s)                   // konstruktor
        :sz(s), elem(new double[s]) // alokowanie pami�ci
    {
        for (int i=0; i<s; ++i) elem[i]=0;    // inicjacja element�w
    }

    ~vector()            // destruktor
    { delete[] elem; }   // pami�� wolna
    // ...
};

//------------------------------------------------------------------------------

void f3(int n)
{
    int* p = new int[n]; // alokuje n liczb typu int
    vector v(n);         // Definicja wektora (kt�ry alokuje kolejne n liczb typu int).
                         // ... operacje z u�yciem p i v ...
    delete[] p;          // dealokacja liczb int
}                        // Wektor automatycznie czy�ci po v.

int main()
{
    f3(42);
}

//------------------------------------------------------------------------------
