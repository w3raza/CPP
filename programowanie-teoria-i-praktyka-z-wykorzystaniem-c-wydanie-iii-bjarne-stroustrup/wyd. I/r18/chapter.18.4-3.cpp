
//
// To jest przyk³adowy kod z podrozdzia³u 18.4 „Uzyskiwanie dostêpu do elementów wektora” ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include <iostream>

using std::cout;

//------------------------------------------------------------------------------

class vector {
    int sz;          // rozmiar
    double* elem;    // wskaŸnik na elementy
public:
    vector(int s) :sz(s), elem(new double[s]) { } // konstruktor
    ~vector() { delete[] elem; }                  // destruktor
    int size() const { return sz; }               // aktualny rozmiar
    double& operator[](int n) { return elem[n]; } // zwraca referencjê
};

//------------------------------------------------------------------------------

int main()
{
    vector v(10);
    for (int i=0; i<v.size(); ++i) {    // Dzia³a!
        v[i] = i;            // v[i] zwraca referencjê do elementu i
        cout << v[i];
    }
}

//------------------------------------------------------------------------------
