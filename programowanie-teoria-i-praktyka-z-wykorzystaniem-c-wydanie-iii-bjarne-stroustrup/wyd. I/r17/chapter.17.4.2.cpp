
//
// To jest przyk�adowy kod z podrozdzia�u 17.4.2 "Dost�p poprzez wska�niki" ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

//------------------------------------------------------------------------------

int main()
{
    double* p = new double[4]; // Alokuje cztery liczby typu double w obszarze pami�ci wolnej.
    double x = *p;       // Odczytuje pierwszy obiekt wskazywany przez p.
    double y = p[2];     // Odczytuje trzeci obiekt wskazywany przez p.

    *p = 7.7;            // Zapisuje w pierwszym obiekcie wskazywanym przez p.
    p[2] = 9.9;          // Zapisuje w trzecim obiekcie wskazywanym przez p.

    {
        double x = *p;   // Odczytuje obiekt wskazywany przez p.
        *p = 8.8;        // Zapisuje w obiekcie wskazywanym przez p.
    }

    {
        double x = p[3]; // Odczytuje czwarty obiekt wskazywany przez p.
        p[3] = 4.4;      // Zapisuje w czwartym obiekcie wskazywanym przez p.
        double y = p[0]; // Instrukcja p[0] jest r�wnowa�na z *p.
    }
}

//------------------------------------------------------------------------------
