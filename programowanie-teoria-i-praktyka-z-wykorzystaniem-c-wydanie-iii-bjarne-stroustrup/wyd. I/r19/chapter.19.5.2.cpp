
//
// To jest przyk³adowy kod z podrozdzia³u 19.5.2 „Zajmowanie zasobów jest inicjacj¹” ksi¹¿ki
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
