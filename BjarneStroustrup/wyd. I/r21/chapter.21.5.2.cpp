
//
// To jest przyk³adowy kod z podrozdzia³u 21.5.2 „Uogólnianie funkcji accumulate()” ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include <functional>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

//------------------------------------------------------------------------------

template <class T, int N>    // Nie do koñca standardowa tablica.
struct array {
    typedef unsigned long size_type;
    typedef T value_type;
    typedef T* iterator;
    typedef T* const_iterator;

    T elems[N];
    // Nie s¹ potzrebne jawne operacje tworzenia, kopiowania i usuwania.

    iterator begin() { return elems; }
    const_iterator begin() const { return elems; }
    iterator end() { return elems+N; }
    const_iterator end() const { return elems+N; }

    size_type size() const;

    T& operator[](int n) { return elems[n]; }
    const T& operator[](int n) const { return elems[n]; }

    const T& at(int n) const; // Dostêp z kontrol¹ zakresu.
    T& at(int n);             // Dostêp z kontrol¹ zakresu.

    T * data() { return elems; }
    const T * data() const { return elems; }
};

//------------------------------------------------------------------------------


template<class In, class T, class BinOp>
T accumulate(In first, In last, T init, BinOp op)
{
    while (first!=last) {
        init = op(init, *first);
        ++first;
    }
    return init;
}

//------------------------------------------------------------------------------

int main()
{
    array<double,4> a = { 1.1, 2.2, 3.3, 4.4 };    // Zobacz podrozdzia³ 20.9.
    cout << accumulate(a.begin(),a.end(), 1.0, multiplies<double>());
}

//------------------------------------------------------------------------------

struct Record {
    double unit_price;
    int units;        // Liczba sprzedanych jednostek.
    // ...
};

//------------------------------------------------------------------------------

double price(double v, const Record& r)
{
    return v + r.unit_price * r.units;
}

//------------------------------------------------------------------------------

void f(const vector<Record>& vr, map<string,Record*>& m)
{
    double total = accumulate(vr.begin(), vr.end(), 0.0, price);
    // ...
}

//------------------------------------------------------------------------------
