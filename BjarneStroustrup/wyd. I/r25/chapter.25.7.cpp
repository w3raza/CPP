
//
// To jest przyk�adowy kod z podrozdzia�u 25.7 "�wiczenia" ksi��ki
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
