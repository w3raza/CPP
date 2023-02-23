
//
// To jest przyk³adowy kod z podrozdzia³u 17.4.6 „Dealokacja pamiêci wolnej” ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

//------------------------------------------------------------------------------

double* calc(int res_size, int max)
// Wywo³uj¹cy odpowiada za pamiêæ przydzielon¹ res.
{
    double* p = new double[max];
    double* res = new double[res_size];
    // U¿ywa p do obliczenia wyników, które maj¹ zostaæ zapisane w res.
    delete[] p;    // Nie potrzebujemy ju¿ tej pamiêci — zwalniamy j¹.
    return res;
}

//------------------------------------------------------------------------------

int main()
{
    double* r = calc(100,1000);
    // U¿ywa r
    delete[] r;    // Nie potrzebujemy ju¿ tej pamiêci — zwalniamy j¹.
}

//------------------------------------------------------------------------------
