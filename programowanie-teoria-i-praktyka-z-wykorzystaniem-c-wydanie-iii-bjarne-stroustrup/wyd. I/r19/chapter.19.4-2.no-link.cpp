
//
// To jest przyk�adowy kod z podrozdzia�u 19.4.2 �Sprawdzanie zakresu i wyj�tki� ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include <iostream>
#include <stdexcept>

using std::cin;
using std::cout;
using std::cerr;

//------------------------------------------------------------------------------

template<class T> class allocator {
public:
    // ...
    T* allocate(int n);            // Alokuje przestrze� dla n obiekt�w typu T.
    void deallocate(T* p, int n);  // Dealokuje n obiekt�w typu T, zaczynaj�c od p.

    void construct(T* p, const T& v); // Konstruuje T z warto�ci� v w p.
    void destroy(T* p);            // Usuwa T z p.
};

//------------------------------------------------------------------------------

struct out_of_range { /* ... */ }; // Klasa do raportowania o b��dach zakresu.

template<class T, class A = allocator<T> > class vector {
    A alloc;                       // Alokuje przestrze� dla element�w.
    int sz;                        // rozmiar
    T* elem;                       // wska�nik na elementy
    int space;                     // size+free_space
public:
    vector() : sz(0), elem(0), space(0) { }    
    vector(int s);

    vector(const vector&);            // konstruktor kopiuj�cy
    vector& operator=(const vector&); // przypisanie kopiuj�ce

    ~vector() { delete[ ] elem; }     // destruktor

    T& at(int n);                     // Dost�p kontrolowany    
    const T& at(int n) const;         // Dost�p kontrolowany

    T& operator[ ](int n);            // Dost�p niekontrolowany
    const T& operator[ ](int n) const;// Dost�p niekontrolowany

    int size() const { return sz; }   // aktualny rozmiar
    int capacity() const { return space; }
};

//------------------------------------------------------------------------------

template<class T, class A >  T& vector<T,A>::at(int n)
{
    if (n<0 || sz<=n) throw out_of_range();
    return elem[n];
}

//------------------------------------------------------------------------------

template<class T, class A >  T& vector<T,A>::operator[ ](int n) // jak poprzednio
{
    return elem[n];
}

//------------------------------------------------------------------------------

void print_some(vector<int>& v)
{
    int i = -1;
    cin >> i;
    while(i!= -1) try {
        cout << "v[" << i << "]==" << v.at(i) << "\n";
    }
    catch(out_of_range) {
        cout << "Nieprawid�owy indeks: " << i << "\n";
    }
}

//------------------------------------------------------------------------------

int main()
try
{
    vector<int> v(10);
    print_some(v);
}
catch (std::exception& e) {
    cerr << "B��d: " << e.what() << '\n'; 
    return 1;
}
catch (...) {
    cerr << "Ojej: nieznany wyj�tek!\n"; 
    return 2;
}

//------------------------------------------------------------------------------
