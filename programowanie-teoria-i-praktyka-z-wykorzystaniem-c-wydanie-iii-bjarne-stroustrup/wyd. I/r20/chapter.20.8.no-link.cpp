
//
// To jest przyk³adowy kod z podrozdzia³u 20.8 „Dostosowanie wektora do biblioteki STL” ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

//------------------------------------------------------------------------------

template<class T> class allocator {
public:
    // ...
    T* allocate(int n);            // Alokacja przestrzeni dla n obiektów typu T.
    void deallocate(T* p, int n);  // Dealokacja n obiektów typu T, zaczynaj¹c od p.

    void construct(T* p, const T& v); // Tworzy obiekt typu T z wartoœci¹ v w p.
    void destroy(T* p);            // Usuwa ten obiekt T z p.
};

//------------------------------------------------------------------------------

template<class T, class A = allocator<T> > class vector {
    int sz;     // rozmiar
    T*  elem;   // wskaŸnik na elementy
    int space;  // liczba elementów plus liczba wolnych miejsc w pamiêci
    A   alloc;  // obs³uga pamiêci dla elementów za pomoc¹ alloc
public:
    typedef unsigned long size_type;
    typedef T             value_type;
    typedef T*            iterator;    // Elem* jest najprostszym mo¿liwym iteratorem.
    typedef const T*      const_iterator;

    iterator       begin();
    const_iterator begin() const;
    iterator       end();
    const_iterator end() const;

    size_type size();
    int capacity() const { return space; }

    // ... ca³a reszta z rozdzia³u 19 i podrozdzia³u 20.5 ...

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
        *(pos-1) = *pos; // Kopiuje element o „jedn¹ pozycjê w lewo”.
    alloc.destroy(&*p);  // Usuwa nadmiarow¹ kopiê ostatniego elementu.
    --sz;
    return p;
}

//------------------------------------------------------------------------------

template<class T, class A>
typename vector<T,A>::iterator vector<T,A>::insert(iterator p, const T& val)
{
    int index = p-begin();
    if (size()==capacity()) reserve(2*size());    // Zapewniamy miejsce.

    // Skopiowanie najpierw elementu w niezainicjowan¹ przestrzeñ:
    alloc.construct(elem+sz,*back());
    ++sz;
    iterator pp = begin()+index; // Miejsce, w którym zostanie wstawiona wartoœæ val.
    for (iterator pos = end()-1; pos!=pp; --pos)
        *pos = *(pos-1);         // Kopiuje elementy o jedno miejsce w prawo.
    *(begin()+index) = val;      // „wstawia” val
    return pp;
}

//------------------------------------------------------------------------------
