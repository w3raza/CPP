
//
// To jest przyk�adowy kod z podrozdzia�u 19.5 �Zasoby i wyj�tki� ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

//------------------------------------------------------------------------------

void suspicious(int s, int x)
{
    int* p = new int[s];  // zajmowanie pami�ci
    // ...
    delete[] p;           // zwalnianie pami�ci
}

//------------------------------------------------------------------------------

int main()
{
    suspicious(4,42);
}

//------------------------------------------------------------------------------
