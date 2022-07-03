
//
// To jest przyk�adowy kod z podrozdzia�u 19.5.5 �Technika RAII dla wektora� ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

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

    // ...
    void reserve(int newalloc);
};

//------------------------------------------------------------------------------

template<class T, class A> 
void vector<T,A>::reserve(int newalloc)
{
    if (newalloc<=space) return;        // Nigdy nie zmniejszaj obszaru alokacji.
    T* p = alloc.allocate(newalloc);    // Alokuje now� przestrze�.
    for (int i=0; i<sz; ++i) alloc.construct(&p[i],elem[i]); // kopiuje
    for (int i=0; i<sz; ++i) alloc.destroy(&elem[i]);        // usuwa
    alloc.deallocate(elem,space);       // Dealokuje star� przestrze�.
    elem = p;
    space = newalloc;    
}

//------------------------------------------------------------------------------

int main()
{
    vector<int> v;
    v.reserve(10);
}

//------------------------------------------------------------------------------
