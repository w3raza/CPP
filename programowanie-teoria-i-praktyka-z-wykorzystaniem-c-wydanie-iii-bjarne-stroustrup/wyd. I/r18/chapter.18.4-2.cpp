
//
// To jest przyk�adowy kod z podrozdzia�u 18.4 �Uzyskiwanie dost�pu do element�w wektora� ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include <iostream>

using std::cout;

//------------------------------------------------------------------------------

class vector {
    int sz;          // rozmiar
    double* elem;    // wska�nik na elementy
public:
    vector(int s) :sz(s), elem(new double[s]) { }  // konstruktor
    ~vector() { delete[] elem; }                   // destruktor
    int size() const { return sz; }                // aktualny rozmiar
    double* operator[](int n) { return &elem[n]; } // zwraca wska�nik
};

//------------------------------------------------------------------------------

int main()
{
    vector v(10);
    for (int i=0; i<v.size(); ++i) {    // Dzia�a, ale jest to nieeleganckie rozwi�zanie.
        *v[i] = i;    
        cout << *v[i];
    }
}

//------------------------------------------------------------------------------
