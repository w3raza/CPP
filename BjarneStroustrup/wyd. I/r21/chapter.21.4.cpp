
//
// To jest przyk�adowy kod z podrozdzia�u 21.4 �Obiekty funkcyjne� ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include <list>
#include <vector>

using namespace std;

//------------------------------------------------------------------------------

template<class In, class Pred>
In find_if(In first, In last, Pred pred)
{
    while (first!=last && !pred(*first)) ++first;
    return first;
}

//------------------------------------------------------------------------------

class Larger_than {
    int v;
public:
    Larger_than(int vv) : v(vv) { }            // przechowuje argument
    bool operator()(int x) const { return x>v; }        // por�wnuje
};

//------------------------------------------------------------------------------

void f(list<double>& v, int x)
{
    list<double>::iterator p = find_if(v.begin(), v.end(), Larger_than(31));
    if (p!=v.end()) { /* znaleziono warto�� wi�ksz� od 31 */ }

    list<double>::iterator q = find_if(v.begin(), v.end(), Larger_than(x));
    if (q!=v.end()) { /* znaleziono warto�� wi�ksz� od x */ }

    // ...
}

//------------------------------------------------------------------------------

int main()
{
    double  initializer[7] = {11.1, 22.2, 33.3, 44.4, 55.5, 66.6, 77.7};
    double* first = initializer;
    double* last  = initializer+7;

    list<double> v(first,last);

    find_if(v.begin(),v.end(),Larger_than(31));
}

//------------------------------------------------------------------------------
