
//
// To jest przyk³adowy kod z podrozdzia³u 19.5 „Zasoby i wyj¹tki” ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

//------------------------------------------------------------------------------

void suspicious(int s, int x)
{
    int* p = new int[s];  // zajmowanie pamiêci
    // ...
    delete[] p;           // zwalnianie pamiêci
}

//------------------------------------------------------------------------------

int main()
{
    suspicious(4,42);
}

//------------------------------------------------------------------------------
