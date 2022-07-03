
//
// Przyk³adowy kod z rozdzia³u 4.3.1 "Wyra¿enia sta³e" ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

//------------------------------------------------------------------------------

int main()
{
    const double pi = 3.14159265359;
    //pi = 7;           // B³¹d: przypisanie do sta³ej.
    int r = 7;
    double c = 2*pi*r;  // ok: tylko odczytaliœmy wartoœæ pi; nie próbujemy jej modyfikowaæ.
    const int max = 17; // Litera³ jest wyra¿eniem sta³ym.
    int val = 19;

    max+2;              // Wyra¿enie sta³e (sta³a liczba ca³kowita plus litera³).
    val+2;              // To nie jest wyra¿enie sta³e: u¿yto w nim zmiennej.
}

//------------------------------------------------------------------------------
