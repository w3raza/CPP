
//
// To jest przyk�adowy kod z podrozdzia�u 19.3.6 �Uog�lnianie wektora� ksi��ki
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
    A alloc;    // Alokuje przestrze� dla element�w.
    int sz;     // rozmiar
    T* elem;    // wska�nik na elementy
    int space;  // size+free_space
public:
    vector() : sz(0), elem(0), space(0) { }    
    vector(int s);
    vector(const vector&);            // konstruktor kopiuj�cy
    vector& operator=(const vector&); // przypisanie kopiuj�ce
    ~vector() { delete[ ] elem; }     // destruktor

    void resize(int newsize, T def = T()); // wzrost
    void push_back(const T& d);
    void reserve(int newalloc);
};

//------------------------------------------------------------------------------

template<class T, class A> 
void vector<T,A>::reserve(int newalloc)
{
    if (newalloc<=space) return;     // Nigdy nie zmniejszaj obszaru alokacji.
    T* p = alloc.allocate(newalloc); // Alokuje now� przestrze�.
    for (int i=0; i<sz; ++i) alloc.construct(&p[i],elem[i]); // kopiuje
    for (int i=0; i<sz; ++i) alloc.destroy(&elem[i]);        // usuwa
    alloc.deallocate(elem,space);    // Dealokuje star� przestrze�.
    elem = p;
    space = newalloc;    
}

//------------------------------------------------------------------------------

template<class T, class A>
void vector<T,A>::push_back(const T& val)
{
    // Rezerwuje wi�cej przestrzeni.
    if (space==0)
        reserve(8);
    else 
    if (space==sz)
        reserve(2*space);

    alloc.construct(&elem[sz],val);  // dodaje val na ko�cu
    ++sz;                            // zwi�ksza rozmiar
}

//------------------------------------------------------------------------------

template<class T, class A>
void vector<T,A>::resize(int newsize, T val)
{
    reserve(newsize);
    for (int i=sz; i<newsize; ++i) alloc.construct(&elem[i],val); // tworzenie
    for (int i = newsize; i<sz; ++i) alloc.destroy(&elem[i]); // usuwa
    sz = newsize;        
}

//------------------------------------------------------------------------------

struct No_default {
    No_default(int);               // Jedyny konstruktor struktury No_default.
    // ...
};

//------------------------------------------------------------------------------

int main(int argc, char* argv[])
{
    vector<double> v1;
    v1.resize(100);                // Dodaje 100 kopii double(), tzn. 0.0.
    v1.resize(200, 0.0);           // Dodaje 100 kopii 0.0 � wpisanie 0.0 by�o zb�dne.
    v1.resize(300, 1.0);           // Dodaje 100 kopii 1.0.

    //vector<No_default> v2(10);   // B��d: pr�ba utworzenia 10 obiekt�w No_default().

    vector<No_default> v3;
    v3.resize(100, No_default(2)); // Dodaje 100 kopii No_default(2).
    //v3.resize(200);              // B��d: pr�ba utworzenia 100 obiekt�w No_default().
}

//------------------------------------------------------------------------------
