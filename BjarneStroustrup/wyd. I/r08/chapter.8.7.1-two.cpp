
//
// To jest przyk�adowy kod z podrozdzia�u 8.7.1 "Dyrektywy i deklaracje using� ksi��ki 
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include<string>        // Do��cza bibliotek� string.
#include<iostream>      // Do��cza bibliotek� iostream.

//------------------------------------------------------------------------------

using namespace std;    // Udost�pnia bezpo�rednio nazwy z biblioteki std.

int main()
{
    string name;
    cout << "Podaj imi�.\n";
    cin >> name;
    cout << "Witaj, " << name << '\n';
}

//------------------------------------------------------------------------------
