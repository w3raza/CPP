
//
// To jest przyk³adowy kod z podrozdzia³u 17.4.5 „WskaŸnik zerowy” ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

//------------------------------------------------------------------------------

int main()
{
    double* p0 = 0;    // WskaŸnik zerowy

    if (p0 != 0) 
    {
        // Nale¿y uznaæ wskaŸnik p0 za nadaj¹cy siê do u¿ytku.
    }

    if (p0)
    {
        // Nale¿y uznaæ wskaŸnik p0 za nadaj¹cy siê do u¿ytku. Równowa¿ne z p0!=0.
    }
}

//------------------------------------------------------------------------------
