
//
// To jest przyk�adowy kod z podrozdzia�u 11.3.3 �Pozycjonowanie w plikach� ksi��ki 
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

int main()
try
{
    string name = "Podrozdzia�.11.3.3.w";
    fstream fs(name.c_str());    // Otwiera w trybie do odczytu i zapisu.
    if (!fs) error("Nie mo�na otworzy� pliku ",name);

fs.seekg(5);    // Przesuwa pozycj� odczytu (g od �get� � pobierz) do 5 (sz�sty znak).
char ch;
fs>>ch;         // Odczytuje i zwi�ksza indeks pozycji odczytu.
cout << "znak [6] to " << ch << '(' << int(ch) << ")\n";

fs.seekp(1);    // Przesuwa pozycj� zapisu (p od �put� � wstawianie) do 1.
fs<<'y';        // Zapisuje i zwi�ksza numer pozycji zapisu.

}
catch (exception& e) {
    cerr << "B��d: " << e.what() << '\n'; 
    return 1;
}
catch (...) {
    cerr << "Nieznany wyj�tek.\n"; 
    return 2;
}

//------------------------------------------------------------------------------
