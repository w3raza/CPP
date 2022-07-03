
//
// To jest przyk³adowy kod z podrozdzia³u 21.8 „Sortowanie i wyszukiwanie” ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

//------------------------------------------------------------------------------

struct No_case {
    bool operator()(const string& x, const string& y) const
    {
        for (int i = 0; i<x.length(); ++i) {
            if (i == y.length()) return false; // y<x
            char xx = tolower(x[i]);
            char yy = tolower(y[i]);
            if (xx<yy) return true;            // x<y
            if (yy<xx) return false;           // y<x
        }
        return true;                           // x<y (mniej znaków w x)
    }
};

//------------------------------------------------------------------------------

void sort_and_print(vector<string>& vc)
{
    sort(vc.begin(),vc.end(),No_case());

    for (vector<string>::const_iterator p = vc.begin(); p!=vc.end(); ++p)
        cout << *p << '\n';
}

//------------------------------------------------------------------------------

void f(vector<string>& vs)    // vs jest posortowany
{
    if (binary_search(vs.begin(),vs.end(),"karambola")) {
        // mamy karambolê
    }

    // ...
}

//------------------------------------------------------------------------------

struct Fruit {
    string name;
    int count;
    double unit_price;
    // ...
    Fruit(const char* n, int c = 1, double p = 0.0) : name(n), count(c), unit_price(p) {}
};

//------------------------------------------------------------------------------

struct Fruit_order {
    bool operator()(const Fruit& a, const Fruit& b) const
    {
        return a.name<b.name;
    }
};

//------------------------------------------------------------------------------

void f(vector<Fruit>& vs)    // vs jest posortowany
{
    typedef vector<Fruit>::iterator FI;
    pair<FI,FI> ff =
        equal_range(vs.begin(), vs.end(), "gruszka", Fruit_order());
    for (FI p =ff.first;  p!=ff.second; ++p) { // iteracja przez wszystkie gruszki
        // mamy gruszkê w p
    }
}

//------------------------------------------------------------------------------

int main()
{
    vector<Fruit> vs;
    f(vs);
}

//------------------------------------------------------------------------------
