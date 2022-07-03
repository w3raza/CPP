
//
// To jest przyk³adowy kod z podrozdzia³u 11.2.2 „Przyjmowanie na wejœciu liczb ca³kowitych” ksi¹¿ki 
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

    cin.unsetf(ios::dec);    // Nie zak³adaj z góry, ¿e liczby s¹ dziesiêtne (0x mo¿e oznaczaæ hex).
    cin.unsetf(ios::oct);    // Nie zak³adaj z góry, ¿e liczby s¹ ósemkowe (12 mo¿e oznaczaæ dwanaœcie).
    cin.unsetf(ios::hex);    // Nie zak³adaj z góry, ¿e liczby s¹ szesnastkowe (12 mo¿e oznaczaæ dwanaœcie).

    cin >>a >> b >> c >> d;
}

//------------------------------------------------------------------------------
