
//
// To jest przyk�adowy kod z podrozdzia�u 21.6.2 �Opis og�lny kontenera map� ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include <functional>
#include <string>

using std::string;
using std::less;

//------------------------------------------------------------------------------

template<class T1, class T2> struct pair {
    typedef T1 first_type;
    typedef T2 second_type;

    T1 first;
    T2 second;

    pair() :first(T1()), second(T2()) { }
    pair(const T1& x, const T2& y) :first(x), second(y) { }
    template<class U, class V>
    pair(const pair<U,V>& p) :first(p.first), second(p.second) { }
};

//------------------------------------------------------------------------------

template<class T1, class T2>
pair<T1,T2> make_pair(T1 x, T2 y)
{
    return pair<T1,T2>(x,y);
}

//------------------------------------------------------------------------------

template<class Key, class Value, class Cmp = less<Key> > class map {
private:
    class tree_node;
    typedef       tree_node* sometype1;
    typedef const tree_node* sometype2;
public:
    // ...
    typedef pair<Key,Value> value_type;    // S�ownik przechowuje pary (klucz,warto��).

    typedef sometype1 iterator;            // Prawdopodobnie wska�nik na w�ze� drzewa.
    typedef sometype2 const_iterator;

    iterator begin();                      // Wskazuje pierwszy element.
    iterator end();                        // Wskazuje miejsce za ostatnim elementem.

    Value& operator[ ](const Key& k);      // Indeksuje warto�ci� k.

    iterator find(const Key& k);           // Sprawdza czy jest co� dla k.

    void erase(iterator p);                // Usuwa element wskazywany przez p.
    pair<iterator, bool> insert(const value_type&); // Wstawia par� (klucz,warto��).
    // ...
};

//------------------------------------------------------------------------------

struct No_case {/*...*/};

int main()
{
    map<string, double, No_case> m;
}

//------------------------------------------------------------------------------

