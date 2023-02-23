
//
// To jest przyk�adowy kod z podrozdzia�u 20.4 �Listy powi�zane� ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

//------------------------------------------------------------------------------

template<class Elem> struct Link {
    Link* prev;    // poprzednie ogniwo
    Link* succ;    // nast�pne ogniwo (nast�pnik)
    Elem  val;     // warto��
};

//------------------------------------------------------------------------------

template<class Elem> struct list {
    Link<Elem>* first;
    Link<Elem>* last; // element za ostatnim ogniwem
};

//------------------------------------------------------------------------------
