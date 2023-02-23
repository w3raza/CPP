
//
// To jest przyk³adowy kod z rozdzia³u 3.9.2 "Konwersje niebezpieczne dla typów" ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

int main()
{
    double d =0;
    while (cin>>d) {   // Powtarza poni¿sze instrukcje tak d³ugo,
                       // jak d³ugo s¹ wpisywane liczby.
        int i = d;     // Próba wciœniêcia liczby typu double do typu int.
        char c = i;    // Próba wciœniêcia liczby typu int do typu char.
        int i2 = c;    // Pobranie wartoœci ca³kowitoliczbowej odpowiadaj¹cej znakowi.
        cout << "d==" << d              // Oryginalna liczba typu double.
             << " i=="<< i              // Po konwersji na typ int.
             << " i2==" << i2           // Wartoœæ int typu char.
             << " char(" << c << ")\n"; // Typ char.
    }

    double x = 2.7;
    // du¿o kodu
    int y = x;         // y otrzymuje wartoœæ 2
    int a = 1000;
    char b = a;        // b otrzyma wartoœæ –24 (na niektórych komputerach)
}

//------------------------------------------------------------------------------
