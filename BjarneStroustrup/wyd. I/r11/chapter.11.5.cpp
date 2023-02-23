
//
// To jest przyk³adowy kod z podrozdzia³u 11.5 „Wprowadzanie danych wierszami” ksi¹¿ki 
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

//------------------------------------------------------------------------------

using namespace std;

int main()
{
    string name;
    cin >> name;            // Wejœcie: Dennis Ritchie
    cout << name << '\n';   // Wyjœcie: Dennis

    getline(cin,name);      // Wejœcie: Dennis Ritchie
    cout << name << '\n';   // Wyjœcie: Dennis Ritchie



    string first_name;
    string second_name;
    stringstream ss(name);
    ss>>first_name;         // Wejœcie: Dennis
    ss>>second_name;        // Wejœcie: Ritchie

    {
        string command;
        getline(cin,command);   // wczytuje wiersz

        stringstream ss(command);
        vector<string> words;
        string s;
        while (ss>>s) words.push_back(s);    // wydobywa poszczególne s³owa
    }
}

//------------------------------------------------------------------------------
