
//
// To jest przyk³adowy kod z podrozdzia³u 17.6 „Dostêp do elementów” ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include <iostream>

using namespace std;

//------------------------------------------------------------------------------

// Bardzo uproszczony wektor liczb typu double.
class vector {
    int sz;            // rozmiar
    double* elem;      // wskaŸnik na elementy
public:
    vector(int s) :sz(s), elem(new double[s]) { } // konstruktor
    ~vector() { delete[] elem; }                  // destruktor

    int size() const { return sz; }               // bie¿¹cy rozmiar wektora

    double get(int n) { return elem[n]; }         // dostêp: odczyt
    void set(int n, double v) { elem[n]=v; }      // dostêp: zapis
};

//------------------------------------------------------------------------------

int main()
{
    vector v(5);
    for (int i=0; i<v.size(); ++i) {
        v.set(i,1.1*i);
        cout << "v[" << i << "]==" << v.get(i) << '\n';
    }
}

//------------------------------------------------------------------------------
