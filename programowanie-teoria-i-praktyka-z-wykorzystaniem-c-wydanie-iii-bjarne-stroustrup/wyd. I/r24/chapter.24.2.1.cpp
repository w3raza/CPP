
//
// To jest przyk�adowy kod z podrozdzia�u 24.2.1 �Ograniczenia typ�w liczbowych� ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include <iostream>
#include <limits>

using namespace std;

//------------------------------------------------------------------------------

int main()
{

    cout << "Liczba bajt�w w typie int: " << sizeof(int) << endl;
    cout << "Najwi�ksza warto�� typu int: " << INT_MAX << endl;
    cout << "Najmniejsza warto�� typu int: " << numeric_limits<int>::min() << endl;

    if (numeric_limits<char>::is_signed)
        cout << "Typ char ma znak.\n";
    else
        cout << "Typ char nie ma znaku.\n";

    cout << "Typ char z najmniejsz� warto�ci�: " << numeric_limits<char>::min() << endl;
    cout << "Najmniejsza warto�� typu char: "  << int(numeric_limits<char>::min()) << endl;
}

//------------------------------------------------------------------------------
