
//
// To jest przyk�adowy kod z rozdzia�u 3.9.2 "Konwersje niebezpieczne dla typ�w" ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

int main()
{
    double d =0;
    while (cin>>d) {   // Powtarza poni�sze instrukcje tak d�ugo,
                       // jak d�ugo s� wpisywane liczby.
        int i = d;     // Pr�ba wci�ni�cia liczby typu double do typu int.
        char c = i;    // Pr�ba wci�ni�cia liczby typu int do typu char.
        int i2 = c;    // Pobranie warto�ci ca�kowitoliczbowej odpowiadaj�cej znakowi.
        cout << "d==" << d              // Oryginalna liczba typu double.
             << " i=="<< i              // Po konwersji na typ int.
             << " i2==" << i2           // Warto�� int typu char.
             << " char(" << c << ")\n"; // Typ char.
    }

    double x = 2.7;
    // du�o kodu
    int y = x;         // y otrzymuje warto�� 2
    int a = 1000;
    char b = a;        // b otrzyma warto�� �24 (na niekt�rych komputerach)
}

//------------------------------------------------------------------------------
