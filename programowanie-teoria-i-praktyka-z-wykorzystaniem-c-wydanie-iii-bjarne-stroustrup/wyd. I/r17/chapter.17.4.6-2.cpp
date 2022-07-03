
//
// To jest przyk�adowy kod z podrozdzia�u 17.4.6 �Dealokacja pami�ci wolnej� ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

//------------------------------------------------------------------------------

double* calc(int res_size, int max)
// Wywo�uj�cy odpowiada za pami�� przydzielon� res.
{
    double* p = new double[max];
    double* res = new double[res_size];
    // U�ywa p do obliczenia wynik�w, kt�re maj� zosta� zapisane w res.
    delete[] p;    // Nie potrzebujemy ju� tej pami�ci � zwalniamy j�.
    return res;
}

//------------------------------------------------------------------------------

int main()
{
    double* r = calc(100,1000);
    // U�ywa r
    delete[] r;    // Nie potrzebujemy ju� tej pami�ci � zwalniamy j�.
}

//------------------------------------------------------------------------------
