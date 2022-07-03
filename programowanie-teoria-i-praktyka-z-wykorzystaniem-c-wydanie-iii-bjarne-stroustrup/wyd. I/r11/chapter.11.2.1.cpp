
//
// To jest przyk�adowy kod z podrozdzia�u 11.2.1 �Wysy�anie na wyj�cie liczb ca�kowitych� ksi��ki 
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include <iostream>

using namespace std;

//------------------------------------------------------------------------------

int main()
{
    cout << 1234 << "\t(dziesi�tny)\n"
         << hex << 1234 << "\t(szesnastkowy)\n"
         << oct << 1234 << "\t(�semkowy)\n";

    cout << 1234 << '\t' << hex << 1234 << '\t' << oct << 1234 << '\n';
    cout << 1234 << '\n';    // System �semkowy jest ca�y czas w��czony.

    cout << 1234 << '\t' << hex << 1234 << '\t' << oct << 1234 << '\n';
    cout << showbase << dec; // pokazuje podstawy system�w liczbowych
    cout << 1234 << '\t' << hex << 1234 << '\t' << oct << 1234 << '\n';

    cout << 1234 << '\t' << 0x4d2 << '\t' << 02322 << '\n';
}

//------------------------------------------------------------------------------
