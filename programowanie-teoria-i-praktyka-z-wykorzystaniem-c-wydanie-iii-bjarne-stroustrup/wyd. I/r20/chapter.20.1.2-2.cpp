
//
// To jest przyk³adowy kod z podrozdzia³u 20.1.2 „Uogólnianie kodu” ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

double* get_from_jack(int* count);  // Jacek wstawia liczby typu double do tablicy
//i zwraca liczbê elementów w *count.

vector<double>* get_from_jill();    // Agatka nape³nia wektor.

//------------------------------------------------------------------------------

double* high(double* first, double* last)
// Zwraca wskaŸnik do elementu o najwy¿szej wartoœci w przedziale <first,last).
{
    double h = -1;
    double* high;
    for(double* p = first; p!=last; ++p)
        if (h<*p) high = p;
    return high;
}

//------------------------------------------------------------------------------

void fct()
{
    int jack_count = 0;
    double* jack_data = get_from_jack(&jack_count);    
    vector<double>* jill_data = get_from_jill();    

    double* jack_high = high(jack_data,jack_data+jack_count);
    vector<double>& v = *jill_data;
    double* jill_high = high(&v[0],&v[0]+v.size());

    cout << "Maks. wartoœæ Agatki: " << *jill_high
        << "; Maks. wartoœæ Jacka: " << *jack_high;

    delete[] jack_data;
    delete jill_data;
}

//------------------------------------------------------------------------------

int main()
{
    fct();
    // ...
    // ...
}

//------------------------------------------------------------------------------

double* get_from_jack(int* count)
{
    if (!count)
        return 0;

    const int n = 10;

    double* arr = new double[n];

    if (arr)
    {
        *count = n;

        for (int i = 0; i < n; ++i)
            arr[i] = i;
    }

    return arr;
}

//------------------------------------------------------------------------------

vector<double>* get_from_jill()
{
    const int n = 10;

    vector<double>* arr = new vector<double>(n);

    if (arr)
    {
        for (int i = 0; i < n; ++i)
            (*arr)[i] = i;
    }

    return arr;
}

//------------------------------------------------------------------------------
