
//
// To jest przyk�adowy kod z podrozdzia�u 8.7.1 �Dyrektywy i deklaracje using� ksi��ki 
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include<string>        // Do��cza bibliotek� string.
#include<iostream>      // Do��cza bibliotek� iostream.

//------------------------------------------------------------------------------

int main()
{
    std::string name;
    std::cout << "Podaj imi�.\n";
    std::cin >> name;
    std::cout << "Witaj, " << name << '\n';
}

//------------------------------------------------------------------------------
