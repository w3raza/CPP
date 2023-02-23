
//
// To jest przyk³adowy kod z podrozdzia³u 18.2 „Kopiowanie” ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include <iostream>

using std::cout;

//------------------------------------------------------------------------------

class vector {
    int sz;                             // rozmiar
    double* elem;                       // wskaŸnik na elementy
public:
    vector(int s)                       // konstruktor
        :sz(s), elem(new double[s]) { } // alokuje pamiêæ
    ~vector()                           // destruktor
    { delete[ ] elem; }                 // dealokuje pamiêæ

    int size() const { return sz; }               // aktualny rozmiar

    double get(int n) { return elem[n]; }         // dostêp: odczyt
    void set(int n, double v) { elem[n]=v; }      // dostêp: zapis
};

//------------------------------------------------------------------------------

void f(int n)
{
    vector v(3);                        // definicja wektora 3 elementów
    v.set(2,2.2);                       // ustawia v[2] na 2.2
    vector v2 = v;                      // Co siê tutaj dzieje?
    // ...
}

//------------------------------------------------------------------------------

int main()
{
    vector v(3);
    vector v2(3);
    v.set(1,99);                        // Ustawia element v[1] na wartoœæ 99.
    v2.set(0,88);                       // Ustawia element v2[0] na wartoœæ 88.
    cout << v.get(0) << ' ' << v2.get(1); 
}

//------------------------------------------------------------------------------
