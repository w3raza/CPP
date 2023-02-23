
//
// To jest przyk³adowy kod z podrozdzia³u 8.7.1 "Dyrektywy i deklaracje using” ksi¹¿ki 
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include<string>        // Do³¹cza bibliotekê string.
#include<iostream>      // Do³¹cza bibliotekê iostream.

//------------------------------------------------------------------------------

using namespace std;    // Udostêpnia bezpoœrednio nazwy z biblioteki std.

int main()
{
    string name;
    cout << "Podaj imiê.\n";
    cin >> name;
    cout << "Witaj, " << name << '\n';
}

//------------------------------------------------------------------------------
