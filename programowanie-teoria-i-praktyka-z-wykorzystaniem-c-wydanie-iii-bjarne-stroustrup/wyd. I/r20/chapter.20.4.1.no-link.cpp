
//
// To jest przyk�adowy kod z podrozdzia�u 20.4.1 �Operacje list� ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

//------------------------------------------------------------------------------

template<class Elem> class list {
    // Szczeg�y reprezentacyjne i implementacyjne.
public:
    class iterator;     // Typ sk�adowy: iterator

    iterator begin();   // Iterator wskazuj�cy pierwszy element.
    iterator end( );    // Iterator wskazuj�cy miejsce za ostatnim elementem.

    iterator  insert(iterator p, const Elem& v); // Wstawia v do listy za p.
    iterator erase(iterator p);     // Usuwa p z listy.

    void push_back(const Elem& v);  // Wstawia v na ko�cu.
    void push_front(const Elem& v); // Wstawia v na pocz�tku.
    void pop_front();   // Usuwa pierwszy element.
    void pop_back();    // Usuwa ostatni element.

    Elem& front();      // Pierwszy element.
    Elem& back();       // Ostatni element.

    // ...
};

//------------------------------------------------------------------------------
