
//
// To jest przyk�adowy kod z podrozdzia�u 20.3.1 �Powr�t do przyk�adu� ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

template<class Iterator >
Iterator high(Iterator first, Iterator last)
// Zwraca iterator wskazuj�cy element o najwy�szej warto�ci w sekwencji <first,last).
{
    Iterator high = first;
    for (Iterator p = first; p!=last; ++p)
        if (*high<*p) high = p;
    return high;
}

//------------------------------------------------------------------------------

double* get_from_jack(int* count);  // Jacek wstawia liczby typu double do tablicy
                                    //i zwraca liczb� element�w w *count.
                                    
vector<double>* get_from_jill();    // Agatka nape�nia wektor.

//------------------------------------------------------------------------------

void fct()
{
    int jack_count = 0;
    double* jack_data = get_from_jack(&jack_count);    
    vector<double>* jill_data = get_from_jill();

    double* jack_high = high(jack_data,jack_data+jack_count);
    vector<double>& v = *jill_data;
    double* jill_high = high(&v[0],&v[0]+v.size());
    cout << "Maks. Agatki: " << *jill_high << "; Maks. Jacka: " << *jack_high;
    // ... 
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
