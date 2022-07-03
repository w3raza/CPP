
//
// To jest przyk³adowy kod z podrozdzia³u 26.3.3.4 „Rozga³êzianie” ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include <iostream>

using namespace std;

//------------------------------------------------------------------------------

void do_branch1(int x, int y) // marna funkcja
// niezdyscyplinowane stosowanie instrukcji if
{
    if (x<0) {
        if (y<0)
            cout << "Bardzo ujemne.\n";
        else
            cout << "Coœ ujemne.\n";
    }
    else if (x>0) {
        if (y<0)
            cout << "Bardzo dodatnie.\n";
        else
            cout << "Coœ dodatnie.\n";
    }
}

//------------------------------------------------------------------------------

int main()
{
    do_branch1(-1,-1);
    do_branch1(-1, 1);
    do_branch1(1,-1);
    do_branch1(1,1);
    do_branch1(-1,0); 
    do_branch1(0,-1);
    do_branch1(1,0);
    do_branch1(0,1);
    do_branch1(0,0);
}

//------------------------------------------------------------------------------

void do_branch2(int x, int y) // marna funkcja
// niezdyscyplinowane stosowanie instrukcji switch
{
    if (y<0 && y<=3)
        switch (x) {
        case 1:
            cout << "one\n"; 
            break;
        case 2:
            cout << "two\n";
        case 3:
            cout << "three\n";
    }
}

//------------------------------------------------------------------------------
