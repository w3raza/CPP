
//
// To jest przyk³adowy kod z podrozdzia³u 24.5.4 „Wejœcie i wyjœcie macierzy” ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include <iostream>
#include "MatrixIO.h"

using namespace std;
using namespace Numeric_lib;

//------------------------------------------------------------------------------

int main()
{
    Matrix<double> a(4);
    cin >> a;
    cout << a;

    Matrix<int,2> m(2,2);
    cin >> m;
    cout << m;
}

//------------------------------------------------------------------------------
