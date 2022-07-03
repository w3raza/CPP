
//
// To jest przyk³adowy kod z podrozdzia³u 17.9.3 „Przyk³ad — listy” ksi¹¿ki
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
    n->succ = p;        // p znajduje siê za n.
    p->prev->succ = n;  // n znajduje siê za tym, co by³o poprzednikiem p.
    n->prev = p->prev;  // Poprzednik p staje siê poprzendikiem n.
    p->prev = n;        // n staje siê poprzednikiem p.
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
