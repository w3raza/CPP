
//
// To jest przyk³adowy kod z podrozdzia³u 21.4.2 „Predykaty sk³adowych klas” ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

struct Record {
    string name;        // Standardowy ³añcuch zastosowany dla u³atwienia.
    char addr[24];    // Stary styl, aby dostosowaæ siê do baz danych.
    // ...
};

//------------------------------------------------------------------------------

// Ró¿ne sposoby porównywania obiektów typu Record:

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
    sort(vr.begin(), vr.end(), Cmp_by_name());    // sortowanie wed³ug nazw
    // ...
    sort(vr.begin(), vr.end(), Cmp_by_addr());    // sortowanie wed³ug adresów
    // ...
}

//------------------------------------------------------------------------------
