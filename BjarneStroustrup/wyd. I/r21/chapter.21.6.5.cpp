
//
// To jest przyk�adowy kod z podrozdzia�u 21.6.5 �Zbiory� ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include <set>
#include <string>

using namespace std;

//------------------------------------------------------------------------------

struct Date {
    int y;    // rok
    int m;    // miesi�c roku
    int d;    // dzie� miesi�ca
};

//------------------------------------------------------------------------------

// Zbi�r owoc�w:
struct Fruit {
    string name;
    int count;
    double unit_price;
    Date last_sale_date;
    // ...
    Fruit(const string& n, int c = 1, double p = 0.0) : name(n), count(c), unit_price(p) {}
};

//------------------------------------------------------------------------------

struct Fruit_order {
    bool operator()(const Fruit& a, const Fruit& b) const
    {
        return a.name<b.name;
    }
};

//------------------------------------------------------------------------------

int main()
{
    set<Fruit, Fruit_order> inventory;
    
    inventory.insert(Fruit("pigwa",5));
    inventory.insert(Fruit("jab�ko", 200, 0.37));
}

//------------------------------------------------------------------------------
