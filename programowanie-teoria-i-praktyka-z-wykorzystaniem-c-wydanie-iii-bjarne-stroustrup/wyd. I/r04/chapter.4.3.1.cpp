
//
// Przyk�adowy kod z rozdzia�u 4.3.1 "Wyra�enia sta�e" ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

//------------------------------------------------------------------------------

int main()
{
    const double pi = 3.14159265359;
    //pi = 7;           // B��d: przypisanie do sta�ej.
    int r = 7;
    double c = 2*pi*r;  // ok: tylko odczytali�my warto�� pi; nie pr�bujemy jej modyfikowa�.
    const int max = 17; // Litera� jest wyra�eniem sta�ym.
    int val = 19;

    max+2;              // Wyra�enie sta�e (sta�a liczba ca�kowita plus litera�).
    val+2;              // To nie jest wyra�enie sta�e: u�yto w nim zmiennej.
}

//------------------------------------------------------------------------------
