
//
// To jest przyk³adowy kod z podrozdzia³u 17.5 „Destruktory” ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

//------------------------------------------------------------------------------
// Bardzo uproszczony wektor liczb typu double.
class vector {
    int sz;              // rozmiar
    double* elem;        // wskaŸnik elementów
public:
    vector(int s)                   // konstruktor
        :sz(s), elem(new double[s]) // alokowanie pamiêci
    {
        for (int i=0; i<s; ++i) elem[i]=0;    // inicjacja elementów
    }

    ~vector()            // destruktor
    { delete[] elem; }   // pamiêæ wolna
    // ...
};

//------------------------------------------------------------------------------

void f3(int n)
{
    int* p = new int[n]; // alokuje n liczb typu int
    vector v(n);         // Definicja wektora (który alokuje kolejne n liczb typu int).
                         // ... operacje z u¿yciem p i v ...
    delete[] p;          // dealokacja liczb int
}                        // Wektor automatycznie czyœci po v.

int main()
{
    f3(42);
}

//------------------------------------------------------------------------------
