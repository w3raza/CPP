
//
// To jest przyk³adowy kod z podrozdzia³u 20.4.1 „Operacje list” ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

//------------------------------------------------------------------------------

template<class Elem> class list {
    // Szczegó³y reprezentacyjne i implementacyjne.
public:
    class iterator;     // Typ sk³adowy: iterator

    iterator begin();   // Iterator wskazuj¹cy pierwszy element.
    iterator end( );    // Iterator wskazuj¹cy miejsce za ostatnim elementem.

    iterator  insert(iterator p, const Elem& v); // Wstawia v do listy za p.
    iterator erase(iterator p);     // Usuwa p z listy.

    void push_back(const Elem& v);  // Wstawia v na koñcu.
    void push_front(const Elem& v); // Wstawia v na pocz¹tku.
    void pop_front();   // Usuwa pierwszy element.
    void pop_back();    // Usuwa ostatni element.

    Elem& front();      // Pierwszy element.
    Elem& back();       // Ostatni element.

    // ...
};

//------------------------------------------------------------------------------
