
//
// To jest przyk�adowy kod z podrozdzia�u 19.5.2 �Zajmowanie zasob�w jest inicjacj�� ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include <vector>

using std::vector;

//------------------------------------------------------------------------------

void f(vector<int>& v, int s)
{
    vector<int> p(s);
    vector<int> q(s);
    // ...
}

//------------------------------------------------------------------------------

int main()
{
    vector<int> v(10);
    f(v,15);
}

//------------------------------------------------------------------------------
