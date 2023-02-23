
//
// To jest przyk³adowy kod z podrozdzia³u 26.6 „Wydajnoœæ” ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include <vector>

using namespace std;

//------------------------------------------------------------------------------

template <class T, int N>
class Matrix 
{
public:
    int dim1() const { return N; }
    T operator()(int n1, int n2) const { return T(); } // To nie jest rzeczywista implementacja.
};

//------------------------------------------------------------------------------

double row_sum(Matrix<double,2> m, int n)    // Suma elementów w wierszu m[n].
{
    double s = 0;
    for (int i=0; i<n; ++i) s+=m(n,i);
    return s;
}

//------------------------------------------------------------------------------

double row_accum(Matrix<double,2> m, int n)  // Suma elementów w m<0,n).
{
    double s = 0;
    for (int i=0; i<n; ++i) s+=row_sum(m,i);
    return s;
}

//------------------------------------------------------------------------------

int main()
{
    Matrix<double,2> m;
    // Oblicza sumê sum wierszy macierzy m:
    vector<double> v;
    for (int i = 0; i<m.dim1(); ++i) v.push_back(row_accum(m,i+1));

    const char* s = "Hello";
    for (int i=0; i<strlen(s); ++i) { /* jakieœ dzia³ania przy u¿yciu s[i] */ }
}

//------------------------------------------------------------------------------
