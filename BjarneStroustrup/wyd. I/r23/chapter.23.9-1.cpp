
//
// To jest przyk�adowy kod z podrozdzia�u 23.9 �Dopasowywanie przy u�yciu wyra�e� regularnych� ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

int main()
try
{
    ifstream in("table.txt");    // plik wej�ciowy
    if (!in) error("Brak pliku wej�ciowego.\n");

    string line;    // bufor wej�ciowy
    int lineno = 0;

    regex header( "^[\\w ]+(	[\\w ]+)*$"); // wiersz nag��wkowy
    regex row( "^[\\w ]+(	\\d+)(	\\d+)(	\\d+)$"); // wiersz danych

    if (getline(in,line)) {       // sprawdza wiersz nag��wkowy
        smatch matches;
        if (!regex_search(line, matches, header))
            error("brak nag��wka");
    }
    while (getline(in,line)) {    // sprawdza wiersz danych
        ++lineno;
        smatch matches;
        if (!regex_search(line, matches, row)) 
            error("Niepoprawny wiersz.", lineno);
    }
}
catch (std::exception& e) {
    cerr << "B��d: " << e.what() << '\n'; 
    return 1;
}
catch (...) {
    cerr << "Nieznany wyj�tek!\n"; 
    return 2;
}

//------------------------------------------------------------------------------
