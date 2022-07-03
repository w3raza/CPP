
//
// To jest przyk³adowy kod z podrozdzia³u 21.3 „Ogólny algorytm wyszukiwania — find_if()” ksi¹¿ki
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
    if (p!=v.end()) { /* znaleziono nieparzyst¹ liczbê */ }
    // ...
}

//------------------------------------------------------------------------------

bool larger_than_42(int x) { return x>42; }

void f(list<double>& v)
{
    list<double>::iterator p = find_if(v.begin(), v.end(), larger_than_42);
    if (p!=v.end()) { /* znaleziono wartoœæ wiêksz¹ od 42 */ }
    // ...
}

//------------------------------------------------------------------------------

int v;        // Wartoœæ, z któr¹ larger_than_v() porównuje swój argument.
bool larger_than_v(int x) { return x>v; }

void f(list<double>& v, int x)
{
    ::v = 31; // Ustawia v_val na 31 dla nastêpnego wywo³ania larger_than_v.
    list<double>::iterator p = find_if(v.begin(), v.end(), larger_than_v);
    if (p!=v.end()) { /* znaleziono wartoœæ wiêksz¹ od 31 */ }

    ::v = x;  // Ustawia v_val na x dla nastêpnego wywo³ania larger_than_v.
    list<double>::iterator q = find_if(v.begin(), v.end(), larger_than_v);
    if (q!=v.end()) { /* znaleziono wartoœæ wiêksz¹ od x*/  }

    // ...
}

//------------------------------------------------------------------------------

int main()
{
    // Dzia³a dla wektorów liczb typu int.
    {
        int initializer[7] = {1,2,3,4,5,6,7};
        int* first = initializer;
        int* last  = initializer+7;

        vector<int> v(first,last);
        f(v);
    }

    // Dzia³a dla list liczb typu double.
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
