
//
// To jest przyk�adowy kod z rozdzia�u 3.5 "Przypisanie i inicjacja" ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

int main()
{
    {
        int a = 3;           // a ma pocz�tkowo warto�� 3

        a = 4;               // a przybiera warto�� 4 ("staje si� 4")

        int b = a;           // b ma pocz�tkowo kopi� warto�ci zmiennej a (tzn. 4)

        b = a+5;             // b przybiera warto�� a+5 (tzn. 9)
        a = a+7;             // a przybiera warto�� a+7 (tzn. 11)
    }

    {
        string a = "alfa";   // a ma pocz�tkowo warto�� "alfa"

        a = "beta";          // a przybiera warto�� "beta" (staje si� warto�ci� "beta")

        string b = a;        // b ma pocz�tkowo kopi� warto�ci zmiennej a (tzn. "beta")

        b = a+"gamma";       // b przybiera warto�� a+"gamma" (tzn. "betagamma")
        a = a+"delta";       // a przybiera warto�� a+"delta" (tzn. "betadelta")
    }

    {
        int y = 8;           // inicjacja y warto�ci� 8
        int x;

        x = 9;               // przypisanie 9 do x

        string t = "Cze��!"; // inicjacja t warto�ci� "Cze��!"
        string s;

        s = "Dobry dzie�";   // przypisanie �a�cucha "Dobry dzie�" do zmiennej s
    }
}

//------------------------------------------------------------------------------
