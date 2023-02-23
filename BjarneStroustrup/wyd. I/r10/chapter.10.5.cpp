
//
// To jest przyk³adowy kod z podrozdzia³u 10.5 „Odczytywanie i zapisywanie plików” ksi¹¿ki 
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include <iostream>
#include <fstream>
#include <string>
#include "std_lib_facilities.h"

using namespace std;

//------------------------------------------------------------------------------

struct Reading {           // Wynik pomiaru temperatury.
    int hour;              // Godzina [0:23].
    double temperature;    // W skali Fahrenheita.
    Reading(int h, double t) :hour(h), temperature(t) { }
};

//------------------------------------------------------------------------------

int main()
try
{
    cout << "Podaj nazwê pliku wejœciowego: ";
    string name;
    cin >> name;
    ifstream ist(name.c_str());    // ist odczytuje dane z pliku o nazwie „name”.
    if (!ist) error("Nie mo¿na otworzyæ pliku wejœciowego ",name);

    cout << "Podaj nazwê pliku wyjœciowego: ";
    cin >> name;
    ofstream ost(name.c_str());    // ost zapisuje dane w pliku o nazwie „name”.
    if (!ost) error("Nie mo¿na otworzyæ pliku wyjœciowego. ",name);

    vector<Reading> temps;    // Do przechowywania wyników pomiarów.
    int hour;
    double temperature;
    while (ist >> hour >> temperature) {
        if (hour < 0 || 23 <hour) error("Niepoprawna godzina.");
        temps.push_back(Reading(hour,temperature));
    }

    for (int i=0; i<temps.size(); ++i)
        ost << '(' << temps[i].hour << ','
            << temps[i].temperature << ")\n";
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
