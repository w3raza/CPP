
//
// To jest przyk³adowy kod z podrozdzia³u 24.2.1 „Ograniczenia typów liczbowych” ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include <iostream>
#include <limits>

using namespace std;

//------------------------------------------------------------------------------

int main()
{

    cout << "Liczba bajtów w typie int: " << sizeof(int) << endl;
    cout << "Najwiêksza wartoœæ typu int: " << INT_MAX << endl;
    cout << "Najmniejsza wartoœæ typu int: " << numeric_limits<int>::min() << endl;

    if (numeric_limits<char>::is_signed)
        cout << "Typ char ma znak.\n";
    else
        cout << "Typ char nie ma znaku.\n";

    cout << "Typ char z najmniejsz¹ wartoœci¹: " << numeric_limits<char>::min() << endl;
    cout << "Najmniejsza wartoœæ typu char: "  << int(numeric_limits<char>::min()) << endl;
}

//------------------------------------------------------------------------------
