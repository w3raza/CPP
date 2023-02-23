
//
// To jest przyk�adowy kod z podrozdzia�u 17.9.4 �Operacje na listach� ksi��ki
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

Link* insert(Link* p, Link* n)    // Wstawia n za p; zwraca n.
{
    if (n==0) return p;
    if (p==0) return n;
    n->succ = p;        // p znajduje si� za n
    if (p->prev) p->prev->succ = n;
    n->prev = p->prev;    // Poprzednik p staje si� poprzednikiem n.
    p->prev = n;        // n staje si� poprzednikiem p.
    return n;
}

//------------------------------------------------------------------------------

Link* add(Link* p, Link* n)   // Wstawia n za p; zwraca n.
{
    // Kod podobny do funkcji insert (zobacz 11. zadanie pracy domowej).
    return insert(p,n);
}

//------------------------------------------------------------------------------

Link* erase(Link* p)          // Usuwa *p z listy; zwraca nast�pnik p.
{
    if (p==0) return 0;
    if (p->succ) p->succ->prev = p->prev;
    if (p->prev) p->prev->succ = p->succ;
    return p->succ;
}

//------------------------------------------------------------------------------

Link* find(Link* p, const string& s) // Znajduje s w li�cie;
                                     // zwraca 0, je�li nie znajdzie.
{
    while(p) {
        if (p->value == s) return p;
        p = p->succ;
    }
    return 0;
}

//------------------------------------------------------------------------------

Link* advance(Link* p, int n) // Przesuwa o n pozycji w li�cie,
                              // zwraca 0, je�li nie znajdzie.
                              // Dodatnia warto�� n oznacza przesuni�cie w prz�d, ujemna w ty�.
{
    if (p==0) return 0;
    if (0<n) {
        while (n--) {
            if (p->succ == 0) return 0;
            p = p->succ;
        }
    }
    if (n<0) {
        while (n++) {
            if (p->prev == 0) return 0;
            p = p->prev;
        }
    }
    return p;
}

//------------------------------------------------------------------------------

int main()
{
    Link* norse_gods = new Link("Thor");
    norse_gods = insert(norse_gods,new Link("Odyn"));
    norse_gods = insert(norse_gods,new Link("Zeus"));
    norse_gods = insert(norse_gods,new Link("Freia"));

    Link* greek_gods = new Link("Hera");
    greek_gods = insert(greek_gods,new Link("Atena")); 
    greek_gods = insert(greek_gods,new Link("Mars"));
    greek_gods = insert(greek_gods,new Link("Posejdon"));

    Link* p = find(greek_gods, "Mars");
    if (p) p->value = "Ares";

    // Analogicznie mo�na przenie�� Zeusa do odpowiedniego panteonu.
    {
        Link* p = find(norse_gods,"Zeus");
        if (p) {
            erase(p);
            insert(greek_gods,p);
        }
    }

    // Bez powy�szego b��du.
    {
        Link* p = find(norse_gods, "Zeus");
        if (p) {
            if (p==norse_gods) norse_gods = p->succ;
            erase(p);
            greek_gods = insert(greek_gods,p);
        }
    }
}

//------------------------------------------------------------------------------
