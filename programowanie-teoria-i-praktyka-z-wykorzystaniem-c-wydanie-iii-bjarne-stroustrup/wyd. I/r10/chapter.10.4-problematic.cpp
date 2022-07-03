
//
// To jest przyk³adowy kod z podrozdzia³u 10.4 „Otwieranie pliku” ksi¹¿ki 
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
    ifs >> foo;                    // Nie uda siê — dla strumienia ifs nie otwarto ¿adnego pliku.
    // ...
    ifs.open(name,ios_base::in);   // Otwarcie do odczytu pliku o nazwie name.
    // ...
    ifs.close();                   // Zamkniêcie pliku.
    // ...
    string   bar;
    ifs >> bar;                    // Nie uda siê — plik strumienia ifs zosta³ zamkniêty.
    // ...

    ifs.open("foo", ios_base::in); // Otwarcie do zapisu.
    // Brakuje close()
    ifs.open("foo", ios_base::in); // Nie uda siê — strumieñ ifs jest ju¿ otwarty.
    if (ifs) error("Niemo¿liwe");
}
catch (exception& e) {
    cerr << "B³¹d: " << e.what() << '\n'; 
    return 1;
}
catch (...) {
    cerr << "Nieznany wyj¹tek!\n"; 
    return 2;
}

//------------------------------------------------------------------------------
