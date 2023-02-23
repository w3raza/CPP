
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

Link* Link::insert(Link* n)   // Wstawia n przed p; zwraca n.
{
    Link* p = this;           // WskaŸnik na ten obiekt.
    if (n==0) return p;       // Nic do wstawienia.
    if (p==0) return n;       // Nie ma gdzie wstawiaæ elementów.
    n->succ = p;              // p znajduje siê za n.
    if (p->prev) p->prev->succ = n;
    n->prev = p->prev;        // Poprzednik p staje siê poprzendikiem n.
    p->prev = n;              // n staje siê poprzednikiem p.
    return n;
}

//------------------------------------------------------------------------------
