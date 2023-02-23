
//
// To jest przyk³adowy kod z podrozdzia³u 20.4 „Listy powi¹zane” ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

//------------------------------------------------------------------------------

template<class Elem> struct Link {
    Link* prev;    // poprzednie ogniwo
    Link* succ;    // nastêpne ogniwo (nastêpnik)
    Elem  val;     // wartoœæ
};

//------------------------------------------------------------------------------

template<class Elem> struct list {
    Link<Elem>* first;
    Link<Elem>* last; // element za ostatnim ogniwem
};

//------------------------------------------------------------------------------
