
//
// To jest przyk�adowy kod z podrozdzia�u 20.4.2 �Iteracja� ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include <iostream>

using namespace std;

//------------------------------------------------------------------------------

template<class Elem> struct Link {
    Link* prev;    // poprzednie ogniwo
    Link* succ;    // nast�pne ogniwo (nast�pnik)
    Elem  val;     // warto��
    Link(const Elem& v = Elem(), Link* p = 0, Link* s = 0) : val(v), prev(p), succ(s) {}
};

//------------------------------------------------------------------------------

template<class Elem> class list {
    // Szczeg�y reprezentacyjne i implementacyjne.
public:
    class iterator;     // Typ sk�adowy: iterator

    list() : first(new Link<Elem>()), last(first) {}

    iterator begin();   // Iterator wskazuj�cy pierwszy element.
    iterator end();     // Iterator wskazuj�cy miejsce za ostatnim elementem.

    iterator insert(iterator p, const Elem& v); // Wstawia v do listy za p.
    iterator erase(iterator p);                 // Usuwa p z listy.

    void push_back(const Elem& v);  // Wstawia v na ko�cu.
    void push_front(const Elem& v); // Wstawia v na pocz�tku.
    void pop_front();   // Usuwa pierwszy element.
    void pop_back();    // Usuwa ostatni element.

    Elem& front();      // Pierwszy element.
    Elem& back();       // Ostatni element.

    Link<Elem>* first;
    Link<Elem>* last;   // element za ostatnim ogniwem
};

//------------------------------------------------------------------------------

template<class Elem> class list<Elem>::iterator {
    Link<Elem>* curr;   // bie��ce ogniwo
public:
    iterator(Link<Elem>* p) :curr(p) { }
    iterator& operator++() {curr = curr->succ; return *this; }  // do przodu
    iterator& operator--() {curr = curr->prev; return *this; } // wstecz
    Elem& operator*() { return curr->val; } // pobiera warto�� (dereferencja)

    friend bool operator==(const iterator& a, const iterator& b)
    {
        return a.curr==b.curr;
    }

    friend bool operator!=(const iterator& a, const iterator& b)
    {
        return a.curr!=b.curr;
    }
};

//------------------------------------------------------------------------------

template<class Elem> 
typename list<Elem>::iterator list<Elem>::begin()  // Iterator wskazuj�cy pierwszy element.
{ 
    return iterator(first); 
}

//------------------------------------------------------------------------------

template<class Elem> 
typename list<Elem>::iterator list<Elem>::end() // Iterator wskazuj�cy miejsce za ostatnim elementem.
{ 
    return iterator(last); 
}

//------------------------------------------------------------------------------

template<class Elem> 
void list<Elem>::push_front(const Elem& v) // Wstawia v na pocz�tku.
{
    first = new Link<Elem>(v,0,first);
}

//------------------------------------------------------------------------------

template<class Iterator >
Iterator high(Iterator first, Iterator last)
// Zwraca iterator wskazuj�cy najwi�kszy element w przedziale <first,last).
{
    Iterator high = first;
    for (Iterator p = first; p!=last; ++p)
        if (*high<*p) high = p;
    return high;
}

//------------------------------------------------------------------------------

void f()
{
    list<int> lst;
    int x;
    while (cin >> x) lst.push_front(x);

    list<int>::iterator q = high(lst.begin(), lst.end());
    cout << "Najwi�ksza warto�� to " << *q << endl;

    list<int>::iterator p = high(lst.begin(), lst.end());
    if (p==lst.end())    // did we reach the end?
        cout << "Lista jest pusta.";
    else
        cout << "Najwi�ksza warto�� to " << *p << endl;
}

//------------------------------------------------------------------------------

int main()
{
    f();
}

//------------------------------------------------------------------------------
