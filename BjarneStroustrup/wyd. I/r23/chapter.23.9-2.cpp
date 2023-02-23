
//
// To jest przyk³adowy kod z podrozdzia³u 23.9 "Dopasowywanie przy u¿yciu wyra¿eñ regularnych" ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

struct bad_from_string : std::bad_cast
// Klasa do raportowania b³êdów zwi¹zanych z rzutowaniem ³añcuchów.
{
    const char* what() const throw() // Przes³oniêcie funkcji what() klasy bad_cast.
    {
        return "bad cast from string";
    }
};

//------------------------------------------------------------------------------

template<class T> T from_string(const string& s)
{
    istringstream is(s);
    T t;
    if (!(is >> t)) throw bad_from_string();
    return t;
}

//------------------------------------------------------------------------------

int main()
try
{
    ifstream in("table.txt");    // plik wejœciowy
    if (!in) error("Brak pliku wejœciowego.");

    string line;            // bufor wejœciowy
    int lineno = 0;

    regex header( "^[\\w ]+(	[\\w ]+)*$");
    regex row( "^[\\w ]+(	\\d+)(	\\d+)(	\\d+)$");

    if (getline(in,line)) {        // sprawdza wiersz nag³ówkowy
        boost::smatch matches;
        if (!boost::regex_search(line, matches, header)) {
            error("brak nag³ówka");
        }
    }

    // sumy kolumn:
    int boys = 0;
    int girls = 0;

    // Wartoœci bie¿¹cych wierszy:
    int curr_boy = 0;
    int curr_girl = 0;

    while (getline(in,line)) {    // Wydobywa i sprawdza dane.
        ++lineno;
        smatch matches;
        if (!regex_search(line, matches, row)) 
            error("Niepoprawny wiersz.", lineno);

        // Sprawdza wiersz:
        curr_boy = from_string<int>(matches[1]);
        curr_girl = from_string<int>(matches[2]);
        int curr_total = from_string<int>(matches[3]);
        if (curr_boy+curr_girl != curr_total) error("Nieprawid³owa suma wiersza");

        boys += curr_boy;
        girls += curr_girl;
    }

    // Sprawdza kolumny:
    if (2*curr_boy  != boys)  error("Nie zgadza siê suma ch³opców.");
    if (2*curr_girl != girls) error("Nie zgadza siê suma dziewcz¹t.");
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
