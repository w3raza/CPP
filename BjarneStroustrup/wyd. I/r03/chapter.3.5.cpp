
//
// To jest przyk³adowy kod z rozdzia³u 3.5 "Przypisanie i inicjacja" ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

int main()
{
    {
        int a = 3;           // a ma pocz¹tkowo wartoœæ 3

        a = 4;               // a przybiera wartoœæ 4 ("staje siê 4")

        int b = a;           // b ma pocz¹tkowo kopiê wartoœci zmiennej a (tzn. 4)

        b = a+5;             // b przybiera wartoœæ a+5 (tzn. 9)
        a = a+7;             // a przybiera wartoœæ a+7 (tzn. 11)
    }

    {
        string a = "alfa";   // a ma pocz¹tkowo wartoœæ "alfa"

        a = "beta";          // a przybiera wartoœæ "beta" (staje siê wartoœci¹ "beta")

        string b = a;        // b ma pocz¹tkowo kopiê wartoœci zmiennej a (tzn. "beta")

        b = a+"gamma";       // b przybiera wartoœæ a+"gamma" (tzn. "betagamma")
        a = a+"delta";       // a przybiera wartoœæ a+"delta" (tzn. "betadelta")
    }

    {
        int y = 8;           // inicjacja y wartoœci¹ 8
        int x;

        x = 9;               // przypisanie 9 do x

        string t = "Czeœæ!"; // inicjacja t wartoœci¹ "Czeœæ!"
        string s;

        s = "Dobry dzieñ";   // przypisanie ³añcucha "Dobry dzieñ" do zmiennej s
    }
}

//------------------------------------------------------------------------------
