
//
// To jest przyk�adowy kod z podrozdzia�u 20.8 �Dostosowanie wektora do biblioteki STL� ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

//------------------------------------------------------------------------------

template<class T> class allocator {
public:
    // ...
    T* allocate(int n);            // Alokacja przestrzeni dla n obiekt�w typu T.
    void deallocate(T* p, int n);  // Dealokacja n obiekt�w typu T, zaczynaj�c od p.

    void construct(T* p, const T& v); // Tworzy obiekt typu T z warto�ci� v w p.
    void destroy(T* p);            // Usuwa ten obiekt T z p.
};

//------------------------------------------------------------------------------

template<class T, class A = allocator<T> > class vector {
    int sz;     // rozmiar
    T*  elem;   // wska�nik na elementy
    int space;  // liczba element�w plus liczba wolnych miejsc w pami�ci
    A   alloc;  // obs�uga pami�ci dla element�w za pomoc� alloc
public:
    typedef unsigned long size_type;
    typedef T             value_type;
    typedef T*            iterator;    // Elem* jest najprostszym mo�liwym iteratorem.
    typedef const T*      const_iterator;

    iterator       begin();
    const_iterator begin() const;
    iterator       end();
    const_iterator end() const;

    size_type size();
    int capacity() const { return space; }

    // ... ca�a reszta z rozdzia�u 19 i podrozdzia�u 20.5 ...

    T&       back();
    iterator insert(iterator p, const T& val);
    iterator erase(iterator p);    
};

//------------------------------------------------------------------------------

template<class T, class A> 
typename vector<T,A>::iterator vector<T,A>::erase(iterator p)
{
    if (p==end()) return p;
    for (iterator pos = p+1; pos!=end(); ++pos)
        *(pos-1) = *pos; // Kopiuje element o �jedn� pozycj� w lewo�.
    alloc.destroy(&*p);  // Usuwa nadmiarow� kopi� ostatniego elementu.
    --sz;
    return p;
}

//------------------------------------------------------------------------------

template<class T, class A>
typename vector<T,A>::iterator vector<T,A>::insert(iterator p, const T& val)
{
    int index = p-begin();
    if (size()==capacity()) reserve(2*size());    // Zapewniamy miejsce.

    // Skopiowanie najpierw elementu w niezainicjowan� przestrze�:
    alloc.construct(elem+sz,*back());
    ++sz;
    iterator pp = begin()+index; // Miejsce, w kt�rym zostanie wstawiona warto�� val.
    for (iterator pos = end()-1; pos!=pp; --pos)
        *pos = *(pos-1);         // Kopiuje elementy o jedno miejsce w prawo.
    *(begin()+index) = val;      // �wstawia� val
    return pp;
}

//------------------------------------------------------------------------------
