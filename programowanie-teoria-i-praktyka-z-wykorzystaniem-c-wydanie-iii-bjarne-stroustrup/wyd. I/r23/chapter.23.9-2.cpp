
//
// To jest przyk�adowy kod z podrozdzia�u 23.9 "Dopasowywanie przy u�yciu wyra�e� regularnych" ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

struct bad_from_string : std::bad_cast
// Klasa do raportowania b��d�w zwi�zanych z rzutowaniem �a�cuch�w.
{
    const char* what() const throw() // Przes�oni�cie funkcji what() klasy bad_cast.
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
    ifstream in("table.txt");    // plik wej�ciowy
    if (!in) error("Brak pliku wej�ciowego.");

    string line;            // bufor wej�ciowy
    int lineno = 0;

    regex header( "^[\\w ]+(	[\\w ]+)*$");
    regex row( "^[\\w ]+(	\\d+)(	\\d+)(	\\d+)$");

    if (getline(in,line)) {        // sprawdza wiersz nag��wkowy
        boost::smatch matches;
        if (!boost::regex_search(line, matches, header)) {
            error("brak nag��wka");
        }
    }

    // sumy kolumn:
    int boys = 0;
    int girls = 0;

    // Warto�ci bie��cych wierszy:
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
        if (curr_boy+curr_girl != curr_total) error("Nieprawid�owa suma wiersza");

        boys += curr_boy;
        girls += curr_girl;
    }

    // Sprawdza kolumny:
    if (2*curr_boy  != boys)  error("Nie zgadza si� suma ch�opc�w.");
    if (2*curr_girl != girls) error("Nie zgadza si� suma dziewcz�t.");
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
