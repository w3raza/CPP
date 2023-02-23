
//
// To jest przyk³adowy kod z podrozdzia³u 21.5.1 „Akumulacja” ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include <iostream>
#include <vector>

using namespace std;

//------------------------------------------------------------------------------

template<class In, class T> T accumulate(In first, In last, T init)
{
    while (first!=last) {
        init = init + *first;
        ++first;
    }
    return init;
}

//------------------------------------------------------------------------------

int main()
{
    int a[] = { 1, 2, 3, 4, 5 };
    cout << accumulate(a, a+sizeof(a)/sizeof(int), 0);
}

//------------------------------------------------------------------------------

void f(vector<double>& vd, int* p, int n)
{
    double sum = accumulate(vd.begin(), vd.end(), 0.0); 
    int sum2 = accumulate(p,p+n,0);
}

//------------------------------------------------------------------------------

void f(int* p, int n)
{
    int s1 = accumulate(p, p+n, 0);        // Sumuje w zmiennej typu int.        

    long sl = accumulate(p, p+n, long(0)); // Sumuje liczby typu int w zmiennej typu long.

    double s2 = accumulate(p, p+n, 0.0);   // Sumuje liczby typu int w zmiennej typu double.
}

//------------------------------------------------------------------------------

namespace oops
{
void f(vector<double>& vd, int* p, int n)
{
    double s1 = 0;
    s1 = accumulate(vd.begin(), vd.end(), s1); 

    int s2 = accumulate(vd.begin(), vd.end(), s2); // Ojej

    float s3 = 0;
    accumulate(vd.begin(), vd.end(), s3);          // Ojej
}

//------------------------------------------------------------------------------
} 
