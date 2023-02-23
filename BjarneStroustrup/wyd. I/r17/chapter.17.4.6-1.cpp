
//
// To jest przyk³adowy kod z podrozdzia³u 17.4.6 „Dealokacja pamiêci wolnej” ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

//------------------------------------------------------------------------------

double* calc(int res_size, int max)    // wyciek pamiêci
{
    double* p = new double[max];
    double* res = new double[res_size];
    // U¿ywa p do obliczenia wyników, które maj¹ zostaæ zapisane w res.
    return res;
}

//------------------------------------------------------------------------------

int main()
{
    double* r = calc(100,1000);
}

//------------------------------------------------------------------------------
