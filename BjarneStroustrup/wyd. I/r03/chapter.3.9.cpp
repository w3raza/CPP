
//
// To jest przyk³adowy kod z rozdzia³u 3.9 "Kontrola typów" ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

//------------------------------------------------------------------------------

int main()
{
    double x;            // zapomnieliœmy zainicjowaæ zmienn¹
                         // wartoœæ x jest niezdefiniowana
    double y = x;        // wartoœæ zmiennej y jest niezdefiniowana
    double z = 2.0+x;    // niezdefiniowane znaczenie + i wartoœæ zmiennej z
}

//------------------------------------------------------------------------------
