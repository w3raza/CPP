
//
// To jest przyk�adowy kod z podrozdzia�u 10.7 �Wczytywanie pojedynczej warto�ci� ksi��ki 
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include <iostream>

using namespace std;

//------------------------------------------------------------------------------

int main()
{
    cout << "Podaj liczb� ca�kowit� z zakresu od 1 do 10 (w��cznie):\n";
    int n = 0;
    while (cin>>n) {                   // wczytywanie
        if   (1<=n && n<=10) break;    // sprawdzanie zakresu
        cout << "Niestety "
            << n << " nie nale�y do zakresu <1,10>. Spr�buj jeszcze raz.\n";
    }

    return n;
}

//------------------------------------------------------------------------------
