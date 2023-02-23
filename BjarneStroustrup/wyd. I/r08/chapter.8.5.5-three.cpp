
//
// To jest przyk�adowy kod z podrozdzia�u 8.5.5 �Przekazywanie przez referencj� ksi��ki 
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

void swap(double& d1, double& d2)
{
    double temp = d1; // Kopiuje warto�� d1 do temp.
    d1 = d2;          // Kopiuje warto�� d2 do d1.
    d2 = temp;        // Kopiuje star� warto�� d1 do d2.
}

//------------------------------------------------------------------------------

int main()
{
    double x = 1;
    double y = 2; 
    cout << "x == " << x << " y== " << y << '\n';    // Drukuje: x==1 y==2.
    swap(x,y);
    cout << "x == " << x << " y== " << y << '\n';    // Drukuje: x==2 y==1.
}

//------------------------------------------------------------------------------
