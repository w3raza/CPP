
//
// To jest przyk³adowy kod z podrozdzia³u 10.7 „Wczytywanie pojedynczej wartoœci” ksi¹¿ki 
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include <iostream>

using namespace std;

//------------------------------------------------------------------------------

int main()
{
    cout << "Podaj liczbê ca³kowit¹ z zakresu od 1 do 10 (w³¹cznie):\n";
    int n = 0;
    while (cin>>n) {                   // wczytywanie
        if   (1<=n && n<=10) break;    // sprawdzanie zakresu
        cout << "Niestety "
            << n << " nie nale¿y do zakresu <1,10>. Spróbuj jeszcze raz.\n";
    }

    return n;
}

//------------------------------------------------------------------------------
