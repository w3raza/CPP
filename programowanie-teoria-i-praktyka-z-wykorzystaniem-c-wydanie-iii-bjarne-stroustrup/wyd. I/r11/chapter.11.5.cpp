
//
// To jest przyk�adowy kod z podrozdzia�u 11.5 �Wprowadzanie danych wierszami� ksi��ki 
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
    cin >> name;            // Wej�cie: Dennis Ritchie
    cout << name << '\n';   // Wyj�cie: Dennis

    getline(cin,name);      // Wej�cie: Dennis Ritchie
    cout << name << '\n';   // Wyj�cie: Dennis Ritchie



    string first_name;
    string second_name;
    stringstream ss(name);
    ss>>first_name;         // Wej�cie: Dennis
    ss>>second_name;        // Wej�cie: Ritchie

    {
        string command;
        getline(cin,command);   // wczytuje wiersz

        stringstream ss(command);
        vector<string> words;
        string s;
        while (ss>>s) words.push_back(s);    // wydobywa poszczeg�lne s�owa
    }
}

//------------------------------------------------------------------------------
