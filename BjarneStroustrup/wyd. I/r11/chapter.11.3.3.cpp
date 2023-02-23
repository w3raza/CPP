
//
// To jest przyk³adowy kod z podrozdzia³u 11.3.3 „Pozycjonowanie w plikach” ksi¹¿ki 
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

int main()
try
{
    string name = "Podrozdzia³.11.3.3.w";
    fstream fs(name.c_str());    // Otwiera w trybie do odczytu i zapisu.
    if (!fs) error("Nie mo¿na otworzyæ pliku ",name);

fs.seekg(5);    // Przesuwa pozycjê odczytu (g od „get” — pobierz) do 5 (szósty znak).
char ch;
fs>>ch;         // Odczytuje i zwiêksza indeks pozycji odczytu.
cout << "znak [6] to " << ch << '(' << int(ch) << ")\n";

fs.seekp(1);    // Przesuwa pozycjê zapisu (p od „put” — wstawianie) do 1.
fs<<'y';        // Zapisuje i zwiêksza numer pozycji zapisu.

}
catch (exception& e) {
    cerr << "B³¹d: " << e.what() << '\n'; 
    return 1;
}
catch (...) {
    cerr << "Nieznany wyj¹tek.\n"; 
    return 2;
}

//------------------------------------------------------------------------------
