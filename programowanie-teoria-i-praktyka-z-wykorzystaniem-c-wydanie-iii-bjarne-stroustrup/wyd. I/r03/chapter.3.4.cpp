
//
// To jest przyk�adowy kod z rozdzia�u 3.4 "Operacje i operatory" ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

int main()
{
    int count;
    cin >> count;                    // >> wczytuje liczb� do zmiennej count
    string name;
    cin >> name;                     // >> wczytuje �a�cuch do zmiennej name

    int c2 = count+2;                // + sumuje liczby ca�kowite
    string s2 = name + " m�odszy ";  // + do��cza znaki

    int c3 = count-2;                // � odejmuje liczby ca�kowite
    //string s3 = name - "m�odszy "; // b��d: operator � nie jest zdefiniowany dla �a�cuch�w

    int age = -100;
}

//------------------------------------------------------------------------------
