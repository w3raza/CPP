
//
// To jest przyk�adowy kod z podrozdzia�u 17.4.6 �Dealokacja pami�ci wolnej� ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

//------------------------------------------------------------------------------

double* calc(int res_size, int max)    // wyciek pami�ci
{
    double* p = new double[max];
    double* res = new double[res_size];
    // U�ywa p do obliczenia wynik�w, kt�re maj� zosta� zapisane w res.
    return res;
}

//------------------------------------------------------------------------------

int main()
{
    double* r = calc(100,1000);
}

//------------------------------------------------------------------------------
