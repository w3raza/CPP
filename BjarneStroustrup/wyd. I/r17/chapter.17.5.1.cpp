
//
// To jest przyk�adowy kod z podrozdzia�u 17.5.1 �Generowanie destruktor�w� ksi��ki
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
    // u�ycie zmiennej fred
}

//------------------------------------------------------------------------------

int main()
{
    some_fct();
}

//------------------------------------------------------------------------------
