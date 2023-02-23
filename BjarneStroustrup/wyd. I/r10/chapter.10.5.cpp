
//
// To jest przyk�adowy kod z podrozdzia�u 10.5 �Odczytywanie i zapisywanie plik�w� ksi��ki 
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
    cout << "Podaj nazw� pliku wej�ciowego: ";
    string name;
    cin >> name;
    ifstream ist(name.c_str());    // ist odczytuje dane z pliku o nazwie �name�.
    if (!ist) error("Nie mo�na otworzy� pliku wej�ciowego ",name);

    cout << "Podaj nazw� pliku wyj�ciowego: ";
    cin >> name;
    ofstream ost(name.c_str());    // ost zapisuje dane w pliku o nazwie �name�.
    if (!ost) error("Nie mo�na otworzy� pliku wyj�ciowego. ",name);

    vector<Reading> temps;    // Do przechowywania wynik�w pomiar�w.
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
    cerr << "B��d: " << e.what() << '\n'; 
    return 1;
}
catch (...) {
    cerr << "Nieznany wyj�tek!\n"; 
    return 2;
}

//------------------------------------------------------------------------------
