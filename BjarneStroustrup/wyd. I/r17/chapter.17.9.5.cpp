
//
// To jest przyk³adowy kod z podrozdzia³u 17.9.5 „Zastosowania list” ksi¹¿ki
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
    n->succ = p;        // p znajduje siê za n
    if (p->prev) p->prev->succ = n;
    n->prev = p->prev;    // poprzednik p staje siê poprzednikiem n
    p->prev = n;        // n staje siê poprzednikiem p
    return n;
}

//------------------------------------------------------------------------------

Link* add(Link* p, Link* n)   // Wstawia n za p; zwraca n.
{
    // Kod podobny do funkcji insert (zobacz 11. zadanie pracy domowej).
    return insert(p,n);
}

//------------------------------------------------------------------------------

Link* erase(Link* p)          // Usuwa *p z listy; zwraca nastêpnik p.
{
    if (p==0) return 0;
    if (p->succ) p->succ->prev = p->prev;
    if (p->prev) p->prev->succ = p->succ;
    return p->succ;
}

//------------------------------------------------------------------------------

Link* find(Link* p, const string& s) // Znajduje s w liœcie;
// zwraca 0, jeœli nie znajdzie.
{
    while(p) {
        if (p->value == s) return p;
        p = p->succ;
    }
    return 0;
}

//------------------------------------------------------------------------------

Link* advance(Link* p, int n) // Przesuwa o n pozycji w liœcie,
// zwraca 0, jeœli nie znajdzie.
// Dodatnia wartoœæ n oznacza przesuniêcie w przód, ujemna w ty³.
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

void print_all(Link* p)
{
    cout << "{ ";
    while (p) {
        cout << p->value;
        if (p=p->succ) cout <<  ", ";
    }
    cout << " }";
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

    // Analogicznie mo¿na przenieœæ Zeusa do odpowiedniego panteonu.
    {
        Link* p = find(norse_gods,"Zeus");
        if (p) {
            erase(p);
            insert(greek_gods,p);
        }
    }

    // Bez powy¿szego b³êdu.
    {
        Link* p = find(norse_gods, "Zeus");
        if (p) {
            if (p==norse_gods) norse_gods = p->succ;
            erase(p);
            greek_gods = insert(greek_gods,p);
        }
    }

    print_all(norse_gods);
    cout<<"\n";

    print_all(greek_gods);
    cout<<"\n";
}

//------------------------------------------------------------------------------
