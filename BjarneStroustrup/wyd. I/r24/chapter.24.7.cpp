
//
// To jest przyk³adowy kod z podrozdzia³u 24.7 „Liczby losowe” ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"
#include "Matrix.h"

//------------------------------------------------------------------------------

using Numeric_lib::Index;

//------------------------------------------------------------------------------

typedef Numeric_lib::Matrix<double, 1> Vector;

//------------------------------------------------------------------------------

Vector random_vector(Index n)
{
    Vector v(n);

    for (Index i = 0; i < n; ++i)
        v(i) = 1.0 * n * rand() / RAND_MAX;

    return v;
}

//------------------------------------------------------------------------------

int rand_int(int max) { return rand()%max; }

//------------------------------------------------------------------------------

int rand_int(int min, int max) { return rand_int(max-min)+min; }

//------------------------------------------------------------------------------

int main()
{

}

//------------------------------------------------------------------------------
