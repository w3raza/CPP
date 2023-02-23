
//
// To jest przyk³adowy kod z podrozdzia³u 21.2 „Najprostszy algorytm — find()” ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include <vector>

using namespace std;

//------------------------------------------------------------------------------

template<class In, class T>
In find(In first, In last, const T& val) 
// Znajduje w <first,last) pierwszy element, który jest równy val.
{
    for (In p = first; p!=last; ++p)
        if (*p == val) return p;
    return last;
}

//------------------------------------------------------------------------------

void f(vector<int>& v, int x)
{
    vector<int>::iterator p = find(v.begin(),v.end(),x);
    if (p!=v.end()) {
        // Znaleziono x w v.
    }
    else {
        // Nie znaleziono x w v.
    }
    // ...
}

//------------------------------------------------------------------------------

int main()
{
    int initializer[7] = {1,2,3,4,5,6,7};
    int* first = initializer;
    int* last  = initializer+7;

    vector<int> v(first,last);
    f(v,4);
}

//------------------------------------------------------------------------------
