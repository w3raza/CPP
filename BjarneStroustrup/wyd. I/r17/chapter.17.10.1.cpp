
//
// To jest przyk³adowy kod z podrozdzia³u 17.10.1 „Wiêcej przyk³adów u¿ycia typu Link" ksi¹¿ki
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

Link* Link::erase()          // Usuwa ten obiekt z listy. Zwraca nastêpnik tego obiektu.
{
    if (this==0) return 0;
    if (succ) succ->prev = prev;
    if (prev) prev->succ = succ;
    return succ;
}

//------------------------------------------------------------------------------

Link* Link::find(const string& s) // Znajduje s w liœcie.;
// zwraca 0, jeœli nie znajdzie.
{
    Link* p = this;
    while(p) {
        if (p->value == s) return p;
        p = p->succ;
    }
    return 0;
}

//------------------------------------------------------------------------------

void print_all(Link* p)
{
    cout << "{ ";
    while (p) {
        cout << p->value;
        if (p=p->next()) cout <<  ", ";
    }
    cout << " }";
}

//------------------------------------------------------------------------------

int main()
{
    Link* norse_gods = new Link("Thor");
    norse_gods = norse_gods->insert(new Link("Odyn"));
    norse_gods = norse_gods->insert(new Link("Zeus"));
    norse_gods = norse_gods->insert(new Link("Freia"));

    Link* greek_gods = new Link("Hera");
    greek_gods = greek_gods->insert(new Link("Atena")); 
    greek_gods = greek_gods->insert(new Link("Mars"));
    greek_gods = greek_gods->insert(new Link("Poseidon"));

    Link* p = greek_gods->find("Mars");
    if (p) p->value = "Ares";

    // Przenosi Zeusa do w³aœciwego panteonu.
    {
        Link* p = norse_gods->find("Zeus");
        if (p) {
            if (p==norse_gods) norse_gods = p->next();
            p->erase();
            greek_gods = greek_gods->insert(p);
        }
    }

    // Drukowanie list.

    print_all(norse_gods);
    cout<<"\n";

    print_all(greek_gods);
    cout<<"\n";
}

//------------------------------------------------------------------------------
