
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

Link* insert(Link* p, Link* n)    // Wstawia n przed p (niekompletne).
{
    n->succ = p;        // p znajduje si� za n.
    p->prev->succ = n;  // n znajduje si� za tym, co by�o poprzednikiem p.
    n->prev = p->prev;  // Poprzednik p staje si� poprzendikiem n.
    p->prev = n;        // n staje si� poprzednikiem p.
    return n;
}

//------------------------------------------------------------------------------

int main()
{
    Link* norse_gods = new Link("Thor",0,0);
    norse_gods = new Link("Odyn",norse_gods,0);
    norse_gods->succ->prev = norse_gods; 
    norse_gods = new Link("Freia",norse_gods,0);
    norse_gods->succ->prev = norse_gods;
}

//------------------------------------------------------------------------------
