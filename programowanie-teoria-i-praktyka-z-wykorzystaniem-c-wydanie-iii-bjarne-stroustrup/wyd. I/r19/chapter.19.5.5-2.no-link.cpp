
//
// To jest przyk³adowy kod z podrozdzia³u 19.5.5 „Technika RAII dla wektora” ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

//------------------------------------------------------------------------------

template<class T> class allocator {
public:
    // ...
    T* allocate(int n);                 // Alokuje przestrzeñ dla n obiektów typu T.
    void deallocate(T* p, int n);       // Dealokuje n obiektów typu T, zaczynaj¹c od p.

    void construct(T* p, const T& v);   // Konstruuje T z wartoœci¹ v w p.
    void destroy(T* p);                 // Usuwa T z p.
};

//------------------------------------------------------------------------------

template<class T, class A>
struct vector_base {
    A alloc;                            // alokator
    T* elem;                            // pocz¹tek alokacji
    int sz;                             // liczba elementów
    int space;                          // iloœæ alokowanej pamiêci

    vector_base(const A& a, int n)
        : alloc(a), elem(a.allocate(n)), sz(n), space(n) { }
    ~vector_base() { alloc.deallocate(elem,space); }
};

//------------------------------------------------------------------------------

template<class T, class A>
void swap(vector_base<T,A>& a, vector_base<T,A>& b);

//------------------------------------------------------------------------------

template<class T, class A = allocator<T> >
class vector : private vector_base<T,A> {
public:
    // ...
    void reserve(int newalloc);
};

//------------------------------------------------------------------------------

template<class T, class A>
void vector<T,A>::reserve(int newalloc)
{
    if (newalloc<=this->space) return;  // Nigdy nie zmniejszaj obszaru alokacji.
    vector_base<T,A> b(this->alloc,newalloc); // Alokuje now¹ przestrzeñ.
    for (int i=0; i<this->sz; ++i) this->alloc.construct(&b.elem[i],this->elem[i]); // kopiuje
    for (int i=0; i<this->sz; ++i) this->alloc.destroy(&this->elem[i]); // usuwa stary 
    swap< vector_base<T,A> >(*this,b);  // Zamienia reprezentacje.
}

//------------------------------------------------------------------------------
