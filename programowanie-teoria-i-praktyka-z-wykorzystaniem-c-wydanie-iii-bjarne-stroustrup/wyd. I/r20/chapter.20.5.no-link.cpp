
//
// To jest przyk³adowy kod z podrozdzia³u 20.5 „Jeszcze raz uogólnianie wektora” ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include <algorithm>
#include <iostream>

using namespace std;

//------------------------------------------------------------------------------

template<class T> class vector {
public:
    typedef unsigned long size_type;
    typedef T value_type;
    typedef T* iterator;
    typedef const T* const_iterator;

    // ...

    iterator begin();
    const_iterator begin() const;
    iterator end();
    const_iterator end() const;

    size_type size();
    void push_back(const T& v);  // Wstawia v na koñcu.
    const T& operator[](size_type i) const;
    // ...
};

//------------------------------------------------------------------------------

int main()
{
    vector<int> v;
    v.push_back(42);
    v.push_back(32);
    v.push_back(22);

    vector<int>::iterator p = find(v.begin(), v.end(),32);

    for (vector<int>::size_type i = 0; i<v.size(); ++i) cout << v[i] << '\n';
}

//------------------------------------------------------------------------------
