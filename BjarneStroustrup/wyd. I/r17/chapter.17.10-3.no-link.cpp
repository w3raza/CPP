
//
// To jest przyk³adowy kod z podrozdzia³u 17.10 „WskaŸnik this” ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

class Link {
public:
    string value; 

    Link(const string& v, Link* p = 0, Link* s = 0)
        : value(v), prev(p), succ(s) { }

    Link* insert(Link* n) ;   // Wstawia n przed p; zwraca n.
    Link* add(Link* n) ;      // Wstawia n przed tym obiektem; zwraca n.
    Link* erase() ;           // Usuwa ten obiekt z listy.
    Link* find(const string& s);    // Znajduje s w liœcie.
    const Link* find(const string& s) const; // Znajduje s w liœcie.

    Link* advance(int n) const;     // Przesuwa o n pozycji listy.

    Link* next() const { return succ; }
    Link* previous() const { return prev; }
private:
    Link* prev;
    Link* succ;
};

//------------------------------------------------------------------------------

Link* Link::insert(Link* n)   // Wstawia n przed p; zwraca n.; return n
{
    if (n==0) return this;
    if (this==0) return n;
    n->succ = this;           // Ten obiekt wystêpuje za n.
    if (prev) prev->succ = n;
    n->prev = prev;           // Poprzednik tego obiektu staje siê poprzednikiem n.
    prev = n;                 // n staje siê poprzednikiem tego obiektu.
    return n;
}

//------------------------------------------------------------------------------
