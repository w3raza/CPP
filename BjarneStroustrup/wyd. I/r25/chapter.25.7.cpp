
//
// To jest przyk³adowy kod z podrozdzia³u 25.7 "Æwiczenia" ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include <iostream>

using namespace std;

//------------------------------------------------------------------------------

int main()
{
    // for int
    {
        int v = 1;

        for (int i = 0; i<sizeof(v)*8; ++i) 
        { 
            cout << v << ' '; v <<=1; 
        }
    }

    // Dla liczb typu int bez znaku.
    {
        unsigned int v = 1;

        for (int i = 0; i<sizeof(v)*8; ++i) 
        { 
            cout << v << ' '; v <<=1; 
        }
    }
}

//------------------------------------------------------------------------------
