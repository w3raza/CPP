
//
// To jest przyk�adowy kod z podrozdzia�u 11.2.2 �Przyjmowanie na wej�ciu liczb ca�kowitych� ksi��ki 
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include <iostream>

using namespace std;

//------------------------------------------------------------------------------

int main()
{
    int a;
    int b;
    int c;
    int d;
    cin >> a >> hex >> b >> oct >>  c >> d;
    cout << a << '\t' << b << '\t' << c << '\t' << d << '\n';

    cin.unsetf(ios::dec);    // Nie zak�adaj z g�ry, �e liczby s� dziesi�tne (0x mo�e oznacza� hex).
    cin.unsetf(ios::oct);    // Nie zak�adaj z g�ry, �e liczby s� �semkowe (12 mo�e oznacza� dwana�cie).
    cin.unsetf(ios::hex);    // Nie zak�adaj z g�ry, �e liczby s� szesnastkowe (12 mo�e oznacza� dwana�cie).

    cin >>a >> b >> c >> d;
}

//------------------------------------------------------------------------------
