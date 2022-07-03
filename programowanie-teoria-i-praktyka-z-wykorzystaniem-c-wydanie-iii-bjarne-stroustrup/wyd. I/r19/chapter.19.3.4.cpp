
//
// To jest przyk³adowy kod z podrozdzia³u 19.3.4 „Liczby ca³kowite jako parametry szablonów” ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include <iostream>
#include <vector>

using std::cout;
using std::vector;

//------------------------------------------------------------------------------

template<class T, int N> struct array {
    T elem[N];                  // Przechowuje elementy w tablicy sk³adowej.

    // Polega na domyœlnych konstruktorach, destruktorze i przypisaniu.

    T& operator[ ] (int n) { return elem[n]; } // dostêp: zwraca referencjê
    const T& operator[ ] (int n) const { return elem[n]; }

    T* data() { return elem; }  // konwersja na T*
    const T* data() const { return elem; }

    int size() const  { return N; }    
};

//------------------------------------------------------------------------------

array<int,256> gb;          // 256 liczb ca³kowitych
array<double,6> ad = { 0.0, 1.1, 2.2, 3.3, 4.4, 5.5 };    // Zwróæ uwagê na inicjator!
const int max = 1024;

void some_fct(int n)
{
    array<char,max> loc;
    //array<char,n> oops;         // B³¹d: wartoœæ n nie jest znana kompilatorowi.
    // ...
    array<char,max> loc2 = loc; // Tworzy kopiê zapasow¹.
    // ...
    loc = loc2;                 // przywrócenie
    // ...
}

//------------------------------------------------------------------------------

template<class C> void printout(const C& c)
{
    for(int i = 0; i<c.size(); ++i) cout << c[i] <<'\n';
}

//------------------------------------------------------------------------------

int main(int argc, char* argv[])
{
    //double* p = ad;             // B³¹d: nie mo¿na stosowaæ niejawnej konwersji na wskaŸnik.
    double* q = ad.data();      // Dobrze: jawna konwersja.

    printout(ad);               // wywo³anie przez tablicê
    vector<int> vi;
    // ...
    printout(vi);               // wywo³anie przez wektor
}

//------------------------------------------------------------------------------
