
//
// To jest przyk�adowy kod z podrozdzia�u 17.10 �Wska�nik this� ksi��ki
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
    Link* find(const string& s);    // Znajduje s w li�cie.
    const Link* find(const string& s) const; // Znajduje s w li�cie.

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
    Link* p = this;           // Wska�nik na ten obiekt.
    if (n==0) return p;       // Nic do wstawienia.
    if (p==0) return n;       // Nie ma gdzie wstawia� element�w.
    n->succ = p;              // p znajduje si� za n.
    if (p->prev) p->prev->succ = n;
    n->prev = p->prev;        // Poprzednik p staje si� poprzendikiem n.
    p->prev = n;              // n staje si� poprzednikiem p.
    return n;
}

//------------------------------------------------------------------------------
