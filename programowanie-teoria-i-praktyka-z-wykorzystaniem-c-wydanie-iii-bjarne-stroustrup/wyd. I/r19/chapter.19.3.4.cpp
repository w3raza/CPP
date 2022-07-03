
//
// To jest przyk�adowy kod z podrozdzia�u 19.3.4 �Liczby ca�kowite jako parametry szablon�w� ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include <iostream>
#include <vector>

using std::cout;
using std::vector;

//------------------------------------------------------------------------------

template<class T, int N> struct array {
    T elem[N];                  // Przechowuje elementy w tablicy sk�adowej.

    // Polega na domy�lnych konstruktorach, destruktorze i przypisaniu.

    T& operator[ ] (int n) { return elem[n]; } // dost�p: zwraca referencj�
    const T& operator[ ] (int n) const { return elem[n]; }

    T* data() { return elem; }  // konwersja na T*
    const T* data() const { return elem; }

    int size() const  { return N; }    
};

//------------------------------------------------------------------------------

array<int,256> gb;          // 256 liczb ca�kowitych
array<double,6> ad = { 0.0, 1.1, 2.2, 3.3, 4.4, 5.5 };    // Zwr�� uwag� na inicjator!
const int max = 1024;

void some_fct(int n)
{
    array<char,max> loc;
    //array<char,n> oops;         // B��d: warto�� n nie jest znana kompilatorowi.
    // ...
    array<char,max> loc2 = loc; // Tworzy kopi� zapasow�.
    // ...
    loc = loc2;                 // przywr�cenie
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
    //double* p = ad;             // B��d: nie mo�na stosowa� niejawnej konwersji na wska�nik.
    double* q = ad.data();      // Dobrze: jawna konwersja.

    printout(ad);               // wywo�anie przez tablic�
    vector<int> vi;
    // ...
    printout(vi);               // wywo�anie przez wektor
}

//------------------------------------------------------------------------------
