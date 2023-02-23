
//
// To jest przyk�adowy kod z podrozdzia�u 19.1 "Analiza problem�w" ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

void foo()
{
    vector<double> vd;             // elementy typu double
    double d;
    while(cin>>d) vd.push_back(d); // Powi�ksza vd, aby zmie�ci�y si� wszystkie elementy.

    vector<char> vc(100);          // elementy typu char
    int n;
    if (cin>>n)
        vc.resize(n);              // Sprawia, �e vc b�dzie zawiera� n element�w.
}

//------------------------------------------------------------------------------

void without_push_back()
{
    // Wczytuje elementy do wektora, nie u�ywaj�c funkcji push_back:
    vector<double>* p = new vector<double>(10);
    int n = 0;                     // liczba element�w
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
