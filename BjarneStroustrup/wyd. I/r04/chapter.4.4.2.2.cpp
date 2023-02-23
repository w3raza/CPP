
//
// Przyk³adowy kod z rozdzia³u 4.4.2.2 "Bloki" ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

//------------------------------------------------------------------------------

int main()
{
    int a = 7;
    int b = 4;

    if (a<=b) { // nic nie robi
    }
    else {      // zamienia a i b
        int t = a;
        a = b;
        b = t;
    }
}

//------------------------------------------------------------------------------
