
//
// To jest przyk³adowy kod z podrozdzia³u 17.5.1 „Generowanie destruktorów” ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

struct Customer {
    string name;
    vector<string> addresses;
    // ...
};

//------------------------------------------------------------------------------

void some_fct()
{
    Customer fred;
    // inicjacja zmiennej fred
    // u¿ycie zmiennej fred
}

//------------------------------------------------------------------------------

int main()
{
    some_fct();
}

//------------------------------------------------------------------------------
