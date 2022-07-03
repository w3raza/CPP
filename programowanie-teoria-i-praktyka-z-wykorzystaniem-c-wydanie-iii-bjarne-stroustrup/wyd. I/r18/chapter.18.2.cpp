
//
// To jest przyk�adowy kod z podrozdzia�u 18.2 �Kopiowanie� ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include <iostream>

using std::cout;

//------------------------------------------------------------------------------

class vector {
    int sz;                             // rozmiar
    double* elem;                       // wska�nik na elementy
public:
    vector(int s)                       // konstruktor
        :sz(s), elem(new double[s]) { } // alokuje pami��
    ~vector()                           // destruktor
    { delete[ ] elem; }                 // dealokuje pami��

    int size() const { return sz; }               // aktualny rozmiar

    double get(int n) { return elem[n]; }         // dost�p: odczyt
    void set(int n, double v) { elem[n]=v; }      // dost�p: zapis
};

//------------------------------------------------------------------------------

void f(int n)
{
    vector v(3);                        // definicja wektora 3 element�w
    v.set(2,2.2);                       // ustawia v[2] na 2.2
    vector v2 = v;                      // Co si� tutaj dzieje?
    // ...
}

//------------------------------------------------------------------------------

int main()
{
    vector v(3);
    vector v2(3);
    v.set(1,99);                        // Ustawia element v[1] na warto�� 99.
    v2.set(0,88);                       // Ustawia element v2[0] na warto�� 88.
    cout << v.get(0) << ' ' << v2.get(1); 
}

//------------------------------------------------------------------------------
