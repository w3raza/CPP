
//
// To jest przyk�adowy kod z podrozdzia�u 17.9.3 �Przyk�ad � listy� ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

struct Link {
    string value;
    Link* prev;
    Link* succ;
    Link(const string& v, Link* p = 0, Link* s = 0)
        : value(v), prev(p), succ(s) { }
};

//------------------------------------------------------------------------------

Link* insert(Link* p, Link* n)    // Wstawia n przed p; zwraca n.
{
    if (n==0) return p;
    if (p==0) return n;
    n->succ = p;        // p znajduje si� za n.
    if (p->prev) p->prev->succ = n;
    n->prev = p->prev;    // Poprzednik p staje si� poprzendikiem n.
    p->prev = n;        // n staje si� poprzednikiem p.
    return n;
}

//------------------------------------------------------------------------------

int main()
{
    Link* norse_gods = new Link("Thor");
    norse_gods = insert(norse_gods,new Link("Odyn"));
    norse_gods = insert(norse_gods,new Link("Freia"));
}

//------------------------------------------------------------------------------
