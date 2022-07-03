
//
// To jest przyk�adowy kod z podrozdzia�u 18.5.1 �Wska�niki na elementy tablicy" ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

int main()
{
    double ad[10];
    double* p = &ad[5];  // wskazuje na ad[5]

    *p =7;
    p[2] = 6;
    p[-3] = 9;

    p += 2;             // Przesuwa p o dwa elementy w prawo.
    p -= 5;             // Przesuwa p o 5 element�w w lewo.
    p += 1000;          // Szalony pomys�: p wskazuje element w tablicy zawieraj�cej tylko 10 element�w.
    double d = *p;      // Niedozwolone: prawdopodobnie niepoprawna warto��
                        //            (zdecydowanie nieprzewidywalna warto��).
    *p = 12.34;         // Niedozwolone: prawdopodobnie uszkodzi jakie� nieznane dane.

    for (double* p = &ad[0]; p<&ad[10]; ++p) cout << *p << '\n';

    // Albo wstecz:

    for (double* p = &ad[9]; p>=&ad[0]; --p) cout << *p << '\n';

    double* p1 = &ad[0];
    double* p2 = p1+7;
    double* p3 = &p1[7];
    if (p2 != p3) cout << "Niemo�liwe!\n";
}

//------------------------------------------------------------------------------
