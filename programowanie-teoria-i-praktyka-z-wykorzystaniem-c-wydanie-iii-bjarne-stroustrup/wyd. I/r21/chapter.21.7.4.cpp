
//
// To jest przyk�adowy kod z podrozdzia�u 21.7.4 �Funkcja copy_if� ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include <vector>

using namespace std;

//------------------------------------------------------------------------------

template<class In, class Out, class Pred>
Out copy_if(In first, In last, Out res, Pred p)
// Kopiuje elementy spe�niaj�ce warunek predykatu.
{
    while (first!=last) {
        if (p(*first)) *res++ = *first;
        ++first;
    }
    return res;
}

//------------------------------------------------------------------------------

class Larger_than {
    int v;
public:
    Larger_than(int vv) : v(vv) { }               // przechowuje argument
    bool operator()(int x) const { return x>v; }  // por�wnuje
};

//------------------------------------------------------------------------------

void f(const vector<int>& v)
// Kopiuje wszystkie elementy, kt�rych warto�� jest wi�ksza od 6.
{
    vector<int> v2(v.size());
    copy_if(v.begin(), v.end(), v2.begin(), Larger_than(6));
    // ...
}

//------------------------------------------------------------------------------

int main()
{
    vector<int> v(10);
    f(v);
}

//------------------------------------------------------------------------------
