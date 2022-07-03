
//
// To jest przyk³adowy kod z podrozdzia³u 19.4 „Sprawdzanie zakresu i wyj¹tki” ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include <iostream>

using std::cin;

//------------------------------------------------------------------------------

template<class T> class allocator {
public:
    // ...
    T* allocate(int n);            // Alokuje przestrzeñ dla n obiektów typu T.
    void deallocate(T* p, int n);  // Dealokuje n obiektów typu T, zaczynaj¹c od p.

    void construct(T* p, const T& v); // Konstruuje T z wartoœci¹ v w p.
    void destroy(T* p);            // Usuwa T z p.
};

//------------------------------------------------------------------------------

template<class T, class A = allocator<T> > class vector {
    A alloc;                       // Alokuje przestrzeñ dla elementów.
    int sz;                        // rozmiar
    T* elem;                       // wskaŸnik na elementy
    int space;                     // size+free_space
public:
    vector() : sz(0), elem(0), space(0) { }    
    vector(int s);

    vector(const vector&);            // konstruktor kopiuj¹cy
    vector& operator=(const vector&); // przypisanie kopiuj¹ce

    ~vector() { delete[ ] elem; }     // destruktor

    T& operator[ ] (int n);           // dostêp: zwraca referencjê
    const T& operator[ ] (int n) const;

    int size() const { return sz; }   // aktualny rozmiar
    int capacity() const { return space; }
};

//------------------------------------------------------------------------------

template<class T, class A> T& vector<T,A>::operator[ ](int n)
{
    return elem[n];
}

//------------------------------------------------------------------------------

int main()
{
    vector<int> v(100);
    v[-200] = v[200];         // Ojej!
    int i;
    cin>>i;
    v[i] = 999;               
}

//------------------------------------------------------------------------------
