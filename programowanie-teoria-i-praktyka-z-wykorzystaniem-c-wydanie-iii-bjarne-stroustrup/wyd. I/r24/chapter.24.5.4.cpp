
//
// To jest przyk�adowy kod z podrozdzia�u 24.5.4 �Wej�cie i wyj�cie macierzy� ksi��ki
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
