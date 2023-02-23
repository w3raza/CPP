
//
// To jest przyk³adowy kod z podrozdzia³u 19.5.5 „Technika RAII dla wektora” ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

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

    // ...
    void reserve(int newalloc);
};

//------------------------------------------------------------------------------

template<class T, class A> 
void vector<T,A>::reserve(int newalloc)
{
    if (newalloc<=space) return;        // Nigdy nie zmniejszaj obszaru alokacji.
    T* p = alloc.allocate(newalloc);    // Alokuje now¹ przestrzeñ.
    for (int i=0; i<sz; ++i) alloc.construct(&p[i],elem[i]); // kopiuje
    for (int i=0; i<sz; ++i) alloc.destroy(&elem[i]);        // usuwa
    alloc.deallocate(elem,space);       // Dealokuje star¹ przestrzeñ.
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
