
//
// To jest przyk³adowy kod z podrozdzia³u 11.2.1 „Wysy³anie na wyjœcie liczb ca³kowitych” ksi¹¿ki 
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include <iostream>

using namespace std;

//------------------------------------------------------------------------------

int main()
{
    cout << 1234 << "\t(dziesiêtny)\n"
         << hex << 1234 << "\t(szesnastkowy)\n"
         << oct << 1234 << "\t(ósemkowy)\n";

    cout << 1234 << '\t' << hex << 1234 << '\t' << oct << 1234 << '\n';
    cout << 1234 << '\n';    // System ósemkowy jest ca³y czas w³¹czony.

    cout << 1234 << '\t' << hex << 1234 << '\t' << oct << 1234 << '\n';
    cout << showbase << dec; // pokazuje podstawy systemów liczbowych
    cout << 1234 << '\t' << hex << 1234 << '\t' << oct << 1234 << '\n';

    cout << 1234 << '\t' << 0x4d2 << '\t' << 02322 << '\n';
}

//------------------------------------------------------------------------------
