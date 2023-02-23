
//
// To jest przyk³adowy kod z podrozdzia³u 18.2.1 „Konstruktory kopiuj¹ce” ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include <iostream>

using std::cout;

//------------------------------------------------------------------------------

class vector {
    int sz;
    double* elem;
    void copy(const vector& arg);                 // Kopiuje elementy z arg do *elem.
public:
    vector(int s) :sz(s), elem(new double[s]) { } // konstruktor
    vector(const vector&) ;                       // Konstruktor kopiuj¹cy — definiuje kopiowanie.
    ~vector() { delete[] elem; }                  // destruktor

    int size() const { return sz; }               // aktualny rozmiar

    double get(int n) { return elem[n]; }         // dostêp: odczyt
    void set(int n, double v) { elem[n]=v; }      // dostêp: zapis
    // ...
};

//------------------------------------------------------------------------------

void vector::copy(const vector& arg)
// Kopiuje elementy <0,arg.sz–1>.
{
    for (int i = 0; i<arg.sz; ++i) elem[i] = arg.elem[i];
}

//------------------------------------------------------------------------------

vector:: vector(const vector& arg)
// Alokuje elementy i inicjuje je poprzez kopiowanie.
    :sz(arg.sz), elem(new double[arg.sz])
{
    copy(arg);
}

//------------------------------------------------------------------------------

int main()
{
    vector v(3);
    vector v2 = v;

    v.set(1,99);         // Ustawia element v[1] na wartoœæ 99.
    v2.set(0,88);        // Ustawia element v2[0] na wartoœæ 88.
    cout << v.get(0) << ' ' << v2.get(1); 
}

//------------------------------------------------------------------------------
