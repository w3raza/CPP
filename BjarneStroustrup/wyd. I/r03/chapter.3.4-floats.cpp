
//
// To jest przyk³adowy kod z rozdzia³u 3.4 "Operacje i operatory" ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

// Prosty program do poæwiczenia operatorów.
int main()
{
    cout << "Podaj liczbê zmiennoprzecinkow¹: ";
    double n;
    cin >> n;    
    cout << "n == " << n
         << "\nn+1 == " << n+1
         << "\nTrzy razy n == " << 3*n
         << "\nDwa razy n == " << n+n
         << "\nn do kwadratu == " << n*n
         << "\nPo³owa n == " << n/2
         << "\nPierwiastek drugiego stopnia z n == " << sqrt(n)
         << endl; // Inny sposób oznaczenia przejœcia do nowego wiersza.
}

//------------------------------------------------------------------------------
