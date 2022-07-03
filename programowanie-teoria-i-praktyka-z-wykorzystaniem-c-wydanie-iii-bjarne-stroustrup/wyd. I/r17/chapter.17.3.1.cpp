
//
// To jest przyk³adowy kod z podrozdzia³u 17.3.1 "Operator sizeof" ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

int main()
{
    cout << "Rozmiar typu char: " << sizeof(char) << ' ' << sizeof ('a') << '\n';
    cout << "Rozmiar typu int: "  << sizeof(int)  << ' ' << sizeof (2+2) << '\n';
    int* p = 0;
    cout << "Rozmiar typu int: "  << sizeof(int*) << ' ' << sizeof (p) << '\n';

    vector<int> v(1000);
    cout << "Rozmiar wektora vector<int>(1000) wynosi "
         << sizeof(vector<int>) << ' ' << sizeof (v) << '\n';
}

//------------------------------------------------------------------------------
