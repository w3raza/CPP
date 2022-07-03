
//
// To jest przyk�adowy kod z podrozdzia�u 20.9 �Dostosowywanie wbudowanych tablic do STL� ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

template <class T, int N>    // Nie do ko�ca standardowa tablica.
struct array {
    typedef unsigned long size_type;
    typedef T value_type;
    typedef T* iterator;
    typedef T* const_iterator;

    T elems[N];
    // Nie s� potrzebne jawne operacje tworzenia, kopiowania i usuwania.

    iterator begin() { return elems; }
    const_iterator begin() const { return elems; }
    iterator end() { return elems+N; }
    const_iterator end() const { return elems+N; }

    size_type size() const;

    T& operator[](int n) { return elems[n]; }
    const T& operator[](int n) const { return elems[n]; }

    const T& at(int n) const;    // dost�p z kontrol� zakresu
    T& at(int n);             // dost�p z kontrol� zakresu

    T * data() { return elems; }
    const T * data() const { return elems; }
};

//------------------------------------------------------------------------------

template<class Iterator >
Iterator high(Iterator first, Iterator last)
// Zwraca iterator wskazuj�cy najwi�kszy element w przedziale <first,last).
{
    Iterator high = first;
    for (Iterator p = first; p!=last; ++p)
        if (*high<*p) high = p;
    return high;
}

//------------------------------------------------------------------------------

void f()
{
    array<double,6> a = { 0.0, 1.1, 2.2, 3.3, 4.4, 5.5 };
    array<double,6>::iterator p = high(a.begin(), a.end());
    cout << "Najwi�ksza warto�� to " << *p << endl;
}

//------------------------------------------------------------------------------

int main()
{
    f();
}

//------------------------------------------------------------------------------
