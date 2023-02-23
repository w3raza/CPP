
//
// To jest przyk�adowy kod z podrozdzia�u 21.4.2 �Predykaty sk�adowych klas� ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

struct Record {
    string name;        // Standardowy �a�cuch zastosowany dla u�atwienia.
    char addr[24];    // Stary styl, aby dostosowa� si� do baz danych.
    // ...
};

//------------------------------------------------------------------------------

// R�ne sposoby por�wnywania obiekt�w typu Record:

struct  Cmp_by_name {
    bool operator()(const Record& a, const Record& b) const
    { return a.name < b.name; }
};

//------------------------------------------------------------------------------

struct  Cmp_by_addr {
    bool operator()(const Record& a, const Record& b) const
    { return strncmp(a.addr, b.addr, 24) < 0; }    // !!!
};

//------------------------------------------------------------------------------

int main()
{
    vector<Record> vr;

    // ...
    sort(vr.begin(), vr.end(), Cmp_by_name());    // sortowanie wed�ug nazw
    // ...
    sort(vr.begin(), vr.end(), Cmp_by_addr());    // sortowanie wed�ug adres�w
    // ...
}

//------------------------------------------------------------------------------
