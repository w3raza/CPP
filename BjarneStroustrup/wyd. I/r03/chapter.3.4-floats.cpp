
//
// To jest przyk�adowy kod z rozdzia�u 3.4 "Operacje i operatory" ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

// Prosty program do po�wiczenia operator�w.
int main()
{
    cout << "Podaj liczb� zmiennoprzecinkow�: ";
    double n;
    cin >> n;    
    cout << "n == " << n
         << "\nn+1 == " << n+1
         << "\nTrzy razy n == " << 3*n
         << "\nDwa razy n == " << n+n
         << "\nn do kwadratu == " << n*n
         << "\nPo�owa n == " << n/2
         << "\nPierwiastek drugiego stopnia z n == " << sqrt(n)
         << endl; // Inny spos�b oznaczenia przej�cia do nowego wiersza.
}

//------------------------------------------------------------------------------
