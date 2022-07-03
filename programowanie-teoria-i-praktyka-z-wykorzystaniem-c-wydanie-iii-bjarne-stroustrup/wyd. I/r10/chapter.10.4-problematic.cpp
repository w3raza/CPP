
//
// To jest przyk�adowy kod z podrozdzia�u 10.4 �Otwieranie pliku� ksi��ki 
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include <fstream>
#include <string>
#include "std_lib_facilities.h"

using namespace std;

//------------------------------------------------------------------------------

int main()
try
{
    ifstream ifs;
    const char* name = "chapter.10.4-problematic.cpp";
    // ...
    string   foo;
    ifs >> foo;                    // Nie uda si� � dla strumienia ifs nie otwarto �adnego pliku.
    // ...
    ifs.open(name,ios_base::in);   // Otwarcie do odczytu pliku o nazwie name.
    // ...
    ifs.close();                   // Zamkni�cie pliku.
    // ...
    string   bar;
    ifs >> bar;                    // Nie uda si� � plik strumienia ifs zosta� zamkni�ty.
    // ...

    ifs.open("foo", ios_base::in); // Otwarcie do zapisu.
    // Brakuje close()
    ifs.open("foo", ios_base::in); // Nie uda si� � strumie� ifs jest ju� otwarty.
    if (ifs) error("Niemo�liwe");
}
catch (exception& e) {
    cerr << "B��d: " << e.what() << '\n'; 
    return 1;
}
catch (...) {
    cerr << "Nieznany wyj�tek!\n"; 
    return 2;
}

//------------------------------------------------------------------------------
