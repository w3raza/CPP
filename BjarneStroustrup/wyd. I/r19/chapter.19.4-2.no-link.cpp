
//
// To jest przyk³adowy kod z podrozdzia³u 19.4.2 „Sprawdzanie zakresu i wyj¹tki” ksi¹¿ki
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
    T* allocate(int n);            // Alokuje przestrzeñ dla n obiektów typu T.
    void deallocate(T* p, int n);  // Dealokuje n obiektów typu T, zaczynaj¹c od p.

    void construct(T* p, const T& v); // Konstruuje T z wartoœci¹ v w p.
    void destroy(T* p);            // Usuwa T z p.
};

//------------------------------------------------------------------------------

struct out_of_range { /* ... */ }; // Klasa do raportowania o b³êdach zakresu.

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

    T& at(int n);                     // Dostêp kontrolowany    
    const T& at(int n) const;         // Dostêp kontrolowany

    T& operator[ ](int n);            // Dostêp niekontrolowany
    const T& operator[ ](int n) const;// Dostêp niekontrolowany

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
        cout << "Nieprawid³owy indeks: " << i << "\n";
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
    cerr << "B³¹d: " << e.what() << '\n'; 
    return 1;
}
catch (...) {
    cerr << "Ojej: nieznany wyj¹tek!\n"; 
    return 2;
}

//------------------------------------------------------------------------------
