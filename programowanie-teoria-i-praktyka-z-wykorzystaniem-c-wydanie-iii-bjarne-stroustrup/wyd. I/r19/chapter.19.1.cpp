
//
// To jest przyk³adowy kod z podrozdzia³u 19.1 "Analiza problemów" ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

void foo()
{
    vector<double> vd;             // elementy typu double
    double d;
    while(cin>>d) vd.push_back(d); // Powiêksza vd, aby zmieœci³y siê wszystkie elementy.

    vector<char> vc(100);          // elementy typu char
    int n;
    if (cin>>n)
        vc.resize(n);              // Sprawia, ¿e vc bêdzie zawieraæ n elementów.
}

//------------------------------------------------------------------------------

void without_push_back()
{
    // Wczytuje elementy do wektora, nie u¿ywaj¹c funkcji push_back:
    vector<double>* p = new vector<double>(10);
    int n = 0;                     // liczba elementów
    double d;
    while(cin >> d) {
        if (n==p->size()) {
            vector<double>* q = new vector<double>(p->size()*2);
            copy(p->begin(), p->end(), q->begin());
            delete p;
            p = q;
        }
        (*p)[n] = d;
        ++n;
    }
}

//------------------------------------------------------------------------------

void with_push_back()
{
    vector<double> vd;
    double d;
    while(cin>>d) vd.push_back(d);
}

//------------------------------------------------------------------------------

int main()
{
    foo();
    without_push_back();
    with_push_back();
}

//------------------------------------------------------------------------------
