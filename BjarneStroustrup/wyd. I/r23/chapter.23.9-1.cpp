
//
// To jest przyk³adowy kod z podrozdzia³u 23.9 „Dopasowywanie przy u¿yciu wyra¿eñ regularnych” ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

int main()
try
{
    ifstream in("table.txt");    // plik wejœciowy
    if (!in) error("Brak pliku wejœciowego.\n");

    string line;    // bufor wejœciowy
    int lineno = 0;

    regex header( "^[\\w ]+(	[\\w ]+)*$"); // wiersz nag³ówkowy
    regex row( "^[\\w ]+(	\\d+)(	\\d+)(	\\d+)$"); // wiersz danych

    if (getline(in,line)) {       // sprawdza wiersz nag³ówkowy
        smatch matches;
        if (!regex_search(line, matches, header))
            error("brak nag³ówka");
    }
    while (getline(in,line)) {    // sprawdza wiersz danych
        ++lineno;
        smatch matches;
        if (!regex_search(line, matches, row)) 
            error("Niepoprawny wiersz.", lineno);
    }
}
catch (std::exception& e) {
    cerr << "B³¹d: " << e.what() << '\n'; 
    return 1;
}
catch (...) {
    cerr << "Nieznany wyj¹tek!\n"; 
    return 2;
}

//------------------------------------------------------------------------------
