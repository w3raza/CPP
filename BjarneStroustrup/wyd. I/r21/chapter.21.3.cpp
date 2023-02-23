
//
// To jest przyk�adowy kod z podrozdzia�u 21.3 �Og�lny algorytm wyszukiwania � find_if()� ksi��ki
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

bool odd(int x) { return x%2; }    // % to operator modulo.

void f(vector<int>& v)
{
    vector<int>::iterator p = find_if(v.begin(), v.end(), odd);
    if (p!=v.end()) { /* znaleziono nieparzyst� liczb� */ }
    // ...
}

//------------------------------------------------------------------------------

bool larger_than_42(int x) { return x>42; }

void f(list<double>& v)
{
    list<double>::iterator p = find_if(v.begin(), v.end(), larger_than_42);
    if (p!=v.end()) { /* znaleziono warto�� wi�ksz� od 42 */ }
    // ...
}

//------------------------------------------------------------------------------

int v;        // Warto��, z kt�r� larger_than_v() por�wnuje sw�j argument.
bool larger_than_v(int x) { return x>v; }

void f(list<double>& v, int x)
{
    ::v = 31; // Ustawia v_val na 31 dla nast�pnego wywo�ania larger_than_v.
    list<double>::iterator p = find_if(v.begin(), v.end(), larger_than_v);
    if (p!=v.end()) { /* znaleziono warto�� wi�ksz� od 31 */ }

    ::v = x;  // Ustawia v_val na x dla nast�pnego wywo�ania larger_than_v.
    list<double>::iterator q = find_if(v.begin(), v.end(), larger_than_v);
    if (q!=v.end()) { /* znaleziono warto�� wi�ksz� od x*/  }

    // ...
}

//------------------------------------------------------------------------------

int main()
{
    // Dzia�a dla wektor�w liczb typu int.
    {
        int initializer[7] = {1,2,3,4,5,6,7};
        int* first = initializer;
        int* last  = initializer+7;

        vector<int> v(first,last);
        f(v);
    }

    // Dzia�a dla list liczb typu double.
    {
        double  initializer[7] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7};
        double* first = initializer;
        double* last  = initializer+7;

        list<double> l(first,last);
        f(l);
        f(l,4);
    }
}

//------------------------------------------------------------------------------
