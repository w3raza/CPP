
//
// To jest przyk�adowy kod z podrozdzia�u 17.4.5 �Wska�nik zerowy� ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

//------------------------------------------------------------------------------

int main()
{
    double* p0 = 0;    // Wska�nik zerowy

    if (p0 != 0) 
    {
        // Nale�y uzna� wska�nik p0 za nadaj�cy si� do u�ytku.
    }

    if (p0)
    {
        // Nale�y uzna� wska�nik p0 za nadaj�cy si� do u�ytku. R�wnowa�ne z p0!=0.
    }
}

//------------------------------------------------------------------------------
