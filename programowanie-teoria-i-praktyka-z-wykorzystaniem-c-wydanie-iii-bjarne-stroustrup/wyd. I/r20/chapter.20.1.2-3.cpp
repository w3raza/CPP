
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
    vector<double>& v = *jill_data;

    double* middle = &v[0]+v.size()/2;
    double* high1 = high(&v[0], middle);          // max of first half
    double* high2 = high(middle, &v[0]+v.size()); // max of second half

	cout << "Maks. pierwszej po³owy: " << *high1
         << "; Maks. drugiej po³owy: " << *high2;

    delete[] jack_data;
    delete jill_data;
}

//------------------------------------------------------------------------------

int main()
{
    fct();
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

double* find_highest(vector<double>& v)
{
    double h = -1;
    double* high = 0;
    for (int i=0; i<v.size(); ++i)
        if (h<v[i]) high = &v[i];
    return high;
}

//------------------------------------------------------------------------------
