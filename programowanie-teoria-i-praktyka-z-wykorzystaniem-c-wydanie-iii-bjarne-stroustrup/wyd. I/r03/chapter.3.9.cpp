
//
// To jest przyk�adowy kod z rozdzia�u 3.9 "Kontrola typ�w" ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

//------------------------------------------------------------------------------

int main()
{
    double x;            // zapomnieli�my zainicjowa� zmienn�
                         // warto�� x jest niezdefiniowana
    double y = x;        // warto�� zmiennej y jest niezdefiniowana
    double z = 2.0+x;    // niezdefiniowane znaczenie + i warto�� zmiennej z
}

//------------------------------------------------------------------------------
