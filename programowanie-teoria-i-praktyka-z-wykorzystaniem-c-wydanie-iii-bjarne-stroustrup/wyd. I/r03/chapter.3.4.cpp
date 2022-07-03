
//
// To jest przyk³adowy kod z rozdzia³u 3.4 "Operacje i operatory" ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

int main()
{
    int count;
    cin >> count;                    // >> wczytuje liczbê do zmiennej count
    string name;
    cin >> name;                     // >> wczytuje ³añcuch do zmiennej name

    int c2 = count+2;                // + sumuje liczby ca³kowite
    string s2 = name + " m³odszy ";  // + do³¹cza znaki

    int c3 = count-2;                // – odejmuje liczby ca³kowite
    //string s3 = name - "m³odszy "; // b³¹d: operator – nie jest zdefiniowany dla ³añcuchów

    int age = -100;
}

//------------------------------------------------------------------------------
